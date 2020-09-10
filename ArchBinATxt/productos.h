#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargar_archivo(char *path);
typedef struct
{
    int cod;
    char desc[20];
    float precio;
}t_producto;

/*
Programa que guarda un archivo binario y luego lo transforma a archivo de texto
con formato de longitud variable o longitud fija segun deseo del usuario
*/

#endif // PRODUCTOS_H_INCLUDED
