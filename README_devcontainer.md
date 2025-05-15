# Digital Twin Dashboard para Sistemas de Energía Solar

Este repositorio contiene un gemelo digital (digital twin) interactivo para sistemas de energía solar, desarrollado utilizando Python y Streamlit.

## Características Principales

- **Dashboard interactivo**: Interfaz gráfica intuitiva para monitorear y simular sistemas solares
- **Dos tecnologías solares**:
  - **Fotovoltaica (PV)**: Monitoreo de una planta fotovoltaica de 1 MW en Antofagasta, Chile
  - **Energía Solar Concentrada (CSP)**: Simulación de plantas CSP tipo torre solar
- **Simulación en tiempo real**: Visualización dinámica de la operación de las plantas
- **Integración con SolarTherm**: Utiliza el motor de simulación SolarTherm para cálculos precisos

## Requisitos

- Python 3.8 o superior
- SolarTherm (instalado en `/home/cparrado/solartherm/src`)
- Streamlit
- Pandas, NumPy, Matplotlib, Plotly

## Estructura del Proyecto

- `digital_twin_dashboard.py`: Aplicación principal del dashboard
- `csp_digital_twin_dashboard.py`: Componentes específicos para CSP
- `CSP/`: Archivos de modelado y datos para sistemas CSP
- `Photovoltaic/`: Archivos de modelado y datos para sistemas PV

## Instalación

1. Clone este repositorio
2. Asegúrese de tener SolarTherm instalado correctamente
3. Instale las dependencias: `pip install -r requirements.txt`
4. Ejecute la aplicación: `streamlit run digital_twin_dashboard.py`

## Uso

### Dashboard Principal
El dashboard principal permite navegar entre los diferentes sistemas solares disponibles.

### Dashboard PV
Monitoreo y simulación de una planta fotovoltaica con análisis de:
- Producción en tiempo real
- Eficiencia del panel
- Temperatura
- Irradiancia

### Dashboard CSP
Simulación de una planta CSP con:
- Configuración de parámetros (potencia nominal, almacenamiento térmico, etc.)
- Vector de despacho personalizable
- Visualización de producción, nivel de almacenamiento y temperaturas
- Cálculos de LCOE y factor de capacidad

## Características Técnicas

- **Modularidad**: Diseño modular para fácil extensión
- **Caché de datos**: Optimización de rendimiento
- **Visualizaciones interactivas**: Gráficos dinámicos usando Plotly
- **Simulación predictiva**: Visualización de datos históricos y futuros con líneas punteadas

## Contribuciones

Las contribuciones son bienvenidas. Por favor, envíe un pull request o abra un issue para discutir cambios propuestos.

## Licencia

Este proyecto está licenciado bajo [Licencia MIT](LICENSE). 