import argparse
import pandas as pd
import numpy as np
import DyMat
import xlsxwriter
import matplotlib as mpl
mpl.use('GtkAgg')
mpl.rcParams["figure.dpi"] = 100.
mpl.rcParams["figure.figsize"] = [6, 4]
#mpl.rcParams['text.usetex'] = True
#mpl.rcParams['text.latex.unicode'] = True
mpl.rcParams['font.size'] = 10
import matplotlib.pyplot as plt
import matplotlib.font_manager as font_manager
import os
from os.path import expanduser

home = expanduser('~') + '/solartherm/examples/'

prop = font_manager.FontProperties(fname='/usr/share/fonts/truetype/cmu/cmunrm.ttf')
mpl.rcParams['font.family'] = prop.get_name()

class read_res:
	def __init__(self,res_file,log_file):
		self.system_name = log_file.split('_')[0]
		self.df_res = pd.read_csv(home + res_file)
		self.df_res = self.df_res.sort_values(by='index')
		self.df_res = self.df_res.set_index('index')

		self.df_log = pd.read_csv(home + log_file)

		self.df_tot = pd.concat([self.df_res,self.df_log], axis = 1)
		self.res = self.df_tot.shape[0]
		self.x = np.linspace(2.5,3.5,11)
		self.var = ['lcoe ($/MWh)','epy (MWh/year)'];
		self.ylb = ['LCOE (\$/MWh)','EPY (MWh/year)']
		self.storage = ['4 h', '8 h', '12 h']

class plot_res:
	def __init__(self,obj,var_name,var_label):
		for j in range(3):
			plt.figure()
			for i in range(len(obj.storage)):
				imin = 0 + 11*i + 33*j
				imax = 10 + 11*i + 33*j
				Label = str(obj.df_tot.loc[imin,'t_storage']) + ' h'
				X = obj.x
				Y = obj.df_tot.loc[imin:imax,var_name]
				plt.plot(X,Y,label = Label)
			plt.xlabel('Solar multiple')
			plt.ylabel(var_label)
			plt.legend(loc='best', frameon=False)
			plt.title(str(100/obj.df_tot.loc[imin,'power_fr']) + ' MW')
			plt.savefig(home + var_label.split(' ')[0] + '_' + str(100/obj.df_tot.loc[imin,'power_fr']) + 'MW' + '.pdf')

class res2excel:
	def __init__(self,res,res_vars,system_name):
		# res is the number of mat files from the simulation
		self.path = home + system_name + '.xlsx'
		workbook = xlsxwriter.Workbook(self.path)
		worksheet = workbook.add_worksheet('summary')
		for j in range(len(res_vars)):
			worksheet.write(0,j,res_vars[j])
		for i in range(res):
			data = DyMat.DyMatFile(home + 'SmallSaltSCO2System_res_' + str(i) + '.mat')
			for j in range(len(res_vars)):
				Var = data.data(res_vars[j]);
				worksheet.write(i+1,j,Var[-1])
		workbook.close()

class excel2plot:
	def __init__(self,path,p_name,t_storage,var_name,ylabel):
		self.df = pd.read_excel(path)
		for i in range(len(p_name)):
			plt.figure()
			for j in range(len(t_storage)):
				if i < 1:
					df = self.df[ (self.df['t_storage']==t_storage[j]) & (self.df['P_name']<(p_name[i] + 1)*1e6)]
				else:
					df = self.df[ (self.df['t_storage']==t_storage[j]) & (self.df['P_name']>(p_name[i-1] + 1)*1e6) & (self.df['P_name']<(p_name[i] + 1)*1e6)]
				x = df['SM']
				y = df[var_name]
				plt.plot(x,y/3600/1e6,label=str(p_name[i]))
			plt.xticks(x)
			plt.ylabel(ylabel)
			plt.xlabel('Solar multiple')
			plt.title(str(p_name[i]) + ' MW')
			plt.savefig(home + var_name + '_' + str(p_name[i]) + 'MW' + '.pdf')

if __name__ == '__main__':
	obj = read_res('results.txt','SmallSaltSCO2System_init.log')
	plot_res(obj,obj.var[0],obj.ylb[0])
	plot_res(obj,obj.var[1],obj.ylb[1])
#	res2excel(obj.res,['P_name','t_storage','SM','heliostatsField.E_field','receiver.E_rec','receiver.E_loss','receiver.E_pip'],obj.system_name)
	excel2plot(home + obj.system_name + '.xlsx',[10,25,50],[4,8,12],'heliostatsField.E_field','EPY Field (MWh)')
#	plt.show()
