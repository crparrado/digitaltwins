import numpy as np
import random
import os
import csv
import time
import sys
import traceback
import pandas as pd
import shutil
import subprocess

# --- Configuración General PSO (idéntica al AG) ---
NUM_PARAMS_VECTOR = 24  # Horas en el vector de despacho (24 genes)
GENE_POSSIBLE_VALUES = [round(0.1 * i, 1) for i in range(1, 11)] # [0.1, 0.2, ..., 1.0]

# --- Casos Experimentales (idénticos al AG) ---
casos_experimentales = [
    {"id_caso": "C1", "tam_poblacion": 10, "num_generaciones": 100},
    {"id_caso": "C2", "tam_poblacion": 10, "num_generaciones": 200},
    {"id_caso": "C3", "tam_poblacion": 10, "num_generaciones": 300},
    {"id_caso": "C4", "tam_poblacion": 30, "num_generaciones": 100},
    {"id_caso": "C5", "tam_poblacion": 30, "num_generaciones": 200},
    {"id_caso": "C6", "tam_poblacion": 30, "num_generaciones": 300},
]

# --- Parámetros de reanudación ---
CASO_A_REANUDAR = "C1"  # Cambia a None para ejecutar todos desde cero
GENERACION_DE_REANUDACION_SCRIPT = 0  # La generación desde la que reanudar (índice de generación)

w = 0.7  # Peso de inercia
c1 = 1.5 # Coeficiente cognitivo
c2 = 1.5 # Coeficiente social

# --- Rutas y modelo ---
try:
    CURRENT_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
    WORKSPACE_DIR = os.path.abspath(os.path.join(CURRENT_SCRIPT_DIR, "..", ".."))
except NameError:
    WORKSPACE_DIR = "/home/cparrado/solartherm"

MODEL_MO_PATH = "/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo"
SIM_BASE_WORKDIR_NAME = "st_pso_sim_workdirs"
SIM_BASE_WORKDIR = os.path.join(WORKSPACE_DIR, SIM_BASE_WORKDIR_NAME)
RESULTS_BASE_DIR_NAME = "pso_dispatch_results"
RESULTS_BASE_DIR = os.path.join(WORKSPACE_DIR, RESULTS_BASE_DIR_NAME)

SREV_COLUMN_NAME_IN_RESULTS_TXT = "srev ($)"

os.makedirs(SIM_BASE_WORKDIR, exist_ok=True)
os.makedirs(RESULTS_BASE_DIR, exist_ok=True)

# --- Funciones Auxiliares ---
def create_dispatch_vector(individuo_normalizado):
    return [(i * 3600, valor) for i, valor in enumerate(individuo_normalizado)]

def write_motab_file(vector_despacho, filepath):
    try:
        with open(filepath, 'w') as file:
            file.write('#1\n')
            file.write(f'double daily1({len(vector_despacho)},2)\n')
            for timestamp, value in vector_despacho:
                file.write(f'{timestamp} {value}\n')
        return True
    except Exception as e:
        print(f"ERROR escribiendo MOTAB {filepath}: {repr(e)}", flush=True)
        return False

def parse_results_txt_pandas(filepath, target_column_name):
    try:
        if not os.path.exists(filepath):
            print(f"ERROR (parse_results): Archivo no encontrado: {filepath}", flush=True)
            return -np.inf
        df = pd.read_csv(filepath, sep=',', comment='#')
        if target_column_name not in df.columns:
            print(f"ERROR (parse_results): Columna '{target_column_name}' no en {filepath}. Columnas: {df.columns.tolist()}", flush=True)
            return -np.inf
        if df.empty:
            print(f"ERROR (parse_results): Archivo {filepath} está vacío o no contiene datos parseables.", flush=True)
            return -np.inf
        srev_value = df[target_column_name].iloc[-1]
        return float(srev_value)
    except Exception as e:
        print(f"ERROR (parse_results): Excepción inesperada parseando {filepath}: {repr(e)}", flush=True)
        traceback.print_exc()
        return -np.inf

