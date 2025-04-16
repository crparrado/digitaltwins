import streamlit as st
import os
import sys
import time
import subprocess
import pandas as pd
import numpy as np
import ast
import matplotlib.pyplot as plt
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

# Vectores a comparar
# Vector por defecto usado en el dashboard
vector_default = [0.2] * 6 + [0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.4] + [0.2] * 6

# Vector propuesto en el primer script
vector_propuesto = [
    0.8, 0.5, 0.3, 0.2, 0.2, 0.3, 
    0.5, 0.7, 0.9, 1.0, 1.0, 1.0, 
    1.0, 0.9, 0.9, 0.8, 0.7, 0.6, 
    0.5, 0.4, 0.3, 0.3, 0.4, 0.6
]

# Función para cargar el vector óptimo desde el archivo CSV
def cargar_vector_optimo_csv():
    try:
        csv_path = '/home/cparrado/solartherm/tests/resultado_genetico_solartherm_final200.csv'
        df = pd.read_csv(csv_path)
        
        # Extraer el vector como string y evaluar para convertirlo en una lista de tuplas
        vector_str = df.iloc[0, 0]
        vector_tuplas = ast.literal_eval(vector_str)
        
        # Extraer solo los valores del vector (sin las horas)
        vector_valores = [valor for _, valor in vector_tuplas]
        
        # Extraer el valor de srev (ingresos)
        srev = df.iloc[0, 1]
        
        print(f"Vector óptimo cargado correctamente del archivo {csv_path}")
        
        return vector_valores, srev
    except Exception as e:
        print(f"Error al cargar el vector óptimo desde CSV: {e}")
        raise

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
        dispatch_vector = create_dispatch_vector(vector)
        self.modify_dispatch_vector(dispatch_vector)
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

def graficar_resultados(resultados, nombres):
    # Crear una figura con 4 subplots
    fig, axes = plt.subplots(2, 2, figsize=(15, 12))
    fig.suptitle('Comparación de Resultados de Simulación', fontsize=16)
    
    # Extraer datos
    energia = [r[0]/1e3 for r in resultados]
    lcoe = [r[1] for r in resultados]
    factor_capacidad = [r[2] for r in resultados]
    ingresos = [r[3]/1e6 for r in resultados]
    
    # Gráfico de energía anual
    axes[0, 0].bar(nombres, energia, color=['blue', 'green', 'red'])
    axes[0, 0].set_title('Energía Anual (GWh)')
    axes[0, 0].set_ylabel('GWh')
    
    # Gráfico de LCOE
    axes[0, 1].bar(nombres, lcoe, color=['blue', 'green', 'red'])
    axes[0, 1].set_title('LCOE (USD/MWh)')
    axes[0, 1].set_ylabel('USD/MWh')
    
    # Gráfico de factor de capacidad
    axes[1, 0].bar(nombres, factor_capacidad, color=['blue', 'green', 'red'])
    axes[1, 0].set_title('Factor de Capacidad (%)')
    axes[1, 0].set_ylabel('%')
    
    # Gráfico de ingresos anuales
    axes[1, 1].bar(nombres, ingresos, color=['blue', 'green', 'red'])
    axes[1, 1].set_title('Ingresos Anuales (Millones USD)')
    axes[1, 1].set_ylabel('Millones USD')
    
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.savefig('comparacion_vectores.png')
    print("Gráfico guardado como 'comparacion_vectores.png'")
    
    return fig

def graficar_vectores(vectores, nombres):
    fig, ax = plt.subplots(figsize=(12, 6))
    horas = range(24)
    
    for i, vector in enumerate(vectores):
        ax.plot(horas, vector, marker='o', label=nombres[i])
    
    ax.set_title('Comparación de Vectores de Despacho')
    ax.set_xlabel('Hora del día')
    ax.set_ylabel('Factor de despacho')
    ax.set_xticks(horas)
    ax.set_xlim(-0.5, 23.5)
    ax.set_ylim(0, 1.1)
    ax.grid(True)
    ax.legend()
    
    plt.tight_layout()
    plt.savefig('vectores_despacho.png')
    print("Gráfico de vectores guardado como 'vectores_despacho.png'")
    
    return fig

