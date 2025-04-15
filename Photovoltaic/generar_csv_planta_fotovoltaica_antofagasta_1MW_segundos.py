import numpy as np
import pandas as pd
import os
import math
import matplotlib.pyplot as plt
from datetime import datetime, timedelta

print("===== Generador de CSV para Simulación Anual de Planta Fotovoltaica - Antofagasta 1 MW (Resolución por Segundo) =====")

# Parámetros de la simulación
potencia_pico = 1000  # kW (1 MW)
eficiencia_referencia = 0.20  # 20%
factor_rendimiento = 0.85  # 85% (pérdidas del sistema)

# Calcular el área de paneles necesaria para alcanzar 1 MW
# Asumiendo condiciones estándar (1000 W/m²)
# Potencia = Area * 1000 W/m² * Eficiencia * Factor rendimiento
# Por lo tanto: Area = Potencia / (1000 * Eficiencia * Factor)
area_paneles = potencia_pico / (1 * eficiencia_referencia * factor_rendimiento) * 1.1  # +10% para asegurar alcanzar la potencia pico
print(f"Área de paneles calculada: {area_paneles:.1f} m² (para asegurar {potencia_pico} kW con irradiancia estándar)")

coef_temperatura = -0.004  # %/K

# Cargar datos de Antofagasta
print("Cargando datos climáticos desde antofagasta.csv...")
try:
    # Leer CSV de antofagasta
    datos_antofagasta = pd.read_csv("solartherm/tests/antofagasta.csv", skiprows=2)
    
    # Verificar estructura del CSV
    print(f"Datos cargados: {len(datos_antofagasta)} registros horarios")
    print("Columnas disponibles:", list(datos_antofagasta.columns))
    
    # Extraer información de ubicación
    info_ubicacion = pd.read_csv("solartherm/tests/antofagasta.csv", nrows=1)
    latitud = float(info_ubicacion['Latitude'][0])
    longitud = float(info_ubicacion['Longitude'][0])
    elevacion = float(info_ubicacion['Elevation'][0])
    print(f"Ubicación: Antofagasta, Chile (Lat: {latitud}, Long: {longitud}, Elev: {elevacion}m)")
    
except Exception as e:
    print(f"Error al cargar datos: {e}")
    print("Asegúrate de que el archivo antofagasta.csv está en la carpeta solartherm/tests/")
    exit(1)

print("Procesando datos horarios...")

# Configurar período de simulación
n_horas = len(datos_antofagasta)
print(f"Datos de entrada: {n_horas} horas ({n_horas/24:.0f} días)")

# PASO 1: Crear un DataFrame con los datos horarios (igual que antes)
# Extraer fechas a nivel de hora
dates_hourly = []
for i in range(n_horas):
    year = datos_antofagasta.iloc[i]['Year']
    month = datos_antofagasta.iloc[i]['Month']
    day = datos_antofagasta.iloc[i]['Day']
    hour = datos_antofagasta.iloc[i]['Hour']
    dates_hourly.append(datetime(year=int(year), month=int(month), day=int(day), hour=int(hour)))

# Arrays para los datos horarios
irradiancia_hourly = np.zeros(n_horas)
temperatura_ambiente_hourly = np.zeros(n_horas)
temperatura_panel_hourly = np.zeros(n_horas)
potencia_generada_hourly = np.zeros(n_horas)

# Procesar cada hora con datos reales
for i in range(n_horas):
    # Extraer datos climáticos
    ghi = datos_antofagasta.iloc[i]['GHI']  # W/m²
    dni = datos_antofagasta.iloc[i]['DNI']  # W/m²
    dhi = datos_antofagasta.iloc[i]['DHI']  # W/m²
    temp_ambiente = datos_antofagasta.iloc[i]['Tdry']  # °C
    
    # Almacenar datos horarios
    irradiancia_hourly[i] = ghi
    temperatura_ambiente_hourly[i] = temp_ambiente
    
    # Calcular temperatura del panel
    if irradiancia_hourly[i] > 0:
        temperatura_panel_hourly[i] = temperatura_ambiente_hourly[i] + 0.03 * irradiancia_hourly[i]
    else:
        temperatura_panel_hourly[i] = temperatura_ambiente_hourly[i]
    
    # Calcular potencia generada
    if irradiancia_hourly[i] <= 0:
        potencia_generada_hourly[i] = 0
    else:
        # Ajuste de eficiencia por temperatura
        temperatura_panel_c = temperatura_panel_hourly[i]
        eficiencia_ajustada = eficiencia_referencia * (1 + coef_temperatura * (temperatura_panel_c - 25))
        
        # Potencia generada (kW)
        potencia_generada_hourly[i] = area_paneles * (irradiancia_hourly[i] / 1000) * eficiencia_ajustada * factor_rendimiento
        
        # Limitar a la potencia pico
        potencia_generada_hourly[i] = min(potencia_generada_hourly[i], potencia_pico)