def cargar_estado_para_reanudar(path_log_csv, generacion_a_reanudar, tam_poblacion, num_params_vector):
    print(f"[Reanudar@{id(path_log_csv)}] Intentando cargar estado desde: {path_log_csv} para reanudar EN generacion {generacion_a_reanudar}", flush=True)
    poblacion_para_reanudar = []
    pbest_positions = []
    pbest_fitness = []
    gbest_position = None
    gbest_fitness = -np.inf
    if not os.path.exists(path_log_csv):
        print(f"[Reanudar] Archivo de log no encontrado: {path_log_csv}. No se puede cargar estado.", flush=True)
        return poblacion_para_reanudar, pbest_positions, pbest_fitness, gbest_position, gbest_fitness
    try:
        df_log = pd.read_csv(path_log_csv)
        if df_log.empty:
            print(f"[Reanudar] Archivo de log {path_log_csv} está vacío. No se puede cargar estado.", flush=True)
            return poblacion_para_reanudar, pbest_positions, pbest_fitness, gbest_position, gbest_fitness
        gene_cols = [f"gen_{i}" for i in range(num_params_vector)]
        # 1. Cargar la población de la 'generacion_a_reanudar'
        df_gen_reanudacion = df_log[df_log['Generacion'] == generacion_a_reanudar].copy()
        if not df_gen_reanudacion.empty:
            for col in gene_cols:
                df_gen_reanudacion[col] = pd.to_numeric(df_gen_reanudacion[col], errors='coerce')
            df_gen_reanudacion.dropna(subset=gene_cols, inplace=True)
            df_gen_reanudacion_unicos = df_gen_reanudacion.drop_duplicates(subset=['Particle_ID'], keep='last')
            df_gen_reanudacion_unicos = df_gen_reanudacion_unicos.sort_values(by="Particle_ID")
            if len(df_gen_reanudacion_unicos) >= tam_poblacion:
                df_poblacion_target = df_gen_reanudacion_unicos[df_gen_reanudacion_unicos['Particle_ID'] < tam_poblacion]
                if len(df_poblacion_target) == tam_poblacion:
                    for _, row in df_poblacion_target.iterrows():
                        individuo = [float(row[col]) for col in gene_cols]
                        poblacion_para_reanudar.append(individuo)
                else:
                    print(f"[Reanudar] No se encontraron exactamente {tam_poblacion} partículas para la gen {generacion_a_reanudar} (encontradas {len(df_poblacion_target)} después de filtrar IDs). No se carga población.", flush=True)
            else:
                print(f"[Reanudar] No hay suficientes partículas únicas ({len(df_gen_reanudacion_unicos)}) en el log para gen {generacion_a_reanudar} para formar población de {tam_poblacion}. No se carga población.", flush=True)
        else:
            print(f"[Reanudar] No hay datos en el log para la gen {generacion_a_reanudar}. No se carga población.", flush=True)
        # 2. Cargar pbest y pbest_fitness de cada partícula hasta la generación anterior
        pbest_positions = []
        pbest_fitness = []
        for pid in range(tam_poblacion):
            df_hist = df_log[(df_log['Particle_ID'] == pid) & (df_log['Generacion'] < generacion_a_reanudar)].copy()
            if not df_hist.empty:
                df_hist['Fitness'] = pd.to_numeric(df_hist['Fitness'], errors='coerce')
                df_hist.dropna(subset=['Fitness'], inplace=True)
                idx_best = df_hist['Fitness'].idxmax()
                best_fit = df_hist.loc[idx_best, 'Fitness']
                best_pos = [float(df_hist.loc[idx_best, f"gen_{i}"]) for i in range(num_params_vector)]
            else:
                best_fit = -np.inf
                best_pos = [GENE_POSSIBLE_VALUES[0]] * num_params_vector
            pbest_positions.append(best_pos)
            pbest_fitness.append(best_fit)
        # 3. Cargar gbest de todas las generaciones anteriores
        df_hist_all = df_log[df_log['Generacion'] < generacion_a_reanudar].copy()
        if not df_hist_all.empty:
            df_hist_all['Fitness'] = pd.to_numeric(df_hist_all['Fitness'], errors='coerce')
            df_hist_all.dropna(subset=['Fitness'], inplace=True)
            idx_gbest = df_hist_all['Fitness'].idxmax()
            gbest_fitness = df_hist_all.loc[idx_gbest, 'Fitness']
            gbest_position = [float(df_hist_all.loc[idx_gbest, f"gen_{i}"]) for i in range(num_params_vector)]
        else:
            gbest_fitness = -np.inf
            gbest_position = [GENE_POSSIBLE_VALUES[0]] * num_params_vector
    except Exception as e:
        print(f"[Reanudar] ERROR cargando estado desde {path_log_csv}: {repr(e)}", flush=True)
        traceback.print_exc()
        return [], [], [], None, -np.inf
    return poblacion_para_reanudar, pbest_positions, pbest_fitness, gbest_position, gbest_fitness

