import numpy as np
import random
import os
import shutil
import subprocess
import xml.etree.ElementTree as ET
import multiprocessing
import pandas as pd
import time
import sys
import csv
import traceback

# --- Configuración General ---
NUM_PARAMS_VECTOR = 24  # Horas en el vector de despacho
MIN_VAL, MAX_VAL = 0.0, 1.0  # Rango para los valores de despacho normalizados

# --- Rutas (¡IMPORTANTE: VERIFICA Y AJUSTA ESTAS RUTAS!) ---
# WORKSPACE_DIR: Intenta deducir la raíz del proyecto 'solartherm'
# Asume que este script está en 'solartherm/tests/metaheuristics/'
try:
    CURRENT_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
    WORKSPACE_DIR = os.path.abspath(os.path.join(CURRENT_SCRIPT_DIR, "..", ".."))
    if not os.path.basename(WORKSPACE_DIR) == "solartherm":
        print(f"ADVERTENCIA: WORKSPACE_DIR ({WORKSPACE_DIR}) podría no ser la raíz del proyecto 'solartherm'. Verifica las rutas.")
except NameError: # Ocurre si __file__ no está definido (ej. en algunos intérpretes interactivos)
    WORKSPACE_DIR = "/home/cparrado/solartherm" # Ruta de respaldo, AJUSTA SI ES NECESARIO
    print(f"ADVERTENCIA: Usando ruta de respaldo para WORKSPACE_DIR: {WORKSPACE_DIR}. Verifica las rutas.")


# MODEL_MO_PATH = os.path.join(WORKSPACE_DIR, "Reference_1.mo") # Comentado: Asume que está en la raíz
MODEL_MO_PATH = "/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo" # Descomentado: Usa la versión de la biblioteca OM
BASE_INIT_XML_PATH = os.path.join(WORKSPACE_DIR, "Reference_1_init.xml")
ST_SIMULATE_SCRIPT_PATH = os.path.join(WORKSPACE_DIR, "tests", "metaheuristics", "st_simulate.py") 

# --- Directorios de Trabajo y Resultados ---
SIM_BASE_WORKDIR_NAME = "st_ga_sim_workdirs_simplified_v2"
SIM_BASE_WORKDIR = os.path.join(WORKSPACE_DIR, SIM_BASE_WORKDIR_NAME)

GA_RESULTS_BASE_DIR_NAME = "ga_dispatch_results_simplified_v2"
GA_RESULTS_BASE_DIR = os.path.join(WORKSPACE_DIR, GA_RESULTS_BASE_DIR_NAME)

# --- Parámetro XML (Confirmado del XML) ---
# El nombre exacto encontrado en Reference_1_init.xml
POSIBLES_NOMBRES_PARAM = [
    "sch_file" 
]
SREV_COLUMN_NAME_IN_RESULTS_TXT = "srev ($)" # Nombre de la columna de fitness en results.txt

# --- Casos Experimentales ---
casos_experimentales = [
    {"id_caso": "C1", "tam_poblacion": 10, "num_generaciones": 10, "prob_mutacion": 0.15, "prob_cruce": 0.75},
    {"id_caso": "C2", "tam_poblacion": 10, "num_generaciones": 15, "prob_mutacion": 0.20, "prob_cruce": 0.70},
]

# --- Funciones Auxiliares ---
def create_dispatch_vector(individuo_normalizado):
    # Asume que el individuo tiene valores normalizados [0,1]
    # Aquí podrías desnormalizar si es necesario, o ajustar los valores.
    # Por ahora, los usamos tal cual, asumiendo que el modelo los interpreta apropiadamente.
    return [(i * 3600, valor) for i, valor in enumerate(individuo_normalizado)]

