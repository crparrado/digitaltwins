# Gemelo Digital para Sistemas Fotovoltaicos y CSP

Este proyecto implementa un gemelo digital completo para sistemas de energía solar, permitiendo la visualización, simulación y monitoreo en tiempo real de plantas fotovoltaicas y de concentración solar térmica.

## Estructura del Sistema

El sistema de gemelos digitales incluye:

1. **Dashboard principal integrado** - Interfaz unificada para acceder a los gemelos digitales específicos
2. **Gemelo digital fotovoltaico** - Simulación y monitoreo de plantas PV
3. **Gemelo digital CSP** - Simulación y monitoreo de sistemas de concentración solar

## Requisitos

- Python 3.6+
- Bibliotecas: streamlit, pandas, numpy, matplotlib, plotly

### Instalación

```bash
pip install streamlit pandas numpy matplotlib plotly
```

### Ejecución del Dashboard Integrado

1. Navega al directorio del proyecto:
```bash
cd digitaltwins
```

2. Ejecuta el dashboard principal:
```bash
streamlit run digital_twin_dashboard.py
```

3. Se abrirá automáticamente en tu navegador web (típicamente en http://localhost:8501)

## Gemelo Digital Fotovoltaico

El dashboard fotovoltaico permite:

1. **Monitoreo en tiempo real**: Visualización de la producción energética, temperatura de paneles y eficiencia en tiempo real con datos simulados.
2. **Análisis histórico**: Evaluación del rendimiento mensual y anual con cálculo de métricas clave.
3. **Predicción**: Estimación de la producción para las próximas horas o días.
4. **Análisis de rendimiento**: Distribución de potencia y evaluación de factor de capacidad.

### Parámetros configurables PV
- Potencia pico de la planta
- Eficiencia de referencia de los paneles
- Factor de rendimiento del sistema
- Coeficiente de temperatura

## Gemelo Digital CSP (Concentrated Solar Power)

El dashboard CSP permite:

1. **Selección de tecnología**: Simular diferentes tipos de plantas CSP (Torre Solar, Cilindro-Parabólicos, Fresnel).
2. **Monitoreo en tiempo real**: Visualización de potencia, temperatura de campo y almacenamiento.
3. **Análisis de rendimiento**: Métricas clave como LCOE, factor de capacidad e ingresos.
4. **Simulación anual**: Proyección de producción mensual.
5. **Comparativa tecnológica**: Comparación entre diferentes tecnologías solares.

### Parámetros configurables CSP
- Tipo de planta CSP
- Potencia nominal
- Horas de almacenamiento térmico
- Temperaturas de operación
- Eficiencia del ciclo
- Parámetros específicos del campo solar
- Múltiplo solar

## Características principales

### Monitoreo en tiempo real
Ambos gemelos digitales simulan el comportamiento de las plantas a lo largo del día, actualizando:
- Potencia generada
- Temperatura de los componentes
- Irradiancia solar
- Eficiencia/rendimiento

### Análisis histórico y predictivo
- Producción mensual y anual
- Cálculo de factores de capacidad
- Horas equivalentes de funcionamiento
- Predicciones de producción

### Simulación de escenarios
- Evaluación de diferentes configuraciones
- Optimización de parámetros
- Análisis comparativo de tecnologías

## Próximos pasos

- Integración de datos de sensores reales mediante APIs
- Implementación de algoritmos avanzados de predicción con ML/IA
- Visualización 3D de las plantas
- Simulación de fallos y mantenimiento predictivo

## Fuentes de datos y modelos

- Modelos fotovoltaicos: Basados en ecuaciones físicas de conversión fotoeléctrica y eficiencia térmica
- Modelos CSP: Basados en SolarTherm y OpenModelica
- Datos climatológicos: Basados en TMY (Año Meteorológico Típico) para Antofagasta, Chile

## Ampliaciones futuras

1. **Conectividad IoT**:
   - Integración con sensores reales
   - Comunicación bidireccional entre modelo y planta física

2. **Analítica avanzada**:
   - Algoritmos de predicción basados en IA/ML
   - Detección de fallos y mantenimiento predictivo

3. **Visualización 3D**:
   - Representación espacial de la planta
   - Mapa térmico de temperaturas

4. **Simulación de escenarios**:
   - Evaluación de cambios en configuración
   - Análisis de estrategias de mantenimiento

# Documentación de `digital_twin_dashboard.py`

## Descripción General
`digital_twin_dashboard.py` es el componente principal del gemelo digital para sistemas de energía solar. Este archivo implementa una interfaz interactiva basada en Streamlit que permite visualizar, monitorear y simular el comportamiento de sistemas solares fotovoltaicos y de concentración.

## Funcionalidades Principales

### Navegación
- Sistema de navegación entre dashboards (principal, PV, CSP)
- Gestión de estado utilizando `st.session_state` para mantener persistencia

### Dashboard Fotovoltaico (PV)
- Monitoreo en tiempo real de una planta fotovoltaica de 1 MW
- Simulación de producción energética basada en datos meteorológicos
- Visualización de potencia generada, irradiancia y temperaturas
- Cálculo dinámico de eficiencia según condiciones ambientales

### Dashboard CSP (Concentración Solar)
- Simulación de plantas CSP tipo torre solar
- Configuración personalizada de vector de despacho
- Visualización de operación a lo largo del día (potencia, almacenamiento térmico)
- Integración con SolarTherm para cálculos precisos

## Estructura de Código

### Importaciones y Configuración
```python
import streamlit as st
import pandas as pd
import numpy as np
import plotly.express as px
import plotly.graph_objects as go
# Más importaciones...

# Inicialización de estado
if 'dashboard' not in st.session_state:
    st.session_state.dashboard = "principal"
```

### Funciones Principales
- `ir_a_principal()`, `ir_a_pv()`, `ir_a_csp()`: Funciones de navegación
- `cargar_datos_antofagasta()`: Carga de datos meteorológicos con caché
- `cargar_vector_optimo_csv()`: Carga de vectores de despacho optimizados
- `calcular_produccion()`: Estimación de producción fotovoltaica
- `generar_datos_csp()`: Simulación de operación CSP 

### Clase `AccionaSimulator`
Integración con SolarTherm para simulaciones de plantas CSP:
```python
class AccionaSimulator:
    def __init__(self, fn='/.../Reference_1.mo'):
        # Inicialización...
    
    def simulate(self):
        # Simulación...
    
    def simulate_with_vector(self, vector):
        # Simulación con vector personalizado...
```

### Visualización con Plotly
Gráficos dinámicos para monitoreo en tiempo real:
- Potencia generada
- Niveles de almacenamiento térmico
- Irradiancia solar
- Temperaturas del sistema

## Características Avanzadas
- **Simulación predictiva**: Visualización de datos históricos y predicciones futuras
- **Actualización en tiempo real**: Refresco automático de datos durante la simulación
- **Interactividad**: Controles para modificar parámetros y observar resultados
- **Líneas de tiempo punteadas**: Representación visual de predicciones futuras

## Uso Técnico
El archivo utiliza la estructura condicional principal:
```python
if st.session_state.dashboard == "principal":
    # Código del dashboard principal
elif st.session_state.dashboard == "pv":
    # Código del dashboard PV
elif st.session_state.dashboard == "csp":
    # Código del dashboard CSP
```

## Dependencias
- Streamlit 1.10+
- Pandas, NumPy para procesamiento de datos
- Plotly para visualizaciones interactivas
- SolarTherm para simulaciones térmicas avanzadas

## Integración
Este archivo funciona en conjunto con `csp_digital_twin_dashboard.py` y los archivos contenidos en los directorios `CSP/` y `Photovoltaic/`.

## Mejoras Futuras
- Implementación de módulos adicionales para otros sistemas de energía renovable
- Mejora de modelos predictivos utilizando aprendizaje automático
- Integración con sistemas de datos en tiempo real 