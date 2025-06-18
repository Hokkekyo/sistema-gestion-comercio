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