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

# --- Configuración General AG (basado en el texto proporcionado) ---
NUM_PARAMS_VECTOR = 24  # Horas en el vector de despacho (24 genes)
# Dominio discreto para los genes: {0.1, 0.2, ..., 1.0}
GENE_POSSIBLE_VALUES = [round(0.1 * i, 1) for i in range(1, 11)] # [0.1, 0.2, ..., 1.0]

PROB_CRUCE_GLOBAL = 1.0       # pc = 1 (cruce de un punto)
PROB_MUTACION_INDIVIDUO = 0.20 # pm = 0.20 (tasa por individuo)
TORNEO_K = 3                  # Tamaño del torneo para selección
MAX_PARALEL_EVALS_PER_GENERATION = 2 # Nuevo: Máximo de evaluaciones de individuos en paralelo por generación

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

# --- Casos Experimentales (según tabla proporcionada por el usuario) ---
# prob_mutacion y prob_cruce ahora son globales.
casos_experimentales = [
    {"id_caso": "C1", "tam_poblacion": 10, "num_generaciones": 100},
    {"id_caso": "C2", "tam_poblacion": 10, "num_generaciones": 200},
    {"id_caso": "C3", "tam_poblacion": 10, "num_generaciones": 300},
    {"id_caso": "C4", "tam_poblacion": 30, "num_generaciones": 100},
    {"id_caso": "C5", "tam_poblacion": 30, "num_generaciones": 200},
    {"id_caso": "C6", "tam_poblacion": 30, "num_generaciones": 300},
]

# --- Funciones Auxiliares ---
def create_dispatch_vector(individuo_normalizado):
    # Asume que el individuo tiene valores normalizados [0,1]
    # Con el nuevo dominio discreto, los valores ya están en el rango deseado {0.1, ..., 1.0}
    # No se necesita desnormalización aquí si el modelo los interpreta directamente.
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
def evaluar_fitness_individual(individuo, id_caso_param, gen_idx_param, indiv_idx_param, base_sim_workdir_param, st_sim_script_path_param, model_mo_path_param):
    pid = os.getpid()
    # ID único para esta evaluación (para nombre de directorio y logs), incluyendo PID del worker
    eval_id_str = f"c{id_caso_param}_g{gen_idx_param}_i{indiv_idx_param}_p{pid}"
    # Nombre del archivo .motab para esta evaluación (local al directorio de la simulación)
    local_motab_filename_for_eval = f"dispatch_{eval_id_str}.motab"
    
    # Directorio de simulación para esta evaluación específica (donde se ejecutará st_simulate y se guardará .motab y results.txt)
    sim_exec_workdir = os.path.join(base_sim_workdir_param, eval_id_str)
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
        st_sim_script_path_param, # Usar el path del script pasado como parámetro
        model_mo_path_param,      # Usar el path del modelo .mo pasado como parámetro
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
    finally:
        # Para ejecuciones largas, es ESENCIAL limpiar para no agotar el disco.
        if os.path.exists(sim_exec_workdir):
            try:
                shutil.rmtree(sim_exec_workdir) # Limpiar después de cada evaluación
                # Para depuración, se podría querer no imprimir esto cada vez:
                # print(f"[{eval_id_str}] INFO: Directorio de simulación {sim_exec_workdir} eliminado.", flush=True)
            except Exception as e_clean:
                # Si la eliminación falla, es una advertencia pero no debería detener todo el AG.
                print(f"[{eval_id_str}] ADVERTENCIA: No se pudo eliminar el directorio de simulación {sim_exec_workdir}: {repr(e_clean)}", flush=True)
            
    # print(f"[{eval_id_str}] Fitness obtenido: {fitness:.4f}", flush=True)
    return fitness

# --- Operadores Genéticos --- 

