#include "../include/funciones.h"
#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

// ===================================================
// ===========  CARGA DE MARCAS - LOTE 1 =============
// ===================================================

// vCodigomarca,vNombremarca,cantidadMarcasCargadas,marcasCargadas

void cargarLoteMarcas(int vCodigomarca[], string vNombremarca[],
                      int &cantidadMarcasCargadas, bool &marcasCargadas)

{
  cantidadMarcasCargadas = 0;
  marcasCargadas = false;

  int codigoIngresado;
  string nombreIngresado;
  bool marcaValida;

  for (int i = 0; i < 10; i++) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "──────────────────────────────────────────────────" << endl;
    cout << "             CARGA DE MARCAS - LOTE 1               " << endl;
    cout << "──────────────────────────────────────────────────" << endl;
    cout << "A continuación, ingrese los datos para la marca #" << i + 1 << "."
         << endl;

    // Solicitamos ingresar código de marca:
    do {
      marcaValida = false;
      cout << "- Código de marca (número entero del 1 al 10): ";
      cin >> codigoIngresado;

      // Se verifica que el codigo ingresado sea entre 1 y 10
      if (codigoIngresado >= 1 && codigoIngresado <= 10) {
        marcaValida = true;
      } else {
        cout << "\nEl código ingresado no es válido. Intente nuevamente."
             << endl;
      }
    } while (marcaValida == false);

    // Si el codigo es correcto se guarda en el vector
    vCodigomarca[i] = codigoIngresado;

    cin.ignore(); // Limpia el buffer antes de getline

    // Solicitamos ingresar nombre de marca:
    do {
      cout << "- Nombre de marca (no puede estar vacío): ";
      getline(cin, nombreIngresado);
      cout << endl;

      nombreIngresado.erase(0, nombreIngresado.find_first_not_of(' '));
      nombreIngresado.erase(nombreIngresado.find_last_not_of(' ') + 1);

      marcaValida = false;
      if (!nombreIngresado.empty()) {
        marcaValida = true;
      } else {
        cout << "El nombre ingresado no es válido. Intente nuevamente." << endl;
      }
    } while (marcaValida == false);

    vNombremarca[i] = nombreIngresado;
    cantidadMarcasCargadas++; // Usamos este contador para contar la cantidad
                              // de marcas que se cargan correctamente
  }

  // En este if validamos que la carga se completó.
  if (cantidadMarcasCargadas == 10) {
    marcasCargadas = true;
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "Carga del lote 1 completada con éxito. A continuación se muestra "
            "el listado:"
         << endl;

    // Mostramos la carga de datos:
    cout << "──────────────────────────────────────────────────────────────────"
            "───────────"
         << endl;
    for (int x = 0; x < 10; x++) {
      if (vCodigomarca[x] <= 9) {
        cout << "Código de marca: " << vCodigomarca[x]
             << "   |   Nombre de marca: " << vNombremarca[x] << endl;
      } else {
        cout << "Código de marca: " << vCodigomarca[x]
             << "  |   Nombre de marca: " << vNombremarca[x] << endl;
      }
    }
  } else {
    cout << "No se completo correctamente la carga del lote 1." << endl;
  }
  cout << "──────────────────────────────────────────────────────────────────"
          "───────────"
       << endl;
}

// ======================================================
// ===========  CARGA DE PRODUCTOS - LOTE 2 =============
// ======================================================

