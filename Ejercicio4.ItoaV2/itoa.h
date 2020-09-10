#ifndef ITOA_H_INCLUDED
#define ITOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

char * mi_itoa(int n, char *vec, int base);
char toAscii(int resto, int base);
void invertirCadena(char *vec, char*ptr);

/*
Desarrollar mi propia función de itoa, que convierte un numero entero
a una cadena de caracteres ascii.
La misma cadena se podra usar para base 2 (binario), base 8 (octal), base 10 (decimal),
base 16(hexadecimal) y basicamente para otras bases tambien.
Ejemplo. Ingreso el número entero 10. Lo convierto a:
decimal : 10
octal : 12
hexadecimal : A                                                                                                       Es
*/


#endif // ITOA_H_INCLUDED