def write_motab_file(vector_despacho, filepath):
    try:
        with open(filepath, 'w') as file:
            file.write('#1\n')
            # El modelo Modelica espera "daily1" como nombre de la tabla interna.
            file.write(f'double daily1({len(vector_despacho)},2)\n') 
            for timestamp, value in vector_despacho:
                file.write(f'{timestamp} {value}\n')
        return True
    except Exception as e:
        print(f"[PID {os.getpid()}] ERROR escribiendo MOTAB {filepath}: {repr(e)}", flush=True)
        return False

def parse_results_txt_pandas(filepath, target_column_name):
    try:
        if not os.path.exists(filepath):
            print(f"[PID {os.getpid()}] ERROR (parse_results): Archivo no encontrado: {filepath}", flush=True)
            return -np.inf
        
        # st_simulate.py usa comas como delimitador.
        df = pd.read_csv(filepath, sep=',', comment='#') # Usar coma como separador

        if target_column_name not in df.columns:
            print(f"[PID {os.getpid()}] ERROR (parse_results): Columna '{target_column_name}' no en {filepath}. Columnas: {df.columns.tolist()}", flush=True)
            # Imprimir contenido para ayudar a depurar formato
            try:
                with open(filepath, 'r') as f_err:
                    print(f"--- Contenido de {filepath} (primeras 5 líneas) ---", flush=True)
                    for _ in range(5): print(f_err.readline().strip(), flush=True)
                    print(f"--- Fin del contenido de {filepath} ---", flush=True)
            except Exception as e_dbg: print(f"Error leyendo archivo para debug: {e_dbg}", flush=True)
            return -np.inf
        
        if df.empty:
            print(f"[PID {os.getpid()}] ERROR (parse_results): Archivo {filepath} está vacío o no contiene datos parseables.", flush=True)
            return -np.inf
            
        srev_value = df[target_column_name].iloc[-1] # Tomar el último valor de la columna
        return float(srev_value)

    except FileNotFoundError:
        print(f"[PID {os.getpid()}] ERROR (parse_results): Archivo no encontrado (FileNotFoundError): {filepath}", flush=True)
        return -np.inf
    except pd.errors.EmptyDataError:
        print(f"[PID {os.getpid()}] ERROR (parse_results): Archivo {filepath} vacío (EmptyDataError).", flush=True)
        return -np.inf
    except KeyError:
        cols_avail = df.columns.tolist() if 'df' in locals() and hasattr(df, 'columns') else "desconocidas"
        print(f"[PID {os.getpid()}] ERROR (parse_results): Columna '{target_column_name}' no encontrada (KeyError). Columnas disponibles: {cols_avail}", flush=True)
        return -np.inf
    except Exception as e:
        print(f"[PID {os.getpid()}] ERROR (parse_results): Excepción inesperada parseando {filepath}: {repr(e)}", flush=True)
        traceback.print_exc()
        return -np.inf

