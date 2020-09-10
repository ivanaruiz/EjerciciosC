#ifndef NORMALIZAR_H_INCLUDED
#define NORMALIZAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>


#define ESLETRA(x)(x>=65 && x<=90) || (x>=97 && x<=122)     ///defino macro

void normalizar(char * cad, int ce);

/*
Realizar una función que formatee una cadena de caracteres.
Eliminando espacios de más y quitando todos los caracteres especiales.
Ejemplo, si llega:
"       hOLa cOmO   ,     EstAn" -> "Hola como estan"
*/

#endif // NORMALIZAR_H_INCLUDED
