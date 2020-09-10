#ifndef NORMALIZAR_H_INCLUDED
#define NORMALIZAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 40
#define VERDADERO   1
#define FALSO   0

///macros
#define ESLETRA(x) ( (x>='a' && x<='z') || (x>='A' && x<='Z') )
#define ESCOMA(x)  ( x==',')
#define ESESPACIO(x) (x==' ')

void normalizar(char *vec);
void colocarComa(char *ptr, char *ptrFin);

/*Desarrollar una funcion donde a raiz de una cadena con apellido y nombre/s, y que tenga simbolos, numeros, espacios de mas,
se normalice. Es decir se saque los simbolos, los espacios de mas, se ponga en mayuscula la primera de cada palabra,
y las demas en minuscula. Y ademas ponga o deje una coma donde tenga que ir. Por ejemplo:
"  rUiZ  , iVAnA ?!·vIctoria!!   "   ----> "Ruiz, Ivana Victoria"
En este caso al tener una sola coma, y despues del apellido, entonces la dejamos tal cual
" ,ruiz  ivana ..victoria "  ----> "Ruiz, Ivana Victoria"
En este caso tiene una coma al principio, lo cual no es valido, entonces la debe organizar y colocar luego del apellido.
"  ruiZ IvanA   victoria!,´´´" ---> "Ruiz, Ivana Victoria"
En este caso tiene una coma al final, por tanto tambien es invalido.
"  ruiZ  Ivana ,  viCtoria  " ----> Ruiz Ivana, Victoria"
En este caso tiene una sola coma y luego de uno de los nombres, que lo deje asi.
" , rUIz , IVAna  , vIctoria  , " ---> "Ruiz, Ivana Victoria"
En este caso tiene varias comas. Solo debe tomar la que esta luego de la primera palabra.
*/

#endif // NORMALIZAR_H_INCLUDED
