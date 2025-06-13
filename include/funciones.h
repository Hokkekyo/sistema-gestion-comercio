#include <string>
#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

/*
 * Archivo: funciones.h
 * Acá van solo las declaraciones de funciones.
 *
 * Es como un índice que le avisa al main qué funciones puede usar de
 * funciones.cpp. Sirve para mantener organizado el proyecto y separar bien las
 * partes.
 */

void cargarLoteMarcas(int vCodigoMarca[], string vNombremarca[], 
                        int &cantidadMarcasCargadas, bool &marcasCargadas);


void cargarLoteProductos(int vCodigoProducto[], string vNombreProducto[],
                         float vPrecioVenta[], float vPrecioCompra[],
                         int vStockDisponible[], int vCodigoMarcaProducto[],
                         const int vCodigomarca[], bool marcasCargadas, 
                         int &cantidadProductosCargados, bool &productosCargados);


void cargarFormasDePago(string codigos[], string nombres[],
                        int porcentajes[], int cantidadFormas);
                        
#endif