#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define     TAM_PILA        50000
#define minimo(x,y)     ((x)<=(y) ? (x) : (y))

typedef struct
{
    char        pila[TAM_PILA];
    unsigned    tope;
} tPila;

//primitivas de pila estática
void crearPila_MIO(tPila *p);
int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes);
int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia_MIO(const tPila *p);
int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes);


#endif // PILA_ESTATICA_H_INCLUDED
