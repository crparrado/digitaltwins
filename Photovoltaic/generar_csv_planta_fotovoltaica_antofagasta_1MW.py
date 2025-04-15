import numpy as np
import pandas as pd
import os
import math
import matplotlib.pyplot as plt
from datetime import datetime, timedelta

print("===== Generador de CSV para Simulación Anual de Planta Fotovoltaica - Antofagasta 1 MW =====")

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
    print(f"Datos cargados: {len(datos_antofagasta)} registros")
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

# Convertir datos a formato adecuado
print("Procesando datos...")

# Configurar período de simulación
n_horas = len(datos_antofagasta)
print(f"Generando datos para {n_horas} horas ({n_horas/24:.0f} días)...")

# Crear arrays para los datos
irradiancia = np.zeros(n_horas)
temperatura_ambiente = np.zeros(n_horas)
temperatura_panel = np.zeros(n_horas)
potencia_generada = np.zeros(n_horas)
energia_diaria = np.zeros(n_horas)
energia_total = np.zeros(n_horas)

# Extraer fechas
dates = []
for i in range(n_horas):
    year = datos_antofagasta.iloc[i]['Year']
    month = datos_antofagasta.iloc[i]['Month']
    day = datos_antofagasta.iloc[i]['Day']
    hour = datos_antofagasta.iloc[i]['Hour']
    dates.append(datetime(year=int(year), month=int(month), day=int(day), hour=int(hour)))

# Procesar cada hora con datos reales
for i in range(n_horas):
    # Extraer datos climáticos
    # GHI: Irradiancia Global Horizontal
    # DNI: Irradiancia Directa Normal
    # DHI: Irradiancia Difusa Horizontal
    # Tdry: Temperatura seca
    ghi = datos_antofagasta.iloc[i]['GHI']  # W/m²
    dni = datos_antofagasta.iloc[i]['DNI']  # W/m²
    dhi = datos_antofagasta.iloc[i]['DHI']  # W/m²
    temp_ambiente = datos_antofagasta.iloc[i]['Tdry']  # °C
    
    # Almacenar irradiancia (usamos GHI como referencia)
    irradiancia[i] = ghi
    
    # Almacenar temperatura ambiente
    temperatura_ambiente[i] = temp_ambiente
    
    # CÁLCULO DE TEMPERATURA DEL PANEL
    # Los paneles se calientan más que el ambiente por la radiación
    if irradiancia[i] > 0:
        # Modelo simple: Tpanel = Tambiente + k*irradiancia
        temperatura_panel[i] = temperatura_ambiente[i] + 0.03 * irradiancia[i]
    else:
        temperatura_panel[i] = temperatura_ambiente[i]
    
    # CÁLCULO DE POTENCIA GENERADA
    if irradiancia[i] <= 0:
        potencia_generada[i] = 0
    else:
        # Ajuste de eficiencia por temperatura (típicamente -0.4%/°C respecto a 25°C)
        temperatura_panel_c = temperatura_panel[i]  # Ya está en °C
        eficiencia_ajustada = eficiencia_referencia * (1 + coef_temperatura * (temperatura_panel_c - 25))
        
        # Potencia generada (kW)
        potencia_generada[i] = area_paneles * (irradiancia[i] / 1000) * eficiencia_ajustada * factor_rendimiento
        
        # Limitar a la potencia pico
        potencia_generada[i] = min(potencia_generada[i], potencia_pico)
    
    # CÁLCULO DE ENERGÍA
    # Energía horaria (kWh)
    energia_hora = potencia_generada[i]  # kWh para 1 hora
    
    # Energía diaria (acumulada dentro del día)
    hora = dates[i].hour
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

# Crear DataFrame
print("Creando DataFrame...")
datos = {
    'Fecha': dates,
    'Hora': [d.hour for d in dates],
    'Dia': [d.timetuple().tm_yday for d in dates],
    'Mes': [d.month for d in dates],
    'Irradiancia_W_m2': irradiancia,
    'Temperatura_Ambiente_C': temperatura_ambiente,
    'Temperatura_Panel_C': temperatura_panel,
    'Potencia_Generada_kW': potencia_generada,
    'Energia_Diaria_kWh': energia_diaria,
    'Energia_Total_kWh': energia_total
}

df = pd.DataFrame(datos)

# Guardar CSV completo con todos los datos horarios
csv_file = "planta_fotovoltaica_1MW_antofagasta_anual.csv"
df.to_csv(csv_file, index=False)
print(f"Datos horarios completos guardados en: {os.path.abspath(csv_file)}")

# Crear resumen mensual
print("Generando resumen mensual...")
resumen_mensual = df.groupby('Mes').agg({
    'Irradiancia_W_m2': ['mean', 'max', 'sum'],
    'Temperatura_Ambiente_C': ['mean', 'max', 'min'],
    'Potencia_Generada_kW': ['mean', 'max', 'sum'],
    'Energia_Total_kWh': lambda x: x.iloc[-1] - x.iloc[0]  # Energía generada en el mes
})

resumen_mensual.columns = ['_'.join(col).strip() for col in resumen_mensual.columns.values]
resumen_mensual = resumen_mensual.reset_index()

# Añadir nombres de mes
nombres_meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 
                'Julio', 'Agosto', 'Septiembre', 'Octubre', 'Noviembre', 'Diciembre']
resumen_mensual['Nombre_Mes'] = [nombres_meses[m-1] for m in resumen_mensual['Mes']]

# Guardar resumen mensual
csv_mensual = "planta_fotovoltaica_1MW_antofagasta_resumen_mensual.csv"
resumen_mensual.to_csv(csv_mensual, index=False)
print(f"Resumen mensual guardado en: {os.path.abspath(csv_mensual)}")

# Mostrar estadísticas generales
print("\nEstadísticas de la simulación anual:")
energia_anual = energia_total[-1]
print(f"Energía total generada: {energia_anual:.2f} kWh")

potencia_media = np.mean(potencia_generada)
print(f"Potencia media: {potencia_media:.2f} kW")
print(f"Potencia máxima: {np.max(potencia_generada):.2f} kW")

# Factor de capacidad (ratio entre producción real y teórica)
factor_capacidad = potencia_media / potencia_pico
print(f"Factor de capacidad: {factor_capacidad:.2%}")

# Horas equivalentes (energía anual / potencia pico)
horas_equivalentes = energia_anual / potencia_pico
print(f"Horas equivalentes: {horas_equivalentes:.0f} h")

# Generar gráfico de producción mensual
print("\nGenerando gráfico de producción mensual...")
plt.figure(figsize=(12, 6))
x = np.arange(len(nombres_meses))
plt.bar(x, resumen_mensual['Energia_Total_kWh_<lambda>'], color='green')
plt.xticks(x, nombres_meses, rotation=45)
plt.title('Producción Mensual de Energía - Planta Fotovoltaica 1 MW (Antofagasta)')
plt.ylabel('Energía (kWh)')
plt.xlabel('Mes')
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()

# Guardar gráfico
plt.savefig('produccion_mensual_planta_1MW_antofagasta.png')
print(f"Gráfico guardado como: {os.path.abspath('produccion_mensual_planta_1MW_antofagasta.png')}")

print("\n===== Generación completada =====")
print("Revisa los archivos CSV generados para análisis detallados de la producción anual.") 