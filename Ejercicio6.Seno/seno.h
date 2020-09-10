#ifndef SENO_H_INCLUDED
#define SENO_H_INCLUDED

/*
Dados x y una tolerancia TOL es posible calcular el seno (x) mediante la suma de los terminos
de la serie:
seno(x) = x - x^3 /3!  +  x^5 /5!  -  x^7 /7!  +  x^9 /9!  -  x^11 /11!  + ..
Este proceso continua mientras el termino calculado (en valor absoluto) sea mayor que la tolerancia.
desarrollar una funcion que obtenga el seno de x con tolerancia TOL, utilizando dicha serie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ingresoDatos(int *n, float*tol);
long double factorial(int expo);
long double seno(int n, float tol);

#endif // SENO_H_INCLUDED
