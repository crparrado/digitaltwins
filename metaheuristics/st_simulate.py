#!/usr/bin/env python
from __future__ import division, print_function,unicode_literals
import os, sys
if os.environ.get('VERBOSE'):
	print("***in st_simulate, SYS.PATH =",sys.path)

import argparse
import itertools
import multiprocessing as mp
from functools import partial
from solartherm import postproc
from solartherm import simulation
from solartherm import params
from time import time

# TODO: Pass on any command line arguments to simulation executable
# TODO: Save separate results files
# TODO: Pull together relevant results

def simulation_worker(fn, start, stop, step, tolerance, initStep, maxStep, integOrder, solver, nls, lv, args, par_n, resultclass, reuse, peaker, i, par_v):
	"""This small function is called from the mp.Pool for parallel simulations"""

	sim = simulation.Simulator(fn, suffix=str(i))

	sim.load_init()

	sim.update_pars(par_n, par_v)

	sim.simulate(start=start, stop=stop, step=step, tolerance=tolerance, initStep=initStep, maxStep=maxStep,
		integOrder=integOrder, solver=solver, nls=nls, lv=lv, args=args)
	res = resultclass(sim.res_fn)
	perf = res.calc_perf(peaker)
	return perf

class LoggerPerf(object):
	def __init__(self,resultclass):
		self.resultclass = resultclass
		self.perf_names = [n + ' (' + u + ')' for n, u in
			zip(resultclass.perf_n, resultclass.perf_u)]

	def header(self):
		print('Starting simulation')
		print(','.join(['index']+self.perf_names))
		text_file = open("results.txt","a")
		text_file.write(','.join(['index']+self.perf_names) + "\n")
		text_file.close()

	def entry(self, suff, perf):
		print(','.join([suff]+list(str(perf[j])
			for j, n in enumerate(self.perf_names))))
		text_file = open("results.txt","a")
		text_file.write(','.join([suff]+list(str(perf[j])
			for j, n in enumerate(self.perf_names))) + "\n")
		text_file.close()

def simulation_callback(perfs, i, logger, perf):
	perfs[i] = perf
	logger.entry(str(i), perf)

