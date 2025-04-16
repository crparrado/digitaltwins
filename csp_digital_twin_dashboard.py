import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import plotly.express as px
import plotly.graph_objects as go
import os
from datetime import datetime, timedelta
import time

# Configuración de la página
st.set_page_config(
    page_title="Gemelo Digital - Planta CSP",
    page_icon="🔆",
    layout="wide"
)

# Título y descripción
st.title("🔆 Gemelo Digital - Planta de Concentración Solar")
st.markdown("Dashboard interactivo para monitorizar y simular el rendimiento de una planta CSP basada en SolarTherm")

# Sidebar para parámetros de la planta
st.sidebar.header("Parámetros de la planta CSP")

# Parámetros de la planta CSP
tipo_planta = st.sidebar.selectbox(
    "Tipo de planta CSP",
    ["Torre Solar", "Colectores Cilindro-Parabólicos", "Fresnel Lineal"]
)

potencia_nominal = st.sidebar.slider("Potencia nominal (MW)", 50, 200, 111)
horas_almacenamiento = st.sidebar.slider("Horas de almacenamiento térmico", 0, 24, 16)
temperatura_sales_frias = st.sidebar.slider("Temperatura sales frías (°C)", 250, 350, 290)
temperatura_sales_calientes = st.sidebar.slider("Temperatura sales calientes (°C)", 450, 600, 574)
eficiencia_ciclo = st.sidebar.slider("Eficiencia del ciclo (%)", 30, 50, 43) / 100

# Calcular volumen de almacenamiento
volumen_almacenamiento = potencia_nominal * horas_almacenamiento * 3600 / (eficiencia_ciclo * 1e6) * 3  # m³ (aproximado)
st.sidebar.metric("Volumen almacenamiento", f"{volumen_almacenamiento:.1f} m³")

# Parámetros del campo solar
if tipo_planta == "Torre Solar":
    altura_torre = st.sidebar.slider("Altura de la torre (m)", 100, 300, 220)
    num_heliostatos = st.sidebar.slider("Número de heliostatos", 5000, 15000, 10600)
    area_heliostato = st.sidebar.slider("Área por heliostato (m²)", 100, 160, 141.8)
    area_campo = num_heliostatos * area_heliostato
    st.sidebar.metric("Área del campo solar", f"{area_campo/1000:.1f} km²")
elif tipo_planta == "Colectores Cilindro-Parabólicos":
    num_colectores = st.sidebar.slider("Número de colectores", 50, 300, 150)
    longitud_colector = st.sidebar.slider("Longitud por colector (m)", 50, 200, 100)
    apertura_colector = st.sidebar.slider("Apertura del colector (m)", 5, 10, 5.77)
    area_campo = num_colectores * longitud_colector * apertura_colector
    st.sidebar.metric("Área del campo solar", f"{area_campo/1000:.1f} km²")
else:  # Fresnel
    num_modulos = st.sidebar.slider("Número de módulos", 50, 300, 150)
    longitud_modulo = st.sidebar.slider("Longitud por módulo (m)", 50, 200, 100)
    apertura_modulo = st.sidebar.slider("Apertura del módulo (m)", 5, 20, 16)
    area_campo = num_modulos * longitud_modulo * apertura_modulo
    st.sidebar.metric("Área del campo solar", f"{area_campo/1000:.1f} km²")

# Múltiplo solar
multiplo_solar = st.sidebar.slider("Múltiplo solar", 1.0, 3.0, 1.8, 0.1)

# Cargar datos de resultados CSP (usamos los resultados de prueba como ejemplo)
@st.cache_data
def cargar_datos_csp():
    try:
        resultados = pd.read_csv("CSP/sunaicl-solartherm/tests/results.csv", header=None)
        # Asignar nombres a las columnas
        resultados.columns = ["Parámetros", "Energía_Anual_MWh", "LCOE_USD_MWh", "Factor_Capacidad", "Ingresos_USD"]
        return resultados
    except Exception as e:
        st.error(f"Error al cargar datos CSP: {e}")
        # Generar datos simulados si no se pueden cargar los reales
        return pd.DataFrame({
            "Parámetros": [f"Sim_{i}" for i in range(10)],
            "Energía_Anual_MWh": np.random.uniform(500000, 600000, 10),
            "LCOE_USD_MWh": np.random.uniform(130, 150, 10),
            "Factor_Capacidad": np.random.uniform(60, 70, 10),
            "Ingresos_USD": np.random.uniform(47000000, 48000000, 10)
        })

