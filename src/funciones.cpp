#include "../include/funciones.h"
#include <cctype>
#include <iostream>

using namespace std;

/*
 * Archivo: funciones.cpp
 * Acá va casi todo el trabajo pesado.
 *
 * Acá se implementan las funciones que usamos para cargar datos, validar,
 * mostrar reportes, etc. La idea es que todo lo que haga cosas (lógica del
 * sistema) esté acá, así el main no se llena de cosas.
 */

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
    system("clear");
    cout << "\n ─────────────────────────────────────────────────────" << endl;
    cout << "               CARGA DE MARCAS - LOTE 1               " << endl;
    cout << " ─────────────────────────────────────────────────────" << endl
         << endl;
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
    cout << "Carga del lote 1 completada con éxito. A continuación se muestra "
            "el listado:"
         << endl
         << endl;

    // Mostramos la carga de datos:
    for (int x = 0; x < 10; x++) {
      cout << "Código de marca: " << vCodigomarca[x]
           << "   |   Nombre de marca: " << vNombremarca[x] << endl;
    }
  } else {
    cout << "No se completo correctamente la carga del lote 1." << endl;
  }
}

// ======================================================
// ===========  CARGA DE PRODUCTOS - LOTE 2 =============
// ======================================================

void cargarLoteProductos(int vCodigoProducto[], string vNombreProducto[],
                         float vPrecioVenta[], float vPrecioCompra[],
                         int vStockDisponible[], int vCodigoMarcaProducto[],
                         const int vCodigomarca[]) {

  cout << "\n –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
  cout << " INICIANDO CARGA DE LOTE 2 - PRODUCTOS. " << endl;
  cout << " –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl
       << endl;

  for (int i = 0; i < 20; i++) {
    cout << "Producto #" << (i + 1) << " :" << endl;

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
  }
  cout << "Carga de productos completada.";
}

// ======================================================
// ===========  Formas de pago - LOTE 3 =================
// ======================================================

void cargarFormasDePago(string codigosLoteTres[], string nombresLoteTres[],
                        int porcentajesLoteTres[], int cantidadFormas) {

  cout << "\n–––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
  cout << "     INICIANDO CARGA DE LOTE 3 - FORMAS DE PAGO. " << endl;
  cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl
       << endl;

  string codigosValidos[5] = {"EF", "MP", "TR", "TC", "CT"};

  for (int i = 0; i < cantidadFormas;) {

    system("clear");
    cout << "––––––––––––––––––––––––––––––––" << endl;
    cout << "       Códigos válidos:" << endl;
    cout << "––––––––––––––––––––––––––––––––" << endl;
    cout << "EF - (Efectivo)" << endl;
    cout << "MP - (Mercado pago)" << endl;
    cout << "TR - (Transferencia)" << endl;
    cout << "TC - (Tarjeta de crédito)" << endl;
    cout << "CT - (Criptomoneda)" << endl << endl;
    cout << "––––––––––––––––––––––––––––––––" << endl;

    string codigo;
    bool valido = false;

    do {
      cout << "Ingrese el código para la forma de pago # " << i + 1 << " : ";
      cin >> codigo;

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
            "para descuento): "
         << endl;
    cin >> porcentajesLoteTres[i];

    cout << endl;
    i++; // Avanza el for si todo fue válido.
  }
}