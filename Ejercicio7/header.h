#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*
un numero natural es perfecto, deficiente o abundante segun que la suma de sus divisores positivos menores
que él sea igual, menor o mayor que él. por ej
numero        divisores positivos menores que el     suma de los divisores      clasificacion
  6                    1,2,3                                  6                  perfecto
  10                   1,2,5                                  8                  deficiente
  12                   1,2,3,4,6                              16                 abundante
desarrollar una funcion que determine si un numero natural es perfecto, deficiente o abundante

*/


#include <stdio.h>
#include <stdlib.h>

void ingresoNumero(int *n);
int calculo(int n);

#endif // HEADER_H_INCLUDED