def seleccion_por_torneo(poblacion, fitness_poblacion, k_torneo):
    """Selecciona un individuo de la población usando selección por torneo."""
    num_individuos = len(poblacion)
    if num_individuos == 0:
        return None # O lanzar un error
    
    # Elegir k competidores al azar (con reemplazo, está bien para torneo)
    indices_competidores = [random.randrange(num_individuos) for _ in range(k_torneo)]
    
    # Encontrar al mejor competidor (el que tiene el índice con mayor fitness)
    mejor_competidor_idx = -1
    mejor_fitness_competidor = -np.inf
    
    for idx in indices_competidores:
        if fitness_poblacion[idx] > mejor_fitness_competidor:
            mejor_fitness_competidor = fitness_poblacion[idx]
            mejor_competidor_idx = idx
            
    # Si todos los competidores tenían -inf, devolver uno al azar de ellos
    if mejor_competidor_idx == -1:
        if indices_competidores: # Asegurarse de que haya competidores
             mejor_competidor_idx = random.choice(indices_competidores)
        else: # No debería ocurrir si la población no está vacía
            return None
            
    return poblacion[mejor_competidor_idx]

# --- Función para cargar estado y reanudar ---
def cargar_estado_para_reanudar(path_log_csv, generacion_a_reanudar, tam_poblacion_esperado, num_params_vector):
    """
    Carga el estado desde un archivo CSV de log para reanudar el AG.
    - Lee el mejor fitness/individuo de las generaciones ANTERIORES a generacion_a_reanudar.
    - Lee la población completa registrada para la generacion_a_reanudar si está disponible.
    Devuelve: (mejor_fitness_previo, mejor_individuo_previo, poblacion_para_reanudar)
    poblacion_para_reanudar estará vacía si no se puede cargar completamente.
    """
    print(f"[Reanudar@{id(path_log_csv)}] Intentando cargar estado desde: {path_log_csv} para reanudar EN generacion {generacion_a_reanudar}", flush=True)
    mejor_fitness_previo = -np.inf
    mejor_individuo_previo = [GENE_POSSIBLE_VALUES[0]] * num_params_vector
    poblacion_para_reanudar = []

    if not os.path.exists(path_log_csv):
        print(f"[Reanudar] Archivo de log no encontrado: {path_log_csv}. No se puede cargar estado.", flush=True)
        return mejor_fitness_previo, mejor_individuo_previo, poblacion_para_reanudar

    try:
        df_log = pd.read_csv(path_log_csv)
        if df_log.empty:
            print(f"[Reanudar] Archivo de log {path_log_csv} está vacío. No se puede cargar estado.", flush=True)
            return mejor_fitness_previo, mejor_individuo_previo, poblacion_para_reanudar

        gene_cols = [f"gen_{i}" for i in range(num_params_vector)]

        # 1. Calcular mejor fitness e individuo de generaciones ANTERIORES a generacion_a_reanudar
        df_generaciones_anteriores = df_log[df_log['Generacion'] < generacion_a_reanudar].copy()
        if not df_generaciones_anteriores.empty:
            df_generaciones_anteriores['Fitness'] = pd.to_numeric(df_generaciones_anteriores['Fitness'], errors='coerce')
            df_generaciones_anteriores.dropna(subset=['Fitness'], inplace=True)

            if not df_generaciones_anteriores.empty:
                idx_mejor_anterior = df_generaciones_anteriores['Fitness'].idxmax()
                mejor_fitness_previo = df_generaciones_anteriores.loc[idx_mejor_anterior, 'Fitness']
                mejor_individuo_previo_series = df_generaciones_anteriores.loc[idx_mejor_anterior, gene_cols]
                mejor_individuo_previo = [float(g) for g in mejor_individuo_previo_series.values]
                print(f"[Reanudar] Mejor fitness histórico (gen < {generacion_a_reanudar}): {mejor_fitness_previo:.4f}", flush=True)
            else:
                print(f"[Reanudar] No hay datos válidos de fitness en generaciones < {generacion_a_reanudar}.", flush=True)
        else:
            print(f"[Reanudar] No hay generaciones < {generacion_a_reanudar} en el log.", flush=True)

        # 2. Cargar la población de la 'generacion_a_reanudar'
        df_gen_reanudacion = df_log[df_log['Generacion'] == generacion_a_reanudar].copy()
        if not df_gen_reanudacion.empty:
            for col in gene_cols: # Asegurar que las columnas de genes son numéricas
                df_gen_reanudacion[col] = pd.to_numeric(df_gen_reanudacion[col], errors='coerce')
            df_gen_reanudacion.dropna(subset=gene_cols, inplace=True) # Eliminar filas donde los genes no son válidos

            # Tomar las últimas entradas para cada Individuo_ID para evitar duplicados si el log es inconsistente
            df_gen_reanudacion_unicos = df_gen_reanudacion.drop_duplicates(subset=['Individuo_ID'], keep='last')
            df_gen_reanudacion_unicos = df_gen_reanudacion_unicos.sort_values(by="Individuo_ID")

            # Verificar si tenemos la población completa para la generación de reanudación
            if len(df_gen_reanudacion_unicos) >= tam_poblacion_esperado:
                # Tomar solo los individuos necesarios para formar la población
                df_poblacion_target = df_gen_reanudacion_unicos[df_gen_reanudacion_unicos['Individuo_ID'] < tam_poblacion_esperado]
                
                if len(df_poblacion_target) == tam_poblacion_esperado:
                    for _, row in df_poblacion_target.iterrows():
                        individuo = [float(row[col]) for col in gene_cols]
                        poblacion_para_reanudar.append(individuo)
                    print(f"[Reanudar] Población para gen {generacion_a_reanudar} cargada con {len(poblacion_para_reanudar)} individuos.", flush=True)
                else:
                    print(f"[Reanudar] No se encontraron exactamente {tam_poblacion_esperado} individuos para la gen {generacion_a_reanudar} (encontrados {len(df_poblacion_target)} después de filtrar IDs). No se carga población.", flush=True)
            else:
                print(f"[Reanudar] No hay suficientes individuos únicos ({len(df_gen_reanudacion_unicos)}) en el log para gen {generacion_a_reanudar} para formar población de {tam_poblacion_esperado}. No se carga población.", flush=True)
        else:
            print(f"[Reanudar] No hay datos en el log para la gen {generacion_a_reanudar}. No se carga población.", flush=True)

    except Exception as e:
        print(f"[Reanudar] ERROR cargando estado desde {path_log_csv}: {repr(e)}", flush=True)
        traceback.print_exc()
        # Devolver valores por defecto, la población estará vacía
        return -np.inf, [GENE_POSSIBLE_VALUES[0]] * num_params_vector, []

    return mejor_fitness_previo, mejor_individuo_previo, poblacion_para_reanudar