void cargarLoteProductos(int vCodigoProducto[], string vNombreProducto[],
                         float vPrecioVenta[], float vPrecioCompra[],
                         int vStockDisponible[], int vCodigoMarcaProducto[],
                         const int vCodigomarca[], bool marcasCargadas,
                         int &cantidadProductosCargados,
                         bool &productosCargados) {

  cout << "─────────────────────────────────────────────────" << endl;
  cout << "          CARGA DE LOTE 2 - PRODUCTOS.           " << endl;
  cout << "─────────────────────────────────────────────────" << endl;

  if (!marcasCargadas) {
    cout << "\nERROR: Debe cargar las marcas antes de iniciar la carga de "
            "productos."
         << endl;
    return;
  }

  cantidadProductosCargados = 0;
  productosCargados = false;

  for (int i = 0; i < 20; i++) {
    cout << "\nProducto #" << (i + 1) << " :" << endl;

    int codigoProducto;
    cout << "Codigo de producto (3 dígitos, no consecutivos): ";
    cin >> codigoProducto;

    if (codigoProducto < 100 || codigoProducto > 999) {
      cout << "Codigo inválido. Carga interrumpida." << endl;
      return;
    }

    int digito1 = codigoProducto / 100;
    int digito2 = (codigoProducto / 10) % 10;
    int digito3 = codigoProducto % 10;

    if ((digito1 + 1 == digito2 && digito2 + 1 == digito3) ||
        (digito1 - 1 == digito2 && digito2 - 1 == digito3)) {
      cout << "El código no puede ser consecutivo. Carga interrumpida." << endl;
      return;
    }

    if (codigoProducto == 0) {
      cout << "El código no puede ser 0. Carga interrumpida." << endl;
      return;
    }

    cout << "Nombre producto: ";

    cin.ignore();
    string nombre;
    getline(cin, nombre);

    if (nombre.empty()) {
      cout << "El nombre no puede estar vacio. Carga interrumpida." << endl;

      return;
    }

    cout << "Precio de venta: ";

    float precioVenta;
    cin >> precioVenta;

    if (precioVenta == 0) {
      cout << "Precio de venta necesario. Carga interrumpida." << endl;

      return;
    }
    cout << "Precio de compra: ";

    float precioCompra;
    cin >> precioCompra;

    if (precioCompra == 0) {
      cout << "Precio de compra necesario. Carga interrumpida." << endl;

      return;
    }

    cout << "Stock disponible: ";

    int stock;
    cin >> stock;

    if (stock == 0) {
      cout << "Stock disponible necesario. Carga interrumpida." << endl;

      return;
    }

    cout << "Código de marca: ";

    int codigoMarca;
    cin >> codigoMarca;
    if (codigoMarca == 0) {
      cout << "Código de marca requerido. Carga interrumpida." << endl;

      return;
    }

    bool marcaEncontrada = false;

    for (int x = 0; x < 10; x++) {
      if (codigoMarca == vCodigomarca[x]) {
        marcaEncontrada = true;
        break; // Sale del for por que encontro la marca
      }
    }
    if (!marcaEncontrada) {
      cout << "Código de marca no encontrado en el lote de marcas. Carga "
              "interrumpida."
           << endl;
      return;
    }

    vCodigoProducto[i] = codigoProducto;
    vNombreProducto[i] = nombre;
    vPrecioVenta[i] = precioVenta;
    vPrecioCompra[i] = precioCompra;
    vStockDisponible[i] = stock;
    vCodigoMarcaProducto[i] = codigoMarca;
    cantidadProductosCargados++;
  }

  // En este if validamos que la carga se completó.
  if (cantidadProductosCargados == 20) {
    productosCargados = true;
    cout << "Carga del lote 2 completada con éxito. A continuación se muestra "
            "el listado de productos:"
         << endl
         << endl;
  }

  // Mostramos la carga de datos:

  mostrarTablaProductos(vCodigoProducto, vNombreProducto, vPrecioVenta,
                        vPrecioCompra, vStockDisponible, vCodigoMarcaProducto,
                        cantidadProductosCargados);

  cout << "\nCarga de productos completada." << endl;
}

// ======================================================
// ===========  Formas de pago - LOTE 3 =================
// ======================================================

void cargarFormasDePago(string codigosLoteTres[], string nombresLoteTres[],
                        int porcentajesLoteTres[], int cantidadFormas) {

  string codigosValidos[5] = {"EF", "MP", "TR", "TC", "CT"};

  for (int i = 0; i < cantidadFormas; i++) {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "────────────────────────────────" << endl;
    cout << " CARGA FORMAS DE PAGO - LOTE 3. " << endl;
    cout << "────────────────────────────────" << endl;
    cout << "       Códigos válidos:" << endl;
    cout << "────────────────────────────────" << endl;
    cout << "EF - (Efectivo)" << endl;
    cout << "MP - (Mercado pago)" << endl;
    cout << "TR - (Transferencia)" << endl;
    cout << "TC - (Tarjeta de crédito)" << endl;
    cout << "CT - (Criptomoneda)" << endl;
    cout << "────────────────────────────────" << endl;

    string codigo;
    bool valido = false;

    do {
      cout << "Ingrese el código para la forma de pago # " << i + 1 << ": ";
      cin >> codigo;

      // Convertir letras a mayúscula
      codigo[0] = toupper(codigo[0]);
      codigo[1] = toupper(codigo[1]);

      // Validar código:
      for (int x = 0; x < 5; x++) {
        if (codigo == codigosValidos[x]) {
          valido = true;
          break;
        }
      }

      // Verificar repetidos:
      for (int j = 0; j < i; j++) {
        if (codigo == codigosLoteTres[j]) {
          valido = false;
          break;
        }
      }

      if (!valido) {
        cout << "El código ingresado está repetido o es inválido. Por favor, "
                "intente nuevamente: "
             << endl;
      }
    } while (!valido);

    codigosLoteTres[i] = codigo;

    cout << "Ingrese nombre de la forma de pago: ";
    cin.ignore();
    getline(cin, nombresLoteTres[i]);

    cout << "Ingrese porcentaje (número entero positivo para interés, negativo "
            "para descuento): ";
    cin >> porcentajesLoteTres[i];

    cout << endl;
  }
}

