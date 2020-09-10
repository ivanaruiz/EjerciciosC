#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nya[10];
}t_alumno;

t_alumno *buscar(t_alumno *vec, t_alumno *fin);
void intercambio(t_alumno *alu, t_alumno *men);
t_alumno * ordenar(t_alumno *vec, int ce);
int leer_arch_ord(char *path);

/*Este programa crea un archivo binario desordenado. Luego lo abre y lo actualiza. Lo ordena segun el dni (ordena
la estructura dentro del archivo) y lo vuelve a guardar en el archivo. Usaremos el metodo de seleccion.
Nos ayudaremos con algunos punteros del tipo estructura. Es decir punteros que apuntaran a distintas posiciones
del struct. */

#endif // ALUMNO_H_INCLUDED
