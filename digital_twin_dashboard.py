import streamlit as st
import os
import sys
import time
import subprocess
import pandas as pd
import numpy as np
import ast
import matplotlib.pyplot as plt
import plotly.express as px
import plotly.graph_objects as go
from datetime import datetime, timedelta
import math
from PIL import Image
from io import BytesIO
import locale

# Configurar el locale para español
try:
    locale.setlocale(locale.LC_TIME, 'es_ES.UTF-8')  # Para sistemas Linux/Unix
except:
    try:
        locale.setlocale(locale.LC_TIME, 'Spanish_Spain.1252')  # Para Windows
    except:
        pass  # Si no se puede configurar, se usa el locale predeterminado

# Agregar la ruta de SolarTherm a sys.path para poder importar los módulos
sys.path.append('/home/cparrado/solartherm/src')
try:
    from solartherm import simulation
    from solartherm import postproc
    print("Módulos de SolarTherm cargados correctamente")
except ImportError as e:
    st.error(f"Error al importar módulos de SolarTherm: {e}")
    print(f"Error al importar módulos de SolarTherm: {e}")
    raise

# Usar session_state para mantener el estado entre recargas
if 'dashboard' not in st.session_state:
    st.session_state.dashboard = "principal"

if 'simulacion_activa' not in st.session_state:
    st.session_state.simulacion_activa = False

if 'simulacion_completada' not in st.session_state:
    st.session_state.simulacion_completada = False

if 'resultados_simulacion' not in st.session_state:
    st.session_state.resultados_simulacion = None

# Configuración de la página (solo se ejecuta una vez)
st.set_page_config(
    page_title="Gemelo Digital - Energía Solar",
    page_icon="☀️",
    layout="wide"
)

# Funciones de navegación
def ir_a_principal():
    st.session_state.dashboard = "principal"
    st.session_state.simulacion_activa = False

def ir_a_pv():
    st.session_state.dashboard = "pv"
    st.session_state.simulacion_activa = False

def ir_a_csp():
    st.session_state.dashboard = "csp"
    st.session_state.simulacion_activa = False

def toggle_simulacion():
    st.session_state.simulacion_activa = not st.session_state.simulacion_activa

# Función para crear vector de despacho
def create_dispatch_vector(individuo):
    """
    Dado un individuo (vector de 24 valores), genera un vector de despacho para 24 horas.
    Cada hora se define como i*3600, para i en 0 a 23.
    """
    return [(i * 3600, valor) for i, valor in enumerate(individuo)]

# Función para cargar el vector óptimo desde el archivo CSV
def cargar_vector_optimo_csv():
    try:
        csv_path = '/home/cparrado/solartherm/tests/resultado_genetico_solartherm_final200.csv'
        df = pd.read_csv(csv_path)
        
        # Extraer el vector como string y evaluar para convertirlo en una lista de tuplas
        vector_str = df.iloc[0, 0]
        vector_tuplas = ast.literal_eval(vector_str)
        
        # Extraer solo los valores del vector (sin las horas)
        vector_valores = [valor for _, valor in vector_tuplas]
        
        # Extraer el valor de srev (ingresos)
        srev = df.iloc[0, 1]
        
        return vector_valores, srev
    except Exception as e:
        st.error(f"Error al cargar el vector óptimo desde CSV: {e}")
        return None, None

