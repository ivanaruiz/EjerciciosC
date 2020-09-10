#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    char desc[12];
    float precio;
    int stock;
}t_producto;

//funciones de archivo
int crear_arch_prod(char * path);
int crear_arch_mov(char * path);
int leer_arch_prod(char *path);
int rellenar_campos_vacios(char *path);
int convertir_a_txt(char * path);


#endif // ARCHIVOS_H_INCLUDED
