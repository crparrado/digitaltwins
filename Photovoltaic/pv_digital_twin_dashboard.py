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
    page_title="Gemelo Digital - Planta Fotovoltaica Antofagasta 1MW",
    page_icon="☀️",
    layout="wide"
)

# Título y descripción
st.title("☀️ Gemelo Digital - Planta Fotovoltaica 1MW")
st.markdown("Dashboard interactivo para monitorizar y simular el rendimiento de una planta fotovoltaica de 1MW en Antofagasta, Chile")

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
            if st.button("Iniciar/Detener simulación en tiempo real"):
                # Valores iniciales
                potencia_actual = 0
                temperatura_panel_actual = datos_dia.iloc[0]['Tdry']
                irradiancia_actual = datos_dia.iloc[0]['GHI']
                eficiencia_actual = eficiencia_referencia
                
                # Datos para gráficos
                horas = list(range(24))
                potencias = [0] * 24
                temperaturas = [0] * 24
                
                # Placeholder para métricas
                col1, col2, col3, col4 = metrics_row.columns(4)
                
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
    
    with tabs[1]:  # Análisis histórico
        st.header("Análisis histórico")
        
        # Selección de rango de fechas
        col1, col2 = st.columns(2)
        with col1:
            mes_inicio = st.selectbox("Mes de inicio:", 
                                     options=list(range(1, 13)),
                                     format_func=lambda x: ["Enero", "Febrero", "Marzo", "Abril", 
                                                          "Mayo", "Junio", "Julio", "Agosto", 
                                                          "Septiembre", "Octubre", "Noviembre", 
                                                          "Diciembre"][x-1])
        with col2:
            mes_fin = st.selectbox("Mes de fin:", 
                                  options=list(range(1, 13)),
                                  index=11,
                                  format_func=lambda x: ["Enero", "Febrero", "Marzo", "Abril", 
                                                       "Mayo", "Junio", "Julio", "Agosto", 
                                                       "Septiembre", "Octubre", "Noviembre", 
                                                       "Diciembre"][x-1])
        
        # Filtrar datos para el rango seleccionado
        datos_filtrados = datos_antofagasta[
            (datos_antofagasta['Month'] >= mes_inicio) & 
            (datos_antofagasta['Month'] <= mes_fin)
        ]
        
        if len(datos_filtrados) == 0:
            st.warning("No hay datos para el período seleccionado.")
        else:
            # Procesar datos mensuales
            datos_mensuales = []
            energia_mensual = []
            
            for mes in range(mes_inicio, mes_fin + 1):
                datos_mes = datos_antofagasta[datos_antofagasta['Month'] == mes]
                
                if len(datos_mes) > 0:
                    # Calcular producción para cada hora
                    energia_total_mes = 0
                    for i in range(len(datos_mes)):
                        irradiancia = datos_mes.iloc[i]['GHI']
                        temp_ambiente = datos_mes.iloc[i]['Tdry']
                        
                        potencia, _, _ = calcular_produccion(
                            area_paneles, irradiancia, temp_ambiente, 
                            eficiencia_referencia, factor_rendimiento, potencia_pico, coef_temperatura
                        )
                        
                        # Acumular energía (kWh)
                        energia_total_mes += potencia  # kWh para 1 hora
                    
                    nombre_mes = ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
                                 "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"][mes-1]
                    datos_mensuales.append(nombre_mes)
                    energia_mensual.append(energia_total_mes)
            
            # Gráfico de energía mensual
            fig = px.bar(x=datos_mensuales, y=energia_mensual,
                         labels={"x": "Mes", "y": "Energía (kWh)"},
                         title=f"Producción mensual de energía - Planta {potencia_pico/1000:.1f} MW")
            st.plotly_chart(fig, use_container_width=True)
            
            # Estadísticas generales
            energia_total = sum(energia_mensual)
            factor_capacidad = energia_total / (potencia_pico * len(datos_filtrados))
            horas_equivalentes = energia_total / potencia_pico
            
            col1, col2, col3 = st.columns(3)
            col1.metric("Energía total generada", f"{energia_total:.2f} kWh")
            col2.metric("Factor de capacidad", f"{factor_capacidad*100:.2f}%")
            col3.metric("Horas equivalentes", f"{horas_equivalentes:.0f} h")
            
    with tabs[2]:  # Predicción
        st.header("Predicción a corto plazo")
        
        # Simular predicciones meteorológicas para las próximas 24 horas
        ahora = datetime.now()
        hora_actual = ahora.hour
        
        # Obtener datos del día actual en el dataset
        dia_actual = 1  # Por defecto usar el primer día del mes de enero
        mes_actual = 1
        
        # Opción para seleccionar el día para la predicción
        dia_pred = st.selectbox("Seleccionar día de referencia:", 
                                options=list(range(1, 32)),
                                index=0)
        mes_pred = st.selectbox("Seleccionar mes de referencia:",
                               options=list(range(1, 13)),
                               index=0,
                               format_func=lambda x: ["Enero", "Febrero", "Marzo", "Abril", 
                                                     "Mayo", "Junio", "Julio", "Agosto", 
                                                     "Septiembre", "Octubre", "Noviembre", 
                                                     "Diciembre"][x-1])
        
        datos_prediccion = datos_antofagasta[(datos_antofagasta['Day'] == dia_pred) & 
                                            (datos_antofagasta['Month'] == mes_pred)]
        
        if len(datos_prediccion) == 0:
            st.warning(f"No hay datos para el día {dia_pred}/{mes_pred}.")
        else:
            # Calcular la producción prevista
            horas_pred = list(range(24))
            irradiancia_pred = [datos_prediccion.iloc[h]['GHI'] if h < len(datos_prediccion) else 0 for h in range(24)]
            temp_ambiente_pred = [datos_prediccion.iloc[h]['Tdry'] if h < len(datos_prediccion) else 0 for h in range(24)]
            potencia_pred = []
            temperatura_panel_pred = []
            
            for h in range(24):
                pot, temp_panel, _ = calcular_produccion(
                    area_paneles, irradiancia_pred[h], temp_ambiente_pred[h], 
                    eficiencia_referencia, factor_rendimiento, potencia_pico, coef_temperatura
                )
                potencia_pred.append(pot)
                temperatura_panel_pred.append(temp_panel)
            
            # Crear DataFrame para la visualización
            df_pred = pd.DataFrame({
                'Hora': horas_pred,
                'Irradiancia (W/m²)': irradiancia_pred,
                'Temperatura ambiente (°C)': temp_ambiente_pred,
                'Temperatura panel (°C)': temperatura_panel_pred,
                'Potencia (kW)': potencia_pred
            })
            
            # Visualizar predicción
            col1, col2 = st.columns(2)
            
            with col1:
                fig = px.line(df_pred, x='Hora', y='Potencia (kW)', 
                             title=f"Predicción de potencia - {dia_pred}/{mes_pred}")
                st.plotly_chart(fig, use_container_width=True)
            
            with col2:
                fig = px.line(df_pred, x='Hora', y=['Temperatura ambiente (°C)', 'Temperatura panel (°C)'],
                             title=f"Predicción de temperaturas - {dia_pred}/{mes_pred}")
                st.plotly_chart(fig, use_container_width=True)
            
            # Energía total prevista para ese día
            energia_dia = sum(potencia_pred)
            st.metric("Energía total prevista para el día", f"{energia_dia:.2f} kWh")
            
            # Tabla de datos
            st.subheader("Datos horarios previstos")
            st.dataframe(df_pred)
    
    with tabs[3]:  # Rendimiento
        st.header("Análisis de rendimiento")
        
        # Histograma de distribución de potencia
        st.subheader("Distribución de potencia generada")
        
        # Calcular la potencia para todas las horas disponibles
        potencias_todas = []
        
        for i in range(len(datos_antofagasta)):
            irradiancia = datos_antofagasta.iloc[i]['GHI']
            temp_ambiente = datos_antofagasta.iloc[i]['Tdry']
            
            potencia, _, _ = calcular_produccion(
                area_paneles, irradiancia, temp_ambiente,
                eficiencia_referencia, factor_rendimiento, potencia_pico, coef_temperatura
            )
            
            potencias_todas.append(potencia)
        
        # Histograma de potencia
        fig = px.histogram(potencias_todas, nbins=50,
                          labels={"value": "Potencia (kW)", "count": "Frecuencia"},
                          title="Distribución de potencia generada")
        st.plotly_chart(fig, use_container_width=True)
        
        # Calcular horas de producción por rangos
        horas_plena_potencia = sum(1 for p in potencias_todas if p > 0.9 * potencia_pico)
        horas_media_potencia = sum(1 for p in potencias_todas if p > 0.5 * potencia_pico and p <= 0.9 * potencia_pico)
        horas_baja_potencia = sum(1 for p in potencias_todas if p > 0 and p <= 0.5 * potencia_pico)
        horas_sin_produccion = sum(1 for p in potencias_todas if p == 0)
        
        # Gráfico de distribución de horas
        labels = ['Plena potencia (>90%)', 'Media potencia (50-90%)', 
                 'Baja potencia (<50%)', 'Sin producción']
        values = [horas_plena_potencia, horas_media_potencia, horas_baja_potencia, horas_sin_produccion]
        
        fig = px.pie(values=values, names=labels,
                    title="Distribución de horas por nivel de potencia")
        st.plotly_chart(fig, use_container_width=True)
        
        # KPIs de rendimiento
        energia_total_anual = sum(potencias_todas)
        factor_capacidad = energia_total_anual / (potencia_pico * len(potencias_todas))
        horas_equivalentes = energia_total_anual / potencia_pico
        
        col1, col2, col3 = st.columns(3)
        col1.metric("Energía anual", f"{energia_total_anual:.2f} kWh")
        col2.metric("Factor de capacidad", f"{factor_capacidad*100:.2f}%")
        col3.metric("Horas equivalentes", f"{horas_equivalentes:.0f} h")

except Exception as e:
    st.error(f"Error al cargar los datos: {e}")
    st.info("Asegúrate de que el archivo antofagasta.csv está en la ubicación correcta.") 