def main():
    print("=== Comparación de Vectores de Despacho ===")
    
    # Cargar el vector óptimo
    vector_optimo, _ = cargar_vector_optimo_csv()
    
    # Mostrar los tres vectores
    print("\nVector por defecto:")
    for i, valor in enumerate(vector_default):
        print(f"Hora {i}: {valor}")
    
    print("\nVector propuesto:")
    for i, valor in enumerate(vector_propuesto):
        print(f"Hora {i}: {valor}")
    
    print("\nVector óptimo:")
    for i, valor in enumerate(vector_optimo):
        print(f"Hora {i}: {valor}")
    
    # Inicializar simulador
    print("\nInicializando simulador de SolarTherm...")
    simulator = AccionaSimulator()
    
    # Ejecutar simulación con los tres vectores
    print("\n=== Simulación con Vector por Defecto ===")
    resultados_default = simulator.simulate_with_vector(vector_default)
    
    print("\n=== Simulación con Vector Propuesto ===")
    resultados_propuesto = simulator.simulate_with_vector(vector_propuesto)
    
    print("\n=== Simulación con Vector Óptimo ===")
    resultados_optimo = simulator.simulate_with_vector(vector_optimo)
    
    # Resultados totales
    resultados = [resultados_default, resultados_propuesto, resultados_optimo]
    nombres = ["Por defecto", "Propuesto", "Óptimo"]
    
    # Crear tabla de resultados
    print("\n=== TABLA COMPARATIVA DE RESULTADOS ===")
    print(f"{'Vector':<15} {'Energía (GWh)':<15} {'LCOE (USD/MWh)':<15} {'Factor Cap. (%)':<15} {'Ingresos (USD)':<15}")
    print("-" * 75)
    
    for i, (nombre, res) in enumerate(zip(nombres, resultados)):
        print(f"{nombre:<15} {res[0]/1e3:<15.2f} {res[1]:<15.2f} {res[2]:<15.2f} {res[3]:<15.2f}")
    
    # Calcular mejoras porcentuales respecto al vector por defecto
    mejora_energia_propuesto = (resultados_propuesto[0] - resultados_default[0]) / resultados_default[0] * 100
    mejora_lcoe_propuesto = (resultados_default[1] - resultados_propuesto[1]) / resultados_default[1] * 100
    mejora_fc_propuesto = (resultados_propuesto[2] - resultados_default[2]) / resultados_default[2] * 100
    mejora_ingresos_propuesto = (resultados_propuesto[3] - resultados_default[3]) / resultados_default[3] * 100
    
    mejora_energia_optimo = (resultados_optimo[0] - resultados_default[0]) / resultados_default[0] * 100
    mejora_lcoe_optimo = (resultados_default[1] - resultados_optimo[1]) / resultados_default[1] * 100
    mejora_fc_optimo = (resultados_optimo[2] - resultados_default[2]) / resultados_default[2] * 100
    mejora_ingresos_optimo = (resultados_optimo[3] - resultados_default[3]) / resultados_default[3] * 100
    
    print("\n=== MEJORAS PORCENTUALES RESPECTO AL VECTOR POR DEFECTO ===")
    print(f"{'Vector':<15} {'Energía (%)':<15} {'LCOE (%)':<15} {'Factor Cap. (%)':<15} {'Ingresos (%)':<15}")
    print("-" * 75)
    print(f"{'Propuesto':<15} {mejora_energia_propuesto:<15.2f} {mejora_lcoe_propuesto:<15.2f} {mejora_fc_propuesto:<15.2f} {mejora_ingresos_propuesto:<15.2f}")
    print(f"{'Óptimo':<15} {mejora_energia_optimo:<15.2f} {mejora_lcoe_optimo:<15.2f} {mejora_fc_optimo:<15.2f} {mejora_ingresos_optimo:<15.2f}")
    
    # Generar gráficos
    graficar_resultados(resultados, nombres)
    graficar_vectores([vector_default, vector_propuesto, vector_optimo], nombres)
    
    print("\nFin de la comparación")

if __name__ == "__main__":
    main() 