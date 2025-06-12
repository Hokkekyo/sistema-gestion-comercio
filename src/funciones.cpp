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

void menuPrincipal(int &opcion) {
  cout << endl;
  cout << " ─────────────────────────────────────" << endl;
  cout << "      MENÚ PRINCIPAL - MI NEGOCIO     " << endl;
  cout << " ─────────────────────────────────────" << endl;
  cout << "" << endl;
  cout << "Seleccione una opción del menú." << endl;
  cout << "" << endl;
  cout << "1. Ingresar Marcas" << endl;
  cout << "2. Ingresar Productos" << endl;
  cout << "3. Ingresar Formas de Pago" << endl;
  cout << "4. Ingresar Ventas" << endl;
  cout << "5. Reportes" << endl << endl;
  cout << "Ingrese el número de la opción deseada: ";
  cin >> opcion;
}

// ===================================================
// ===========  CARGA DE MARCAS - LOTE 1 =============
// ===================================================
// vCodigomarca,vNombremarca,cantidadMarcasCargadas,marcasCargadas
void cargarLoteMarcas(int vCodigomarca[], string vNombremarca[],
                      int &cantidadMarcasCargadas, bool &marcasCargadas) {
  cantidadMarcasCargadas = 0;
  marcasCargadas = false;

  int codigoIngresado;
  string nombreIngresado;
  bool marcaValida;

  cout << "\n –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
  cout << " INICIANDO CARGA DE LOTE 1 - Código y nombre de marcas." << endl;
  cout << " –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl
       << endl;

  for (int i = 0; i < 10; i++) {
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

    vCodigomarca[i] =
        codigoIngresado; // Si el codigo es correcto se guarda en el vector

    cin.ignore(); // Limpia el buffer antes de getline

    // Solicitamos ingresar nombre de marca:
    do {
      cout << "- Nombre de marca (no puede estar vacío): ";
      getline(cin,
              nombreIngresado); // Es para evitar que ingresen solo espacios
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

// ===================================================
// ===========  CARGA DE PRODUCTOS - LOTE 2 =============
// ===================================================
