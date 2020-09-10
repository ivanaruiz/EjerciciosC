#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define cel 6       ///cel= cantidad de elementos

 /*
 Desarrollar una funcion que elimine el elemento que ocupa una determinada posicion de un arreglo
 de enteros
 */

void ingresoPos(int  *pos, int ce);
void mostrar(int *vec, int ce);
void borrar(int *vec, int ce, int pos);


#endif // HEADER_H_INCLUDED