# PASO 2: Interpolar para crear datos por segundo
print("\nGenerando datos con resolución por segundo...")
print("NOTA: Por razones prácticas, se va a generar un subconjunto de los datos de un día.")

# Elegir un día para generar datos por segundo (por ejemplo, 1 de enero)
dia_elegido = 1  # 1 de enero
mes_elegido = 1  # enero

# Obtener los índices de las horas de ese día en el conjunto de datos horarios
indices_dia = []
for i, fecha in enumerate(dates_hourly):
    if fecha.day == dia_elegido and fecha.month == mes_elegido:
        indices_dia.append(i)

if not indices_dia:
    print(f"No se encontraron datos para el día {dia_elegido}/{mes_elegido}")
    exit(1)

print(f"Generando datos de alta resolución para el {dia_elegido}/{mes_elegido}...")

# Crear arrays para los datos por segundo (24 horas * 3600 segundos = 86400 segundos en un día)
n_segundos = 24 * 3600
dates_seconds = []
irradiancia_seconds = np.zeros(n_segundos)
temperatura_ambiente_seconds = np.zeros(n_segundos)
temperatura_panel_seconds = np.zeros(n_segundos)
potencia_generada_seconds = np.zeros(n_segundos)
energia_acumulada_seconds = np.zeros(n_segundos)

# Fecha base para ese día
fecha_base = dates_hourly[indices_dia[0]].replace(hour=0, minute=0, second=0)

# Para cada segundo del día
for s in range(n_segundos):
    # Calcular timestamp
    fecha_actual = fecha_base + timedelta(seconds=s)
    dates_seconds.append(fecha_actual)
    
    # Calcular hora decimal para interpolación (e.g., 1.5 = 1:30)
    hora_decimal = fecha_actual.hour + fecha_actual.minute/60 + fecha_actual.second/3600
    
    # Encontrar las horas enteras antes y después para interpolar
    hora_antes = int(hora_decimal)
    hora_despues = (hora_antes + 1) % 24
    
    # Índices en el array horario
    idx_antes = indices_dia[hora_antes]
    idx_despues = indices_dia[hora_despues] if hora_despues < len(indices_dia) else indices_dia[0]
    
    # Factor de interpolación (0 a 1)
    factor = hora_decimal - hora_antes
    
    # Interpolar valores
    irradiancia_seconds[s] = (1-factor) * irradiancia_hourly[idx_antes] + factor * irradiancia_hourly[idx_despues]
    temperatura_ambiente_seconds[s] = (1-factor) * temperatura_ambiente_hourly[idx_antes] + factor * temperatura_ambiente_hourly[idx_despues]
    temperatura_panel_seconds[s] = (1-factor) * temperatura_panel_hourly[idx_antes] + factor * temperatura_panel_hourly[idx_despues]
    potencia_generada_seconds[s] = (1-factor) * potencia_generada_hourly[idx_antes] + factor * potencia_generada_hourly[idx_despues]
    
    # Añadir pequeñas variaciones para simular fluctuaciones en tiempo real
    if irradiancia_seconds[s] > 0:
        # Fluctuaciones aleatorias de ±2%
        factor_fluctuacion = np.random.uniform(0.98, 1.02)
        irradiancia_seconds[s] *= factor_fluctuacion
        potencia_generada_seconds[s] *= factor_fluctuacion

    # Calcular energía acumulada (kWh), dividiendo por 3600 para convertir de kW a kWh por segundo
    if s == 0:
        energia_acumulada_seconds[s] = potencia_generada_seconds[s] / 3600
    else:
        energia_acumulada_seconds[s] = energia_acumulada_seconds[s-1] + potencia_generada_seconds[s] / 3600

# PASO 3: Crear DataFrame con datos por segundo y guardar
print(f"Creando DataFrame con {len(dates_seconds)} timestamps por segundo...")
datos_segundos = {
    'Timestamp': dates_seconds,
    'Fecha': [d.strftime('%Y-%m-%d') for d in dates_seconds],
    'Hora': [d.hour for d in dates_seconds],
    'Minuto': [d.minute for d in dates_seconds],
    'Segundo': [d.second for d in dates_seconds],
    'Irradiancia_W_m2': irradiancia_seconds,
    'Temperatura_Ambiente_C': temperatura_ambiente_seconds,
    'Temperatura_Panel_C': temperatura_panel_seconds,
    'Potencia_Generada_kW': potencia_generada_seconds,
    'Energia_Acumulada_kWh': energia_acumulada_seconds
}

df_segundos = pd.DataFrame(datos_segundos)

