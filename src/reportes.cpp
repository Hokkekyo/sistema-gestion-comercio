#include "../include/funciones.h"
#include <iostream>

using namespace std;

// ===================================================
// ======  RECAUDACION POR PRODUCTO - REPORTE 1 ======
// ===================================================

void reporteRecaudacionPorProducto(const int vCodigoProducto[], const string vNombreProducto[],
    const int ventasPorProducto[], const float recaudacionPorProducto[],
    const int vStockDisponible[], int cantidadProductos){
   
    int auxCodigos[20];
    string auxNombres[20];
    int auxVentas[20];
    float auxRecaudado[20];
    int auxStock[20];

    // copio los vectores a los vectores auxiliares
    for (int i = 0; i < cantidadProductos; i++) {
        auxCodigos[i] = vCodigoProducto[i];
        auxNombres[i] = vNombreProducto[i];
        auxVentas[i] = ventasPorProducto[i];
        auxRecaudado[i] = recaudacionPorProducto[i];
        auxStock[i] = vStockDisponible[i];
    }

    // bubble sort
    for (int i = 0; i < cantidadProductos - 1; i++) {
        for (int j = 0; j < cantidadProductos - i - 1; j++) {
            if (auxVentas[j] < auxVentas[j + 1]) {
                // ordeno el vector de ventas
                int tmpVenta = auxVentas[j];
                auxVentas[j] = auxVentas[j + 1];
                auxVentas[j + 1] = tmpVenta;
                
                // ordeno el vector de codigos
                int tmpCodigo = auxCodigos[j];
                auxCodigos[j] = auxCodigos[j + 1];
                auxCodigos[j + 1] = tmpCodigo;

                // ordeno el vector de nombres de producto
                string tmpNombre = auxNombres[j];
                auxNombres[j] = auxNombres[j + 1];
                auxNombres[j + 1] = tmpNombre;

                // ordeno el vector de recaudacion
                float tmpRecaudado = auxRecaudado[j];
                auxRecaudado[j] = auxRecaudado[j + 1];
                auxRecaudado[j + 1] = tmpRecaudado;
                
                // ordeno el vector de stock
                int tmpStock = auxStock[j];
                auxStock[j] = auxStock[j + 1];
                auxStock[j + 1] = tmpStock;
            }
        }
    }

    // Encabezado
  cout << "\n─────────────────────────────────────────────────────────────" << endl;
  cout << "     REPORTE - RECAUDACIÓN POR PRODUCTO (Lote 4)             " << endl;
  cout << "─────────────────────────────────────────────────────────────" << endl;
  cout << "Código   Vendido   Recaudado     Stock   Nombre" << endl;
  cout << "─────────────────────────────────────────────────────────────" << endl;

  // Tabla
  for (int i = 0; i < cantidadProductos; i++) {
    cout << auxCodigos[i] << "       ";
    cout << auxVentas[i];

    // Espaciado entre vendido y recaudado
    if (auxVentas[i] < 10)
      cout << "         ";
    else if (auxVentas[i] < 100)
      cout << "        ";
    else
      cout << "       ";

    cout << auxRecaudado[i];

    // Espaciado entre recaudado y stock
    if (auxRecaudado[i] < 10)
      cout << "         ";
    else if (auxRecaudado[i] < 100)
      cout << "        ";
    else
      cout << "       ";

    cout << auxStock[i] << "       ";

    cout << auxNombres[i] << endl;
    }
}

// ==========================================================
// ====== Ventas por marca y forma de pago - REPORTE 3 ======
// ==========================================================

/*
3.Ventas por marca y forma de pago:
La cantidad total vendida de productos de cada marca discriminada por forma de
pago.
*/

void ventaPorMarcaYFormaDePago(int cantidadProductosCargados[],string codigoLoteTres[]);
