# -*- coding: utf-8 -*-
from scipy import interpolate
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import pandas as pd
import os
home = os.path.expanduser('~')

ele = np.linspace(0,np.pi/2,10)
azi = np.linspace(0,33*np.pi/18,12)

ele2D, azi2D = np.meshgrid(ele,azi)

OELT = pd.read_csv(home + '/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/csv_acciona/field_opt_eff_4ms.csv', usecols = [1,2,3,4,5,6,7,8,9,10,11,12])

opt_eff = OELT.values

f = interpolate.interp2d(ele2D, azi2D, opt_eff)

TMY = pd.read_csv('TMY.csv')

aziTMY = TMY['Azimuth\n[°]']
eleTMY = TMY['Elevation\n[°]']

for i in range(np.size(eleTMY)):
	opt_effTMY = f(aziTMY[i], eleTMY[i])
	res = str(opt_effTMY)[1:-1]
	print res