# --- Función de Evaluación de Fitness ---
def evaluar_fitness_individual(individuo, eval_id_str, base_sim_workdir, base_init_xml_to_copy_path, st_sim_script_path, local_motab_filename_for_eval):
    pid = os.getpid()
    
    # Directorio de simulación para esta evaluación específica (donde se ejecutará st_simulate y se guardará .motab y results.txt)
    sim_exec_workdir = os.path.join(base_sim_workdir, eval_id_str)
    os.makedirs(sim_exec_workdir, exist_ok=True)
    
    # Ruta completa al archivo .motab (se guarda en el directorio de ejecución de st_simulate)
    motab_filepath_in_exec_workdir = os.path.join(sim_exec_workdir, local_motab_filename_for_eval)
    
    dispatch_vector = create_dispatch_vector(individuo)
    if not write_motab_file(dispatch_vector, motab_filepath_in_exec_workdir):
        print(f"[{eval_id_str}] ERROR: Falló write_motab_file para {motab_filepath_in_exec_workdir}", flush=True)
        return -np.inf

    # --- YA NO SE MODIFICA EL XML --- 
    # La lógica de copiar y modificar Reference_1_init.xml se elimina.
    # st_simulate.py usará su XML base y nosotros le pasaremos sch_file como argumento.

    # Construir comando para st_simulate.py, pasando el parámetro sch_file
    # local_motab_filename_for_eval ya es solo el nombre del archivo, ej. "dispatch_XYZ.motab"
    # st_simulate se ejecutará en sim_exec_workdir, donde reside este .motab.
    cmd_list = [
        sys.executable,             
        st_sim_script_path,
        MODEL_MO_PATH, 
        f"sch_file={local_motab_filename_for_eval}" # Pasando sch_file como argumento
        # Otros argumentos fijos si son necesarios (ej. "stopTime=...", etc.)
    ]
    
    fitness = -np.inf 
    try:
        # El CWD para st_simulate.py es sim_exec_workdir.
        result = subprocess.run(cmd_list, cwd=sim_exec_workdir, capture_output=True, text=True, check=True, timeout=400)
        
        # --- Imprimir STDOUT y STDERR para depuración --- 
        if result.stdout:
            print(f"[{eval_id_str}] STDOUT subproceso (código 0):", flush=True)
            print(result.stdout, flush=True) # DESCOMENTADO para depuración
        if result.stderr:
            print(f"[{eval_id_str}] STDERR subproceso (código 0):", flush=True)
            print(result.stderr, flush=True) # DESCOMENTADO para depuración
        # ----------------------------------------------
            
        # results.txt se guardará por st_simulate en su CWD (sim_exec_workdir)
        results_filepath = os.path.join(sim_exec_workdir, "results.txt") 
        fitness = parse_results_txt_pandas(results_filepath, SREV_COLUMN_NAME_IN_RESULTS_TXT)
        
        # --- Verificar si el fitness parseado es -inf --- 
        if fitness == -np.inf:
             print(f"[{eval_id_str}] INFO: parse_results_txt_pandas devolvió -inf.", flush=True)
        # ----------------------------------------------
        
    except subprocess.CalledProcessError as e_subproc:
        print(f"[{eval_id_str}] ERROR: st_simulate.py falló (código de retorno {e_subproc.returncode}).", flush=True)
        print(f"    Comando: {' '.join(e_subproc.cmd)}", flush=True)
        print(f"    Stderr: {e_subproc.stderr}", flush=True) # Muy importante para errores de OpenModelica
    except subprocess.TimeoutExpired:
        print(f"[{eval_id_str}] ERROR: st_simulate.py excedió el timeout de 400s.", flush=True)
    except Exception as e_runtime:
        print(f"[{eval_id_str}] ERROR: Excepción inesperada ejecutando subprocess o parseando resultados: {repr(e_runtime)}", flush=True)
        traceback.print_exc()
    # finally:
        # Para depurar, es útil NO eliminar los directorios de simulación individuales.
        # if os.path.exists(sim_exec_workdir):
        #     shutil.rmtree(sim_exec_workdir) # Limpiar después de cada evaluación
            
    # print(f"[{eval_id_str}] Fitness obtenido: {fitness:.4f}", flush=True)
    return fitness