# Función para generar datos de producción diaria
def generar_datos_produccion(tipo_planta, potencia_nominal, multiplo_solar, dia_anio=1):
    # Simulación simplificada basada en los parámetros
    horas = list(range(24))
    
    # Patrones de irradiancia (aproximados)
    if 1 <= dia_anio <= 90 or 270 <= dia_anio <= 365:  # Invierno
        irradiancia_max = 750
        horas_sol = 10
    else:  # Verano
        irradiancia_max = 950
        horas_sol = 14
    
    # Generar datos de irradiancia
    irradiancia = []
    for h in horas:
        if h < (12 - horas_sol/2) or h > (12 + horas_sol/2):
            irradiancia.append(0)
        else:
            # Curva de campana para la irradiancia diaria
            hora_rel = (h - (12 - horas_sol/2)) / horas_sol
            irradiancia.append(irradiancia_max * np.sin(np.pi * hora_rel))
    
    # Calcular producción según tipo de planta
    potencia = []
    temp_campo = []
    temp_almacenamiento = []
    estado_almacenamiento = []
    nivel_almacenamiento = [50]  # Comenzar con 50% de almacenamiento
    
    # Eficiencias según tipo
    if tipo_planta == "Torre Solar":
        eff_optica = 0.65
        eff_termica = 0.95
    elif tipo_planta == "Colectores Cilindro-Parabólicos":
        eff_optica = 0.70
        eff_termica = 0.90
    else:  # Fresnel
        eff_optica = 0.60
        eff_termica = 0.85
    
    for h, irrad in enumerate(irradiancia):
        # Temperatura del campo
        if irrad > 0:
            t_campo = 400 + irrad/1000 * 200  # Aproximación simplificada
        else:
            t_campo = 290
        temp_campo.append(t_campo)
        
        # Potencia térmica recibida (MW)
        pot_termica = irrad * area_campo * eff_optica * eff_termica / 1e6
        
        # Potencia eléctrica potencial (MW)
        pot_electrica_max = min(pot_termica * eficiencia_ciclo, potencia_nominal)
        
        # Lógica de almacenamiento
        if pot_termica > potencia_nominal / eficiencia_ciclo:
            # Hay exceso, cargar almacenamiento
            exceso = pot_termica - potencia_nominal / eficiencia_ciclo
            incremento_nivel = exceso * 100 / (volumen_almacenamiento * 0.3)  # Aproximación muy simplificada
            nuevo_nivel = min(nivel_almacenamiento[-1] + incremento_nivel, 100)
            pot_electrica = potencia_nominal
            estado = "Generando + Cargando"
        elif pot_termica > 0:
            # Generación directa
            pot_electrica = pot_electrica_max
            nuevo_nivel = nivel_almacenamiento[-1]
            estado = "Generando"
        elif nivel_almacenamiento[-1] > 5:
            # Usar almacenamiento
            pot_electrica = potencia_nominal
            decremento_nivel = potencia_nominal * 100 / (volumen_almacenamiento * 0.3)  # Aproximación simplificada
            nuevo_nivel = max(nivel_almacenamiento[-1] - decremento_nivel, 0)
            estado = "Descargando"
        else:
            # Sin sol y sin almacenamiento
            pot_electrica = 0
            nuevo_nivel = nivel_almacenamiento[-1]
            estado = "Parado"
        
        potencia.append(pot_electrica)
        nivel_almacenamiento.append(nuevo_nivel)
        estado_almacenamiento.append(estado)
        
        # Temperatura del almacenamiento
        if nuevo_nivel > 0:
            t_almacenamiento = temperatura_sales_calientes - (100 - nuevo_nivel) * (temperatura_sales_calientes - temperatura_sales_frias) / 100
        else:
            t_almacenamiento = temperatura_sales_frias
        temp_almacenamiento.append(t_almacenamiento)
    
    # Eliminar el valor extra del nivel de almacenamiento (se añadió uno inicial)
    nivel_almacenamiento = nivel_almacenamiento[1:]
    
    return {
        'Hora': horas,
        'Irradiancia': irradiancia,
        'Potencia_MW': potencia,
        'Temperatura_Campo': temp_campo,
        'Temperatura_Almacenamiento': temp_almacenamiento,
        'Nivel_Almacenamiento': nivel_almacenamiento,
        'Estado': estado_almacenamiento
    }

