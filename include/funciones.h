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

void cargarLoteVentas(int vCodigoProducto[], string vNombreProducto[],
                      float vPrecioVenta[], int vStockDisponible[], int vCodigoMarcaProducto[],
                      string vCodigoFP[], int vPorcentajeFP[],
                      int cantidadProductosCargados, int cantidadFormasPago,
                      int ventasPorProducto[], float recaudacionPorProducto[],
                      int comprasPorCliente[], int ventasPorFormaYMarca[][5],
                      bool marcasCargadas, bool productosCargados, bool formasPagoCargadas);

bool existeProducto(int codigo, int vCodigoProducto[], int cantidadProductosCargados);

bool existeFormaPago(string codigoFP, string codigos[], int cantidadFormas);

// Tabla de datos:
void tablaDatosLote3(string codigoLoteTres[], string nombresLoteTres[],
                     int porcentajesLoteTres[]);

                        
#endif