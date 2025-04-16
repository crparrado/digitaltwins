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