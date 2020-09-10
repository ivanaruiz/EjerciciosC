#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y)     ((x)<=(y) ? (x) : (y))
#define TAM_PILA 340

typedef struct
{
    char pila[TAM_PILA-1];
    unsigned tope;
}t_pila;



void crear_pila(t_pila *p);
int pila_llena(const t_pila *p, unsigned cant_bytes);
int pila_vacia(const t_pila *p);
int poner_en_pila(t_pila *p, const void *d, unsigned cant_bytes);
int sacar_de_pila(t_pila *p, void *d, unsigned cant_bytes);
int ver_tope(const t_pila *p, void *d, unsigned cant_bytes);
void vaciar_pila(t_pila *p);




#endif // PILA_ESTATICA_H_INCLUDED


