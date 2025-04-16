import os
import pandas as pd
import numpy as np

def verificar_archivo_meteo():
    # Rutas posibles para el archivo
    posibles_rutas = [
        "/home/cparrado/digitaltwins/CSP/Weather/tmy_acc_mod.motab",  # Ruta local específica
        "/home/cparrado/digitaltwins/CSP/Weather/tmy_acc_mod.motab",  # Ruta local específica
        "CSP/Weather/tmy_acc_mod.motab",  # Ruta relativa local
        "CSP/sunaicl-solartherm/SolarTherm/Data/Weather/tmy_acc_mod.motab",
        "/home/cparrado/digitaltwins/CSP/sunaicl-solartherm/SolarTherm/Data/Weather/tmy_acc_mod.motab",
        "/home/cparrado/.openmodelica/libraries/SolarTherm/Data/Weather/tmy_acc_mod.motab",
        "/home/cparrado/solartherm/SolarTherm/Data/Weather/tmy_acc_mod.motab"
    ]
    
    print(f"Directorio actual: {os.getcwd()}")
    
    # Buscar archivo en las rutas disponibles
    ruta_archivo = None
    for ruta in posibles_rutas:
        print(f"Probando ruta: {ruta}")
        if os.path.exists(ruta):
            ruta_archivo = ruta
            print(f"¡Archivo encontrado en: {ruta}!")
            break
    
    if ruta_archivo is None:
        print("No se encontró el archivo en ninguna de las rutas predefinidas.")
        return
    
    # Intentar leer el archivo
    try:
        print("\nIntentando leer el archivo...")
        with open(ruta_archivo, 'r') as f:
            # Leer las primeras líneas para confirmar formato
            lineas = []
            for i in range(10):
                lineas.append(f.readline().strip())
        
        print("\nPrimeras líneas del archivo:")
        for i, linea in enumerate(lineas):
            print(f"{i+1}: {linea}")
        
        print("\nIntentando procesar el archivo como en el dashboard...")
        # Código similar al del dashboard para procesar el archivo
        datos = []
        columnas = None
        n_columnas = 0
        
        with open(ruta_archivo, 'r') as f:
            lineas = f.readlines()
            
            # Procesar encabezado para obtener el formato
            if len(lineas) > 1 and "double data" in lineas[1]:
                info_dims = lineas[1].strip().split('(')[1].split(')')[0].split(',')
                n_filas = int(info_dims[0])
                n_columnas = int(info_dims[1])
                print(f"Formato detectado: {n_filas} filas, {n_columnas} columnas")
                
                # Leer primeras 10 filas de datos
                for i in range(2, min(12, len(lineas))):
                    valores = lineas[i].strip().replace('\n', '').split(',')
                    valores_limpios = []
                    for v in valores:
                        if v.strip():
                            try:
                                valores_limpios.append(float(v.strip()))
                            except ValueError:
                                valores_limpios.append(0.0)
                    
                    if len(valores_limpios) >= n_columnas:
                        datos.append(valores_limpios[:n_columnas])
                
                print(f"\nDatos procesados correctamente. Filas leídas: {len(datos)}")
                print("Primeros valores de la primera fila:", datos[0][:5])
                
                columnas = ['tiempo', 'GHI', 'DNI', 'DHI', 'Tamb', 'Tdew', 'RH', 'Pres', 'Wind', 'Albedo', 'Precipitacion']
                if len(columnas) > n_columnas:
                    columnas = columnas[:n_columnas]
                
                print(f"Columnas detectadas: {columnas}")
                print("\nVerificación completada con éxito.")
            else:
                print("Formato no reconocido. No se pudo procesar el archivo.")
    
    except Exception as e:
        print(f"Error al procesar el archivo: {e}")

if __name__ == "__main__":
    verificar_archivo_meteo() 