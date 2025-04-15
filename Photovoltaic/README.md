# Simulación de Planta Fotovoltaica - Antofagasta

Este repositorio contiene un conjunto de scripts y modelos para simular el rendimiento de una planta fotovoltaica de 1 MW ubicada en Antofagasta, Chile, utilizando datos meteorológicos reales.

## Descripción

El proyecto permite simular la producción de energía de una planta fotovoltaica utilizando tanto un modelo en Modelica como una implementación alternativa en Python. El flujo de trabajo incluye la carga de datos climáticos, el procesamiento con un modelo físico detallado, y la generación de gráficos y estadísticas para análisis energético.

La simulación incluye:
- Cálculo de temperatura de los paneles
- Ajuste de eficiencia por temperatura
- Estimación de potencia generada hora a hora
- Cálculo de métricas de rendimiento (factor de capacidad, horas equivalentes)
- Generación de datos con alta resolución temporal (hasta por segundo)
- Visualización de la producción energética

## Archivos principales

### Datos de entrada
- `solartherm/tests/antofagasta.csv` - Datos meteorológicos de Antofagasta (irradiancia, temperatura, etc.)

### Modelos
- `solartherm/tests/planta_fotovoltaica_anual.mo` - Modelo Modelica de la planta fotovoltaica

### Scripts de simulación
- `solartherm/tests/generar_csv_planta_fotovoltaica_antofagasta_1MW.py` - Genera datos horarios para un año completo
- `solartherm/tests/generar_csv_planta_fotovoltaica_antofagasta_1MW_segundos.py` - Genera datos con resolución por segundo para un día específico
- `solartherm/tests/generar_grafico_7dias_potencia.py` - Crea visualizaciones de la producción durante 7 días
- `solartherm/tests/generar_datos_climaticos.py` - Herramienta para generar datos climáticos sintéticos (opcional)

### Archivos de salida
- `planta_fotovoltaica_1MW_antofagasta_anual.csv` - Datos horarios para todo el año
- `planta_fotovoltaica_1MW_antofagasta_resumen_mensual.csv` - Resumen mensual de producción
- `planta_fotovoltaica_1MW_antofagasta_01_01_segundos.csv` - Datos por segundo para el 1 de enero
- `potencia_vs_tiempo_7dias.png` - Gráfico de 7 días de potencia vs tiempo
- `potencia_vs_tiempo_7dias_desglosado.png` - Gráfico desglosado por día
- `produccion_mensual_planta_1MW_antofagasta.png` - Gráfico de producción mensual

## Requisitos

- Python 3.6 o superior
- Bibliotecas Python:
  - numpy
  - pandas
  - matplotlib
  - datetime
- OpenModelica (opcional, solo si se desea ejecutar el modelo .mo directamente)

## Cómo ejecutar

### 1. Generar datos horarios y resumen mensual

```bash
python3 solartherm/tests/generar_csv_planta_fotovoltaica_antofagasta_1MW.py
```

Este comando procesará los datos climáticos y generará:
- Archivo CSV con datos horarios para todo el año
- Archivo CSV con resumen mensual
- Gráfico de producción mensual
- Estadísticas de la planta (energía total, factor de capacidad, etc.)

### 2. Generar datos con resolución por segundo

```bash
python3 solartherm/tests/generar_csv_planta_fotovoltaica_antofagasta_1MW_segundos.py
```

Este comando genera datos con alta resolución temporal (por segundo) para un día específico (por defecto, el 1 de enero). Por razones prácticas, solo se genera para un día debido al gran volumen de datos que supondría hacerlo para un año completo.

### 3. Generar gráficos de 7 días

```bash
python3 solartherm/tests/generar_grafico_7dias_potencia.py
```

Este comando crea visualizaciones detalladas de la producción de energía durante una semana.

## Modelo fotovoltaico

El modelo físico implementado incluye:

1. **Dimensionamiento de la planta**
   - Área de paneles calculada para alcanzar 1 MW de potencia pico nominal
   - Eficiencia de referencia: 20%
   - Factor de rendimiento del sistema: 85%

2. **Temperatura del panel**
   - `Tpanel = Tambiente + 0.03 * irradiancia`

3. **Eficiencia ajustada por temperatura**
   - `eficiencia = eficiencia_ref * (1 + coef_temp * (Tpanel - 25°C))`
   - Coeficiente de temperatura: -0.4%/°C

4. **Potencia generada**
   - `potencia = área * (irradiancia/1000) * eficiencia * factor_rendimiento`
   - Limitada a la potencia nominal (1 MW)

## Resultados para Antofagasta

Para una planta fotovoltaica de 1 MW en Antofagasta, Chile, los resultados muestran:
- Factor de capacidad: 30.47%
- Horas equivalentes: 2,669 h/año
- Energía anual generada: 2,669,444 kWh

Estos valores son considerablemente buenos para instalaciones fotovoltaicas, gracias a las excelentes condiciones de radiación solar en el norte de Chile.

## Autor

Crparrado 