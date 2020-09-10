#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Dado un numero entero X y una tolerancia TOL, puede obtenerse e^X mediante la suma de los terminos
de la serie:
e^X = 1+ (X^1 /1) + (X^2/(1*2)) + (X^3/(1*2*3)) + (X^4/(1*2*3*4)) + ...
El proceso termina cuando se obtiene un termino calculado que sea menor que la tolerancia TOL.
desarrollar una funcion para calcular el e^X, datos X y TOL.
*/

void ingresoDatos(int *n, float *tol);
double calculo (int n, float tol);
double factorial(int val);

#endif // HEADER_H_INCLUDED
