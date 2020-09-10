#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una funcion que elimine la primera aparicion de un numero determinado de
un arreglo de enteros*/

#define VERDADERO   1
#define FALSO   0


void mostrar(int *vec, int ce);
int buscar(int *vec, int ce, int n);
void borrar(int vec[], int ce, int n , int i);

#endif // HEADER_H_INCLUDED
