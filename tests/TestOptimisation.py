# -*- coding: utf-8 -*-
from solartherm import simulation
from solartherm import postproc
from solartherm import params
from solartherm.optimisation import *
import functools

import colorama
colorama.init()
def yellow(text):
	return colorama.Fore.YELLOW + colorama.Style.BRIGHT + text + colorama.Style.RESET_ALL

class acciona:
	def __init__(self, fn='../SolarTherm/SaltTwoTanks_Acciona_4.mo'):
		self.sim = simulation.Simulator(fn)
		print('Compiling model')
		self.sim.compile_model(args=['-d=nonewInst'])
		self.sim.compile_sim(args=['-s'])
		self.sim.load_init()

	def simulate(self, scale, offset, par_n, par_val):
		par_v = [str(v*scale[i] + offset[i]) for i, v in enumerate(par_val)]
		self.sim.update_pars(par_n, par_v)
		self.sim.simulate(start=0, stop='1y', tolerance=1e-4, step='900s',solver='dassl', nls='homotopy')
		self.res = postproc.SimResultElec(self.sim.res_fn)
		self.perf = self.res.calc_perf()
		print(yellow('	Pars: {0}	Vals: {1}'.format(par_n,par_v) + '	lcoe [$/MWh]: {0}'.format(self.perf[1])))
		return self.perf[1]

	def optimise(self):
		vals = [[10,20]]
		par_n = ['t_storage']
		par_b = [[0,1]]
		par_0 = []
		LB = []
		UB = []
		offset = []
		scale = []
		for i in vals:
			lb = i[0]
			ub = i[1]
			p0 = (ub + lb)/2
			offset.append(lb)
			scale.append((ub - lb))
			par_0.append((p0 - lb)/(ub - lb))

		objfunc = functools.partial(self.simulate, scale, offset, par_n)
		res, cand = st_ga1(objfunc, par_b, par_n, scale, offset)
		print("Optimal design parameters: ", cand)
		print("Optimal objective function: ", res)
		return res,cand

if __name__=='__main__':
	model = acciona(fn='../SolarTherm/SaltTwoTanks_Acciona_4.mo')
	model.optimise()