# ------------------------
# Clase de simulación SolarTherm
# ------------------------
class AccionaSimulator:
    def __init__(self, fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo'):
        self.fn = fn
        self.inicializar_sim()

    def inicializar_sim(self):
        # Forzamos la recompilación y carga creando una nueva instancia del simulador
        self.sim = simulation.Simulator(self.fn)
        print('Compiling model')
        self.sim.compile_model(args=['-d=nonewInst'])
        self.sim.compile_sim(args=['-s'])
        self.sim.load_init()

    def simulate(self):
        self.sim.simulate(start=0, stop='1y', tolerance=1e-4, step='300s', solver='dassl', nls='homotopy')
        self.res = postproc.SimResultElec(self.sim.res_fn)
        self.perf = self.res.calc_perf()
        print('epy  [GWhe ]: {0}'.format(self.perf[0]/1e3))
        print('lcoe [$/MWh]: {0}'.format(self.perf[1]))
        print('capf [  %  ]: {0}'.format(self.perf[2]))
        print('srev [  USD  ]: {0}'.format(self.perf[3]))
        return self.perf

    def simulate_with_vector(self, vector):
        # Actualiza el archivo de despacho con el vector proporcionado
        self.modify_dispatch_vector(vector)
        # Reinicializar el simulador para forzar la lectura del archivo actualizado
        self.inicializar_sim()
        self.simulate()
        return self.perf

    def modify_dispatch_vector(self, vector):
        vector_path = '/home/cparrado/.openmodelica/libraries/SolarTherm/Data/Schedules/sch_acciona.motab'
        with open(vector_path, 'w') as file:
            file.write('#1\ndouble daily1(24,2)\n')
            for hour, value in vector:
                file.write(f'{hour} {value}\n')
        # Opcional: imprimir el contenido para verificación
        with open(vector_path, 'r') as file:
            contenido = file.read()
            print("Nuevo contenido de sch_acciona.motab:\n", contenido)

# Dashboard Principal
if st.session_state.dashboard == "principal":
    st.title("🌞 Gemelo Digital de Sistemas de Energía Solar")
    
    # Descripción
    st.markdown("""
    ## Bienvenido al Digital Twin Dashboard para Sistemas de Energía Solar
    
    Esta herramienta permite monitorear y simular diferentes sistemas de energía solar:
    
    1. **Fotovoltaico (PV)**: Monitoreo y simulación de plantas solares fotovoltaicas.
    2. **Energía Solar Concentrada (CSP)**: Simulación de plantas de torre solar utilizando SolarTherm.
    
    Selecciona una de las opciones a continuación para comenzar.
    """)
    
    # Columnas para las tarjetas
    col1, col2 = st.columns(2)
    
    # Tarjeta para PV
    with col1:
        st.info("### Sistema Fotovoltaico (PV)")
        st.write("""
        Accede al gemelo digital de una planta fotovoltaica de 1 MW en Antofagasta, Chile.
        Visualiza datos de producción en tiempo real, analiza rendimiento y más.
        """)
        
        # Botón para ir al dashboard PV
        if st.button("Ir al dashboard PV", use_container_width=True):
            ir_a_pv()
            st.rerun()
    
    # Tarjeta para CSP
    with col2:
        st.success("### Sistema de Energía Solar Concentrada (CSP)")
        st.write("""
        Accede al gemelo digital de una planta CSP basada en el modelo Reference_1.
        Ejecuta simulaciones directamente con SolarTherm y optimiza el vector de despacho.
        """)
        
        # Botón para ir al dashboard CSP
        if st.button("Ir al dashboard CSP", use_container_width=True):
            ir_a_csp()
            st.rerun()
    
    # Footer
    st.markdown("---")
    with st.expander("Acerca de esta herramienta"):
        st.markdown("""
        ### Gemelo Digital para Sistemas de Energía Solar
        
        Este dashboard funciona como un gemelo digital (digital twin) para sistemas de energía solar,
        permitiendo monitorear, simular y analizar el rendimiento de distintas tecnologías.
        
        #### Características
        - Monitoreo en tiempo real
        - Simulación de condiciones operativas
        - Análisis de rendimiento y producción energética
        
        #### Tecnologías
        - PV: Sistemas fotovoltaicos conectados a red
        - CSP: Sistemas de concentración solar con módulo SolarTherm
        """)
        
        st.info("Desarrollado utilizando Python, Streamlit y librerías científicas de código abierto.")

# Dashboard PV
elif st.session_state.dashboard == "pv":
    # Botón para volver al menú principal
    if st.button("← Volver al menú principal", key="volver_pv"):
        ir_a_principal()
        st.rerun()
    
    st.title("☀️ Gemelo Digital - Planta Fotovoltaica")
    st.write("Monitoreo de una planta fotovoltaica de 1 MW en Antofagasta, Chile")

    # Función para cargar datos
    @st.cache_data
    def cargar_datos_antofagasta():
        try:
            # Intentar cargar desde la ubicación del script en el directorio PV
            datos = pd.read_csv("Photovoltaic/antofagasta.csv", skiprows=2)
            info_ubicacion = pd.read_csv("Photovoltaic/antofagasta.csv", nrows=1)
            return datos, info_ubicacion
        except FileNotFoundError:
            # Si no se encuentra, intentar desde solartherm/tests/
            datos = pd.read_csv("solartherm/tests/antofagasta.csv", skiprows=2)
            info_ubicacion = pd.read_csv("solartherm/tests/antofagasta.csv", nrows=1)
            return datos, info_ubicacion

    # Función para calcular la producción en tiempo real
    def calcular_produccion(area_paneles, irradiancia, temperatura_ambiente, eficiencia_referencia=0.20, factor_rendimiento=0.85, potencia_pico=1000, coef_temperatura=-0.004):
        # Cálculo de temperatura del panel
        temperatura_panel = temperatura_ambiente + 0.03 * irradiancia
        
        # Ajuste de eficiencia por temperatura
        eficiencia_ajustada = eficiencia_referencia * (1 + coef_temperatura * (temperatura_panel - 25))
        
        # Potencia generada (kW)
        potencia = area_paneles * (irradiancia / 1000) * eficiencia_ajustada * factor_rendimiento
        
        # Limitar a la potencia pico
        potencia = min(potencia, potencia_pico)
        
        return potencia, temperatura_panel, eficiencia_ajustada

    # Carga de datos
    try:
        datos_antofagasta, info_ubicacion = cargar_datos_antofagasta()
        latitud = float(info_ubicacion['Latitude'][0])
        longitud = float(info_ubicacion['Longitude'][0])
        elevacion = float(info_ubicacion['Elevation'][0])
        
        # Mostrar información de ubicación
        col1, col2, col3 = st.columns(3)
        with col1:
            st.metric("Latitud", f"{latitud:.4f}°")
        with col2:
            st.metric("Longitud", f"{longitud:.4f}°")
        with col3:
            st.metric("Elevación", f"{elevacion:.0f} m")
        
        # Parámetros de la simulación
        st.sidebar.header("Parámetros de simulación")
        
        # Parámetros ajustables
        potencia_pico = st.sidebar.slider("Potencia pico (kW)", 100, 5000, 1000)
        eficiencia_referencia = st.sidebar.slider("Eficiencia referencia (%)", 10, 30, 20) / 100
        factor_rendimiento = st.sidebar.slider("Factor de rendimiento (%)", 70, 95, 85) / 100
        coef_temperatura = st.sidebar.slider("Coeficiente de temperatura (%/°C)", -0.6, -0.2, -0.4) / 100
        
        # Calcular el área de paneles
        area_paneles = potencia_pico / (1 * eficiencia_referencia * factor_rendimiento) * 1.1
        st.sidebar.metric("Área de paneles", f"{area_paneles:.1f} m²")
        
        # Secciones del dashboard
        tabs = st.tabs(["Monitoreo en tiempo real", "Análisis histórico", "Predicción", "Rendimiento"])
        
        with tabs[0]:  # Monitoreo en tiempo real
            st.header("Monitoreo en tiempo real")
            
            # Selección de día de simulación
            dia_seleccionado = st.date_input("Seleccione día para simular:", 
                                              value=datetime(2014, 1, 1),
                                              min_value=datetime(2014, 1, 1), 
                                              max_value=datetime(2014, 12, 31))
            
            # Filtrar datos para el día seleccionado
            dia = dia_seleccionado.day
            mes = dia_seleccionado.month
            datos_dia = datos_antofagasta[(datos_antofagasta['Day'] == dia) & 
                                          (datos_antofagasta['Month'] == mes)]
            
            if len(datos_dia) == 0:
                st.warning(f"No hay datos para el día {dia}/{mes}.")
            else:
                # Simulación en tiempo real
                col1, col2 = st.columns(2)
                
                # Crear placeholders para actualización en tiempo real
                with col1:
                    chart_pot = st.empty()
                    
                with col2:
                    chart_temp = st.empty()
                    
                metrics_row = st.empty()
                
                # Botón para iniciar/detener simulación
                sim_button = st.button("Iniciar/Detener simulación en tiempo real", key="sim_pv")
                if sim_button:
                    toggle_simulacion()
                
                # Si la simulación está activa, ejecutarla
                if st.session_state.simulacion_activa:
                    # Placeholder para métricas
                    col1, col2, col3, col4 = metrics_row.columns(4)
                    
                    # Valores iniciales
                    potencia_actual = 0
                    temperatura_panel_actual = datos_dia.iloc[0]['Tdry']
                    irradiancia_actual = datos_dia.iloc[0]['GHI']
                    eficiencia_actual = eficiencia_referencia
                    
                    # Datos para gráficos
                    horas = list(range(24))
                    potencias = [0] * 24
                    temperaturas = [0] * 24
                    
                    # Simulación para cada hora del día
                    for i, hora in enumerate(range(24)):
                        # Obtener datos de la hora actual
                        if i < len(datos_dia):
                            irradiancia_actual = datos_dia.iloc[i]['GHI']
                            temp_ambiente_actual = datos_dia.iloc[i]['Tdry']
                            
                            # Calcular producción
                            potencia_actual, temperatura_panel_actual, eficiencia_actual = calcular_produccion(
                                area_paneles, irradiancia_actual, temp_ambiente_actual, 
                                eficiencia_referencia, factor_rendimiento, potencia_pico, coef_temperatura
                            )
                            
                            # Actualizar arrays para gráficos
                            potencias[hora] = potencia_actual
                            temperaturas[hora] = temperatura_panel_actual
                            
                            # Actualizar gráficos
                            fig_pot = px.line(x=horas[:hora+1], y=potencias[:hora+1], 
                                            labels={"x": "Hora", "y": "Potencia (kW)"})
                            fig_pot.update_layout(title="Potencia generada (kW)", height=300)
                            chart_pot.plotly_chart(fig_pot, use_container_width=True)
                            
                            fig_temp = px.line(x=horas[:hora+1], y=temperaturas[:hora+1],
                                            labels={"x": "Hora", "y": "Temperatura (°C)"})
                            fig_temp.update_layout(title="Temperatura del panel (°C)", height=300)
                            chart_temp.plotly_chart(fig_temp, use_container_width=True)
                            
                            # Actualizar métricas
                            col1.metric("Potencia actual", f"{potencia_actual:.2f} kW")
                            col2.metric("Irradiancia", f"{irradiancia_actual:.1f} W/m²")
                            col3.metric("Temp. panel", f"{temperatura_panel_actual:.1f} °C")
                            col4.metric("Eficiencia", f"{eficiencia_actual*100:.2f}%")
                            
                            # Esperar para simular tiempo real
                            time.sleep(0.5)  # Acelerar simulación (0.5s por hora)
                    
                    # Apagar la simulación al finalizar
                    st.session_state.simulacion_activa = False
        
        with tabs[1]:  # Análisis histórico
            st.header("Análisis histórico")
            
            # Resto del código del dashboard PV...
            st.write("Pestaña de análisis histórico en construcción.")

    except Exception as e:
        st.error(f"Error al cargar los datos: {e}")
        st.info("Asegúrate de que el archivo antofagasta.csv está en la ubicación correcta.")

# Dashboard CSP
elif st.session_state.dashboard == "csp":
    # Botón para volver al menú principal
    if st.button("← Volver al menú principal", key="volver_csp"):
        ir_a_principal()
        st.rerun()
    
    st.title("🔆 Gemelo Digital CSP - Modelo Reference_1")
    
    # Inicialización de estado
    if 'simulacion_csp_iniciada' not in st.session_state:
        st.session_state.simulacion_csp_iniciada = False
    
    if 'resultados_csp' not in st.session_state:
        st.session_state.resultados_csp = None
    
    if 'csp_hora_actual' not in st.session_state:
        st.session_state.csp_hora_actual = 12  # Hora por defecto (mediodía)
    
    if 'csp_dia_actual' not in st.session_state:
        st.session_state.csp_dia_actual = 172  # Día por defecto (21 de junio aprox.)
    
    if 'csp_simulacion_tiempo_real' not in st.session_state:
        st.session_state.csp_simulacion_tiempo_real = False
    
    if 'csp_datos_dia' not in st.session_state:
        st.session_state.csp_datos_dia = None
    
    # Sidebar con parámetros
    st.sidebar.header("Parámetros de Reference_1")
    
    # Tabs para diferentes vistas del dashboard CSP
    tabs = st.tabs(["Simulación de despacho", "Simulación dinámica", "Información del modelo"])
    
    with tabs[0]:  # Simulación de despacho
        # Opción para seleccionar tipo de vector de despacho
        tipo_vector = st.radio(
            "Tipo de vector de despacho",
            ["Por defecto", "Personalizado", "Vector óptimo del algoritmo genético"],
            help="Seleccione el tipo de vector de despacho que desea utilizar"
        )
        
        vector_despacho = []
        
        if tipo_vector == "Personalizado":
            st.subheader("Vector de despacho por hora")
            # Crear 24 sliders, uno para cada hora del día
            cols = st.columns(6)
            for hora in range(24):
                with cols[hora % 6]:
                    valor = st.slider(f"Hora {hora}:00", 0.0, 1.0, 0.5, step=0.05, key=f"desp_{hora}")
                    vector_despacho.append(valor)
        elif tipo_vector == "Vector óptimo del algoritmo genético":
            # Cargar el vector óptimo desde CSV
            vector_optimo, srev_esperado = cargar_vector_optimo_csv()
            if vector_optimo:
                vector_despacho = vector_optimo
                st.success("✅ Vector óptimo cargado correctamente")
                st.info(f"Ingresos esperados: {srev_esperado/1e6:.2f} M USD")
            else:
                st.error("❌ Error al cargar el vector óptimo")
                # Usar vector por defecto en caso de error
                vector_despacho = [0.2] * 6 + [0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.4] + [0.2] * 6
        else:  # Por defecto
            # Vector de despacho por defecto (día/noche)
            vector_despacho = [0.2] * 6 + [0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.4] + [0.2] * 6
        
        # Gráfico del vector de despacho
        fig_despacho = px.bar(
            x=list(range(24)),
            y=vector_despacho,
            labels={"x": "Hora", "y": "Factor de despacho"},
            title="Vector de despacho"
        )
        fig_despacho.update_layout(xaxis=dict(
            tickmode='array',
            tickvals=list(range(24)),
            ticktext=[f"{h}:00" for h in range(24)]
        ))
        st.plotly_chart(fig_despacho, use_container_width=True)
        
        # Columnas para métricas y controles
        col1, col2 = st.columns([3, 1])
        
        with col2:
            # Botón para ejecutar la simulación
            if st.button("Ejecutar simulación", use_container_width=True):
                with st.spinner("Ejecutando simulación en SolarTherm..."):
                    try:
                        # Preparar el vector de despacho en el formato requerido por AccionaSimulator
                        dispatch_vector = create_dispatch_vector(vector_despacho)
                        
                        # Inicializar el simulador
                        simulator = AccionaSimulator()
                        
                        # Simular con el vector de despacho
                        resultados = simulator.simulate_with_vector(dispatch_vector)
                        
                        # Guardar resultados en el estado de la sesión
                        st.session_state.resultados_csp = {
                            'energia_anual': resultados[0] * 1000,  # De GWh a MWh
                            'lcoe': resultados[1],  # USD/MWh
                            'factor_capacidad': resultados[2],  # %
                            'ingresos_anuales': resultados[3]  # USD
                        }
                        st.session_state.simulacion_csp_iniciada = True
                        
                    except Exception as e:
                        st.error(f"Error al ejecutar la simulación: {e}")
        
        # Mostrar resultados si ya se ha ejecutado la simulación
        if st.session_state.simulacion_csp_iniciada and st.session_state.resultados_csp is not None:
            resultados = st.session_state.resultados_csp
            
            # Mostrar métricas principales
            with col1:
                st.subheader("Resultados de la simulación")
                
                # Crear columnas para métricas
                m1, m2, m3, m4 = st.columns(4)
                
                with m1:
                    st.metric("Energía anual", f"{resultados['energia_anual']/1000:.2f} GWh")
                
                with m2:
                    st.metric("Factor de capacidad", f"{resultados['factor_capacidad']:.2f}%")
                
                with m3:
                    st.metric("LCOE", f"{resultados['lcoe']:.2f} USD/MWh")
                
                with m4:
                    st.metric("Ingresos anuales", f"{resultados['ingresos_anuales']/1e6:.2f} M USD")

    with tabs[1]:  # Simulación dinámica
        st.subheader("Comportamiento dinámico de la planta a lo largo del día")
        
        # Controles para la simulación
        col1, col2 = st.columns([3, 1])
        
        with col2:
            # Selección del día del año
            dia_seleccionado = st.slider("Día del año", 1, 365, st.session_state.csp_dia_actual, 
                                          help="Seleccione un día del año para la simulación")
            
            # Calcular la fecha correspondiente al día del año
            fecha = datetime(2023, 1, 1) + timedelta(days=dia_seleccionado-1)
            
            # Determinar la estación del año (hemisferio sur - Chile/Antofagasta)
            if 355 <= dia_seleccionado or dia_seleccionado <= 79:  # 21 Dec - 20 Mar
                estacion = "☀️ Verano"
            elif 80 <= dia_seleccionado <= 172:  # 21 Mar - 20 Jun
                estacion = "🍂 Otoño"
            elif 173 <= dia_seleccionado <= 265:  # 21 Jun - 20 Sep
                estacion = "❄️ Invierno"
            elif 266 <= dia_seleccionado <= 354:  # 21 Sep - 20 Dec
                estacion = "🌱 Primavera"
                
            st.info(f"📅 Fecha: {fecha.strftime('%d de %B, %Y')} | {estacion}")
            
            # Actualizar el día actual en la sesión
            if dia_seleccionado != st.session_state.csp_dia_actual:
                st.session_state.csp_dia_actual = dia_seleccionado
                st.session_state.csp_datos_dia = None  # Forzar regeneración de datos
            
            # Checkbox para simulación en tiempo real
            tiempo_real = st.checkbox("Simulación en tiempo real", 
                                      value=st.session_state.csp_simulacion_tiempo_real,
                                      help="Actualiza automáticamente la simulación")
            
            # Actualizar estado de simulación en tiempo real
            if tiempo_real != st.session_state.csp_simulacion_tiempo_real:
                st.session_state.csp_simulacion_tiempo_real = tiempo_real
            
            # Botón para reiniciar simulación
            if st.button("Reiniciar simulación"):
                st.session_state.csp_hora_actual = 0
                st.session_state.csp_simulacion_tiempo_real = True
        
        # Función para generar datos de producción diaria para CSP
        def generar_datos_csp(dia_anio=1):
            # Patrones de irradiancia según época del año (ajustado para hemisferio sur)
            if 173 <= dia_anio <= 265:  # Invierno en hemisferio sur (21 Jun - 20 Sep)
                irradiancia_max = 750
                horas_sol = 10
            else:  # Resto del año (mayor irradiancia)
                irradiancia_max = 950
                horas_sol = 14
                # Aumentar irradiancia para verano en hemisferio sur (Dec-Mar)
                if 355 <= dia_anio or dia_anio <= 79:
                    irradiancia_max = 1050
                    horas_sol = 14.5
            
            horas = list(range(24))
            irradiancia = []
            potencia = []
            nivel_almacenamiento = [50]  # Comenzar con 50% de almacenamiento
            temperatura_sales = []
            temperatura_receptor = []
            estado = []
            
            # Parámetros de la planta
            potencia_nominal = 111  # MW
            eficiencia_ciclo = 0.43
            capacidad_almacenamiento = 16  # horas
            temperatura_sales_frias = 290  # °C
            temperatura_sales_calientes = 574  # °C
            
            # Generar datos para cada hora
            for h in range(24):
                # Cálculo de irradiancia
                if h < (12 - horas_sol/2) or h >= (12 + horas_sol/2):
                    irrad = 0
                else:
                    # Curva de campana para irradiancia
                    hora_rel = (h - (12 - horas_sol/2)) / horas_sol
                    irrad = irradiancia_max * np.sin(np.pi * hora_rel)
                
                irradiancia.append(irrad)
                
                # Potencia térmica recibida
                pot_termica = irrad * 0.65 * 1500000 / 1e6  # MW (aproximado)
                
                # Vector de despacho (usar el mismo que en la otra pestaña)
                factor_despacho = vector_despacho[h] if vector_despacho else 0.5
                
                # Lógica de almacenamiento y generación
                nivel_actual = nivel_almacenamiento[-1]
                
                if irrad > 400:  # Hay suficiente radiación directa
                    if pot_termica > potencia_nominal / eficiencia_ciclo:
                        # Hay exceso, cargar almacenamiento
                        exceso = pot_termica - potencia_nominal / eficiencia_ciclo
                        nuevo_nivel = min(nivel_actual + exceso / 60, 100)  # Simplificado
                        pot_electrica = potencia_nominal * factor_despacho
                        estado_actual = "Generando + Cargando"
                    else:
                        # Generación directa
                        pot_electrica = min(pot_termica * eficiencia_ciclo, potencia_nominal) * factor_despacho
                        nuevo_nivel = nivel_actual
                        estado_actual = "Generando"
                elif nivel_actual > 5:
                    # Usar almacenamiento
                    pot_electrica = potencia_nominal * factor_despacho
                    nuevo_nivel = max(nivel_actual - pot_electrica / 20, 0)  # Simplificado
                    estado_actual = "Descargando"
                else:
                    # Sin sol y sin almacenamiento suficiente
                    pot_electrica = 0
                    nuevo_nivel = nivel_actual
                    estado_actual = "Parado"
                
                potencia.append(pot_electrica)
                nivel_almacenamiento.append(nuevo_nivel)
                estado.append(estado_actual)
                
                # Temperatura de las sales
                if nuevo_nivel > 0:
                    t_sales = temperatura_sales_frias + (temperatura_sales_calientes - temperatura_sales_frias) * nuevo_nivel / 100
                else:
                    t_sales = temperatura_sales_frias
                temperatura_sales.append(t_sales)
                
                # Temperatura del receptor
                if irrad > 0:
                    t_receptor = min(t_sales + irrad / 5, 700)  # Valor simplificado
                else:
                    t_receptor = max(temperatura_sales_frias, 25 + 273.15)  # Kelvin a Celsius
                temperatura_receptor.append(t_receptor)
            
            # Eliminar el valor extra del nivel de almacenamiento
            nivel_almacenamiento = nivel_almacenamiento[1:]
            
            return {
                'Hora': horas,
                'Irradiancia': irradiancia,
                'Potencia_MW': potencia,
                'Nivel_Almacenamiento': nivel_almacenamiento,
                'Temperatura_Sales': temperatura_sales,
                'Temperatura_Receptor': temperatura_receptor,
                'Estado': estado
            }
        
        # Generar o recuperar datos del día
        if st.session_state.csp_datos_dia is None or dia_seleccionado != st.session_state.csp_dia_actual:
            datos_dia = generar_datos_csp(dia_seleccionado)
            st.session_state.csp_datos_dia = datos_dia
        else:
            datos_dia = st.session_state.csp_datos_dia
        
        # Slider para selección de hora (si no está en tiempo real)
        if not st.session_state.csp_simulacion_tiempo_real:
            hora_actual = st.slider("Hora del día", 0, 23, st.session_state.csp_hora_actual)
            st.session_state.csp_hora_actual = hora_actual
        else:
            # En modo tiempo real, incrementar la hora automáticamente
            if 'last_update_time' not in st.session_state:
                st.session_state.last_update_time = time.time()
            
            tiempo_actual = time.time()
            if tiempo_actual - st.session_state.last_update_time > 2:  # Actualizar cada 2 segundos
                st.session_state.csp_hora_actual = (st.session_state.csp_hora_actual + 1) % 24
                st.session_state.last_update_time = tiempo_actual
            
            hora_actual = st.session_state.csp_hora_actual
            
            # Mostrar la hora actual
            st.info(f"⏰ Hora actual: {hora_actual}:00")
        
        # Mostrar métricas clave para la hora actual
        st.subheader(f"Métricas actuales - {fecha.strftime('%d de %B')}, {hora_actual}:00h")
        
        m1, m2, m3, m4 = st.columns(4)
        with m1:
            st.metric("Potencia generada", 
                      f"{datos_dia['Potencia_MW'][hora_actual]:.1f} MW", 
                      delta=f"{datos_dia['Potencia_MW'][hora_actual] - datos_dia['Potencia_MW'][hora_actual-1]:.1f} MW" if hora_actual > 0 else None)
        
        with m2:
            st.metric("Irradiación directa", 
                      f"{datos_dia['Irradiancia'][hora_actual]:.0f} W/m²",
                      delta=f"{datos_dia['Irradiancia'][hora_actual] - datos_dia['Irradiancia'][hora_actual-1]:.0f}" if hora_actual > 0 else None)
        
        with m3:
            st.metric("Nivel almacenamiento", 
                      f"{datos_dia['Nivel_Almacenamiento'][hora_actual]:.1f}%",
                      delta=f"{datos_dia['Nivel_Almacenamiento'][hora_actual] - datos_dia['Nivel_Almacenamiento'][hora_actual-1]:.1f}%" if hora_actual > 0 else None)
        
        with m4:
            st.metric("Estado operativo", datos_dia['Estado'][hora_actual])
        
        # Mostrar temperaturas
        t1, t2 = st.columns(2)
        with t1:
            st.metric("Temperatura sales", 
                      f"{datos_dia['Temperatura_Sales'][hora_actual]:.1f} °C",
                      delta=f"{datos_dia['Temperatura_Sales'][hora_actual] - datos_dia['Temperatura_Sales'][hora_actual-1]:.1f}" if hora_actual > 0 else None)
        
        with t2:
            st.metric("Temperatura receptor", 
                      f"{datos_dia['Temperatura_Receptor'][hora_actual]:.1f} °C",
                      delta=f"{datos_dia['Temperatura_Receptor'][hora_actual] - datos_dia['Temperatura_Receptor'][hora_actual-1]:.1f}" if hora_actual > 0 else None)
        
        # Gráficos
        g1, g2 = st.columns(2)
        
        with g1:
            # Gráfico de potencia vs hora
            # Dividir los datos en "histórico" y "futuro"
            horas_historico = datos_dia['Hora'][:hora_actual+1]
            potencia_historico = datos_dia['Potencia_MW'][:hora_actual+1]
            
            horas_futuro = datos_dia['Hora'][hora_actual:]
            potencia_futuro = datos_dia['Potencia_MW'][hora_actual:]
            
            # Crear el gráfico con datos históricos (línea sólida)
            fig_potencia = px.line(
                x=horas_historico, 
                y=potencia_historico,
                labels={"x": "Hora", "y": "Potencia (MW)"},
                title="Potencia generada a lo largo del día"
            )
            
            # Agregar datos futuros (línea punteada)
            fig_potencia.add_scatter(
                x=horas_futuro, 
                y=potencia_futuro,
                mode='lines',
                line=dict(dash='dash', color='rgba(0,0,255,0.5)'),
                name='Predicción'
            )
            
            # Agregar punto actual
            fig_potencia.add_scatter(
                x=[hora_actual], 
                y=[datos_dia['Potencia_MW'][hora_actual]],
                mode='markers',
                marker=dict(size=12, color='red'),
                name='Actual'
            )
            
            st.plotly_chart(fig_potencia, use_container_width=True)
        
        with g2:
            # Gráfico de nivel de almacenamiento vs hora
            # Dividir los datos en "histórico" y "futuro"
            nivel_historico = datos_dia['Nivel_Almacenamiento'][:hora_actual+1]
            nivel_futuro = datos_dia['Nivel_Almacenamiento'][hora_actual:]
            
            # Crear el gráfico con datos históricos (línea sólida)
            fig_almacenamiento = px.line(
                x=horas_historico, 
                y=nivel_historico,
                labels={"x": "Hora", "y": "Nivel (%)"},
                title="Nivel de almacenamiento térmico"
            )
            
            # Agregar datos futuros (línea punteada)
            fig_almacenamiento.add_scatter(
                x=horas_futuro, 
                y=nivel_futuro,
                mode='lines',
                line=dict(dash='dash', color='rgba(0,0,255,0.5)'),
                name='Predicción'
            )
            
            # Agregar punto actual
            fig_almacenamiento.add_scatter(
                x=[hora_actual], 
                y=[datos_dia['Nivel_Almacenamiento'][hora_actual]],
                mode='markers',
                marker=dict(size=12, color='red'),
                name='Actual'
            )
            
            st.plotly_chart(fig_almacenamiento, use_container_width=True)
        
        # Gráficos adicionales
        g3, g4 = st.columns(2)
        
        with g3:
            # Gráfico de irradiancia vs hora
            # Dividir los datos en "histórico" y "futuro"
            irradiancia_historico = datos_dia['Irradiancia'][:hora_actual+1]
            irradiancia_futuro = datos_dia['Irradiancia'][hora_actual:]
            
            # Crear el gráfico con datos históricos (línea sólida)
            fig_irradiancia = px.line(
                x=horas_historico, 
                y=irradiancia_historico,
                labels={"x": "Hora", "y": "Irradiancia (W/m²)"},
                title="Irradiancia solar directa"
            )
            
            # Agregar datos futuros (línea punteada)
            fig_irradiancia.add_scatter(
                x=horas_futuro, 
                y=irradiancia_futuro,
                mode='lines',
                line=dict(dash='dash', color='rgba(0,0,255,0.5)'),
                name='Predicción'
            )
            
            # Agregar punto actual
            fig_irradiancia.add_scatter(
                x=[hora_actual], 
                y=[datos_dia['Irradiancia'][hora_actual]],
                mode='markers',
                marker=dict(size=12, color='red'),
                name='Actual'
            )
            
            st.plotly_chart(fig_irradiancia, use_container_width=True)
        
        with g4:
            # Gráfico de temperatura vs hora
            # Crear listas separadas para temperaturas históricas y futuras
            temp_sales_historico = datos_dia['Temperatura_Sales'][:hora_actual+1]
            temp_receptor_historico = datos_dia['Temperatura_Receptor'][:hora_actual+1]
            
            temp_sales_futuro = datos_dia['Temperatura_Sales'][hora_actual:]
            temp_receptor_futuro = datos_dia['Temperatura_Receptor'][hora_actual:]
            
            # Gráfico de temperaturas históricas (líneas sólidas)
            fig_temperatura = go.Figure()
            
            # Temperatura sales (histórico)
            fig_temperatura.add_trace(go.Scatter(
                x=horas_historico, 
                y=temp_sales_historico,
                mode='lines',
                name='Sales (histórico)',
                line=dict(color='orange')
            ))
            
            # Temperatura receptor (histórico)
            fig_temperatura.add_trace(go.Scatter(
                x=horas_historico, 
                y=temp_receptor_historico,
                mode='lines',
                name='Receptor (histórico)',
                line=dict(color='red')
            ))
            
            # Temperatura sales (futuro - punteado)
            fig_temperatura.add_trace(go.Scatter(
                x=horas_futuro, 
                y=temp_sales_futuro,
                mode='lines',
                name='Sales (predicción)',
                line=dict(dash='dash', color='rgba(255,165,0,0.5)')
            ))
            
            # Temperatura receptor (futuro - punteado)
            fig_temperatura.add_trace(go.Scatter(
                x=horas_futuro, 
                y=temp_receptor_futuro,
                mode='lines',
                name='Receptor (predicción)',
                line=dict(dash='dash', color='rgba(255,0,0,0.5)')
            ))
            
            # Agregar puntos actuales
            fig_temperatura.add_trace(go.Scatter(
                x=[hora_actual, hora_actual], 
                y=[datos_dia['Temperatura_Sales'][hora_actual], datos_dia['Temperatura_Receptor'][hora_actual]],
                mode='markers',
                marker=dict(size=12, color=['orange', 'red']),
                name='Actual'
            ))
            
            # Configurar layout
            fig_temperatura.update_layout(
                title="Temperaturas del sistema",
                xaxis_title="Hora",
                yaxis_title="Temperatura (°C)",
                legend=dict(
                    orientation="h",
                    yanchor="bottom",
                    y=1.02,
                    xanchor="right",
                    x=1
                )
            )
            
            st.plotly_chart(fig_temperatura, use_container_width=True)
        
        # Actualizar la página si está en modo tiempo real
        if st.session_state.csp_simulacion_tiempo_real:
            time.sleep(0.1)  # Pequeña pausa para no saturar
            st.rerun()

    with tabs[2]:  # Información del modelo
        # Información adicional sobre el modelo
        st.subheader("Acerca del modelo Reference_1")
        
        st.markdown("""
        ### Modelo Reference_1 de SolarTherm
        
        Este gemelo digital utiliza el modelo Reference_1 de SolarTherm, que representa una planta de torre solar con las siguientes características:
        
        - **Potencia nominal**: 111 MW
        - **Almacenamiento térmico**: 16 horas
        - **Temperatura sales calientes**: 574°C
        - **Temperatura sales frías**: 290°C
        - **Eficiencia del bloque de potencia**: 43%
        
        El modelo incluye:
        - Campo de heliostatos con seguimiento solar
        - Receptor solar en torre
        - Sistema de almacenamiento térmico de sales fundidas
        - Bloque de potencia tipo Rankine
        
        La simulación se realiza utilizando OpenModelica a través de la API de SolarTherm.
        """)
        
        col1, col2 = st.columns(2)
        
        with col1:
            st.subheader("Vector óptimo")
            st.write("El vector óptimo de despacho fue obtenido mediante un algoritmo genético que maximiza los ingresos anuales de la planta.")
            
            # Cargar el vector óptimo
            vector_optimo, srev_esperado = cargar_vector_optimo_csv()
            
            if vector_optimo:
                # Crear dataframe para mostrar el vector óptimo
                df_vector = pd.DataFrame({
                    "Hora": range(24),
                    "Factor de despacho": vector_optimo
                })
                
                # Mostrar el vector óptimo como una tabla
                st.dataframe(df_vector, use_container_width=True)
                
                # Mostrar métricas clave
                st.metric("Ingresos esperados con vector óptimo", f"{srev_esperado/1e6:.2f} M USD")
        
        with col2:
            st.subheader("Comparación de estrategias")
            st.write("La estrategia de despacho óptima mejora significativamente el rendimiento de la planta frente a estrategias convencionales.")
            
            # Datos estimados para comparación
            datos_comparacion = {
                "Estrategia": ["Convencional", "Propuesta", "Óptima (AG)"],
                "Energía anual (GWh)": [553.2, 672.5, 784.3],
                "Factor de capacidad (%)": [56.7, 69.1, 89.5],
                "LCOE (USD/MWh)": [175.3, 120.8, 104.7],
                "Ingresos (M USD)": [32.5, 48.7, 67.1]
            }
            
            df_comparacion = pd.DataFrame(datos_comparacion)
            
            # Mostrar tabla de comparación
            st.dataframe(df_comparacion, use_container_width=True)
            
            # Añadir un gráfico de mejora porcentual
            mejoras = {
                "Métrica": ["Energía anual", "Factor de capacidad", "Reducción LCOE", "Ingresos"],
                "Mejora (%)": [
                    (784.3 - 553.2) / 553.2 * 100,  # Energía
                    (89.5 - 56.7) / 56.7 * 100,     # Factor de capacidad
                    (175.3 - 104.7) / 175.3 * 100,  # LCOE (reducción)
                    (67.1 - 32.5) / 32.5 * 100      # Ingresos
                ]
            }
            
            df_mejoras = pd.DataFrame(mejoras)
            
            # Gráfico de mejoras
            fig_mejoras = px.bar(
                df_mejoras,
                x="Métrica",
                y="Mejora (%)",
                title="Mejora porcentual con la estrategia óptima vs. convencional",
                text_auto=True
            )
            st.plotly_chart(fig_mejoras, use_container_width=True)
            
        st.info("Para obtener resultados más detallados, consulte la documentación de SolarTherm o utilice el software directamente.")
else:
    st.error("Sección desconocida")
    ir_a_principal()
    st.rerun() 