if __name__ == '__main__':
	"""
	Should make sure parameters are not final (protected), or that other
	derived parameters are final.
	For example, the internal starting level and height of an OpenTank is final
	"""
	parser = argparse.ArgumentParser()
	parser.add_argument('file',
			help='model file name')
	parser.add_argument('-v', action='store_true',
			help='verbose')
	parser.add_argument('--nomc', action='store_true',
			help='no model compilation')
	parser.add_argument('--nosc', action='store_true',
			help='no simulation compilation')
	parser.add_argument('--noc', action='store_true',
			help='no compilation at all (--nomc and --nosc)')
	parser.add_argument('--nosim', action='store_true',
			help='no simulation')
	parser.add_argument('--peaker', action='store_true',
			help='peaker configuration')
	parser.add_argument('--start', type=str, default='0',
			help='simulation start time: <number>[,y,d,m,s]')
	parser.add_argument('--stop', type=str, default='1y',
			help='simulation stop time: <number>[,y,d,m,s]')
	parser.add_argument('--step', type=str, default='5m',
			help='simulation time step: <number>[,y,d,m,s]')
	parser.add_argument('--tolerance', type=str, default='1e-04',
			help='simulation tolerance: <number>')
	parser.add_argument('--initStep', type=str, default=None,
			help='simulation initial step size used by dassl and ida methods: <number>[,y,d,m,s]')
	parser.add_argument('--maxStep', type=str, default=None,
			help='simulation maximum absolute step size used by dassl and ida methods: <number>[,y,d,m,s]')
	parser.add_argument('--integOrder', type=str, default='5',
			help='simulation maximum integration order used by dassl and ida methods: <number>')
	parser.add_argument('--lv', type=str, default='-LOG_SUCCESS,-stdout',
			help='a comma-separated String list specifing which logging levels to enable, e.g. LOG_DASSL,LOG_SOLVER etc')
	parser.add_argument('--plot', type=str, default=None,
			help='plot given quantity (at most 2 parameter dimensions)')
	parser.add_argument('--plot3d', action='store_true',
			help='plot in 3d')
	parser.add_argument('--eunit', type=str, default='MWh',
			help='unit of energy, e.g., J, kWh, MWh, or GWh')
	parser.add_argument('--punit', type=str, default='MW',
			help='unit of power(i.e. energy rate), e.g., W, kW, MW, or GW')
	parser.add_argument('-o', '--outfile',  type=str, default=None,
			help='save figure to outfile instead of displaying')
	parser.add_argument('--dpi', type=int, default=600,
			help='dpi if saving figure')
	parser.add_argument('--font', nargs=2, type=str, default=['serif', 'Times New Roman'],
			help='font family and style, family can only be one of serif, sans-serif, cursive, fantasy, monospace')
	parser.add_argument('--usetex', action='store_true',
			help='use text rendering With LaTeX')
	parser.add_argument('--unicode', action='store_true',
			help='use usetex with unicode')
	parser.add_argument('--mcargs', nargs=1, type=str, default=[],
			help='model compilation arguments')
	parser.add_argument('--sargs', type=str, default=None,
			help='simulation arguments')
	parser.add_argument('--np', type=int, default=mp.cpu_count(),
			help='number of processes (set to 0 for serial mode)')
	parser.add_argument('--solver', type=str, default='dassl',
			help='solver choice for OpenModelica')
	parser.add_argument('--nls', type=str, default='homotopy',
			help='non-linear solver choice for OpenModelica e.g. newton, hybrid, kinsol, mixed, and homotopy')
	#parser.add_argument('--nthsim', type=int, default=None,
	#		help='number of threads per simulation')
	parser.add_argument('par', metavar='P', type=str, nargs='*',
			help='set or sweep parameters, e.g.: p1=val1,val2 p2=val3')
	parser.add_argument('--fuel', action='store_true',
			help='run post-processing calculations for levelised cost of fuel')
	parser.add_argument('--fuse', action='store_true',
			help='disable use of unionfs-fuse to clean temporary files')
	parser.add_argument('--excel', type=str, default=None,
			help='the directry of the input excel data sheet')
	parser.add_argument('--wd', type=str, default=os.getcwd(),
			help='the working directory')


	args = parser.parse_args()

	fn=os.path.abspath(args.file)
	mn=os.path.splitext(os.path.split(fn)[1])[0] # model name
	input_xml=mn+'_init.xml'

	'''
	if not os.path.isabs(args.wd):
		savedir=os.path.join(os.getcwd(),args.wd)
	else:
		savedir=args.wd

	if not os.path.exists(args.wd):
		os.makedirs(args.wd)	

	os.chdir(args.wd)
	'''

	sim = simulation.Simulator(fn,fusemount=args.fuse)
	fuse_dirs = sim.get_fuse_dirs()

	# TODO This part to temperately fix the old front end issue for omc 1.17
	# will be revised later to work with the new front end
	#mcargs = ['-d=nonewInst']
	#if len(args.mcargs) == 1:
	#	mcargs = args.mcargs[0].split(' ')
	#else:
	#	mcargs=args.mcargs		

	sargs = []
	if args.sargs is not None:
		sargs = args.sargs[0].split(' ')

	if not args.noc:
		if not args.nomc:
			print('Compiling model')
			sim.compile_model()
		if not args.nosc:
			print('Compiling simulator')
			sim.compile_sim(args=([] if args.v else ['-s']))

	if args.fuel:
		resultclass = postproc.SimResultFuel
	else:
		resultclass = postproc.SimResultElec


	if args.excel!=None:
		tree=params.Tree()
		tree.load_xml(input_xml)
		#TODO check the units of the loaded parameters
		# convert the units if nessary using simulation.parse_var_val
		params.load_values_from_excel(args.excel, tree)	
		tree.write_xml(input_xml)

	sim.load_init()

	dims = [] # dimensions
	par_n = [] # names
	par_v = [] # values
	for pp in args.par:
		k, v = pp.split('=')
		par_n.append(k)
		
		# Modificación para tratar sch_file como string
		if k == "sch_file":
			vals = [val_str for val_str in v.split(',')] # Tomar como string directamente
		else:
			# Código original para otros parámetros numéricos
			vals = [str(simulation.parse_var_val(vv, sim.get_unit(k)))
				for vv in v.split(',')]
		par_v.append(vals)

		if len(vals) >= 2:
			dims.append(len(par_n) - 1)

	f_ilog = open(sim.model+'_init.log', 'w')
	f_ilog.write(','.join(['index']+par_n) + '\n')


	var_vals = []
	for i, val in enumerate(itertools.product(*par_v)):
		var_vals.append(val)
		f_ilog.write(','.join([str(i)]+list(val)) + '\n')
		

	logger = LoggerPerf(resultclass)
	perfs = [None]*len(var_vals)
	if not args.nosim:
		t = time()
		logger.header()
		worker_enc = partial(simulation_worker, args.file, args.start,
				args.stop, args.step, args.tolerance, args.initStep, args.maxStep, args.integOrder,
				args.solver, args.nls, args.lv, sargs, par_n, resultclass, fuse_dirs, args.peaker)
		if args.np:
			pool = mp.Pool(processes=args.np)
			# use apply_async in loop (not map_async) so callback runs 1x per sim.
			for i, val in enumerate(var_vals):
				pool.apply_async(worker_enc, args=(i, val)
					,callback=partial(simulation_callback, perfs, i, logger)
				)
			pool.close()
			pool.join()
		else:
		# serial version...
			for i, val in enumerate(var_vals):
				perf = worker_enc(i, val)
				simulation_callback(perfs,i,logger,perf)

		print("Simulation time: %fs"%(time()-t))

	if args.plot is not None:
		from solartherm import plotting
		import numpy as np
		ys = []
		ylabels = []
		for name in args.plot.split(','):
			try:
				pei = resultclass.perf_n.index(name)
			except ValueError:
				raise ValueError('Value to plot should be one of '
						+ str(resultclass.perf_n))
			ys.append([p[pei] for p in perfs])
			ylabels.append(name.upper() + ' (' + resultclass.perf_u[pei] + ')')
		if len(dims) == 1:
			x1 = [v[dims[0]] for v in var_vals]
			x1_unit = sim.get_unit(par_n[dims[0]])
			if x1_unit == 'J':
				x1_unit = args.eunit
				x1 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x1]), 'J', x1_unit)]
			if x1_unit == 'W':
				x1_unit = args.punit 
				x1 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x1]), 'W', x1_unit)]
			xlabel = par_n[dims[0]] + ' (' + x1_unit + ')'

			plotting.plot_par1(x1, ys, xlabel=xlabel, ylabels=ylabels, out=args.outfile,
				dpi=args.dpi, font=args.font, usetex=args.usetex, ucode=args.unicode)
		elif len(dims) == 2 and not args.plot3d:
			x1 = [v[dims[0]] for v in var_vals]
			x1_unit = sim.get_unit(par_n[dims[0]])
			if x1_unit == 'J':
				x1_unit = args.eunit
				x1 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x1]), 'J', x1_unit)]
			if x1_unit == 'W':
				x1_unit = args.punit 
				x1 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x1]), 'W', x1_unit)]
			x1label = par_n[dims[0]] + ' (' + x1_unit + ')'

			x2 = [v[dims[1]] for v in var_vals]
			x2_unit = sim.get_unit(par_n[dims[1]])
			if x2_unit == 'J':
				x2_unit = args.eunit
				x2 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x2]), 'J', x2_unit)]
			if x2_unit == 'W':
				x2_unit = args.punit 
				x2 = [str(j) for j in simulation.convert_val(np.array([float(i) for i in x2]), 'W', x2_unit)]
			x2label = par_n[dims[1]] + ' (' + x2_unit + ')'
			plotting.plot_par2(x1, x2, ys, x1label=x1label, x2label=x2label,
					ylabels=ylabels, out=args.outfile, dpi=args.dpi,
					font=args.font, usetex=args.usetex, ucode=args.unicode)
		elif len(dims) == 2 and args.plot3d:
			x1 = [float(v[dims[0]]) for v in var_vals]
			x1_unit = sim.get_unit(par_n[dims[0]])
			if x1_unit == 'J':
				x1_unit = args.eunit
				x1 = [float(j) for j in simulation.convert_val(np.array(x1), 'J', x1_unit)]
			if x1_unit == 'W':
				x1_unit = args.punit 
				x1 = [float(j) for j in simulation.convert_val(np.array(x1), 'W', x1_unit)]
			x1label = par_n[dims[0]] + ' (' + x1_unit + ')'

			x2 = [float(v[dims[1]]) for v in var_vals]
			x2_unit = sim.get_unit(par_n[dims[1]])
			if x2_unit == 'J':
				x2_unit = args.eunit
				x2 = [float(j) for j in simulation.convert_val(np.array(x2), 'J', x2_unit)]
			if x2_unit == 'W':
				x2_unit = args.punit 
				x2 = [float(j) for j in simulation.convert_val(np.array(x2), 'W', x2_unit)]
			x2label = par_n[dims[1]] + ' (' + x2_unit + ')'
			plotting.plot_3d(x1, x2, ys[0], xlabel=x1label, ylabel=x2label,
					zlabel=ylabels[0], out=args.outfile, dpi=args.dpi, font=args.font,
					usetex=args.usetex, ucode=args.unicode)
		else:
			print('Cannot plot problem with ' + str(len(dims)) + ' dimensions')

# vim: ts=4:sw=4:noet:syntax=python
