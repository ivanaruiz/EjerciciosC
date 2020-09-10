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
int pasar_a_vec(t_producto *vec, int ce, char *path);
//funciones de ordenamiento generico
void * ordenar(void * vec, size_t ce, size_t tam, int (*cmp)(const void*, const void*));
void intercambio(void *a1, void *a2, size_t tam);
int cmp_cod(const void *, const void* );

#endif // ARCHIVOS_H_INCLUDED
