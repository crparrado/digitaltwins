#!/usr/bin/env python3
import os
import shutil
import sys

def configurar_datos_meteorologicos():
    """
    Copia los archivos meteorológicos de SolarTherm a la ubicación 
    esperada por el dashboard.
    """
    print("Configurando archivos meteorológicos para el dashboard CSP...")
    
    # Rutas origen (directorio SolarTherm)
    ruta_origen = "/home/cparrado/solartherm/SolarTherm/Data/Weather/tmy_acc_mod.motab"
    
    # Ruta destino (directorio del dashboard)
    directorio_destino = "/home/cparrado/digitaltwins/CSP/Weather"
    ruta_destino = os.path.join(directorio_destino, "tmy_acc_mod.motab")
    
    # Crear directorio si no existe
    if not os.path.exists(directorio_destino):
        print(f"Creando directorio: {directorio_destino}")
        try:
            os.makedirs(directorio_destino, exist_ok=True)
        except Exception as e:
            print(f"Error al crear directorio: {e}")
            return False
    
    # Copiar archivo si existe
    if os.path.exists(ruta_origen):
        print(f"Copiando archivo de: {ruta_origen} a {ruta_destino}")
        try:
            shutil.copy2(ruta_origen, ruta_destino)
            # Establecer permisos de lectura para todos
            os.chmod(ruta_destino, 0o644)
            print("Archivo copiado correctamente y permisos establecidos.")
            return True
        except Exception as e:
            print(f"Error al copiar archivo: {e}")
            return False
    else:
        print(f"Error: No se encontró el archivo origen en {ruta_origen}")
        return False

if __name__ == "__main__":
    exito = configurar_datos_meteorologicos()
    if exito:
        print("Configuración completada con éxito.")
        sys.exit(0)
    else:
        print("Error en la configuración de archivos meteorológicos.")
        sys.exit(1) 