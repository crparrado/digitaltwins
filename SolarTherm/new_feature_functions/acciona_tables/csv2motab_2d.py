#!/usr/bin/env python
# coding: utf-8

import argparse
parser = argparse.ArgumentParser(description='converts a .csv file into an openmodelica readable .motab file')
parser.add_argument('-f_in',action='store',dest='f_in',
                    help='location of .csv file to convert')
parser.add_argument('-tname',action='store',dest='tname',
                    help='table label for .motab file')
parser.add_argument('-f_out',action='store',dest='f_out',
                    help='location of .motab converted file')
args = parser.parse_args()

from re import sub

def csv_OM_format_2d(data_str,table_name,sep=','):
    # recibe un string con  el contenido del csv
    row_list = data_str.split('\n')
    motab_str = ''
    for ii in range(len(row_list)):
        
        row = row_list[ii]
        row = row.split(sep)
        if ii == 0:
            row[0] = '0.0'
            u1dim = len(row_list)-1 # u[1]  dim
            u2dim = len(row)# u[2] dim
        row_alnum = sub(r'\W+', '', "".join(row))
        if not row_alnum.isalnum():
            u1dim = u1dim - 1 # remueve la fila "no alfanumerica" de la cuenta de filas 
            continue
        
        row = ','.join(row).replace('%','')
        motab_str = motab_str + row + '\n'
    motab_str = "#1\ndouble %s(%d,%d)\n%s"%(table_name,u1dim,u2dim,motab_str)
    return motab_str

f_in = args.f_in
tname = args.tname
f_out = args.f_out

csv_folder = './csv_acciona/'
csv_name_in = '/bop_aux_loads.csv'
csv_name_out = '/bop_aux_load.motab'

with open(f_in, 'r') as file:
    data_str = file.read()#.replace('\n', '')

motab_str = csv_OM_format_2d(data_str,tname)

with open(f_out, "w") as file:
    file.write(motab_str)
