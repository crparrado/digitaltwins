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
	def __init__(self, fn='../SolarTherm/Systems/Reference_1.mo'):
		self.sim = simulation.Simulator(fn)
		print('Compiling model')
		self.sim.compile_model(args=['-d=nonewInst'])
		self.sim.compile_sim(args=['-s'])
		self.sim.load_init()

	def simulate(self):
		self.sim.simulate(start=0, stop='1y', tolerance=1e-4, step='300s',solver='dassl', nls='homotopy')
		self.res = postproc.SimResultElec(self.sim.res_fn)
		self.perf = self.res.calc_perf()
		print('epy  [GWhe ]: {0}'.format(self.perf[0]/1e3))
		print('lcoe [$/MWh]: {0}'.format(self.perf[1]))
		print('capf [  %  ]: {0}'.format(self.perf[2]))
		print('srev [  USD  ]: {0}'.format(self.perf[3]))

if __name__=='__main__':
	model = acciona(fn='../SolarTherm/Systems/Reference_1.mo')
	model.simulate()

