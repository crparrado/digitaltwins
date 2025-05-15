# Imagen base: Ubuntu 20.04 LTS
FROM --platform=linux/amd64 ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Paquetes básicos + utilidades
RUN apt-get update && apt-get install -y \
        build-essential git cmake curl \
        python3-venv python3-pip \
        wget ca-certificates gnupg lsb-release \
        software-properties-common \
        sudo \
        scons \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Actualizar pip y setuptools
RUN python3 -m pip install --upgrade pip setuptools wheel

# Instalar dependencias de Python
RUN python3 -m pip install \
    scipy \
    matplotlib \
    DyMat \
    pyswarm \
    cma \
    pytest \
    solsticepy \
    openpyxl \
    distro \
    colorama

# Install prerequisites
RUN apt-get update && apt-get install -y \
    ca-certificates curl gnupg lsb-release

# Add OpenModelica GPG key
RUN curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc | gpg --dearmor -o /usr/share/keyrings/openmodelica-keyring.gpg

# Add OpenModelica 1.18.0 repository
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] https://build.openmodelica.org/omc/builds/linux/releases/1.18.0/ $(lsb_release -cs) release" > /etc/apt/sources.list.d/openmodelica.list

# Install OpenModelica and libraries
RUN apt-get update && apt-get install -y openmodelica omlib-modelica-3.2.3 omlib-modelicareference

# Verify installation
RUN omc --version

# Crea el usuario que usará VS Code dentro del contenedor
RUN useradd -m dev && \
    echo "dev ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER dev
WORKDIR /workspaces

# (Opcional) clona el repo la primera vez si el volumen aún está vacío
RUN git clone https://github.com/arfontalvoANU/sunaicl-solartherm.git || true

# Default command
CMD ["/bin/bash"]