def evaluar_fitness_individual(individuo, sim_workdir, model_mo_path):
    pid = os.getpid()
    eval_id_str = f"pso_g0_i0_p{pid}_{random.randint(0,99999)}"
    local_motab_filename = f"dispatch_{eval_id_str}.motab"
    sim_exec_workdir = os.path.join(sim_workdir, eval_id_str)
    os.makedirs(sim_exec_workdir, exist_ok=True)
    motab_filepath = os.path.join(sim_exec_workdir, local_motab_filename)
    dispatch_vector = create_dispatch_vector(individuo)
    if not write_motab_file(dispatch_vector, motab_filepath):
        print(f"[{eval_id_str}] ERROR: Falló write_motab_file para {motab_filepath}", flush=True)
        return -np.inf
    cmd_list = [
        sys.executable,
        os.path.join(WORKSPACE_DIR, "tests", "metaheuristics", "st_simulate.py"),
        model_mo_path,
        f"sch_file={local_motab_filename}"
    ]
    fitness = -np.inf
    try:
        result = subprocess.run(cmd_list, cwd=sim_exec_workdir, capture_output=True, text=True, check=True, timeout=400)
        results_filepath = os.path.join(sim_exec_workdir, "results.txt")
        fitness = parse_results_txt_pandas(results_filepath, SREV_COLUMN_NAME_IN_RESULTS_TXT)
    except Exception as e:
        print(f"[{eval_id_str}] ERROR ejecutando simulación: {repr(e)}", flush=True)
        traceback.print_exc()
    finally:
        if os.path.exists(sim_exec_workdir):
            try:
                shutil.rmtree(sim_exec_workdir)
            except Exception as e_clean:
                print(f"[{eval_id_str}] ADVERTENCIA: No se pudo eliminar el directorio de simulación {sim_exec_workdir}: {repr(e_clean)}", flush=True)
    return fitness

# --- Ejecución de los 6 casos experimentales ---
resultados_de_todos_los_casos = []

indice_de_partida_script = 0
config_reanudar_aplicada_a_lista = False
casos_configurados_para_ejecutar = []
for idx, caso_original_cfg in enumerate(casos_experimentales):
    cfg_actual = dict(caso_original_cfg)
    if CASO_A_REANUDAR and caso_original_cfg['id_caso'] == CASO_A_REANUDAR and not config_reanudar_aplicada_a_lista:
        print(f"  INFO: Configurando caso '{cfg_actual['id_caso']}' para reanudar desde el inicio de la generación {GENERACION_DE_REANUDACION_SCRIPT}.")
        cfg_actual['reanudar_desde_generacion'] = GENERACION_DE_REANUDACION_SCRIPT
        indice_de_partida_script = idx
        config_reanudar_aplicada_a_lista = True
    casos_configurados_para_ejecutar.append(cfg_actual)

