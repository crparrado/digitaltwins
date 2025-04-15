# Gemelo Digital para Sistemas Fotovoltaicos y CSP

Este proyecto implementa un gemelo digital para sistemas de energía solar, permitiendo la visualización, simulación y monitoreo en tiempo real de plantas fotovoltaicas y de concentración solar.

## Gemelo Digital Fotovoltaico

El dashboard interactivo permite:

1. **Monitoreo en tiempo real**: Visualización de la producción energética, temperatura de paneles y eficiencia en tiempo real con datos simulados.
2. **Análisis histórico**: Evaluación del rendimiento mensual y anual con cálculo de métricas clave.
3. **Predicción**: Estimación de la producción para las próximas horas o días.
4. **Análisis de rendimiento**: Distribución de potencia y evaluación de factor de capacidad.

### Requisitos

- Python 3.6+
- Bibliotecas: streamlit, pandas, numpy, matplotlib, plotly

### Instalación

```bash
pip install streamlit pandas numpy matplotlib plotly
```

### Ejecución del Dashboard

1. Navega al directorio del proyecto:
```bash
cd digitaltwins/Photovoltaic
```

2. Ejecuta el dashboard:
```bash
streamlit run pv_digital_twin_dashboard.py
```

3. Se abrirá automáticamente en tu navegador web (típicamente en http://localhost:8501)

### Funcionalidades principales

#### Parámetros configurables
- Potencia pico de la planta
- Eficiencia de referencia de los paneles
- Factor de rendimiento del sistema
- Coeficiente de temperatura

#### Monitoreo en tiempo real
Simula el comportamiento de la planta a lo largo del día, con actualización de:
- Potencia generada
- Temperatura de los paneles
- Irradiancia solar
- Eficiencia actual

#### Análisis histórico
- Producción mensual
- Cálculo de energía total
- Factor de capacidad
- Horas equivalentes de funcionamiento

#### Predicción a corto plazo
- Previsión de producción para días específicos
- Estimación de energía generada

#### Análisis de rendimiento
- Distribución estadística de potencia
- Horas de funcionamiento por nivel
- Métricas de rendimiento anual

## Próximos pasos

- Integración de datos de sensores reales
- Implementación del gemelo digital CSP
- Alertas y detección de anomalías
- Optimización predictiva de operaciones

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