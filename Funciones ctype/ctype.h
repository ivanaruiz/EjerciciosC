#ifndef CTYPE_H_INCLUDED
#define CTYPE_H_INCLUDED

/*
Programa con funciones propias de la libreria ctype:
Las primeras tres son macros (isdigit, isalpha, isspace)
isdigit: Comprueba si un caracter es un digito decimal (del '0' al '9' (seria del 48 al 57 tabla ascii))
El valor de retorno será no nulo si c (el digito) es un dígito decimal.
isalpha: Comprueba sin un carácter es alfabético (de 'A' a 'Z' (de 65 a 90 ascii) o de 'a' a 'z' (97 a 122 ascii))
El valor de retorno será no nulo si c es una letra y cero en caso contrario.
isspace: Comprueba sin un carácter es de tipo espacio.
isspace es una macro que verifica si el caracter c pertenece grupo de caracteres de espacio, '',
tab, retorno de carro, nueva línea, tabulador vertical o salto de página
(es decir si es igual a 32 ascii, o de 09 a 13 ascii)
El valor de retorno será no nulo si c es un carácter de tipo espacio.
toupper: Convierte un carácter a mayúscula. Es decir, si el caracter está en el rango de 'a' a 'z' (97 a 122 ascii),
le resto 32 y se convierte en su equivalente mayuscula.
tolower: Convierte un carácter a minúscula. Es decir, si el caracter está en el rango de 'A' a 'Z' (65 a 90 ascii),
le sumo 32 y se convierte en su equivalente mayuscula.
*/

#define VERDADERO   1
#define FALSO   0

#include <stdio.h>
#include <stdlib.h>

int my_isalpha(char c);
int my_isdigit(char c);
int my_isspace(char c);
char my_toupper(char c);
char my_tolower(char c);

#define ES_NUMERO(X) ( ((X)>=48 && (X)<=57))
#define ES_LETRA(X) ( ((X)>=65 && (X)<=90) || ((X)>=97 && (X)<=122))
#define ES_ESPACIO(X) (((X)==32) || ((X)>=9 &&(X)<=13))

#endif // CTYPE_H_INCLUDED