if CASO_A_REANUDAR and not config_reanudar_aplicada_a_lista:
    print(f"  ADVERTENCIA: CASO_A_REANUDAR ('{CASO_A_REANUDAR}') no fue encontrado en la lista 'casos_experimentales'. Se ejecutarán todos los casos desde el principio o según el índice de partida por defecto (0).")
    indice_de_partida_script = 0
elif CASO_A_REANUDAR:
    print(f"  INFO: La ejecución de casos comenzará desde el índice {indice_de_partida_script} (caso '{casos_configurados_para_ejecutar[indice_de_partida_script]['id_caso']}').")
else:
    print("  INFO: No se ha especificado CASO_A_REANUDAR. Se ejecutarán todos los casos desde el principio.")

for i in range(indice_de_partida_script, len(casos_configurados_para_ejecutar)):
    config_caso = casos_configurados_para_ejecutar[i]
    id_caso = config_caso['id_caso']
    tam_poblacion = config_caso['tam_poblacion']
    num_generaciones = config_caso['num_generaciones']
    generacion_de_reanudacion = config_caso.get('reanudar_desde_generacion', 0)
    print(f"\n[PSO] Iniciando caso {id_caso}: {tam_poblacion} partículas, {num_generaciones} generaciones", flush=True)
    if generacion_de_reanudacion > 0:
        print(f"[PSO][{id_caso}] REANUDANDO desde el inicio de la generación {generacion_de_reanudacion}", flush=True)
    directorio_resultados_caso = os.path.join(RESULTS_BASE_DIR, f"caso_{id_caso}")
    os.makedirs(directorio_resultados_caso, exist_ok=True)
    path_log_generaciones_csv = os.path.join(directorio_resultados_caso, f"log_generaciones_caso_{id_caso}.csv")

    # Inicialización por defecto
    np.random.seed(42)
    random.seed(42)
    positions = np.random.choice(GENE_POSSIBLE_VALUES, size=(tam_poblacion, NUM_PARAMS_VECTOR))
    velocities = np.random.uniform(low=-0.1, high=0.1, size=(tam_poblacion, NUM_PARAMS_VECTOR))
    pbest_positions = positions.copy()
    pbest_fitness = np.array([
        evaluar_fitness_individual(ind, SIM_BASE_WORKDIR, MODEL_MO_PATH) for ind in positions
    ])
    gbest_index = np.argmax(pbest_fitness)
    gbest_position = pbest_positions[gbest_index, :].copy()
    gbest_fitness = pbest_fitness[gbest_index]
    modo_apertura_log = 'w'
    escribir_encabezado_csv = True
    generacion_inicial_loop = 0

    if generacion_de_reanudacion > 0:
        modo_apertura_log = 'a'
        escribir_encabezado_csv = False
        generacion_inicial_loop = generacion_de_reanudacion
        pob_reanudar, pbest_pos, pbest_fit, gbest_pos, gbest_fit = cargar_estado_para_reanudar(
            path_log_generaciones_csv,
            generacion_de_reanudacion,
            tam_poblacion,
            NUM_PARAMS_VECTOR
        )
        if pob_reanudar and len(pob_reanudar) == tam_poblacion:
            positions = np.array(pob_reanudar)
            if pbest_pos and len(pbest_pos) == tam_poblacion:
                pbest_positions = np.array(pbest_pos)
            if pbest_fit and len(pbest_fit) == tam_poblacion:
                pbest_fitness = np.array(pbest_fit)
            if gbest_pos is not None:
                gbest_position = np.array(gbest_pos)
            if gbest_fit is not None:
                gbest_fitness = gbest_fit
            print(f"[PSO][{id_caso}] Población y estado de PSO cargados exitosamente para reanudación.", flush=True)
        else:
            print(f"[PSO][{id_caso}] ADVERTENCIA: No se pudo cargar la población para reanudar en gen {generacion_de_reanudacion} o el tamaño no coincide. Se usará una población aleatoria para esta generación.", flush=True)

    with open(path_log_generaciones_csv, modo_apertura_log, newline="") as f_csv_log:
        escritor_csv = csv.writer(f_csv_log)
        if escribir_encabezado_csv:
            encabezado_csv = ["Generacion", "Particle_ID", "Fitness"] + [f"gen_{i}" for i in range(NUM_PARAMS_VECTOR)]
            escritor_csv.writerow(encabezado_csv)
            f_csv_log.flush()

        for gen_idx in range(generacion_inicial_loop, num_generaciones):
            print(f"[PSO][{id_caso}] Generación {gen_idx+1}/{num_generaciones}", flush=True)
            for i in range(tam_poblacion):
                fitness = evaluar_fitness_individual(positions[i, :], SIM_BASE_WORKDIR, MODEL_MO_PATH)
                if fitness > pbest_fitness[i]:
                    pbest_fitness[i] = fitness
                    pbest_positions[i, :] = positions[i, :].copy()
                if fitness > gbest_fitness:
                    gbest_fitness = fitness
                    gbest_position = positions[i, :].copy()
                fila_log = [gen_idx, i, f"{fitness:.4f}"] + [f"{g:.4f}" for g in positions[i, :]]
                escritor_csv.writerow(fila_log)
                f_csv_log.flush()
            # Actualizar velocidades y posiciones
            for i in range(tam_poblacion):
                r1 = np.random.rand(NUM_PARAMS_VECTOR)
                r2 = np.random.rand(NUM_PARAMS_VECTOR)
                velocities[i, :] = (
                    w * velocities[i, :]
                    + c1 * r1 * (pbest_positions[i, :] - positions[i, :])
                    + c2 * r2 * (gbest_position - positions[i, :])
                )
                positions[i, :] = positions[i, :] + velocities[i, :]
                positions[i, :] = np.clip(positions[i, :], min(GENE_POSSIBLE_VALUES), max(GENE_POSSIBLE_VALUES))
                positions[i, :] = np.array([min(GENE_POSSIBLE_VALUES, key=lambda x: abs(x-v)) for v in positions[i, :]])
            print(f"[PSO][{id_caso}] Mejor fitness global hasta ahora: {gbest_fitness:.4f}", flush=True)

    path_mejor_individuo_final = os.path.join(directorio_resultados_caso, f"mejor_individuo_caso_{id_caso}.csv")
    df_mejor_ind = pd.DataFrame([gbest_position], columns=[f"gen_{k}" for k in range(NUM_PARAMS_VECTOR)])
    df_mejor_ind.to_csv(path_mejor_individuo_final, index=False)
    print(f"[PSO][{id_caso}] Mejor individuo guardado en: {path_mejor_individuo_final}", flush=True)
    print(f"[PSO][{id_caso}] Mejor fitness global: {gbest_fitness:.4f}", flush=True)
    resultados_de_todos_los_casos.append((id_caso, gbest_fitness, list(gbest_position)))

# --- Resumen global ---
if resultados_de_todos_los_casos:
    df_resumen = pd.DataFrame(
        resultados_de_todos_los_casos,
        columns=["ID_Caso", "Mejor_Fitness_Final", "Mejor_Individuo_Genes_Final"]
    )
    path_resumen_csv_global = os.path.join(RESULTS_BASE_DIR, "resumen_ejecucion_global.csv")
    try:
        df_resumen.to_csv(path_resumen_csv_global, index=False)
        print(f"[PSO] Resumen global de la ejecución guardado en: {path_resumen_csv_global}", flush=True)
    except Exception as e_csv_resumen:
        print(f"[PSO] ERROR guardando resumen global CSV: {repr(e_csv_resumen)}", flush=True)
else:
    print("[PSO] No se obtuvieron resultados finales de los casos experimentales.", flush=True) 