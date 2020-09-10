#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1
#define FALSO   0


typedef struct
{
    int cod;
    char desc[30];
    float precio;
}t_producto;



int crear(char * path);
int leer(char *path);
int modificar(char *path);
void menu();

#endif // PRODUCTOS_H_INCLUDED