# --- Función Principal para un Caso de GA ---
def ejecutar_un_caso_ga_simple(config_del_caso):
    id_caso = config_del_caso['id_caso']
    tam_poblacion = config_del_caso['tam_poblacion']
    num_generaciones_totales = config_del_caso['num_generaciones'] # Renombrado para claridad
    
    # Parámetros de reanudación
    generacion_de_reanudacion = config_del_caso.get('reanudar_desde_generacion', 0)

    print(f"[Caso {id_caso}] Iniciando AG. Población: {tam_poblacion}, Generaciones Totales: {num_generaciones_totales}", flush=True)
    if generacion_de_reanudacion > 0:
        print(f"[Caso {id_caso}] REANUDANDO desde el inicio de la generación {generacion_de_reanudacion}", flush=True)

    directorio_resultados_caso = os.path.join(GA_RESULTS_BASE_DIR, f"caso_{id_caso}")
    os.makedirs(directorio_resultados_caso, exist_ok=True)
    path_log_generaciones_csv = os.path.join(directorio_resultados_caso, f"log_generaciones_caso_{id_caso}.csv")

    # Inicialización por defecto (si no se reanuda o la reanudación falla en cargar población)
    poblacion_actual = [[random.choice(GENE_POSSIBLE_VALUES) for _ in range(NUM_PARAMS_VECTOR)] for _ in range(tam_poblacion)]
    mejor_fitness_historico_caso = -np.inf
    mejor_individuo_historico_caso = [GENE_POSSIBLE_VALUES[0]] * NUM_PARAMS_VECTOR
    
    generacion_inicial_loop = 0
    modo_apertura_log = 'w'
    escribir_encabezado_csv = True

    if generacion_de_reanudacion > 0:
        modo_apertura_log = 'a'
        escribir_encabezado_csv = False # El encabezado ya debería existir
        generacion_inicial_loop = generacion_de_reanudacion
        
        # Intentar cargar estado
        m_fit_prev, m_ind_prev, pob_reanudar = cargar_estado_para_reanudar(
            path_log_generaciones_csv,
            generacion_de_reanudacion, # La generación *en la que* queremos empezar
            tam_poblacion,
            NUM_PARAMS_VECTOR
        )
        
        mejor_fitness_historico_caso = m_fit_prev
        mejor_individuo_historico_caso = list(m_ind_prev) # Asegurar copia

        if pob_reanudar and len(pob_reanudar) == tam_poblacion: # Cambio aquí
            poblacion_actual = pob_reanudar
            print(f"[Caso {id_caso}] Población para generación {generacion_de_reanudacion} cargada exitosamente para reanudación.", flush=True)
        else:
            print(f"[Caso {id_caso}] ADVERTENCIA: No se pudo cargar la población para reanudar en gen {generacion_de_reanudacion} o el tamaño no coincide. Se usará una población aleatoria para esta generación.", flush=True)
            # La población_actual ya está inicializada aleatoriamente por defecto.
            # Si estamos en generacion_de_reanudacion > 0, y la población no se cargó,
            # significa que el log de esa generación está incompleto o ausente para la población.
            # Seguiremos con la población aleatoria, pero el mejor_fitness/individuo histórico sí se usa.

    # Determinar el número de procesos para las evaluaciones de individuos dentro de este caso
    cpus_disponibles = os.cpu_count() if os.cpu_count() else 1
    num_procesos_para_evaluaciones = min(MAX_PARALEL_EVALS_PER_GENERATION, tam_poblacion, cpus_disponibles)
    num_procesos_para_evaluaciones = max(1, num_procesos_para_evaluaciones)

    if num_procesos_para_evaluaciones > 1 and tam_poblacion > 0 :
        print(f"[Caso {id_caso}] Evaluaciones de individuos en paralelo: {num_procesos_para_evaluaciones} procesos.", flush=True)
    else:
        print(f"[Caso {id_caso}] Evaluaciones de individuos secuenciales.", flush=True)

    with open(path_log_generaciones_csv, mode=modo_apertura_log, newline='') as f_csv_log:
        escritor_csv = csv.writer(f_csv_log)
        if escribir_encabezado_csv:
            encabezado_csv = ["Generacion", "Individuo_ID", "Fitness"] + [f"gen_{i}" for i in range(NUM_PARAMS_VECTOR)]
            escritor_csv.writerow(encabezado_csv)
            f_csv_log.flush()


        for gen_idx in range(generacion_inicial_loop, num_generaciones_totales):
            tiempo_inicio_gen = time.time()
            
            print(f"[Caso {id_caso}, Gen {gen_idx+1}/{num_generaciones_totales}] Iniciando evaluación de {tam_poblacion} individuos...", flush=True)
            if gen_idx == generacion_de_reanudacion and generacion_de_reanudacion > 0 :
                 print(f"[Caso {id_caso}, Gen {gen_idx+1}] Esta es la generación de reanudación. Se evaluará toda la población cargada/nueva.", flush=True)

            # --- Preparar tareas para evaluación ---
            tareas_evaluacion = []
            for indiv_idx, individuo_actual in enumerate(poblacion_actual):
                tareas_evaluacion.append(
                    (individuo_actual, 
                     id_caso, 
                     gen_idx, # Usar el gen_idx actual del bucle
                     indiv_idx, 
                     SIM_BASE_WORKDIR, 
                     ST_SIMULATE_SCRIPT_PATH,
                     MODEL_MO_PATH)
                )
            
            fitness_de_poblacion_actual = []
            # --- Evaluación (Paralela o Secuencial dentro del caso) ---
            if num_procesos_para_evaluaciones > 1 and tam_poblacion > 0:
                pool_eval = None 
                try:
                    with multiprocessing.Pool(processes=num_procesos_para_evaluaciones) as pool_eval:
                        fitness_de_poblacion_actual = pool_eval.starmap(evaluar_fitness_individual, tareas_evaluacion)
                except Exception as e_pool_eval:
                    print(f"[Caso {id_caso}, Gen {gen_idx+1}] ERROR en Pool de evaluación: {repr(e_pool_eval)}", flush=True)
                    traceback.print_exc()
                    fitness_de_poblacion_actual = [-np.inf] * tam_poblacion
            else: 
                for tarea_args in tareas_evaluacion:
                    try:
                        fitness_de_poblacion_actual.append(evaluar_fitness_individual(*tarea_args))
                    except Exception as e_seq_eval:
                        print(f"[Caso {id_caso}, Gen {gen_idx+1}, Indiv {tarea_args[3]}] ERROR en evaluación secuencial: {repr(e_seq_eval)}", flush=True)
                        traceback.print_exc()
                        fitness_de_poblacion_actual.append(-np.inf)

            # --- Procesamiento después de la evaluación de toda la generación ---
            for indiv_idx, individuo_actual in enumerate(poblacion_actual):
                fitness_indiv = fitness_de_poblacion_actual[indiv_idx] if indiv_idx < len(fitness_de_poblacion_actual) else -np.inf
                
                fila_log = [gen_idx, indiv_idx, f"{fitness_indiv:.4f}"] + [f"{g:.4f}" for g in individuo_actual]
                escritor_csv.writerow(fila_log)
                f_csv_log.flush()

                if fitness_indiv > mejor_fitness_historico_caso:
                    mejor_fitness_historico_caso = fitness_indiv
                    mejor_individuo_historico_caso = list(individuo_actual) 
            
            fitness_validos = [f for f in fitness_de_poblacion_actual if f > -np.inf]
            avg_fitness_gen = np.mean(fitness_validos) if fitness_validos else -np.inf
            max_fitness_gen = np.max(fitness_validos) if fitness_validos else -np.inf
            
            tiempo_fin_gen = time.time()
            print(f"[Caso {id_caso}, Gen {gen_idx+1}/{num_generaciones_totales}] Fitness Max: {max_fitness_gen:.4f}, Avg: {avg_fitness_gen:.4f}. Tiempo: {tiempo_fin_gen - tiempo_inicio_gen:.2f}s", flush=True)

            # --- Selección, Cruce y Mutación ---
            if not fitness_validos: 
                print(f"[Caso {id_caso}, Gen {gen_idx+1}] Todos los fitness son -np.inf. Reiniciando parte de la población.", flush=True)
                num_a_reiniciar = tam_poblacion // 2 if tam_poblacion > 0 else 0
                for k_idx in range(num_a_reiniciar):
                    poblacion_actual[k_idx] = [random.choice(GENE_POSSIBLE_VALUES) for _ in range(NUM_PARAMS_VECTOR)]
                if not poblacion_actual and tam_poblacion > 0: 
                    poblacion_actual = [[random.choice(GENE_POSSIBLE_VALUES) for _ in range(NUM_PARAMS_VECTOR)] for _ in range(tam_poblacion)]
                continue 

            indices_ordenados_por_fitness = np.argsort(fitness_de_poblacion_actual)[::-1] 
            
            poblacion_siguiente_generacion = []
            
            num_elites = max(1, tam_poblacion // 10) if tam_poblacion > 0 else 0
            for k_elite in range(num_elites):
                if k_elite < len(indices_ordenados_por_fitness): # Asegurar que no nos pasamos de índice
                    idx_elite = indices_ordenados_por_fitness[k_elite]
                    poblacion_siguiente_generacion.append(list(poblacion_actual[idx_elite]))

            while len(poblacion_siguiente_generacion) < tam_poblacion:
                padre1_obj = seleccion_por_torneo(poblacion_actual, fitness_de_poblacion_actual, TORNEO_K)
                padre2_obj = seleccion_por_torneo(poblacion_actual, fitness_de_poblacion_actual, TORNEO_K)
                
                if padre1_obj is None or padre2_obj is None:
                    print(f"[Caso {id_caso}, Gen {gen_idx+1}] ERROR: Selección por torneo devolvió None. Usando aleatorios para completar.", flush=True)
                    # Rellenar con aleatorios si la selección falla críticamente
                    padre1 = [random.choice(GENE_POSSIBLE_VALUES) for _ in range(NUM_PARAMS_VECTOR)]
                    padre2 = [random.choice(GENE_POSSIBLE_VALUES) for _ in range(NUM_PARAMS_VECTOR)]
                else:
                    padre1 = list(padre1_obj) 
                    padre2 = list(padre2_obj)
                
                hijo1, hijo2 = list(padre1), list(padre2) 

                if random.random() < PROB_CRUCE_GLOBAL: 
                    if NUM_PARAMS_VECTOR > 1:
                        punto_cruce = random.randint(1, NUM_PARAMS_VECTOR - 1)
                        hijo1 = padre1[:punto_cruce] + padre2[punto_cruce:]
                        hijo2 = padre2[:punto_cruce] + padre1[punto_cruce:]
                
                if random.random() < PROB_MUTACION_INDIVIDUO:
                    if hijo1: # Asegurar que el hijo no está vacío
                        gen_a_mutar_h1 = random.randrange(NUM_PARAMS_VECTOR)
                        hijo1[gen_a_mutar_h1] = random.choice(GENE_POSSIBLE_VALUES)
                
                if random.random() < PROB_MUTACION_INDIVIDUO:
                    if hijo2: # Asegurar que el hijo no está vacío
                        gen_a_mutar_h2 = random.randrange(NUM_PARAMS_VECTOR)
                        hijo2[gen_a_mutar_h2] = random.choice(GENE_POSSIBLE_VALUES)
                
                if hijo1: poblacion_siguiente_generacion.append(hijo1)
                if len(poblacion_siguiente_generacion) < tam_poblacion and hijo2:
                    poblacion_siguiente_generacion.append(hijo2)
            
            poblacion_actual = poblacion_siguiente_generacion[:tam_poblacion] 

    print(f"[Caso {id_caso}] AG Finalizado. Mejor fitness global del caso: {mejor_fitness_historico_caso:.4f}", flush=True)
    
    path_mejor_individuo_final_caso = os.path.join(directorio_resultados_caso, f"mejor_individuo_caso_{id_caso}.csv")
    df_mejor_ind = pd.DataFrame([mejor_individuo_historico_caso], columns=[f"gen_{k}" for k in range(NUM_PARAMS_VECTOR)])
    df_mejor_ind.to_csv(path_mejor_individuo_final_caso, index=False)
    print(f"[Caso {id_caso}] Mejor individuo del caso guardado en: {path_mejor_individuo_final_caso}", flush=True)

    return id_caso, mejor_fitness_historico_caso, mejor_individuo_historico_caso


# --- Función Principal de Ejecución ---
if __name__ == "__main__":
    tiempo_inicio_script = time.time()

    if os.path.exists(SIM_BASE_WORKDIR): 
        print(f"ADVERTENCIA: El directorio de simulación {SIM_BASE_WORKDIR} ya existe. Se recomienda limpiarlo antes de una nueva ejecución completa.", flush=True)
    else:
        os.makedirs(SIM_BASE_WORKDIR, exist_ok=True)
    
    os.makedirs(GA_RESULTS_BASE_DIR, exist_ok=True)
    
    print(f"Directorio de trabajo para simulaciones: {SIM_BASE_WORKDIR}", flush=True)
    print(f"Directorio de resultados del GA: {GA_RESULTS_BASE_DIR}", flush=True)
    print(f"Usando Python: {sys.executable}", flush=True)
    print(f"Ruta base del proyecto (WORKSPACE_DIR): {WORKSPACE_DIR}", flush=True)
    print(f"Ruta al .mo: {MODEL_MO_PATH}", flush=True)
    print(f"Ruta al XML base: {BASE_INIT_XML_PATH}", flush=True) # Sigue siendo relevante para st_simulate.py aunque no se modifique aquí
    print(f"Ruta a st_simulate.py: {ST_SIMULATE_SCRIPT_PATH}", flush=True)

    # --- Configuración de Reanudación ---
    CASO_A_REANUDAR = "C2"
    GENERACION_DE_REANUDACION_SCRIPT = 147 # El script reanudará AL INICIO de esta generación (gen_idx = 147)
    # ----------------------------------

    MAX_PROCESOS_POR_LOTE = 1 
    TAMANO_LOTE_DE_CASOS = 1  
    num_total_casos = len(casos_experimentales)
    resultados_de_todos_los_casos = []

    print(f"Configuración: Máximo {MAX_PROCESOS_POR_LOTE} procesos por lote, tamaño de lote de casos: {TAMANO_LOTE_DE_CASOS}.", flush=True)

    indice_de_partida_script = 0
    config_reanudar_aplicada_a_lista = False

    casos_configurados_para_ejecutar = []
    for idx, caso_original_cfg in enumerate(casos_experimentales):
        cfg_actual = dict(caso_original_cfg)
        if CASO_A_REANUDAR and caso_original_cfg['id_caso'] == CASO_A_REANUDAR and not config_reanudar_aplicada_a_lista:
            print(f"  INFO: Configurando caso '{cfg_actual['id_caso']}' para reanudar desde el inicio de la generación {GENERACION_DE_REANUDACION_SCRIPT}.")
            cfg_actual['reanudar_desde_generacion'] = GENERACION_DE_REANUDACION_SCRIPT
            indice_de_partida_script = idx # El script comenzará a procesar lotes desde este índice de caso
            config_reanudar_aplicada_a_lista = True 
        casos_configurados_para_ejecutar.append(cfg_actual)

    if CASO_A_REANUDAR and not config_reanudar_aplicada_a_lista:
        print(f"  ADVERTENCIA: CASO_A_REANUDAR ('{CASO_A_REANUDAR}') no fue encontrado en la lista 'casos_experimentales'. Se ejecutarán todos los casos desde el principio o según el índice de partida por defecto (0).")
        indice_de_partida_script = 0 # Fallback si el caso a reanudar no se encuentra
    elif CASO_A_REANUDAR:
        print(f"  INFO: La ejecución de casos comenzará desde el índice {indice_de_partida_script} (caso '{casos_configurados_para_ejecutar[indice_de_partida_script]['id_caso']}').")
    else:
        print("  INFO: No se ha especificado CASO_A_REANUDAR. Se ejecutarán todos los casos desde el principio.")


    for i in range(indice_de_partida_script, num_total_casos, TAMANO_LOTE_DE_CASOS):
        lote_casos_actual_configs = casos_configurados_para_ejecutar[i:i + TAMANO_LOTE_DE_CASOS]
        num_casos_en_lote = len(lote_casos_actual_configs)
        
        if num_casos_en_lote == 0:
            continue

        print(f"\nProcesando lote {(i // TAMANO_LOTE_DE_CASOS) + 1 - (indice_de_partida_script // TAMANO_LOTE_DE_CASOS)} (casos {i + 1} a {i + num_casos_en_lote} de la lista original)...", flush=True)

        cpus_disponibles = os.cpu_count() if os.cpu_count() else 1
        procesos_para_este_lote = min(num_casos_en_lote, MAX_PROCESOS_POR_LOTE, cpus_disponibles)
        procesos_para_este_lote = max(1, procesos_para_este_lote) 

        # La configuración de reanudación ya está en cfg_ejecutar si aplica.
        # No se necesita el FLAG_REANUDACION_APLICADA anterior aquí.

        if num_casos_en_lote <= 1 or procesos_para_este_lote <= 1:
            print(f"  Ejecutando {num_casos_en_lote} caso(s) de este lote secuencialmente...", flush=True)
            resultados_lote = []
            for cfg_idx_en_lote, cfg_ejecutar in enumerate(lote_casos_actual_configs):
                id_c_actual = cfg_ejecutar.get('id_caso', 'N/A')
                print(f"    Iniciando caso {id_c_actual} ({(cfg_idx_en_lote + 1)}/{num_casos_en_lote} del lote)...", flush=True)
                if cfg_ejecutar.get('reanudar_desde_generacion', 0) > 0:
                    print(f"      Este caso ({id_c_actual}) está configurado para reanudar desde la generación {cfg_ejecutar['reanudar_desde_generacion']}.", flush=True)
                try:
                    resultados_lote.append(ejecutar_un_caso_ga_simple(cfg_ejecutar))
                except Exception as e_caso_sec:
                    print(f"    ERROR ejecutando caso {id_c_actual} secuencialmente: {repr(e_caso_sec)}", flush=True)
                    traceback.print_exc()
                    resultados_lote.append(None) 
        else:
            print(f"  Ejecutando {num_casos_en_lote} caso(s) de este lote en paralelo usando {procesos_para_este_lote} procesos...", flush=True)
            # Es importante que cada config en lote_casos_actual_configs ya tenga su 'reanudar_desde_generacion' si aplica
            pool = None
            try:
                with multiprocessing.Pool(processes=procesos_para_este_lote) as pool:
                    resultados_lote = pool.map(ejecutar_un_caso_ga_simple, lote_casos_actual_configs)
            except Exception as e_pool_err:
                print(f"  ERROR principal durante la ejecución del Pool para el lote actual: {repr(e_pool_err)}", flush=True)
                traceback.print_exc()
                resultados_lote = [None] * num_casos_en_lote 
        
        resultados_de_todos_los_casos.extend(resultados_lote)
        print(f"Lote {(i // TAMANO_LOTE_DE_CASOS) + 1 - (indice_de_partida_script // TAMANO_LOTE_DE_CASOS)} completado.", flush=True)

    print("\n--- RESUMEN FINAL DE TODOS LOS CASOS EXPERIMENTALES PROCESADOS ---", flush=True)
    if resultados_de_todos_los_casos:
        valid_results = [r for r in resultados_de_todos_los_casos if r]
        for res_caso in valid_results:
            id_c, fitness_c, _ = res_caso 
            print(f"  Caso {id_c}: Mejor Fitness = {fitness_c:.4f}", flush=True)
        
        if not valid_results and resultados_de_todos_los_casos: # Si hubo resultados pero todos fueron None
            print("  Todos los casos experimentales fallaron o no devolvieron resultados válidos.", flush=True)
        elif not resultados_de_todos_los_casos: # Si la lista original está vacía
             print("  No se procesaron casos experimentales.", flush=True)

        if valid_results:
            df_resumen = pd.DataFrame(
                valid_results, 
                columns=["ID_Caso", "Mejor_Fitness_Final", "Mejor_Individuo_Genes_Final"]
            )
            path_resumen_csv_global = os.path.join(GA_RESULTS_BASE_DIR, "resumen_ejecucion_global.csv")
            try:
                df_resumen.to_csv(path_resumen_csv_global, index=False)
                print(f"Resumen global de la ejecución guardado en: {path_resumen_csv_global}", flush=True)
            except Exception as e_csv_resumen:
                print(f"ERROR guardando resumen global CSV: {repr(e_csv_resumen)}", flush=True)

    else:
        print("No se obtuvieron resultados finales de los casos experimentales.", flush=True)

    tiempo_fin_script = time.time()
    print(f"\nDuración total del script: {(tiempo_fin_script - tiempo_inicio_script) / 60:.2f} minutos.", flush=True)
    print(f"Todos los directorios de simulación individual (si no se borraron) están en: {SIM_BASE_WORKDIR}", flush=True)
    print(f"Todos los resultados y logs de cada caso del GA están en subdirectorios de: {GA_RESULTS_BASE_DIR}", flush=True)