// ===================================================
// ===========  CARGA DE VENTAS - LOTE 4 =============
// ===================================================

void cargarLoteVentas(int vCodigoProducto[], string vNombreProducto[],
                      float vPrecioVenta[], int vStockDisponible[],
                      int vCodigoMarcaProducto[], string vCodigoFP[],
                      int vPorcentajeFP[], int cantidadProductosCargados,
                      int cantidadFormasPago, int ventasPorProducto[],
                      float recaudacionPorProducto[], int comprasPorCliente[],
                      int ventasPorFormaYMarca[][5], bool marcasCargadas,
                      bool productosCargados, bool formasPagoCargadas,
                      int ventasPorForma[], int &totalVentas) {

  cout << "─────────────────────────────────────────────" << endl;
  cout << "         CARGA DE VENTAS - LOTE 4            " << endl;
  cout << "─────────────────────────────────────────────" << endl;

  if (!marcasCargadas || !productosCargados || !formasPagoCargadas) {
    cout << "\n ERROR: Para cargar ventas primero debe cargar:" << endl;
    if (!marcasCargadas)
      cout << "- Lote 1: Marcas" << endl;
    if (!productosCargados)
      cout << "- Lote 2: Productos" << endl;
    if (!formasPagoCargadas)
      cout << "- Lote 3: Formas de Pago" << endl;
    return;
  }

  totalVentas = 0; // Inicializamos el contador de ventas
  for (int i = 0; i < 5;
       i++) // Inicializamos el vector de ventas por forma de pago
    ventasPorForma[i] = 0;

  int nroCompra;

  do {
    cout << "\nIngrese Nro de Compra (0 para finalizar): ";
    cin >> nroCompra;

    if (nroCompra == 0) {
      cout << "\nCarga de ventas finalizada." << endl;
      break;
    }

    int codigoProducto;
    string codigoFormaPago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;

    cout << "Ingrese Código de Producto: ";
    cin >> codigoProducto;

    if (!existeProducto(codigoProducto, vCodigoProducto,
                        cantidadProductosCargados)) {
      cout << "Código de producto inválido. Venta no registrada.\n";
      continue; // se salta a la siguiente venta
    }

    cout << "Ingrese Código de Forma de Pago: ";
    cin >> codigoFormaPago;

    if (!existeFormaPago(codigoFormaPago, vCodigoFP, cantidadFormasPago)) {
      cout << "Código de forma de pago inválido. Venta no registrada.\n";
      continue;
    }

    cout << "Ingrese Cantidad Vendida: ";
    cin >> cantidadVendida;

    if (cantidadVendida <= 0) {
      cout << "La cantidad vendida debe ser mayor a 0. Venta no registrada.\n";
      continue;
    }

    cout << "Ingrese Código de Cliente (1 a 50): ";
    cin >> codigoCliente;

    if (codigoCliente < 1 || codigoCliente > 50) {
      cout << "Código de cliente inválido. Venta no registrada.\n";
      continue;
    }

    cout << "Ingrese Día de Venta (1 a 30): ";
    cin >> diaVenta;

    if (diaVenta < 1 || diaVenta > 30) {
      cout << "Dia inválido. Venta no registrada.\n";
      continue;
    }

    // carga de datos necesarios para el reporte 1
    int posProducto = obtenerPosProductoPorCodigoProducto(
        vCodigoProducto, codigoProducto, cantidadProductosCargados);
    int posFormaPago =
        obtenerPosFPPorCodigoFP(vCodigoFP, codigoFormaPago, cantidadFormasPago);

    float factorDescuentoIncremento = 1 + (vPorcentajeFP[posFormaPago] / 100.0);
    float montoVentaActual = (vPrecioVenta[posProducto] * cantidadVendida) *
                             factorDescuentoIncremento;

    recaudacionPorProducto[posProducto] += montoVentaActual;
    ventasPorProducto[posProducto] += cantidadVendida;
    vStockDisponible[posProducto] -= cantidadVendida;

    // lógica para reporte 3
    int codigoMarca = vCodigoMarcaProducto[posProducto];
    int indiceMarca = codigoMarca - 1;

    if (indiceMarca >= 0 && indiceMarca < 10 && posFormaPago != -1) {
      ventasPorFormaYMarca[indiceMarca][posFormaPago] += cantidadVendida;
    }

    // Carga de vectores para el reporte 2
    // Listado con el procentaje de ventas realizado por cada forma de pago,
    // incluir el nombre de la forma de pago y el porcentaje correspondiente

    for (int j = 0; j < 5; j++) {
      if (codigoFormaPago == vCodigoFP[j]) {
        ventasPorForma[j]++; // Suma una venta a esa forma de pago

        break;
      }
    }
    totalVentas++; // Suma una venta al total general

    // Carga de datos para el reporte 5

    comprasPorCliente[codigoCliente]++; // Incrementa la compra del cliente

  } while (true);
}

