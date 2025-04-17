#!/usr/bin/env python3
import os
import pandas as pd
import numpy as np

def analizar_archivo_meteo():
    """Analiza y corrige el archivo meteorológico para asegurar su correcta carga"""
    
    # Ruta del archivo original
    ruta_original = "/home/cparrado/solartherm/SolarTherm/Data/Weather/tmy_acc_mod.motab"
    ruta_destino = "/home/cparrado/digitaltwins/CSP/Weather/tmy_acc_mod.motab"
    ruta_corregida = "/home/cparrado/digitaltwins/CSP/Weather/tmy_acc_mod_fixed.motab"
    
    print(f"Analizando archivo: {ruta_original}")
    
    if not os.path.exists(ruta_original):
        print(f"Error: El archivo original no existe: {ruta_original}")
        return
    
    # Leer el archivo original para analizar
    try:
        with open(ruta_original, 'r') as f:
            contenido = f.read()
            lineas = contenido.splitlines()
            
        print(f"Archivo leído correctamente. {len(lineas)} líneas encontradas.")
        
        # Analizar las primeras líneas
        print("\nPrimeras 5 líneas del archivo:")
        for i, linea in enumerate(lineas[:5]):
            print(f"{i+1}: {linea}")
        
        # Verificar la cabecera
        if len(lineas) > 1 and "double data" in lineas[1]:
            cabecera = lineas[1]
            print(f"\nCabecera detectada: '{cabecera}'")
            
            # Extraer dimensiones
            try:
                dimensiones = cabecera.split('(')[1].split(')')[0]
                filas, columnas = map(int, dimensiones.split(','))
                print(f"Dimensiones: {filas} filas, {columnas} columnas")
            except Exception as e:
                print(f"Error al extraer dimensiones: {e}")
                return
            
            # Verificar datos
            lineas_datos = lineas[2:2+filas]
            print(f"\nVerificando {len(lineas_datos)} líneas de datos...")
            
            # Identificar problemas comunes
            problemas = []
            lineas_corregidas = []
            
            for i, linea in enumerate(lineas_datos):
                num_linea = i + 3  # Línea real en el archivo (1-indexed)
                valores = linea.split(',')
                
                # Verificar número de valores vs número esperado de columnas
                if len(valores) != columnas:
                    problemas.append(f"Línea {num_linea}: Se esperaban {columnas} valores, se encontraron {len(valores)}")
                
                # Verificar valores no numéricos
                for j, valor in enumerate(valores):
                    try:
                        float(valor.strip())
                    except ValueError:
                        problemas.append(f"Línea {num_linea}, Columna {j+1}: Valor no numérico '{valor}'")
                
                # Limpiar línea (eliminar espacios, caracteres extraños, etc.)
                valores_limpios = []
                for valor in valores:
                    valor = valor.strip()
                    try:
                        valor_float = float(valor)
                        valores_limpios.append(f"{valor_float}")
                    except ValueError:
                        if valor:
                            valores_limpios.append("0.0")  # Reemplazar valores no numéricos con 0
                        else:
                            valores_limpios.append("0.0")  # Reemplazar valores vacíos con 0
                
                linea_corregida = ", ".join(valores_limpios)
                lineas_corregidas.append(linea_corregida)
            
            # Mostrar resumen de problemas
            if problemas:
                print(f"\nSe encontraron {len(problemas)} problemas:")
                for p in problemas[:10]:  # Mostrar solo los primeros 10 problemas
                    print(f"- {p}")
                if len(problemas) > 10:
                    print(f"  ... y {len(problemas) - 10} problemas más.")
            else:
                print("\nNo se encontraron problemas en el formato de los datos.")
            
            # Generar archivo corregido
            print(f"\nGenerando archivo corregido: {ruta_corregida}")
            with open(ruta_corregida, 'w') as f:
                # Escribir cabecera
                f.write(lineas[0] + '\n')
                f.write(lineas[1] + '\n')
                
                # Escribir datos corregidos
                for linea in lineas_corregidas:
                    f.write(linea + '\n')
            
            print(f"Archivo corregido generado correctamente.")
            print(f"Ahora, modifica el dashboard para usar: {ruta_corregida}")
        else:
            print("Error: No se encontró la cabecera 'double data' en el archivo.")
    
    except Exception as e:
        print(f"Error al analizar el archivo: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    analizar_archivo_meteo() 

