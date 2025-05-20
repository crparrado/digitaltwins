# Digital Twins para Sistemas Energéticos

Este repositorio contiene implementaciones de gemelos digitales para diferentes tecnologías energéticas, con un enfoque en energías renovables como Concentrated Solar Power (CSP) y Photovoltaic (PV). El proyecto se construye sobre OpenModelica y Python para simulación, optimización y visualización de resultados.

## Componentes principales

- **CSP**: Modelos de energía solar concentrada usando SolarTherm
- **Photovoltaic**: Simulación de sistemas fotovoltaicos
- **Metaheuristics**: Algoritmos de optimización para diseño y operación
- **Dashboard**: Interfaz visual para análisis de resultados

## Requisitos

- Docker (recomendado)
- OpenModelica 1.18.0
- Python 3.8+
- Dependencias específicas (gestionadas por Docker)

## Configuración rápida con Docker

### Para sistemas x86_64 (Intel/AMD)

```bash
# Clonar el repositorio
git clone https://github.com/crparrado/digitaltwins.git
cd digitaltwins

# Construir la imagen Docker
docker build -t digitaltwins-dev-image -f .devcontainer/Dockerfile .

# Ejecutar el contenedor
docker run -it -v $(pwd):/workspaces/host digitaltwins-dev-image
```

### Para sistemas ARM (Jetson, Raspberry Pi)

Modificaciones necesarias en el Dockerfile:
- Eliminar la especificación `--platform=linux/amd64`
- Verificar la disponibilidad de paquetes para ARM

Consulte la documentación específica para ARM en el directorio `.devcontainer/ARM/`.

## Estructura del repositorio

```
digitaltwins/
├── .devcontainer/         # Configuración de Docker
├── CSP/                   # Modelos de energía solar concentrada
│   └── tests/             # Tests para modelos CSP
├── Photovoltaic/          # Modelos de sistemas fotovoltaicos
├── data/                  # Datos para simulación y validación
├── metaheuristics/        # Algoritmos de optimización
└── digital_twin_dashboard.py  # Interfaz de usuario
```

## Ejecutando simulaciones

### Modelo CSP (SolarTherm)

```bash
# Dentro del contenedor Docker
cd /workspaces/sunaicl-solartherm/tests
python3 TestSimulation.py
```

Resultados esperados:
```
epy  [GWhe ]: 703.33...
lcoe [$/MWh]: 116.39...
capf [  %  ]: 80.28...
```

## Variables de entorno

- `OPENMODELICALIBRARY`: Configurada automáticamente en Docker para localizar bibliotecas de OpenModelica

## Desarrollo

Para contribuir al proyecto:

1. Cree un fork del repositorio
2. Desarrolle sus cambios en una rama nueva
3. Asegúrese de que todos los tests pasan
4. Envíe un pull request

## Licencia

Este proyecto está bajo [licencia MIT](LICENSE).

## Contacto

Para más información, contacte a los mantenedores del proyecto.

---

*Este README fue generado el 20 de mayo de 2024.*
