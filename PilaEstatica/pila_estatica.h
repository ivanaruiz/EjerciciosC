#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ((x)<(y) ? (x):(y))
#define TAM_PILA 200

typedef struct
{
    char pila[TAM_PILA];
    //es de char porque el char usa 1 byte, por ende no importa los datos que meta luego,
    //sino que mi pila es de tama�o 200 bytes, y tiene esos 200 bytes para ocuparlos como desee
    unsigned tope;
}t_pila;

//el tope me dice d�nde est� parada la pila

void crear_pila(t_pila *p);
int pila_vacia(const t_pila *p);
int pila_llena(const t_pila *p, unsigned tam_dato);
int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato);
int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato);
int ver_tope(const t_pila *p, void *d, unsigned tam_dato);
void vaciar_pila(t_pila *p);

#endif // PILA_ESTATICA_H_INCLUDED
