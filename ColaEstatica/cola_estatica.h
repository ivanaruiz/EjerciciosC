#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ( (x)<=(y) ? (x) : (y))

#define TAM_COLA 300

typedef struct
{
    char cola [TAM_COLA];
    unsigned pri;   //primero "persigue" a ultimo
    unsigned ult;
    unsigned tam_disponible;
}t_cola;

void crear_cola(t_cola * pc);

int poner_en_cola(t_cola *pc, const void * d, unsigned tam_dato);
int sacar_de_cola(t_cola *pc, void * d, unsigned tam_dato);

int ver_frente_de_cola(const t_cola *pc, void *d, unsigned tam_dato);

int cola_vacia(const t_cola * pc);
int cola_llena(const t_cola * pc, unsigned tam_dato);

void vaciar_cola(t_cola * pc);


#endif // COLA_ESTATICA_H_INCLUDED
