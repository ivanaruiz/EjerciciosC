#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dni;
    char nya[30];
}t_alumno;


t_alumno * ord_struct_x_sel(t_alumno *vec, int ce, int (*cmp) (const t_alumno *, const t_alumno *));
t_alumno * buscar_menor(t_alumno *vec, t_alumno *fin, int (*cmp) (const t_alumno *, const t_alumno *));
void intercambio(t_alumno *vec, t_alumno *men);
int cmp_x_dni(const t_alumno *, const t_alumno *);
int cmp_x_nya(const t_alumno *, const t_alumno *);

/*
Este programa crea un archivo binario desordenado de cero. Luego lo abre y lo actualiza, ordenandolo tanto por dni
como por nombre, y luego lo vuelve a guardar.
La novedad aca es reutilizar codigo, entonces usare funciones pasadas por parametros (la funcion cmp). La cual en ella
es donde se haran las comparaciones segun corresponda.

En resumen, si quiero que la funcion se ejecute, le pongo parentesis.
Si no quiero que se ejecute y solo se la paso como puntero para que mas tarde se ejecute, no le pongo parentesis.
*/

#endif // ALUMNO_H_INCLUDED
