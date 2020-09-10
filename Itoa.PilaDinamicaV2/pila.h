#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ((x)<=(y) ? (x): (y))


//pila dinamica
typedef struct sNodo
{
    void * info;
    unsigned tamInfo;
    struct sNodo * sig;
}tNodo;

typedef tNodo * tPila;

//primitivas
void crearPila(tPila * p);
int ponerEnPila(tPila * p, const void * d, unsigned tam_dato);
int pilaVacia(const tPila *p);
int sacarDePila(tPila * p, void * d, unsigned tam_dato);

#endif // PILA_H_INCLUDED
