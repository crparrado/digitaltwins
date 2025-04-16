import streamlit as st
import os
import sys
import time
import subprocess
import pandas as pd
import numpy as np
import ast
from datetime import datetime

# Agregar la ruta de SolarTherm a sys.path para poder importar los módulos
sys.path.append('/home/cparrado/solartherm/src')
try:
    from solartherm import simulation
    from solartherm import postproc
    print("Módulos de SolarTherm cargados correctamente")
except ImportError as e:
    print(f"Error al importar módulos de SolarTherm: {e}")
    raise

# Función para cargar el vector óptimo desde el archivo CSV
def cargar_vector_optimo_csv():
    try:
        csv_path = '/home/cparrado/solartherm/tests/resultado_genetico_solartherm_final200.csv'
        df = pd.read_csv(csv_path)
        
        # Extraer el vector como string y evaluar para convertirlo en una lista de tuplas
        vector_str = df.iloc[0, 0]
        vector_tuplas = ast.literal_eval(vector_str)
        
        # Extraer el valor de srev (ingresos)
        srev = df.iloc[0, 1]
        
        print(f"Vector óptimo cargado correctamente del archivo {csv_path}")
        print(f"Ingresos esperados (srev): {srev}")
        
        return vector_tuplas, srev
    except Exception as e:
        print(f"Error al cargar el vector óptimo desde CSV: {e}")
        raise

# Clase de simulación SolarTherm
class AccionaSimulator:
    def __init__(self, fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo'):
        self.fn = fn
        self.inicializar_sim()

    def inicializar_sim(self):
        # Forzamos la recompilación y carga creando una nueva instancia del simulador
        self.sim = simulation.Simulator(self.fn)
        print('Compiling model')
        self.sim.compile_model(args=['-d=nonewInst'])
        self.sim.compile_sim(args=['-s'])
        self.sim.load_init()

    def simulate(self):
        self.sim.simulate(start=0, stop='1y', tolerance=1e-4, step='300s', solver='dassl', nls='homotopy')
        self.res = postproc.SimResultElec(self.sim.res_fn)
        self.perf = self.res.calc_perf()
        print('epy  [GWhe ]: {0}'.format(self.perf[0]/1e3))
        print('lcoe [$/MWh]: {0}'.format(self.perf[1]))
        print('capf [  %  ]: {0}'.format(self.perf[2]))
        print('srev [  USD  ]: {0}'.format(self.perf[3]))
        return self.perf

    def simulate_with_vector(self, vector):
        # Actualiza el archivo de despacho con el vector proporcionado
        self.modify_dispatch_vector(vector)
        # Reinicializar el simulador para forzar la lectura del archivo actualizado
        self.inicializar_sim()
        resultado = self.simulate()
        return resultado

    def modify_dispatch_vector(self, vector):
        vector_path = '/home/cparrado/.openmodelica/libraries/SolarTherm/Data/Schedules/sch_acciona.motab'
        with open(vector_path, 'w') as file:
            file.write('#1\ndouble daily1(24,2)\n')
            for hour, value in vector:
                file.write(f'{hour} {value}\n')
        # Opcional: imprimir el contenido para verificación
        with open(vector_path, 'r') as file:
            contenido = file.read()
            print("Nuevo contenido de sch_acciona.motab:\n", contenido)

def main():
    print("=== Simulación con Vector Óptimo final del Algoritmo Genético ===")
    
    # Cargar el vector óptimo desde el CSV
    vector_optimo, srev_esperado = cargar_vector_optimo_csv()
    
    # Convertir el vector a formato más legible para impresión
    vector_valores = [valor for _, valor in vector_optimo]
    
    print("\nVector óptimo a utilizar:")
    for i, (hora, valor) in enumerate(vector_optimo):
        print(f"Hora {i}: {valor}")
    
    # Inicializar simulador
    print("\nInicializando simulador de SolarTherm...")
    simulator = AccionaSimulator()
    
    # Ejecutar simulación con el vector óptimo
    print("\nEjecutando simulación con vector óptimo final...")
    resultados = simulator.simulate_with_vector(vector_optimo)
    
    # Mostrar resultados
    print("\n=== RESULTADOS DE LA SIMULACIÓN ===")
    print(f"Energía anual [GWh]: {resultados[0]/1e3:.2f}")
    print(f"LCOE [USD/MWh]: {resultados[1]:.2f}")
    print(f"Factor de capacidad [%]: {resultados[2]:.2f}")
    print(f"Ingresos anuales [USD]: {resultados[3]:.2f}")
    
    # Comparar con el valor esperado
    print("\n=== VALIDACIÓN ===")
    diferencia = abs(resultados[3] - srev_esperado)
    diferencia_porcentual = diferencia / srev_esperado * 100
    
    print(f"Ingresos esperados según CSV: {srev_esperado:.2f} USD")
    print(f"Ingresos obtenidos: {resultados[3]:.2f} USD")
    print(f"Diferencia: {diferencia:.2f} USD ({diferencia_porcentual:.2f}%)")
    
    print("\nFin de la simulación")

if __name__ == "__main__":
    main() 