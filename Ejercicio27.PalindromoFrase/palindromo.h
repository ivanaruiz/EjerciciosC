#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*Hacer una funcion que me diga si frase que se ingresa es palindromo o no*/
/*Si ingreso por ejemplo:
"AniTA LavA LA tiNA"
la formatea toda la frase quedando "anitalavalatina"
y me dira que es palindromo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ce  20
#define VERDADERO   1
#define FALSO   0

#define NOESLETRA(X) (X<65 || X>90) && (X<97 || X>122)

int es_palindromo(char *vec);
char* sacarCaracteres(char *vec);
#endif // HEADER_H_INCLUDED
