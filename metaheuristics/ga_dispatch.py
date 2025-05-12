#Algoritmo Genético
import numpy as np
import csv
import random
import os
import colorama
import multiprocessing # Añadido para paralelización
# import time # Descomentar si se quiere medir tiempos específicos

colorama.init()

# Importar módulos de SolarTherm
from solartherm import simulation, postproc
from solartherm.optimisation import *

# ------------------------
# Función para crear el vector de despacho completo
# ------------------------
def create_dispatch_vector(individuo):
    """
    Dado un individuo (vector de 24 valores), genera un vector de despacho para 24 horas.
    Cada hora se define como i*3600, para i en 0 a 23.
    """
    return [(i * 3600, valor) for i, valor in enumerate(individuo)]

# ------------------------
# Clase de simulación SolarTherm
# ------------------------
class acciona:
    def __init__(self, fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo'):
        self.fn = fn
        self.sim = None 
        # La compilación/inicialización ahora ocurre dentro de inicializar_sim(), 
        # que es llamado por simulate_with_vector().

    def inicializar_sim(self):
        # El workdir ahora se gestiona externamente mediante os.chdir() antes de llamar a este método.
        # Se crea una nueva instancia del simulador. Usará el CWD del proceso.
        self.sim = simulation.Simulator(self.fn)
        
        # print(f'Compiling model in simulator workdir: {self.sim.workdir}') # ESTA LÍNEA CAUSA EL ERROR Y SE ELIMINA
        # El simulador usará el directorio de trabajo actual (CWD) establecido por os.chdir() en la función worker.
        print(f'Compiling model in CWD: {os.getcwd()}') # Imprimimos el CWD actual para confirmación
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

    def simulate_with_vector(self, vector):
        # Modifica el archivo de despacho con el nuevo vector
        self.modify_dispatch_vector(vector)
        # Reinicializamos el simulador para forzar la lectura del nuevo vector
        self.inicializar_sim()
        # Ejecuta la simulación
        self.simulate()
        # Devuelve los parámetros de desempeño
        return self.perf

    def modify_dispatch_vector(self, vector):
        vector_path = '/home/cparrado/.openmodelica/libraries/SolarTherm/Data/Schedules/sch_acciona.motab'
        with open(vector_path, 'w') as file:
            file.write('#1\ndouble daily1(24,2)\n')
            for hour, value in vector:
                file.write(f'{hour} {value}\n')
        # Opcional: imprimir el contenido para depuración
        with open(vector_path, 'r') as file:
            contenido = file.read()
            print("Nuevo contenido de sch_acciona.motab:\n", contenido)

# ------------------------
# Constantes globales para el AG (usadas por cada proceso worker)
# ------------------------
NUM_VARIABLES = 24         # Cada individuo tiene 24 genes, uno por cada hora
PROB_MUTACION = 0.2        # Aumentamos la probabilidad de mutación a 0.2
VARIATION_RANGE = [i * 0.1 for i in range(1, 11)] # Rango de valores para cada gen

# ------------------------
# Función worker para ejecutar un caso experimental del GA
# ------------------------
def ejecutar_caso_ga(args):
    caso_config, lock = args
    tam_poblacion = caso_config["tam_poblacion"]
    num_generaciones = caso_config["num_generaciones"]
    caso_idx = caso_config["caso_idx"]

    # Crear un directorio de trabajo único para este worker.
    process_workdir = os.path.join(os.getcwd(), f"st_workdir_case{caso_idx+1}_pid{os.getpid()}")
    os.makedirs(process_workdir, exist_ok=True)
    print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Usando workdir: {process_workdir}")

    original_cwd = os.getcwd() # Guardar el directorio de trabajo actual
    os.chdir(process_workdir)  # Cambiar al directorio de trabajo específico del proceso
    print(f"[Caso {caso_idx+1}, PID {os.getpid()}] CWD cambiado a: {os.getcwd()}")

    try:
        # Instanciar el modelo SolarTherm para este proceso/caso.
        # Ahora usará el process_workdir como su directorio de trabajo actual.
        model = acciona(fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo')

        # ------------------------
        # Función de evaluación (fitness) - Adaptada para el worker
        # ------------------------
        def evaluar_fitness_worker(individuo, model_instance, sim_lock):
            """
            Para un individuo (vector de 24 valores), crea el vector de despacho completo,
            ejecuta la simulación en SolarTherm y retorna el valor de srev (revenues) como fitness.
            La simulación está protegida por un Lock.
            """
            dispatch_vector = create_dispatch_vector(individuo)
            fitness = -np.inf  # Default fitness
            
            sim_lock.acquire()
            print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Adquirió el lock para simular individuo: {' '.join(map(str, individuo[:3]))}...")
            try:
                # Esta llamada es la sección crítica que modifica sch_acciona.motab y recompila/simula
                perf = model_instance.simulate_with_vector(dispatch_vector)
                fitness = perf[3]  # Se asume que el cuarto valor (srev) es el objetivo a maximizar
                print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Simulación completada, srev: {fitness}")
            except Exception as e:
                print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Simulation error for individual {individuo}: {e}")
                fitness = -np.inf  # Penaliza en caso de error
            finally:
                sim_lock.release()
                print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Liberó el lock.")
            return fitness

        print(f"\n--- Iniciando Caso Experimental {caso_idx+1} (PID {os.getpid()}) ---")
        print(f"Población: {tam_poblacion}, Generaciones: {num_generaciones}")

        poblacion = np.array([[random.choice(VARIATION_RANGE) for _ in range(NUM_VARIABLES)] 
                              for _ in range(tam_poblacion)])

        csv_filename = f"resultados_generaciones_pop{tam_poblacion}_gen{num_generaciones}_caso{caso_idx+1}.csv"
        with open(csv_filename, "w", newline="") as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(["Generacion", "Indice_Individuo", "Genes", "Dispatch_Vector", "srev"])

            for gen in range(num_generaciones):
                print(f"\n[Caso {caso_idx+1}, PID {os.getpid()}] Generacion {gen+1}/{num_generaciones}")
                fitness_generacion = np.zeros(tam_poblacion)
                
                for i in range(tam_poblacion):
                    # No se llama a evaluar_fitness_worker aquí directamente para el fitness_generacion,
                    # sino que el contenido de la evaluación se hace en linea para grabar en CSV
                    # pero la simulación en sí (parte de evaluar_fitness_worker) es lo que se usa para el fitness real
                    
                    # dispatch_vector_eval = create_dispatch_vector(poblacion[i, :]) # Ya se hace en evaluar_fitness_worker
                    # Llamada a la función de evaluación que maneja el Lock
                    current_fitness = evaluar_fitness_worker(poblacion[i, :], model, lock)
                    fitness_generacion[i] = current_fitness
                    
                    # Para el CSV, necesitamos el dispatch_vector que se usó
                    dispatch_vector_csv = create_dispatch_vector(poblacion[i, :])
                    writer.writerow([gen+1, i, poblacion[i, :].tolist(), dispatch_vector_csv, fitness_generacion[i]])
                    csvfile.flush()
                
                mejor_idx_gen = np.argmax(fitness_generacion)
                elitismo = poblacion[mejor_idx_gen, :].copy()
                
                nueva_poblacion_gen = [elitismo]
                
                def torneo_worker(pobl, fit, k=3):
                    indices = random.sample(range(len(pobl)), k)
                    sub_fit = fit[indices]
                    best = indices[np.argmax(sub_fit)]
                    return pobl[best, :]
                
                while len(nueva_poblacion_gen) < tam_poblacion:
                    padre1 = torneo_worker(poblacion, fitness_generacion, k=3)
                    padre2 = torneo_worker(poblacion, fitness_generacion, k=3)
                    punto_cruce = np.random.randint(1, NUM_VARIABLES)
                    hijo1 = np.concatenate((padre1[:punto_cruce], padre2[punto_cruce:]))
                    hijo2 = np.concatenate((padre2[:punto_cruce], padre1[punto_cruce:]))
                    nueva_poblacion_gen.append(hijo1)
                    if len(nueva_poblacion_gen) < tam_poblacion:
                        nueva_poblacion_gen.append(hijo2)
                
                nueva_poblacion_gen = np.array(nueva_poblacion_gen[:tam_poblacion])
                
                for i in range(tam_poblacion):
                    if np.random.rand() < PROB_MUTACION:
                        idx = np.random.randint(0, NUM_VARIABLES)
                        nueva_poblacion_gen[i, idx] = random.choice(VARIATION_RANGE)
                
                poblacion = nueva_poblacion_gen.copy()

        # Evaluación final de la población para el caso actual
        fitness_final_caso = np.zeros(tam_poblacion)
        for i in range(tam_poblacion):
            # Usar la función de evaluación con lock para la evaluación final también
            fitness_final_caso[i] = evaluar_fitness_worker(poblacion[i, :], model, lock)

        mejor_idx_final = np.argmax(fitness_final_caso)
        mejor_fitness_final = fitness_final_caso[mejor_idx_final]
        mejor_individuo_final = poblacion[mejor_idx_final, :]
        dispatch_vector_final_csv = create_dispatch_vector(mejor_individuo_final)

        # Escribir el archivo CSV con el resultado final del caso actual
        # El nombre del archivo será relativo al CWD actual (process_workdir)
        final_result_csv_name_relative = f"resultado_genetico_solartherm_final_pop{tam_poblacion}_gen{num_generaciones}_caso{caso_idx+1}.csv"
        with open(final_result_csv_name_relative, "w", newline="") as csvfile_final:
            writer_final = csv.writer(csvfile_final)
            writer_final.writerow(["Dispatch Vector (hora, valor)", "srev"])
            writer_final.writerow([dispatch_vector_final_csv, mejor_fitness_final])

        # Los archivos CSV se crearán relativos al process_workdir o puedes usar rutas absolutas.
        # Para mantenerlos dentro del process_workdir:
        # csv_filename_path y resultado_final_csv_path ya están definidos usando os.path.join(os.getcwd(), f"...")
        # y os.getcwd() en este punto es process_workdir, por lo que son correctos para imprimir las rutas absolutas.
        csv_filename_path = os.path.join(os.getcwd(), csv_filename) # csv_filename fue definido en L139
        resultado_final_csv_path = os.path.join(os.getcwd(), final_result_csv_name_relative)

        # Reabrir el archivo CSV de generaciones aquí si es necesario o asegurarse de que se escribió correctamente antes.
        # Si el with open() para csv_filename está dentro del bucle de generaciones, ya está relativo al CWD (process_workdir)
        # Asegurémonos de que los nombres de archivo en las sentencias 'with open' usen rutas relativas (o absolutas si se prefiere)
        # La implementación actual de csv_filename y resultado_final_csv dentro del bucle ya será relativa al CWD (process_workdir)

        # El with open(csv_filename, ...) y with open(resultado_final_csv, ...) usarán el CWD que es process_workdir.
        # Esto significa que los archivos CSV se guardarán dentro de cada st_workdir_caseX_pidY.
        # Si quieres que se guarden en el directorio original desde donde se lanzó el script, tendrías que usar
        # os.path.join(original_cwd, csv_filename)

        # La impresión actual del nombre del archivo CSV es relativa, lo que está bien.
        print(f"\n[Caso {caso_idx+1}, PID {os.getpid()}] Mejor vector de despacho encontrado:")
        print(dispatch_vector_final_csv)
        print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Valor óptimo (srev): {mejor_fitness_final}")
        # Si los archivos CSV están en process_workdir, los paths impresos aquí deberían reflejar eso o ser ajustados.
        print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Resultados parciales guardados en: {csv_filename_path}") # Usar path absoluto para claridad
        print(f"[Caso {caso_idx+1}, PID {os.getpid()}] Resultados finales guardados en: {resultado_final_csv_path}") # Usar path absoluto
        
        result_message = f"Caso {caso_idx+1} finalizado con srev: {mejor_fitness_final}"
    finally:
        os.chdir(original_cwd) # Restaurar el directorio de trabajo original
        print(f"[Caso {caso_idx+1}, PID {os.getpid()}] CWD restaurado a: {os.getcwd()}")

    return result_message

# ------------------------
# Función de evaluación (fitness) - Esta ya no se usará directamente, se usa la _worker
# ------------------------
# def evaluar_fitness(individuo):
#     """
#     Para un individuo (vector de 24 valores), crea el vector de despacho completo,
#     ejecuta la simulación en SolarTherm y retorna el valor de srev (revenues) como fitness.
#     """
#     dispatch_vector = create_dispatch_vector(individuo)
#     try:
#         perf = model.simulate_with_vector(dispatch_vector) # 'model' sería global aquí
#         fitness = perf[3]
#     except Exception as e:
#         print(f"Simulation error for individual {individuo}: {e}")
#         fitness = -np.inf
#     return fitness

# ------------------------
# Parámetros del Algoritmo Genético (movidos a constantes globales o definidos por caso)
# ------------------------
# num_variables = 24
# prob_mutacion = 0.2
# variation_range = [i * 0.1 for i in range(1, 11)]

# Definir los casos experimentales basados en la tabla
casos_experimentales_config = [
    {"tam_poblacion": 10, "num_generaciones": 100, "caso_idx": 0},
    {"tam_poblacion": 10, "num_generaciones": 200, "caso_idx": 1},
    {"tam_poblacion": 10, "num_generaciones": 300, "caso_idx": 2},
    {"tam_poblacion": 30, "num_generaciones": 100, "caso_idx": 3},
    {"tam_poblacion": 30, "num_generaciones": 200, "caso_idx": 4},
    {"tam_poblacion": 30, "num_generaciones": 300, "caso_idx": 5},
]

# Instanciar el modelo SolarTherm (se compila una sola vez al inicio) --> Se mueve a la función worker
# model = acciona(fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo')

if __name__ == "__main__": # Necesario para multiprocessing en algunas plataformas
    print("Iniciando ejecuciones paralelas de los casos experimentales...")
    
    # Crear un Lock para serializar el acceso a la simulación de SolarTherm
    simulation_lock = multiprocessing.Manager().Lock() # Usar Manager().Lock() si se pasa a Pool por map
                                                    # o multiprocessing.Lock() si se usa initializer

    # Preparar argumentos para la función worker
    # Cada worker necesita la configuración del caso y el lock
    args_para_pool = [(caso_conf, simulation_lock) for caso_conf in casos_experimentales_config]

    # Determinar el número de procesos a usar
    # Usar el número de casos o el número de CPUs, lo que sea menor, para no crear procesos innecesarios.
    num_procesos = min(len(casos_experimentales_config), os.cpu_count())
    print(f"Se usarán {num_procesos} procesos paralelos.")

    # Crear y ejecutar el pool de procesos
    with multiprocessing.Pool(processes=num_procesos) as pool:
        resultados_pool = pool.map(ejecutar_caso_ga, args_para_pool)
    
    print("\n--- Todos los casos experimentales han finalizado (paralelamente) ---")
    for res in resultados_pool:
        print(res)

# El código original del bucle de casos ya no es necesario aquí, se movió a ejecutar_caso_ga
# # Bucle principal para iterar sobre cada caso experimental
# for caso_idx, caso in enumerate(casos_experimentales):
#     tam_poblacion = caso["tam_poblacion"]
# ... (resto del código secuencial eliminado) ...
# print("\\n--- Todos los casos experimentales han finalizado ---")