#ifndef PILA_CIRCULAR_H_INCLUDED
#define PILA_CIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) ((X)<(Y) ? (X):(Y))


typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_pila;

//son solo 7 primitivas
void crear_pila(t_pila *p);
int pila_llena(const t_pila *p, unsigned tam_info);
int pila_vacia(const t_pila *p);
int poner_en_pila(t_pila *p, const void * d, unsigned tam_info);
int sacar_de_pila(t_pila *p, void * d, unsigned tam_info);
int ver_tope(const t_pila *p, void * d, unsigned tam_info);
void vaciar_pila(t_pila *p);



#endif // PILA_CIRCULAR_H_INCLUDED
