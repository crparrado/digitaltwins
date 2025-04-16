import streamlit as st
import os
import sys
import time
import subprocess
import pandas as pd
import numpy as np
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

# Vector óptimo obtenido desde el algoritmo genético
# Estos valores representan el factor de despacho para cada hora del día (0-23)
vector_optimo = [
    0.8, 0.5, 0.3, 0.2, 0.2, 0.3, 
    0.5, 0.7, 0.9, 1.0, 1.0, 1.0, 
    1.0, 0.9, 0.9, 0.8, 0.7, 0.6, 
    0.5, 0.4, 0.3, 0.3, 0.4, 0.6
]

# Función para crear vector de despacho
def create_dispatch_vector(individuo):
    """
    Dado un individuo (vector de 24 valores), genera un vector de despacho para 24 horas.
    Cada hora se define como i*3600, para i en 0 a 23.
    """
    return [(i * 3600, valor) for i, valor in enumerate(individuo)]

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
    print("=== Simulación con Vector Óptimo del Algoritmo Genético ===")
    print("Vector óptimo a utilizar:")
    for i, valor in enumerate(vector_optimo):
        print(f"Hora {i}: {valor}")
    
    # Crear el vector de despacho
    dispatch_vector = create_dispatch_vector(vector_optimo)
    
    # Inicializar simulador
    print("\nInicializando simulador de SolarTherm...")
    simulator = AccionaSimulator()
    
    # Ejecutar simulación con el vector óptimo
    print("\nEjecutando simulación con vector óptimo...")
    resultados = simulator.simulate_with_vector(dispatch_vector)
    
    # Mostrar resultados
    print("\n=== RESULTADOS DE LA SIMULACIÓN ===")
    print(f"Energía anual [GWh]: {resultados[0]/1e3:.2f}")
    print(f"LCOE [USD/MWh]: {resultados[1]:.2f}")
    print(f"Factor de capacidad [%]: {resultados[2]:.2f}")
    print(f"Ingresos anuales [USD]: {resultados[3]:.2f}")
    
    # Vector por defecto para referencia (sin simulación)
    vector_default = [0.2] * 6 + [0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.4] + [0.2] * 6
    print("\nVector por defecto (para referencia, no simulado):")
    for i, valor in enumerate(vector_default):
        print(f"Hora {i}: {valor}")
    
    print("\nFin de la simulación")

if __name__ == "__main__":
    main() 