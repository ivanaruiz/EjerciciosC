

#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED

/*
En la serie de fibonacci, cada termino es la suma de los dos anteriores y los dos
primeros terminos son 1
serie: 1 1 2 3 5 8 13 21 ...
desarrollar una funcion para determinar si un entero pertenece a la serie de fibonacci
*/

#include <stdio.h>
#include <stdlib.h>

#define NOFIBO 0
#define FIBO 1

void validar (int *num);
int fibonacci(int num);
void mostrarLista(int suma, int num);


#endif // FIBONACCI_H_INCLUDED
