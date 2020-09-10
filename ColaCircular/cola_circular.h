#ifndef COLA_CIRCULAR_H_INCLUDED
#define COLA_CIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ( (x)<=(y) ? (x) : (y))

//aca tambien siempre inserto y saco del segundo elemento

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_cola;


void crear_cola(t_cola * pc);

int poner_en_cola(t_cola *pc, const void * d, unsigned tam_dato);
int sacar_de_cola(t_cola *pc, void * d, unsigned tam_dato);

int ver_frente_de_cola(const t_cola *pc, void *d, unsigned tam_dato);

int cola_vacia(const t_cola * pc);
int cola_llena(const t_cola * pc, unsigned tam_dato);

void vaciar_cola(t_cola * pc);



#endif // COLA_CIRCULAR_H_INCLUDED
