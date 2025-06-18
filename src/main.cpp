#include "../include/funciones.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

  // Declaración de variables:
  int opcion, opcionRep;          // Menu
  bool opInvalida, opRepInvalida; // Menu

  int vCodigomarca[10];           // LOTE 1
  string vNombremarca[10];        // LOTE 1
  int cantidadMarcasCargadas = 0; // LOTE 1
  bool marcasCargadas = false;    // LOTE 1

  int vCodigoProducto[20];           // LOTE 2 (productos)
  string vNombreProducto[20];        // LOTE 2 (productos)
  float vPrecioVenta[20];            // LOTE 2 (productos)
  float vPrecioCompra[20];           // LOTE 2 (productos)
  int vStockDisponible[20];          // LOTE 2 (productos)
  int vCodigoMarcaProducto[20];      // LOTE 2 (productos)
  int cantidadProductosCargados = 0; // LOTE 2 (productos)
  bool productosCargados = false;    // LOTE 2 (productos)

  string codigosLoteTres[5];  // LOTE 3 (formas de pago)
  string nombresLoteTres[5];  // LOTE 3 (formas de pago)
  int porcentajesLoteTres[5]; // LOTE 3 (formas de pago)

  int ventasPorProducto[20] = {0};          // LOTE 4
  float recaudacionPorProducto[20] = {0.0}; // LOTE 4
  int comprasPorCliente[51] = {0};          // LOTE 4
  int ventasPorFormaYMarca[10][5] = {0};    // LOTE 4
  bool formasPagoCargadas = false;          // LOTE 4

  // ─────────────────────────────────────────────────────────────
  // REPORTES:

  int totalVentas = 0;
  int ventasPorForma[5] = {0};

  // Menú:
  do {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "=====================================" << endl;
    cout << "   • MENÚ PRINCIPAL - MI NEGOCIO •   " << endl;
    cout << "=====================================" << endl;
    cout << "   Seleccione una opción del menú." << endl;
    cout << "─────────────────────────────────────" << endl;
    cout << "1. Ingresar Marcas" << endl;
    cout << "2. Ingresar Productos" << endl;
    cout << "3. Ingresar Formas de Pago" << endl;
    cout << "4. Ingresar Ventas" << endl;
    cout << "5. Reportes" << endl;
    cout << "─────────────────────────────────────" << endl;
    cout << "0. SALIR" << endl << endl;

    opInvalida = true;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    while (opInvalida == true) {
      switch (opcion) {
      case 1:
        opInvalida = false;

        cargarLoteMarcas(vCodigomarca, vNombremarca, cantidadMarcasCargadas,
                         marcasCargadas);

        marcasCargadas = true;
        cout << "\nToca ENTER para ir al menú principal.";
        cin.ignore();
        cin.get();
        break;

      case 2:
        opInvalida = false;
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cargarLoteProductos(vCodigoProducto, vNombreProducto, vPrecioVenta,
                            vPrecioCompra, vStockDisponible,
                            vCodigoMarcaProducto, vCodigomarca, marcasCargadas,
                            cantidadProductosCargados, productosCargados);

        cout << "\nToca ENTER para ir al menú principal.";
        cin.ignore();
        cin.get();
        break;
      case 3:
        opInvalida = false;
        cargarFormasDePago(codigosLoteTres, nombresLoteTres,
                           porcentajesLoteTres, 5);

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        tablaDatosLote3(codigosLoteTres, nombresLoteTres, porcentajesLoteTres);

        formasPagoCargadas = true;
        cout << "\nToca ENTER para volver al menú principal.";
        cin.ignore();
        cin.get();
        break;
      case 4:
        opInvalida = false;
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cargarLoteVentas(
            vCodigoProducto, vNombreProducto, vPrecioVenta, vStockDisponible,
            vCodigoMarcaProducto, codigosLoteTres, porcentajesLoteTres,
            cantidadProductosCargados, 5, ventasPorProducto,
            recaudacionPorProducto, comprasPorCliente, ventasPorFormaYMarca,
            marcasCargadas, productosCargados, formasPagoCargadas,
            ventasPorForma, totalVentas);

        break;
      case 0:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "\nGracias por utilizar Mi Negocio. Hasta pronto!" << endl;
        return 0;
        break;
      // case 6;
      //  Agregar sub menu para visualizar las tablas de los datos ingresados
      case 5:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        opInvalida = false;
        opRepInvalida = true;
        while (opRepInvalida == true) {
          cout << "─────────────────────────────────────" << endl;
          cout << "          MENÚ DE REPORTES          " << endl;
          cout << "─────────────────────────────────────" << endl;
          cout << "  Seleccione una opción de reporte." << endl;
          cout << "─────────────────────────────────────" << endl;
          cout << "1. Recaudación por producto" << endl;
          cout << "2. Porcentaje de ventas por forma de pago" << endl;
          cout << "3. Ventas por marca y forma de pago" << endl;
          cout << "4. Productos sin ventas" << endl;
          cout << "5. Top 10 clientes + sorteo de cupones" << endl;
          cout << "─────────────────────────────────────" << endl;
          cout << "0. Volver al MENÚ PRINCIPAL." << endl << endl;
          cout << "Seleccione una opción: ";
          cin >> opcionRep;

          switch (opcionRep) {
          case 1:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            if (productosCargados) {
              reporteRecaudacionPorProducto(
                  vCodigoProducto, vNombreProducto, ventasPorProducto,
                  recaudacionPorProducto, vStockDisponible,
                  cantidadProductosCargados);
            } else {
              cout << "ERROR: primero debe cargar los productos y las ventas."
                   << endl;
            }

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
            break;
          case 2:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            reportePorcentajeVentasPorFormaPago(ventasPorForma, codigosLoteTres,
                                                nombresLoteTres, 5,
                                                totalVentas);

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
            break;

          case 3:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            if (marcasCargadas && formasPagoCargadas) {

              mostrarReporteVentasPorMarcaYFormaPago(
                  ventasPorFormaYMarca, vCodigomarca, vNombremarca,
                  cantidadMarcasCargadas, codigosLoteTres, 5);
            } else {
              cout << "ERROR: faltan cargar marcas o formas de pago." << endl;
            }

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
            break;
          case 4:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            reporteProductosSinVentas(vCodigoProducto, vNombreProducto,
                                      cantidadProductosCargados,
                                      ventasPorProducto);

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
            break;
          case 5:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            reporteTop10Clientes(comprasPorCliente);

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
            break;
          case 0:
            opRepInvalida = false;
            break;
          default:
            cout << "La opción ingresada no es válida. Por favor, intente "
                    "nuevamente: ";
            cin >> opcionRep;
            break;
          }
        }
        break;
      default:
        cout << "La opción ingresada no es válida. Por favor, intente "
                "nuevamente: ";
        cin >> opcion;
        break;
      }
    }
  } while (opcion != 0);

  return 0;
}
