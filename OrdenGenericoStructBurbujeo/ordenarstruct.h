#ifndef ORDENARSTRUCT_H_INCLUDED
#define ORDENARSTRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERDADERO   1
#define FALSO   0

typedef struct
{
    int cod;
    char prod[15];
    float precio;

}t_producto;


void* ordenar(void *vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *));
void intercambio(void *, void *, size_t tam);
int cmp_ent(const void *, const void *);
int cmp_float(const void *, const void*);
int cmp_char(const void*, const void*);


#endif // ORDENARSTRUCT_H_INCLUDED
