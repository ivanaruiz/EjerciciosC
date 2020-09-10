#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estructura de 36 bytes cada registro
typedef struct
{
    int dni;
    char nya[30];
}t_alumno;

//el tipo de dato size_t indica que es un long. es decir, es como un int mas largo
//se usa para estas variables tipo tamaño o ce
//en size_t tam, tenemos el tamaño de cada registro en bytes, en este caso seria de 36 bytes
void * ord_vec_x_sel(void *vec, size_t ce, size_t tam, int (*cmp) (const void *, const void *));
void * buscar_menor(void *vec, void *fin, size_t tam, int (*cmp) (const void *, const void*));
void intercambio(void *vec, void *men, size_t tam);
int cmp_x_dni(const void *, const void *);
int cmp_x_nya(const void *, const void *);

/*Este programa crea una estructura simple y la inicializa con un vector desordenado.
Mediante el metodo de seleccion, usaremos funciones del tipo "qsort" que es para ordenar pero en forma generica.
Es decir, las mismas funciones serviran para ordenar segun cualquier tipo de dato, puede ser ordenar segun dni(int)
u ordenar segun nya (char).
Usaremos todos datos de tipo void ya que desconocemos qué tipo de comparacion haremos, asi que por eso es generico.
*/


#endif // ALUMNO_H_INCLUDED