# --- Función Principal para un Caso de GA ---
def ejecutar_un_caso_ga_simple(config_del_caso):
    id_caso = config_del_caso['id_caso']
    tam_poblacion = config_del_caso['tam_poblacion']
    num_generaciones = config_del_caso['num_generaciones']
    prob_mutacion = config_del_caso['prob_mutacion']
    prob_cruce = config_del_caso['prob_cruce']
    
    print(f"[Caso {id_caso}] Iniciando AG. Población: {tam_poblacion}, Generaciones: {num_generaciones}", flush=True)

    # Directorio para resultados de este caso (logs, mejor individuo)
    directorio_resultados_caso = os.path.join(GA_RESULTS_BASE_DIR, f"caso_{id_caso}")
    os.makedirs(directorio_resultados_caso, exist_ok=True)
    path_log_generaciones_csv = os.path.join(directorio_resultados_caso, f"log_generaciones_caso_{id_caso}.csv")

    # Inicializar población: lista de listas (individuos), cada individuo es una lista de genes (floats)
    poblacion_actual = [[random.uniform(MIN_VAL, MAX_VAL) for _ in range(NUM_PARAMS_VECTOR)] for _ in range(tam_poblacion)]
    
    mejor_fitness_historico_caso = -np.inf
    mejor_individuo_historico_caso = [0.0] * NUM_PARAMS_VECTOR # Inicializar con algo

    with open(path_log_generaciones_csv, 'w', newline='') as f_csv_log:
        escritor_csv = csv.writer(f_csv_log)
        encabezado_csv = ["Generacion", "Individuo_ID", "Fitness"] + [f"gen_{i}" for i in range(NUM_PARAMS_VECTOR)]
        escritor_csv.writerow(encabezado_csv)

        for gen_idx in range(num_generaciones):
            tiempo_inicio_gen = time.time()
            fitness_de_poblacion_actual = []
            
            # --- Evaluación (Secuencial dentro de un caso) ---
            for indiv_idx, individuo_actual in enumerate(poblacion_actual):
                # ID único para esta evaluación (para nombre de directorio y logs)
                id_evaluacion = f"c{id_caso}_g{gen_idx}_i{indiv_idx}_p{os.getpid()}"
                # Nombre del archivo .motab para esta evaluación (local al directorio de la simulación)
                nombre_motab_local = f"dispatch_{id_evaluacion}.motab"
                
                fitness_indiv = evaluar_fitness_individual(
                    individuo_actual,
                    id_evaluacion, 
                    SIM_BASE_WORKDIR,             # Directorio base donde se crearán subdirectorios para cada simulación
                    BASE_INIT_XML_PATH,           # Ruta al XML de inicialización base que se copiará y modificará
                    ST_SIMULATE_SCRIPT_PATH,      # Ruta al script st_simulate.py
                    nombre_motab_local            # Nombre que tendrá el .motab dentro del subdir de simulación
                )
                fitness_de_poblacion_actual.append(fitness_indiv)
                
                # Registrar en CSV
                fila_log = [gen_idx, indiv_idx, f"{fitness_indiv:.4f}"] + [f"{g:.4f}" for g in individuo_actual]
                escritor_csv.writerow(fila_log)
                f_csv_log.flush() # Escribir al disco después de cada individuo

                if fitness_indiv > mejor_fitness_historico_caso:
                    mejor_fitness_historico_caso = fitness_indiv
                    mejor_individuo_historico_caso = list(individuo_actual) # Guardar una copia
            
            fitness_validos = [f for f in fitness_de_poblacion_actual if f > -np.inf]
            avg_fitness_gen = np.mean(fitness_validos) if fitness_validos else -np.inf
            max_fitness_gen = np.max(fitness_validos) if fitness_validos else -np.inf
            
            tiempo_fin_gen = time.time()
            print(f"[Caso {id_caso}, Gen {gen_idx+1}/{num_generaciones}] Fitness Max: {max_fitness_gen:.4f}, Avg: {avg_fitness_gen:.4f}. Tiempo: {tiempo_fin_gen - tiempo_inicio_gen:.2f}s", flush=True)

            # --- Selección, Cruce y Mutación (Operadores Genéticos Simples) ---
            if not fitness_validos: # Si todos los individuos fallaron
                print(f"[Caso {id_caso}, Gen {gen_idx+1}] Todos los fitness son -np.inf. Reiniciando una parte de la población.", flush=True)
                num_a_reiniciar = tam_poblacion // 2
                for k in range(num_a_reiniciar):
                    poblacion_actual[k] = [random.uniform(MIN_VAL, MAX_VAL) for _ in range(NUM_PARAMS_VECTOR)]
                if not poblacion_actual: # salvaguarda
                    poblacion_actual = [[random.uniform(MIN_VAL, MAX_VAL) for _ in range(NUM_PARAMS_VECTOR)] for _ in range(tam_poblacion)]
                continue # Saltar operadores genéticos si todo falló

            indices_ordenados_por_fitness = np.argsort(fitness_de_poblacion_actual)[::-1] # Mayor a menor
            
            poblacion_siguiente_generacion = []
            
            # Elitismo: los N mejores individuos pasan directamente
            num_elites = max(1, tam_poblacion // 10) # ej. 10% de élite, mínimo 1
            for k in range(num_elites):
                poblacion_siguiente_generacion.append(list(poblacion_actual[indices_ordenados_por_fitness[k]]))

            # Cruce y Mutación para el resto
            while len(poblacion_siguiente_generacion) < tam_poblacion:
                # Selección por Torneo (k=3)
                idx_padre1 = random.choice(indices_ordenados_por_fitness[:tam_poblacion//2]) # Elegir de la mitad superior
                idx_padre2 = random.choice(indices_ordenados_por_fitness[:tam_poblacion//2])
                # Asegurar que no sean el mismo para cruce simple
                # (para torneo más formal, se haría un subconjunto y se elegiría el mejor de ese subconjunto)

                padre1 = poblacion_actual[idx_padre1]
                padre2 = poblacion_actual[idx_padre2]
                
                hijo1, hijo2 = list(padre1), list(padre2) # Por defecto, copia de padres

                if random.random() < prob_cruce:
                    # Cruce de un punto simple
                    if NUM_PARAMS_VECTOR > 1:
                        punto_cruce = random.randint(1, NUM_PARAMS_VECTOR - 1)
                        hijo1 = padre1[:punto_cruce] + padre2[punto_cruce:]
                        hijo2 = padre2[:punto_cruce] + padre1[punto_cruce:]
                
                # Mutación para los hijos
                for j in range(NUM_PARAMS_VECTOR):
                    if random.random() < prob_mutacion:
                        hijo1[j] = random.uniform(MIN_VAL, MAX_VAL)
                    if random.random() < prob_mutacion:
                        hijo2[j] = random.uniform(MIN_VAL, MAX_VAL)
                
                poblacion_siguiente_generacion.append(hijo1)
                if len(poblacion_siguiente_generacion) < tam_poblacion:
                    poblacion_siguiente_generacion.append(hijo2)
            
            poblacion_actual = poblacion_siguiente_generacion[:tam_poblacion] # Asegurar tamaño correcto

    print(f"[Caso {id_caso}] AG Finalizado. Mejor fitness global del caso: {mejor_fitness_historico_caso:.4f}", flush=True)
    
    # Guardar el mejor individuo del caso
    path_mejor_individuo_final_caso = os.path.join(directorio_resultados_caso, f"mejor_individuo_caso_{id_caso}.csv")
    df_mejor_ind = pd.DataFrame([mejor_individuo_historico_caso], columns=[f"gen_{k}" for k in range(NUM_PARAMS_VECTOR)])
    df_mejor_ind.to_csv(path_mejor_individuo_final_caso, index=False)
    print(f"[Caso {id_caso}] Mejor individuo del caso guardado en: {path_mejor_individuo_final_caso}", flush=True)

    return id_caso, mejor_fitness_historico_caso, mejor_individuo_historico_caso


# --- Función Principal de Ejecución ---
if __name__ == "__main__":
    tiempo_inicio_script = time.time()

    # Crear directorios base si no existen
    if os.path.exists(SIM_BASE_WORKDIR): # Limpiar directorio de simulaciones previas
        print(f"ADVERTENCIA: El directorio de simulación {SIM_BASE_WORKDIR} ya existe. Se recomienda limpiarlo antes de una nueva ejecución completa.", flush=True)
        # shutil.rmtree(SIM_BASE_WORKDIR) # DESCOMENTAR CON MUCHO CUIDADO para limpiar
        # os.makedirs(SIM_BASE_WORKDIR)
    else:
        os.makedirs(SIM_BASE_WORKDIR, exist_ok=True)
    
    os.makedirs(GA_RESULTS_BASE_DIR, exist_ok=True)
    
    print(f"Directorio de trabajo para simulaciones: {SIM_BASE_WORKDIR}", flush=True)
    print(f"Directorio de resultados del GA: {GA_RESULTS_BASE_DIR}", flush=True)
    print(f"Usando Python: {sys.executable}", flush=True)
    print(f"Ruta base del proyecto (WORKSPACE_DIR): {WORKSPACE_DIR}", flush=True)
    print(f"Ruta al .mo: {MODEL_MO_PATH}", flush=True)
    print(f"Ruta al XML base: {BASE_INIT_XML_PATH}", flush=True)
    print(f"Ruta a st_simulate.py: {ST_SIMULATE_SCRIPT_PATH}", flush=True)


    num_total_casos = len(casos_experimentales)
    # Decidir si paralelizar los casos. No paralelizar si solo hay 1 caso o si se prefiere secuencial.
    # Limitar el número de procesos para no sobrecargar si st_simulate es pesado.
    procesos_para_pool_de_casos = min(num_total_casos, os.cpu_count(), 2) # EJ: Max 2-4 procesos para los casos
    
    if num_total_casos <= 1 or procesos_para_pool_de_casos <=1:
        print(f"Ejecutando {num_total_casos} caso(s) experimental(es) secuencialmente...", flush=True)
        resultados_de_todos_los_casos = [ejecutar_un_caso_ga_simple(cfg) for cfg in casos_experimentales]
    else:
        print(f"Ejecutando {num_total_casos} caso(s) experimental(es) en paralelo usando {procesos_para_pool_de_casos} procesos...", flush=True)
        pool = None
        try:
            # El contexto with multiprocessing.Pool(...) maneja pool.close() y pool.join()
            with multiprocessing.Pool(processes=procesos_para_pool_de_casos) as pool:
                # pool.map pasa cada elemento de casos_experimentales como un solo argumento a la función.
                resultados_de_todos_los_casos = pool.map(ejecutar_un_caso_ga_simple, casos_experimentales)
        except Exception as e_pool_err:
            print(f"ERROR principal durante la ejecución del Pool de casos: {repr(e_pool_err)}", flush=True)
            traceback.print_exc()
            resultados_de_todos_los_casos = [] # Asegurar que es una lista vacía en caso de error del pool


    print("\n--- RESUMEN FINAL DE TODOS LOS CASOS EXPERIMENTALES ---", flush=True)
    if resultados_de_todos_los_casos:
        for res_caso in resultados_de_todos_los_casos:
            if res_caso: # Puede ser None si un proceso del pool falló catastróficamente
                id_c, fitness_c, _ = res_caso # No necesitamos el individuo aquí para el resumen
                print(f"  Caso {id_c}: Mejor Fitness = {fitness_c:.4f}", flush=True)
            else:
                print("  Un caso experimental no devolvió resultados (posible error en proceso hijo).", flush=True)
        
        # Guardar un resumen CSV global
        df_resumen = pd.DataFrame(
            [r for r in resultados_de_todos_los_casos if r], # Filtrar Nones
            columns=["ID_Caso", "Mejor_Fitness_Final", "Mejor_Individuo_Genes_Final"]
        )
        path_resumen_csv_global = os.path.join(GA_RESULTS_BASE_DIR, "resumen_ejecucion_global.csv")
        df_resumen.to_csv(path_resumen_csv_global, index=False)
        print(f"Resumen global de la ejecución guardado en: {path_resumen_csv_global}", flush=True)
    else:
        print("No se obtuvieron resultados finales de los casos experimentales.", flush=True)

    tiempo_fin_script = time.time()
    print(f"\nDuración total del script: {(tiempo_fin_script - tiempo_inicio_script) / 60:.2f} minutos.", flush=True)
    print(f"Todos los directorios de simulación individual (si no se borraron) están en: {SIM_BASE_WORKDIR}", flush=True)
    print(f"Todos los resultados y logs de cada caso del GA están en subdirectorios de: {GA_RESULTS_BASE_DIR}", flush=True)