# Función para simular datos anuales
def simular_datos_anuales(tipo_planta, potencia_nominal, multiplo_solar):
    meses = ["Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"]
    dias_por_mes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    energía_mensual = []
    factor_capacidad_mensual = []
    ingresos_mensual = []
    
    for mes, dias in enumerate(dias_por_mes):
        dia_anio = sum(dias_por_mes[:mes]) + 15  # día representativo del mes
        datos_dia = generar_datos_produccion(tipo_planta, potencia_nominal, multiplo_solar, dia_anio)
        energia_dia = sum(datos_dia['Potencia_MW'])  # MWh por el día representativo
        energia_mes = energia_dia * dias  # MWh en el mes
        
        factor_cap = energia_dia / (potencia_nominal * 24) * 100  # %
        ingresos = energia_mes * 80  # USD (precio aproximado de 80 USD/MWh)
        
        energía_mensual.append(energia_mes)
        factor_capacidad_mensual.append(factor_cap)
        ingresos_mensual.append(ingresos)
    
    return {
        'Mes': meses,
        'Energía_MWh': energía_mensual,
        'Factor_Capacidad': factor_capacidad_mensual,
        'Ingresos_USD': ingresos_mensual
    }

# Cargar datos
try:
    resultados_csp = cargar_datos_csp()
    
    # Definir las pestañas del dashboard
    tabs = st.tabs(["Monitoreo en tiempo real", "Análisis de rendimiento", "Simulación anual", "Comparativa"])
    
    with tabs[0]:  # Monitoreo en tiempo real
        st.header("Monitoreo en tiempo real")
        
        # Selección de día del año
        dia_anio = st.slider("Día del año", 1, 365, 172)
        
        # Generar datos para el día seleccionado
        datos_dia = generar_datos_produccion(tipo_planta, potencia_nominal, multiplo_solar, dia_anio)
        
        # Crear dataframe
        df_dia = pd.DataFrame(datos_dia)
        
        # Visualizar estado actual
        hora_actual = st.select_slider("Hora del día", options=range(24), value=12)
        
        # Mostrar métricas actuales
        col1, col2, col3, col4 = st.columns(4)
        
        with col1:
            st.metric("Potencia actual", f"{df_dia.iloc[hora_actual]['Potencia_MW']:.1f} MW")
        with col2:
            st.metric("Irradiancia", f"{df_dia.iloc[hora_actual]['Irradiancia']:.0f} W/m²")
        with col3:
            st.metric("Nivel almacenamiento", f"{df_dia.iloc[hora_actual]['Nivel_Almacenamiento']:.1f}%")
        with col4:
            st.metric("Estado", df_dia.iloc[hora_actual]['Estado'])
        
        # Gráficos
        col1, col2 = st.columns(2)
        
        with col1:
            # Gráfico de potencia vs hora
            fig = px.line(df_dia, x='Hora', y='Potencia_MW', 
                         title=f"Potencia generada - Día {dia_anio}")
            fig.add_scatter(x=[hora_actual], y=[df_dia.iloc[hora_actual]['Potencia_MW']], 
                           mode='markers', marker=dict(size=12, color='red'), name='Actual')
            st.plotly_chart(fig, use_container_width=True)
        
        with col2:
            # Gráfico de nivel de almacenamiento
            fig = px.line(df_dia, x='Hora', y='Nivel_Almacenamiento',
                         title=f"Nivel de almacenamiento térmico - Día {dia_anio}")
            fig.add_scatter(x=[hora_actual], y=[df_dia.iloc[hora_actual]['Nivel_Almacenamiento']], 
                           mode='markers', marker=dict(size=12, color='red'), name='Actual')
            st.plotly_chart(fig, use_container_width=True)
        
        # Gráficos de temperatura
        col1, col2 = st.columns(2)
        
        with col1:
            # Gráfico de temperatura del campo solar
            fig = px.line(df_dia, x='Hora', y='Temperatura_Campo',
                         title=f"Temperatura del campo solar - Día {dia_anio}")
            fig.add_scatter(x=[hora_actual], y=[df_dia.iloc[hora_actual]['Temperatura_Campo']], 
                           mode='markers', marker=dict(size=12, color='red'), name='Actual')
            st.plotly_chart(fig, use_container_width=True)
        
        with col2:
            # Gráfico de temperatura del almacenamiento
            fig = px.line(df_dia, x='Hora', y='Temperatura_Almacenamiento',
                         title=f"Temperatura del almacenamiento - Día {dia_anio}")
            fig.add_scatter(x=[hora_actual], y=[df_dia.iloc[hora_actual]['Temperatura_Almacenamiento']], 
                           mode='markers', marker=dict(size=12, color='red'), name='Actual')
            st.plotly_chart(fig, use_container_width=True)
        
        # Visualización en forma de tabla
        st.subheader("Datos horarios")
        st.dataframe(df_dia)
        
    with tabs[1]:  # Análisis de rendimiento
        st.header("Análisis de rendimiento")
        
        # Usar los datos de SolarTherm si están disponibles
        if not resultados_csp.empty:
            # Mostrar los mejores resultados
            st.subheader("Mejores configuraciones simuladas con SolarTherm")
            
            # Ordenar por factor de capacidad
            mejores_fc = resultados_csp.sort_values(by='Factor_Capacidad', ascending=False).head(5)
            st.write("Mejores por factor de capacidad:")
            st.dataframe(mejores_fc)
            
            # Ordenar por LCOE (menor es mejor)
            mejores_lcoe = resultados_csp.sort_values(by='LCOE_USD_MWh', ascending=True).head(5)
            st.write("Mejores por LCOE (USD/MWh):")
            st.dataframe(mejores_lcoe)
            
            # Gráfico de dispersión
            st.subheader("Relación entre Factor de Capacidad y LCOE")
            fig = px.scatter(resultados_csp, x='Factor_Capacidad', y='LCOE_USD_MWh',
                           title="Factor de Capacidad vs LCOE",
                           color='Energía_Anual_MWh', size='Ingresos_USD',
                           hover_data=['Parámetros'])
            st.plotly_chart(fig, use_container_width=True)
        
        # Mostrar métricas clave para la configuración actual
        st.subheader("Métricas estimadas para la configuración actual")
        
        # Calcular métricas aproximadas
        datos_anuales = simular_datos_anuales(tipo_planta, potencia_nominal, multiplo_solar)
        energia_anual = sum(datos_anuales['Energía_MWh'])
        factor_capacidad = sum(datos_anuales['Factor_Capacidad']) / 12
        ingresos_anuales = sum(datos_anuales['Ingresos_USD'])
        
        # Cálculo aproximado del LCOE
        inversion_estimada = potencia_nominal * 5e6  # USD (aprox 5M USD/MW)
        vida_util = 25  # años
        om_anual = potencia_nominal * 80000  # USD (aprox 80k USD/MW)
        lcoe = (inversion_estimada/vida_util + om_anual) / energia_anual  # USD/MWh
        
        # Métricas
        col1, col2, col3, col4 = st.columns(4)
        col1.metric("Energía anual", f"{energia_anual/1000:.2f} GWh")
        col2.metric("Factor de capacidad", f"{factor_capacidad:.2f}%")
        col3.metric("LCOE estimado", f"{lcoe:.2f} USD/MWh")
        col4.metric("Ingresos anuales", f"{ingresos_anuales/1e6:.2f} M USD")
        
    with tabs[2]:  # Simulación anual
        st.header("Simulación anual")
        
        # Simular datos anuales
        datos_anuales = simular_datos_anuales(tipo_planta, potencia_nominal, multiplo_solar)
        df_anual = pd.DataFrame(datos_anuales)
        
        # Gráficos de producción mensual
        fig = px.bar(df_anual, x='Mes', y='Energía_MWh',
                   title=f"Producción mensual - Planta {tipo_planta} {potencia_nominal} MW")
        st.plotly_chart(fig, use_container_width=True)
        
        # Gráfico de factor de capacidad mensual
        fig = px.line(df_anual, x='Mes', y='Factor_Capacidad',
                    title="Factor de capacidad mensual", markers=True)
        st.plotly_chart(fig, use_container_width=True)
        
        # Gráfico de ingresos mensuales
        fig = px.bar(df_anual, x='Mes', y='Ingresos_USD',
                   title="Ingresos mensuales (USD)")
        st.plotly_chart(fig, use_container_width=True)
        
        # Tabla de datos mensuales
        st.subheader("Datos mensuales detallados")
        st.dataframe(df_anual)
        
    with tabs[3]:  # Comparativa con otras tecnologías
        st.header("Comparativa con otras tecnologías")
        
        # Datos comparativos de tecnologías de energía solar
        tecnologias = ["Torre Solar", "Cilindro-Parabólicos", "Fresnel", "Fotovoltaica", "FV + Almacenamiento"]
        
        # Factor de capacidad
        fc = [65, 55, 45, 30, 40]
        
        # LCOE (USD/MWh)
        lcoe = [140, 150, 160, 50, 120]
        
        # Horas de almacenamiento
        almacenamiento = [16, 10, 8, 0, 4]
        
        # Temperatura de operación (°C)
        temperatura = [565, 450, 380, 60, 60]
        
        # Gráficos comparativos
        col1, col2 = st.columns(2)
        
        with col1:
            # Factor de capacidad
            fig = px.bar(x=tecnologias, y=fc, 
                       title="Factor de capacidad (%)",
                       labels={'x': 'Tecnología', 'y': 'Factor de capacidad (%)'})
            st.plotly_chart(fig, use_container_width=True)
            
            # Horas de almacenamiento
            fig = px.bar(x=tecnologias, y=almacenamiento,
                       title="Capacidad de almacenamiento (horas)",
                       labels={'x': 'Tecnología', 'y': 'Horas'})
            st.plotly_chart(fig, use_container_width=True)
        
        with col2:
            # LCOE
            fig = px.bar(x=tecnologias, y=lcoe,
                       title="LCOE (USD/MWh)",
                       labels={'x': 'Tecnología', 'y': 'LCOE (USD/MWh)'})
            st.plotly_chart(fig, use_container_width=True)
            
            # Temperatura
            fig = px.bar(x=tecnologias, y=temperatura,
                       title="Temperatura de operación (°C)",
                       labels={'x': 'Tecnología', 'y': 'Temperatura (°C)'})
            st.plotly_chart(fig, use_container_width=True)
        
        # Gráfico de radar para comparación multidimensional
        fig = go.Figure()
        
        # Normalizar valores para el gráfico de radar
        fc_norm = [v/max(fc)*100 for v in fc]
        lcoe_norm = [100-v/max(lcoe)*100 for v in lcoe]  # Invertido (menor es mejor)
        alm_norm = [v/max(almacenamiento)*100 for v in almacenamiento]
        temp_norm = [v/max(temperatura)*100 for v in temperatura]
        
        categories = ['Factor de capacidad', 'Competitividad de costos', 'Almacenamiento', 'Temperatura']
        
        for i, tec in enumerate(tecnologias):
            fig.add_trace(go.Scatterpolar(
                r=[fc_norm[i], lcoe_norm[i], alm_norm[i], temp_norm[i]],
                theta=categories,
                fill='toself',
                name=tec
            ))
        
        fig.update_layout(
            polar=dict(
                radialaxis=dict(
                    visible=True,
                    range=[0, 100]
                )),
            showlegend=True,
            title="Comparación multidimensional de tecnologías solares"
        )
        
        st.plotly_chart(fig, use_container_width=True)
        
except Exception as e:
    st.error(f"Error en el dashboard: {e}")
    st.info("Verifique que los archivos necesarios estén disponibles y en la ubicación correcta.") 