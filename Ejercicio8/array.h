#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

/*Dado un array de char que contiene un texto compuesto por palabra que termina en '.'
(o en su defecto en caracter nulo '\0', escriba un programa en que determine e informe:
 a-cuál es la primer palabra y cuántas veces se repite en el texto
 b-cuántas palabras tiene el texto
 c-longitud de la palabra más larga */

#include <stdio.h>
#include <stdlib.h>
#define ES_LETRA(X) ( (X>='a' && X<='z') || (X>='A' && X<='Z'))

void resolver(char * texto);
int buscarRepe(char *ppIni, char* ppFin, char* texto, int cantLetPP, int *cantVecesRepetidas);
void mostrar_resultados(char * ppIni, char* ppFin, int huborepe, int cantPal, int maxLongPal);

#endif // ARRAY_H_INCLUDED
