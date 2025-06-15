#include <string>
#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

// ========================================
// ============= REPORTES.CPP =============
// ========================================

// Reporte 1:
void reporteRecaudacionPorProducto(const int vCodigoProducto[],
                                   const string vNombreProducto[],
                                   const int ventasPorProducto[],
                                   const float recaudacionPorProducto[],
                                   const int vStockDisponible[],
                                   int cantidadProductos);

// Reporte 3:
void mostrarReporteVentasPorMarcaYFormaPago(
    int ventasPorFormaYMarca[10][5],
    int vCodigomarca[], string vNombremarca[], int cantidadMarcas,
    string codigosLoteTres[], int cantidadFormasPago
);

// ========================================
// ============ FUNCIONES.CPP =============
// ========================================
void cargarLoteMarcas(int vCodigoMarca[], string vNombremarca[],
                      int &cantidadMarcasCargadas, bool &marcasCargadas);

void cargarLoteProductos(int vCodigoProducto[], string vNombreProducto[],
                         float vPrecioVenta[], float vPrecioCompra[],
                         int vStockDisponible[], int vCodigoMarcaProducto[],
                         const int vCodigomarca[], bool marcasCargadas,
                         int &cantidadProductosCargados,
                         bool &productosCargados);

void cargarFormasDePago(string codigos[], string nombres[], int porcentajes[],
                        int cantidadFormas);

void cargarLoteVentas(int vCodigoProducto[], string vNombreProducto[],
                      float vPrecioVenta[], int vStockDisponible[],
                      int vCodigoMarcaProducto[], string vCodigoFP[],
                      int vPorcentajeFP[], int cantidadProductosCargados,
                      int cantidadFormasPago, int ventasPorProducto[],
                      float recaudacionPorProducto[], int comprasPorCliente[],
                      int ventasPorFormaYMarca[][5], bool marcasCargadas,
                      bool productosCargados, bool formasPagoCargadas);

bool existeProducto(int codigo, int vCodigoProducto[],
                    int cantidadProductosCargados);

bool existeFormaPago(string codigoFP, string codigos[], int cantidadFormas);

int obtenerPosProductoPorCodigoProducto(int vCodigoProducto[],
                                        int codigoProducto,
                                        int cantidadProductos);

int obtenerPosFPPorCodigoFP(string vFormasPago[], string formaPago,
                            int cantidadFormasPago);

// ========================================================
// ============ TABLA DE DATOS (funciones.cpp) ============
// ========================================================

void tablaDatosLote3(string codigoLoteTres[], string nombresLoteTres[],
                     int porcentajesLoteTres[]);

#endif