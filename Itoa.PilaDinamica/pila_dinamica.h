#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ((x)<(y) ? (x) : (y))

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_pila;


//primitivas
void crear_pila(t_pila *p);
int pila_vacia(const t_pila *p);
int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato);
int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato);




#endif // PILA_DINAMICA_H_INCLUDED