# Guardar CSV con datos por segundo (solo para un día, por eficiencia)
csv_file_segundos = f"planta_fotovoltaica_1MW_antofagasta_{dia_elegido:02d}_{mes_elegido:02d}_segundos.csv"
df_segundos.to_csv(csv_file_segundos, index=False)
print(f"Datos con resolución por segundo guardados en: {os.path.abspath(csv_file_segundos)}")

# PASO 4: Guardar también los datos horarios completos
print("\nGuardando también datos horarios para el año completo...")

# Crear DataFrame con datos horarios
energia_diaria = np.zeros(n_horas)
energia_total = np.zeros(n_horas)

# Calcular energía acumulada
for i in range(n_horas):
    # Energía horaria (kWh)
    energia_hora = potencia_generada_hourly[i]  # kWh para 1 hora
    
    # Energía diaria (acumulada dentro del día)
    hora = dates_hourly[i].hour
    if hora == 0:  # Inicio de un nuevo día
        energia_diaria[i] = energia_hora
    else:
        if i > 0:
            energia_diaria[i] = energia_diaria[i-1] + energia_hora
            if hora == 23:  # Final del día, preparando para el siguiente
                if i + 1 < n_horas:
                    energia_diaria[i+1] = 0
        else:
            energia_diaria[i] = energia_hora
    
    # Energía total acumulada
    if i == 0:
        energia_total[i] = energia_hora
    else:
        energia_total[i] = energia_total[i-1] + energia_hora

datos_horarios = {
    'Fecha': dates_hourly,
    'Hora': [d.hour for d in dates_hourly],
    'Dia': [d.timetuple().tm_yday for d in dates_hourly],
    'Mes': [d.month for d in dates_hourly],
    'Irradiancia_W_m2': irradiancia_hourly,
    'Temperatura_Ambiente_C': temperatura_ambiente_hourly,
    'Temperatura_Panel_C': temperatura_panel_hourly,
    'Potencia_Generada_kW': potencia_generada_hourly,
    'Energia_Diaria_kWh': energia_diaria,
    'Energia_Total_kWh': energia_total
}

df_horarios = pd.DataFrame(datos_horarios)
csv_file_horarios = "planta_fotovoltaica_1MW_antofagasta_anual_horario.csv"
df_horarios.to_csv(csv_file_horarios, index=False)
print(f"Datos horarios completos guardados en: {os.path.abspath(csv_file_horarios)}")

# Mostrar estadísticas generales
print("\nEstadísticas de la simulación anual:")
energia_anual = energia_total[-1]
print(f"Energía total generada: {energia_anual:.2f} kWh")

potencia_media = np.mean(potencia_generada_hourly)
print(f"Potencia media: {potencia_media:.2f} kW")
print(f"Potencia máxima: {np.max(potencia_generada_hourly):.2f} kW")

# Factor de capacidad (ratio entre producción real y teórica)
factor_capacidad = potencia_media / potencia_pico
print(f"Factor de capacidad: {factor_capacidad:.2%}")

# Horas equivalentes (energía anual / potencia pico)
horas_equivalentes = energia_anual / potencia_pico
print(f"Horas equivalentes: {horas_equivalentes:.0f} h")

# Estadísticas para los datos por segundo
print("\nEstadísticas de los datos por segundo (1 día):")
print(f"Número de timestamps: {len(df_segundos)}")
print(f"Potencia media: {df_segundos['Potencia_Generada_kW'].mean():.2f} kW")
print(f"Potencia máxima: {df_segundos['Potencia_Generada_kW'].max():.2f} kW")
print(f"Energía generada en el día: {df_segundos['Energia_Acumulada_kWh'].iloc[-1]:.2f} kWh")

# Generar gráfico de ejemplo de los datos por segundo (una hora)
print("\nGenerando gráfico de ejemplo con datos de alta resolución (una hora)...")
hora_ejemplo = 12  # mediodía
indices_hora = (df_segundos['Hora'] == hora_ejemplo)
df_hora_ejemplo = df_segundos[indices_hora]

plt.figure(figsize=(12, 6))
plt.plot(df_hora_ejemplo['Segundo'], df_hora_ejemplo['Potencia_Generada_kW'])
plt.title(f'Potencia Generada durante la Hora {hora_ejemplo}:00 (Resolución por Segundo)')
plt.ylabel('Potencia (kW)')
plt.xlabel('Segundo')
plt.grid(True, linestyle='--', alpha=0.7)
plt.tight_layout()

# Guardar gráfico
grafico_hora = f'potencia_segundos_hora_{hora_ejemplo}.png'
plt.savefig(grafico_hora)
print(f"Gráfico guardado como: {os.path.abspath(grafico_hora)}")

print("\n===== Generación completada =====")
print("Revisa los archivos CSV generados para análisis detallados de la producción.") 