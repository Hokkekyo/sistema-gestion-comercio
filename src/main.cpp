#include <iostream>
using namespace std;

int main () {

    return 0;
}

/*
Lote 1: Marcas
El primer lote solicita las marcas con las que trabaja el comercio. Son 10 marcas en total y
por cada marca se ingresan los siguientes datos:

Código de Marca: (entero del 1 y 10)
Nombre: (string)
Ambos campos son requeridos. Cero se toma como vacío para el campo numérico. El
código de marca debe ser validado que es un número entre 1 y 10. El campo string no
puede estar vacío (es decir, “”). Los registros no se ingresan ordenados.

-------------------------------------------------------------------------------------------

Lote 2: Productos
El segundo lote cuenta con 20 productos y por cada registro se cuenta con la siguiente
información: Código de Producto. (entero, 3 dígitos, no consecutivos)
Nombre (string)
Precio de Venta. (float)
Precio de Compra. (float)
Stock Disponible. (entero)
Código de Marca. (entero del 1 al 10)
La carga de este lote debe estar validada:
Todos los datos son requeridos, es decir que no puede haber un campo para algún
registro que no sea cargado. CERO se toma como vacío para los campos
numéricos.

El código de marca debe existir en el lote de marcas cargado previamente. Si no se
cargaron las marcas, entonces no se podrán cargar los productos.
Si hubiese alguna validación que no se cumple, la carga del lote se tiene que interrumpir,
emitir el mensaje de error correspondiente, por ejemplo “Código de marca no encontrado en
el lote de marcas”, y redirigir al menú principal para que se vuelva a ejecutar el proceso de carga desde cero.

Nota: si las marcas estuviesen cargadas, la falla de la carga de productos no resetea el lote
de marcas, solo el de productos.

-------------------------------------------------------------------------------------------

Lote 3: Formas de Pago
El tercer lote requiere los datos de las formas de pago. Son un total de 5 opciones distintas
a la hora de abonar y por cada registro se cuenta con los siguientes datos:
Código de Forma de Pago: string (EF, MP, TR, TC, CT)
Nombre de la Forma de Pago. (string)
Porcentaje de descuento o interés. (entero)
Negativo: descuento
Positivo: interés
Códigos posibles:
Para la carga del código de forma de pago solo se pueden cargar los códigos listados a
continuación. El orden no es un requisito, es decir que se pueden cargar en un orden
distinto al que se presenta, pero no puede haber códigos distintos o repetir los códigos de
las formas de pago.
EF: Efectivo
MP: Mercado Pago
TR: Transferencia
TC: Tarjeta de Crédito
CT: Criptomoneda

-------------------------------------------------------------------------------------------

🧾 Lote de Ventas
Finalmente, se cuenta con un lote con las ventas registradas durante la semana anterior. La
aplicación en cuestión, se ejecutará cada semana con los datos de la semana recién
concluida. Por cada registro de venta se cuenta con los siguientes datos:
Nro de Compra. (entero)
Código de Producto. (entero)
Forma de Pago. (string)
Cantidad Vendida. (entero)
Código de Cliente. ( entero de 1 a 50)
Día de la Venta. ( entero de 1 a 30)
Los registros de este lote, a diferencia de los lotes anteriores, se cargan pero no se
guardan. En este lote se deberá procesar para calcular lo necesario según los
requerimientos que se listan a continuación. La carga del lote finaliza con un registro con
número de compra cero.

-------------------------------------------------------------------------------------------

📊 Reportes requeridos
Recaudación por producto:
2. 3. Emitir un listado con el total recaudado por producto ordenado de mayor a menor por
cantidad vendida. El informe debe mostrarse en formato listado e incluir:
Código de producto.
Nombre del producto.
Total recaudado.
Cantidad vendida.
Stock remanente.
Porcentaje de ventas por forma de pago:
Listado con el porcentaje de ventas realizado por cada forma de pago. Incluir el
nombre de la forma de pago y el porcentaje correspondiente.
Ventas por marca y forma de pago:
La cantidad total vendida de productos de cada marca discriminada por forma de
pago.

-------------------------------------------------------------------------------------------

4. Productos sin ventas:
5. Emitir un listado con los productos que no registraron ninguna venta. Incluir el código
y nombre del producto.
Top 10 clientes + sorteo de cupones:
Se desea premiar a las personas más frecuentes del comercio. Se solicita una
funcionalidad que, a partir del top 10 de los clientes que más compras hayan
realizado, calcule e informe de manera aleatoria a 3 personas que serán acreedoras
de un cupón de descuento para su próxima compra. Se deberá emitir el top 10 con
el código de cliente y la cantidad total de compras realizadas y luego el listado de los
3 clientes ganadores con el código de cliente y la cantidad que compraron

Calcular el top 10 de clientes con más compras realizadas (por cantidad de compras).
Elegir aleatoriamente 3 de ellos y otorgarles un cupón de descuento.
Mostrar el top 10 y los 3 ganadores con su código de cliente y cantidad de
compras.

-------------------------------------------------------------------------------------------

⭐ Desafío Adicional: Descuentos Especiales por Marca
Puede haber marcas que tengan definidos días en los cuales se realizan una promo
adicional y acumulativa para esa marca. En ese caso, el registro original de la marca
quedaría de la siguiente manera:
Código de marca. (entero del 1 al 10)
Nombre de marca. (string)
Días especiales de promoción. (vector de 5 que son como máximo los días
configurables en el mes).
De esta forma, por ejemplo, la marca con código 8 podría tener los días 3, 4, 10, 11 y 12
como especiales para promoción. Si la marca no tiene días de promoción, el vector estará
cargado completamente con ceros. Puede tener menos de 5 días cargados para la oferta.
En esos casos, el precio total de la venta tendrá un 15% más de descuento sobre el total
final.
Emitir un informe con la cantidad de ventas que entraron en ésta promo para cada marca y
la cantidad de dinero brindado en descuentos en base a dicha promoción.

Para estas marcas:
Se guarda un vector de hasta 5 días (1 a 30 cada uno) en los que se aplicará un
15% de descuento adicional.
Si no hay días especiales, el vector se completa con ceros.

-------------------------------------------------------------------------------------------

📢 Informe adicional:
Cantidad de ventas que aplicaron esta promoción por marca.
Total de dinero descontado gracias a esta promoción especial.
📋 Menú de Opciones
La aplicación deberá contar con un menú desde el cual se accederá a las distintas
funcionalidades disponibles.
1. Cargar lote de marcas
2. Cargar lote de productos
3. Cargar lote de formas de pago
4. Cargar lote de ventas
5. Mostrar reportes
La opción 5, a su vez, contará con un submenú con las opciones de reportes disponibles.
*/