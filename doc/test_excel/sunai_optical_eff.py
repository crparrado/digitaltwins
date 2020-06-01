from scipy import interpolate
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import os
home = os.path.expanduser('~')

x = np.linspace(0,np.pi/2,10)
y = np.linspace(0,330*np.pi/180,12)

xx, yy = np.meshgrid(x,y)

df = pd.read_csv(home + '/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/csv_acciona/field_opt_eff_4ms.csv', usecols = [1,2,3,4,5,6,7,8,9,10,11,12])

z = df.values

f = interpolate.interp2d(xx, yy, z)

df = pd.read_csv('TMY.csv')

xnew = df['Azimuth\n[°]']
ynew = df['Elevation\n[°]']

for i in range(np.size(xnew)):
	znew = f(xnew[i], ynew[i])
