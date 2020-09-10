#ifndef ORDENAMIENTO_GENERICO_METODO_INSERCION_H_INCLUDED
#define ORDENAMIENTO_GENERICO_METODO_INSERCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * ordenar(void * vec, size_t ce, size_t tam, int (*cmp)(const void*, const void*));
void insertar_en_subvec_ord(void *vec, void *iniOrd, void *finOrd, size_t tam,
                            int (*cmp) (const void*, const void*));
void intercambio(void *vec, void * iniOrd, size_t tam);
int cmp_ent( const void *, const void *);
int cmp_char( const void *, const void *);

/*Ordenamos dos vectores, uno de tipo int, y otro de tipo char,
usando funciones de forma genérica.
Para el mismo nos valemos del metodo de insercion.*/

/*Metodo de insercion: se basa en imaginarnos que existe una parte del vector que ya está
ordenado (subvector), y se van insertando en orden los elementos restantes, hasta que todos
los elementos hayan quedado en el subvector. Es decir, la primera posicion ya esta ordenada
(tomaremos esa parte como subvector ordenado). Luego se toma la siguiente posicion y se lo
"lleva al subvector" y se lo acomoda. Y asi sucesivamente. Ejemplo:
Vector desordenado: 4 2 5 1 3. Pensamos que el 4 ya esta ordenado. Asi que tomamos al 2 y
evaluamos. Como es menor hay cambio.
Primer cambio: 2 4 5 1 3. Por lo tanto el vector subordenado es 2 4. Ahora tomamos el 5.
Queda igual en este caso ya que no es menor. Tomamos el siguiente, el 1.
Segundo cambio: 1 2 4 5 3. El vector subordenado queda conformado por 1 2 4 5. Tomamos el 3.
Tercer cambio: 1 2 3 4 5*/

#endif // ORDENAMIENTO_GENERICO_METODO_INSERCION_H_INCLUDED
