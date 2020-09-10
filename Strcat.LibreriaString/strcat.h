#ifndef STRCAT_H_INCLUDED
#define STRCAT_H_INCLUDED

/*
Crear una función para emular lo que hace la función strcat de la librería string.
Es decir, basicamente se ingresan dos cadenas de texto y se concatenan (la segunda se agrega a la primera).
Luego por pantalla muestro la cadena1 (que estara concatenada con la cadena2).

La función retorna el valor de s1.
char * strcat(char * s1, const char * s2);
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 30

char * mi_strcat(char *t1, const char *t2);

#endif // STRCAT_H_INCLUDED
