#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int cargar_archivo(char * path);

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}t_producto;



#endif // PRODUCTOS_H_INCLUDED