bool existeProducto(int codigo, int vCodigoProducto[],
                    int cantidadProductosCargados) {
  for (int i = 0; i < cantidadProductosCargados; i++) {
    if (vCodigoProducto[i] == codigo) {
      return true;
    }
  }
  return false;
}

bool existeFormaPago(string codigoFP, string codigos[], int cantidadFormas) {
  for (int i = 0; i < cantidadFormas; i++) {
    if (codigos[i] == codigoFP) {
      return true;
    }
  }
  return false;
}

int obtenerPosProductoPorCodigoProducto(int vCodigoProducto[],
                                        int codigoProducto,
                                        int cantidadProductos) {
  for (int i = 0; i < cantidadProductos; i++) {
    if (vCodigoProducto[i] == codigoProducto) {
      return i;
    }
  }
  return -1;
}

int obtenerPosFPPorCodigoFP(string vFormasPago[], string formaPago,
                            int cantidadFormasPago) {
  for (int i = 0; i < cantidadFormasPago; i++) {
    if (vFormasPago[i] == formaPago) {
      return i;
    }
  }
  return -1;
}

// ========================================
// ============ TABLA DE DATOS ============
// ========================================

// LOTE 2 - Productos

void mostrarTablaProductos(int vCodigoProducto[], std::string vNombreProducto[],
                           float vPrecioVenta[], float vPrecioCompra[],
                           int vStockDisponible[], int vCodigoMarcaProducto[],
                           int cantidadProductosCargados) {

  cout << endl;
  cout << "============================================================"
       << endl;
  cout << left << setw(10) << "Código" << setw(25) << "Nombre" << setw(15)
       << "Precio Venta" << setw(15) << "Precio Compra" << setw(15) << "Stock"
       << setw(15) << "Cod. Marca" << endl;
  cout << "------------------------------------------------------------"
       << endl;
  for (int i = 0; i < cantidadProductosCargados; i++) {
    cout << left << setw(10) << vCodigoProducto[i] << setw(25)
         << vNombreProducto[i] << setw(15) << fixed << setprecision(2)
         << vPrecioVenta[i] << setw(15) << fixed << setprecision(2)
         << vPrecioCompra[i] << setw(15) << vStockDisponible[i] << setw(15)
         << vCodigoMarcaProducto[i] << endl;
  }
  cout << "================================================================="
       << endl;
}

// LOTE 3 - Formas de pago
void tablaDatosLote3(string codigoLoteTres[], string nombresLoteTres[],
                     int porcentajesLoteTres[]) {
  cout << "──────────────────────────────────────────────────" << endl;
  cout << "          TABLA FORMAS DE PAGO - LOTE 3          " << endl;
  cout << "──────────────────────────────────────────────────" << endl;
  cout << "Código   Porcentaje   Nombre" << endl;
  cout << "──────────────────────────────────────────────────" << endl;

  for (int i = 0; i < 5; i++) {
    cout << codigoLoteTres[i] << "       " << porcentajesLoteTres[i];

    if ((porcentajesLoteTres[i] >= 0 && porcentajesLoteTres[i] < 10)) {
      cout << "            ";
    } else if ((porcentajesLoteTres[i] >= 10 && porcentajesLoteTres[i] < 100) ||
               (porcentajesLoteTres[i] <= -1 && porcentajesLoteTres[i] > -10)) {
      cout << "           ";
    } else {
      cout << "          ";
    }

    cout << nombresLoteTres[i] << endl;
  }
}
