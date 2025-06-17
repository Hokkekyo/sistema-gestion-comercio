#include "../include/funciones.h"
#include <iostream>

using namespace std;

int main() {

  /*
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
   LOTE 1 - Declaracion de vectores/variables (Codigo de Marca + Nombre de
  Marca)
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
  - int vCodigomarca[10] - Vector de Codigo de marcas.
  - string vNombremarca[10] - Vector de Nombres de marcas.
  - int cantidadMarcasCargadas=0 - Contador de marcas cargadas para validar la
  bandera de marcasCargadas.
  - bool marcasCargadas - Bandera para validar la carga completa.
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
   LOTE 2 - Declaracion de vectores/variables (Productos)
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
  -
  -
  -
  -
  -
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
   LOTE 3 - Declaracion de vectores/variables (Formas de pago)
  –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
  - string codigosLoteTres[5]; - Códigos de forma de pago
  - string nombresLoteTres[5]; - Nombres de forma de pago
  - int porcentajesLoteTres[]; - Porcentaje de descuento o interés
  - int cantidadFormas; - Cantidad de formas de pago (5)
 –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
   LOTE 4 - Declaracion de vectores/variables (Ventas)
 –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
  - int ventasPorProducto[20] - Cantidad total vendida por producto
  - float recaudacionPorProducto[20] - Dinero recaudado por producto
  - int comprasPorCliente[50] - Cantidad de compras por cliente
  - int ventasPorFormaYMarca[10][5] - Ventas por marca y forma de pago
  - bool formasPagoCargadas - Bandera para validar carga de formas de pago
 */

  // Declaración de variables:
  int opcion, opcionRep;          // Menu
  bool opInvalida, opRepInvalida; // Menu

  int vCodigomarca[10];            // LOTE 1
  string vNombremarca[10];         // LOTE 1
  int cantidadMarcasCargadas = 0; // LOTE 1
  bool marcasCargadas = false;    // LOTE 1

  int vCodigoProducto[20];            // LOTE 2 (productos)
  string vNombreProducto[20];         // LOTE 2 (productos)
  float vPrecioVenta[20];             // LOTE 2 (productos)
  float vPrecioCompra[20];            // LOTE 2 (productos)
  int vStockDisponible[20];           // LOTE 2 (productos)
  int vCodigoMarcaProducto[20];       // LOTE 2 (productos)
  int cantidadProductosCargados = 0; // LOTE 2 (productos)
  bool productosCargados = false;    // LOTE 2 (productos)

  string codigosLoteTres[5];  // LOTE 3 (formas de pago)
  string nombresLoteTres[5];  // LOTE 3 (formas de pago)
  int porcentajesLoteTres[5]; // LOTE 3 (formas de pago)

  int ventasPorProducto[20] = {0};          // LOTE 4
  float recaudacionPorProducto[20] = {0.0}; // LOTE 4
  int comprasPorCliente[50] = {0};          // LOTE 4
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
    cout << endl;
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

        cout << "\nToca ENTER para volver al menú principal.";
        cin.ignore();
        cin.get();
        break;
      case 0:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "\nNos re vimoooooooo." << endl;
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
          cout << endl;
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
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;
          case 2:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            // Ingrese <AQUI> funcion para porcentaje de ventas por forma de
            // pago.
            reportePorcentajeVentasPorFormaPago(ventasPorForma, codigosLoteTres,
                                                nombresLoteTres, 5,
                                                totalVentas);

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
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
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;
          case 4:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
reporteProductosSinVentas(vCodigoProducto, vNombreProducto, cantidadProductosCargados, ventasPorProducto);

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;
          case 5:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            // Ingrese <AQUI> funcion top 10 clientes + sorteo de cupones.

            cout << "\nToca ENTER para volver al menú de reportes." << endl;
            cin.ignore();
            cin.get();
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
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

/*

LOTE 1: Marcas
El primer lote solicita las marcas con las que trabaja el comercio. Son 10
marcas en total y por cada marca se ingresan los siguientes datos:

Código de Marca: (entero del 1 y 10)
Nombre: (string)
Ambos campos son requeridos. Cero se toma como vacío para el campo numérico. El
código de marca debe ser validado que es un número entre 1 y 10. El campo string
no puede estar vacío (es decir, “”). Los registros no se ingresan ordenados.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

LOTE 2: Productos
El segundo lote cuenta con 20 productos y por cada registro se cuenta con la
siguiente información:
-Código de Producto. (entero, 3 dígitos, no consecutivos)
-Nombre (string)
-Precio de Venta. (float)
-Precio de Compra. (float)
-Stock Disponible. (entero)
-Código de Marca. (entero del 1 al 10)

La carga de este lote debe estar validada:
-Todos los datos son requeridos, es decir que no puede haber un campo para algún
registro que no sea cargado. CERO se toma como vacío para los campos
numéricos.
-El código de marca debe existir en el lote de marcas cargado previamente. Si no
se cargaron las marcas, entonces no se podrán cargar los productos.

Si hubiese alguna validación que no se cumple, la carga del lote se tiene que
interrumpir, emitir el mensaje de error correspondiente, por ejemplo “Código de
marca no encontrado en el lote de marcas”, y redirigir al menú principal para
que se vuelva a ejecutar el proceso de carga desde cero.

NOTA: si las marcas estuviesen cargadas, la falla de la carga de productos no
resetea el lote de marcas, solo el de productos.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

LOTE 3: Formas de Pago
El tercer lote requiere los datos de las formas de pago. Son un total de 5
opciones distintas a la hora de abonar y por cada registro se cuenta con los
siguientes datos:

-Código de Forma de Pago: string (EF, MP, TR, TC, CT)
-Nombre de la Forma de Pago. (string)
-Porcentaje de descuento o interés. (entero)
•Negativo: descuento
•Positivo: interés

Códigos posibles:
Para la carga del código de forma de pago solo se pueden cargar los códigos
listados a continuación. El orden no es un requisito, es decir que se pueden
cargar en un orden distinto al que se presenta, pero no puede haber códigos
distintos o repetir los códigos de las formas de pago. -EF: Efectivo -MP:
Mercado Pago -TR: Transferencia -TC: Tarjeta de Crédito -CT: Criptomoneda

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

🧾 LOTE DE VENTAS:
Finalmente, se cuenta con un lote con las ventas registradas durante la semana
anterior. La aplicación en cuestión, se ejecutará cada semana con los datos de
la semana recién concluida. Por cada registro de venta se cuenta con los
siguientes datos:

-Nro de Compra. (entero)
-Código de Producto. (entero)
-Forma de Pago. (string)
-Cantidad Vendida. (entero)
-Código de Cliente. ( entero de 1 a 50)
-Día de la Venta. ( entero de 1 a 30)

Los registros de este lote, a diferencia de los lotes anteriores, se cargan pero
no se guardan. En este lote se deberá procesar para calcular lo necesario según
los requerimientos que se listan a continuación. La carga del lote finaliza con
un registro con número de compra cero.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

📊 REPORTES REQUERIDOS:
1. Recaudación por producto:
Emitir un listado con el total recaudado por producto ordenado de mayor a menor
por cantidad vendida. El informe debe mostrarse en formato listado e incluir:
-Código de producto.
-Nombre del producto.
-Total recaudado.
-Cantidad vendida.
-Stock remanente.

2.Porcentaje de ventas por forma de pago:
Listado con el porcentaje de ventas realizado por cada forma de pago. Incluir el
nombre de la forma de pago y el porcentaje correspondiente.

3.Ventas por marca y forma de pago:
La cantidad total vendida de productos de cada marca discriminada por forma de
pago.

4. Productos sin ventas:
Emitir un listado con los productos que no registraron ninguna venta. Incluir el
código y nombre del producto.

5. Top 10 clientes + sorteo de cupones:
Se desea premiar a las personas más frecuentes del comercio. Se solicita una
funcionalidad que, a partir del top 10 de los clientes que más compras hayan
realizado, calcule e informe de manera aleatoria a 3 personas que serán
acreedoras de un cupón de descuento para su próxima compra. Se deberá emitir el
top 10 con el código de cliente y la cantidad total de compras realizadas y
luego el listado de los 3 clientes ganadores con el código de cliente y la
cantidad que compraron

-Calcular el top 10 de clientes con más compras realizadas (por cantidad de
compras). -Elegir aleatoriamente 3 de ellos y otorgarles un cupón de descuento.
-Mostrar el top 10 y los 3 ganadores con su código de cliente y cantidad de
compras.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

⭐ DESAFÍO ADICIONAL: Descuentos especiales por marca
Puede haber marcas que tengan definidos días en los cuales se realizan una promo
adicional y acumulativa para esa marca. En ese caso, el registro original de la
marca quedaría de la siguiente manera: -Código de marca. (entero del 1 al 10)
-Nombre de marca. (string)
-Días especiales de promoción. (vector de 5 que son como máximo los días
configurables en el mes).

De esta forma, por ejemplo, la marca con código 8 podría tener los días 3, 4,
10, 11 y 12 como especiales para promoción. Si la marca no tiene días de
promoción, el vector estará cargado completamente con ceros. Puede tener menos
de 5 días cargados para la oferta.

En esos casos, el precio total de la venta tendrá un 15% más de descuento sobre
el total final.

Emitir un informe con la cantidad de ventas que entraron en ésta promo para cada
marca y la cantidad de dinero brindado en descuentos en base a dicha promoción.

Para estas marcas:
-Se guarda un vector de hasta 5 días (1 a 30 cada uno) en los que se aplicará un
15% de descuento adicional.
-Si no hay días especiales, el vector se completa con ceros.

📢 Informe adicional:
-Cantidad de ventas que aplicaron esta promoción por marca.
-Total de dinero descontado gracias a esta promoción especial.

📋 Menú de Opciones
La aplicación deberá contar con un menú desde el cual se accederá a las
distintas funcionalidades disponibles.

1. Cargar lote de marcas
2. Cargar lote de productos
3. Cargar lote de formas de pago
4. Cargar lote de ventas
5. Mostrar reportes

La opción 5, a su vez, contará con un submenú con las opciones de reportes
disponibles.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

CONSIDERACIONES GENERALES SOBRE EL DESARROLLO DEL PROGRAMA:

-El proyecto se realizará en grupos de hasta cuatro integrantes, utilizando
Code::Blocks como entorno de desarrollo.

-Todos los integrantes deben contar con el proyecto funcionando correctamente en
su propia computadora.

-Es obligatorio estructurar el código utilizando funciones y vectores. Se
evaluará especialmente el uso adecuado de funciones para dividir la lógica del
programa (carga de lotes, validaciones, búsquedas, etc.).

-El programa debe incluir al menos un archivo .h y .cpp para organizar las
funciones de forma modular.

-Cada opción del menú principal debe estar asociada a una o más funciones
específicas, empleando correctamente la estructura switch.

-No está permitido utilizar herramientas, bibliotecas o conceptos que no hayan
sido trabajados en la materia (como punteros, archivos binarios o estructuras
avanzadas). Si será opcional el uso de STRUCT, siempre y cuando el Equipo sepa
manejarlo a la perfección.

-No se deben utilizar variables globales. El uso correcto del paso de parámetros
será parte de la evaluación.

-Para poder cargar el lote de ventas se debe validar que los lotes 1, 2 y 3
estén cargados. Lo mismo al momento de intentar acceder a alguna de las
funcionalidades de los reportes: si no se cargaron los lotes iniciales incluido
el lote de ventas, no habrá datos calculados que mostrar.

-El programa contará con los datos cargados mientras se mantenga en ejecución y
se podrá acceder a las funcionalidades a elección las cuales emitirán los
reportes solicitados.

-Una vez cerrada la aplicación, en su nueva apertura los lotes deberán ser
cargados nuevamente para trabajar.

-El Desafío Adicional es una funcionalidad opcional y no es obligatoria. Queda a
criterio del grupo realizarlas o no.
*/