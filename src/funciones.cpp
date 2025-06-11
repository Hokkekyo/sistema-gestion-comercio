#include <iostream>
#include "../include/funciones.h"

using namespace std;

/*
 * Archivo: funciones.cpp
 * Acá va casi todo el trabajo pesado.
 *
 * Acá se implementan las funciones que usamos para cargar datos, validar, mostrar reportes, etc.
 * La idea es que todo lo que haga cosas (lógica del sistema) esté acá, así el main no se llena de cosas.
 */

//vCodigomarca,vNombremarca,cantidadMarcasCargadas,marcasCargadas

void cargarLoteMarcas(int vCodigomarca[], string vNombremarca[], int &cantidadMarcasCargadas, bool &marcasCargadas)
{
cantidadMarcasCargadas=0;
marcasCargadas=false;

int codigoIngresado;
string nombreIngresado;
bool marcaValida;

cout << "\n –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
cout << " INICIANDO CARGA DE LOTE 1 - Código y nombre de marcas."<<endl;
cout << " –––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
cout<<endl;

for (int i=0; i<10; i++){
    cout<<"A continuación, ingrese los datos para la Marca #"<<i+1<<"."<<endl;
    //cout<<endl;

    do{
        marcaValida=false;
        cout<<"- Código de marca (entero del 1 al 10): ";
        cin>>codigoIngresado;
        
        //Se verifica que el codigo ingresado sea entre 1 y 10

        if (codigoIngresado>=1 && codigoIngresado<=10){
            marcaValida=true;
        }
        else {
            cout<<"El código ingresado es inválido."<<endl;
        }
    } while (marcaValida==false);
//Si el codigo es correcto se guarda en el vector 
vCodigomarca[i]= codigoIngresado;

cin.ignore(); // Limpia el buffer antes de getline

do {
    cout<<"- Nombre de marca (no puede estar vacío): ";
    getline(cin, nombreIngresado); //Es para evitar que ingresen solo espacios 
    cout<<endl;

    nombreIngresado.erase(0, nombreIngresado.find_first_not_of(' '));
    nombreIngresado.erase(nombreIngresado.find_last_not_of(' ')+1);

    marcaValida=false;
    if (!nombreIngresado.empty()){
        marcaValida=true;
    } 
    else {
        cout<<"El nombre ingresado no es valido: "<<endl;
    }
} while (marcaValida==false);

vNombremarca[i]= nombreIngresado;

cantidadMarcasCargadas ++;//Usamos este contador para contar la cantidad 
//de marcas que se cargan correctamente 
}
//En este if validamos que la carga se completo y en el for mostramos el listado de marcas cargadas

if (cantidadMarcasCargadas==10){
    marcasCargadas=true;
    cout<<"Carga de Lote 1 - Codigo y nombre de marcas completo."<<endl;

    for (int x=0; x<10; x++){
    cout<<"Cod Marca: "<<vCodigomarca[x]<<"  Nombre de marca: "<<vNombremarca[x]<<endl;
}
}
else {
    cout<<"No se completo correctamente la carga del Lote 1"<<endl;
}

 }

 