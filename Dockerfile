# Usa una imagen base de Python (basada en Debian)
FROM python:3.9-slim-bullseye

# Evitar preguntas interactivas durante la instalación
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias del sistema: git (para clonar SolarTherm), locales (para idioma), wget y gnupg (para repo OM)
RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    locales \
    wget \
    gnupg \
    ca-certificates \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Configurar locale español
RUN sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=es_ES.UTF-8
ENV LANG es_ES.UTF-8
ENV LANGUAGE es_ES:es
ENV LC_ALL es_ES.UTF-8

# Instalar OpenModelica
RUN apt-get update && apt-get install -y --no-install-recommends software-properties-common && \
    wget -qO - https://build.openmodelica.org/apt/openmodelica.asc | apt-key add - && \
    echo "deb https://build.openmodelica.org/apt $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/openmodelica.list && \
    apt-get update && apt-get install -y --no-install-recommends openmodelica && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Establecer directorio de trabajo
WORKDIR /app

# Copiar archivo de requerimientos e instalar dependencias Python
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Clonar SolarTherm
RUN git clone https://github.com/SolarTherm/SolarTherm.git /opt/solartherm

# Copiar el resto del código de la aplicación y los datos
# Asegúrate de que los archivos CSV y .motab estén en una carpeta 'data' en tu repo
COPY . /app

# Exponer el puerto de Streamlit
EXPOSE 8501

# Comando para ejecutar la aplicación
CMD ["streamlit", "run", "digital_twin_dashboard.py"] 