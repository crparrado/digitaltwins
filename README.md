# Digital Twins para Tecnologías de Energía Solar

Este repositorio contiene modelos de simulación (gemelos digitales) para diferentes tecnologías de energía solar, permitiendo simular el comportamiento y rendimiento de sistemas fotovoltaicos y de concentración solar.

## Estructura del Repositorio

El repositorio está organizado en dos carpetas principales:

### 1. Photovoltaic (PV)

Contiene modelos y herramientas para simular sistemas fotovoltaicos, incluyendo:

- Scripts para generar datos de producción horaria y por segundo
- Modelos para calcular la eficiencia de los paneles según temperatura
- Herramientas para visualización de producción energética
- Simulación de plantas fotovoltaicas con diferentes potencias y ubicaciones

Los scripts permiten generar simulaciones para una planta fotovoltaica de 1MW en Antofagasta, Chile, calculando su producción anual, factor de capacidad y otros parámetros relevantes.

### 2. CSP (Concentrated Solar Power)

Contiene una implementación basada en SolarTherm para modelar y simular sistemas de concentración solar, incluyendo:

- Modelos en Modelica para simular diferentes componentes de plantas CSP
- Scripts para análisis de rendimiento
- Herramientas para la optimización de parámetros operativos
- Simulaciones de diferentes configuraciones (torre solar, colectores parabólicos, etc.)

SolarTherm es un software de simulación especializado en energía solar térmica de código abierto.

## Requisitos

- Python 3.6+
- OpenModelica (para simulaciones CSP)
- Bibliotecas Python: numpy, pandas, matplotlib, scipy

## Uso

Cada carpeta contiene sus propias instrucciones y scripts para ejecutar las simulaciones correspondientes.

## Autor

Crparrado 