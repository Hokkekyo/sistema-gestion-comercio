#include "../include/funciones.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

// ===================================================
// ======  RECAUDACION POR PRODUCTO - REPORTE 1 ======
// ===================================================

void reporteRecaudacionPorProducto(const int vCodigoProducto[],
                                   const string vNombreProducto[],
                                   const int ventasPorProducto[],
                                   const float recaudacionPorProducto[],
                                   const int vStockDisponible[],
                                   int cantidadProductos) {

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
  cout << "─────────────────────────────────────────────────────────────"
       << endl;
  cout << "                   RECAUDACIÓN POR PRODUCTO                  "
       << endl;
  cout << "─────────────────────────────────────────────────────────────"
       << endl;
  cout << "Código   Vendido   Recaudado     Stock   Nombre" << endl;
  cout << "─────────────────────────────────────────────────────────────"
       << endl;

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

// =========================================================
// === Porcentaje de ventas por foma de pago - REPORTE 2 ===
// =========================================================

void reportePorcentajeVentasPorFormaPago(const int ventasPorForma[],
                                         const string vCodigoFP[],
                                         const string nombresLoteTres[],
                                         int cantidadFormasPago,
                                         int totalVentas) {
  cout << "─────────────────────────────────────────────────────────────"
       << endl;
  cout << "           PORCENTAJE DE VENTAS POR FORMA DE PAGO           "
       << endl;
  cout << "─────────────────────────────────────────────────────────────"
       << endl;

  if (totalVentas == 0) {
    cout << "No hay ventas registradas para calcular porcentajes." << endl;
    return;
  }

  cout << "Código   Porcentaje      Nombre" << endl;
  cout << "─────────────────────────────────────────────────────────────"
       << endl;

  for (int i = 0; i < cantidadFormasPago; i++) {
    float porcentaje =
        (static_cast<float>(ventasPorForma[i]) / totalVentas) * 100;
    cout << vCodigoFP[i] << "       " << porcentaje << "%" << "          "
         << fixed << setprecision(2) << nombresLoteTres[i] << endl;
  }
  cout << "─────────────────────────────────────────────────────────────"
       << endl;
  cout << "Total ventas: " << totalVentas << endl;
}

// ==========================================================
// ====== Ventas por marca y forma de pago - REPORTE 3 ======
// ==========================================================

void mostrarReporteVentasPorMarcaYFormaPago(
    int ventasPorFormaYMarca[10][5], int vCodigomarca[], string vNombremarca[],
    int cantidadMarcas, string codigosLoteTres[], int cantidadFormasPago) {
  cout << "Ventas por marca y forma de pago:\n" << endl;

  for (int i = 0; i < cantidadMarcas; i++) {
    int codigoMarca = vCodigomarca[i];
    int indiceMarca = codigoMarca - 1;

    cout << "Marca: " << vNombremarca[i] << endl;

    for (int x = 0; x < cantidadFormasPago; x++) {
      cout << codigosLoteTres[x] << ": " << ventasPorFormaYMarca[indiceMarca][x]
           << " unidades" << endl;
    }

    cout << endl;
  }
}

// ============================================================
// ============= PRODUCTOS SIN VENTAS - REPORTE 4 =============
// ============================================================

void reporteProductosSinVentas(int vCodigoProducto[], string vNombreProducto[],
                               int cantidadProductosCargados,
                               int ventasPorProducto[]) {

  cout << "─────────────────────────────────────" << endl;
  cout << "        PRODUCTOS SIN VENTAS" << endl;
  cout << "─────────────────────────────────────" << endl;

  bool sinVentas = false;
  for (int i = 0; i < cantidadProductosCargados; i++) {
    if (ventasPorProducto[i] == 0) {
      cout << "Código: " << vCodigoProducto[i] << " | "
           << "Nombre del producto: " << vNombreProducto[i] << "." << endl;
      sinVentas = true;
    }
  }

  if (!sinVentas) {
    cout << "No hay productos sin ventas." << endl;
  }
}

// ============================================================
// =============   TOP 10 CLIENTES  - REPORTE 5   =============
// ============================================================

void reporteTop10Clientes(int comprasPorCliente[]) {

  cout << "─────────────────────────────────────" << endl;
  cout << "   TOP 10 CLIENTES CON MÁS COMPRAS   " << endl;
  cout << "─────────────────────────────────────" << endl;

  int copiaCompras[51];
  int copiaCodigos[51];

  // Copiar los datos originales (del 1 al 50)
  for (int i = 1; i <= 50; i++) {
    copiaCompras[i] = comprasPorCliente[i];
    copiaCodigos[i] = i;
  }

  // Ordenar ambos vectores de mayor a menor usando burbujeo
  for (int i = 1; i < 50; i++) {
    for (int j = 1; j <= 50 - i; j++) {
      if (copiaCompras[j] < copiaCompras[j + 1]) {
        // Intercambiar compras
        int aux = copiaCompras[j];
        copiaCompras[j] = copiaCompras[j + 1];
        copiaCompras[j + 1] = aux;
        // Intercambiar códigos para mantener la relación
        int auxCod = copiaCodigos[j];
        copiaCodigos[j] = copiaCodigos[j + 1];
        copiaCodigos[j + 1] = auxCod;
      }
    }
  }

  // Verificar si hubo al menos una compra
  bool huboCompras = false;
  for (int i = 1; i <= 50; i++) {
    if (copiaCompras[i] > 0) {
      huboCompras = true;
      break;
    }
  }

  if (!huboCompras) {
    cout << "No hubo compras registradas. No hay sorteo." << endl;
    return;
  }

  // Mostrar el top 10
  cout << "Cliente\t"
          "    "
          "Compras"
       << endl;
  cout << "─────────────────────────────────────" << endl;
  for (int i = 1; i <= 10; i++) {
    cout << copiaCodigos[i]
         << "\t"
            "    "
         << copiaCompras[i] << endl;
  }

  // Elegir aleatoriamente 3 clientes ganadores
  cout << "\nClientes ganadores del cupón de descuento:" << endl;
  cout << "───────────────────────────────────────────" << endl;

  srand((unsigned)time(0));
  bool yaSalio[11] = {false}; // Marca que índices 1 a 10 ya saliern
  int ganadores = 0;

  while (ganadores < 3) {
    int indiceGanador = rand() % 10 + 1; // Genera un número entre 1 y 10
    if (!yaSalio[indiceGanador]) {       // Si no salió antes
      cout << "Cliente #" << copiaCodigos[indiceGanador] << endl;
      yaSalio[indiceGanador] = true; // Marca como salido
      ganadores++;
    }
  }
}
