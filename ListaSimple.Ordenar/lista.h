#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y) ((x)<=(y) ? (x):(y))

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_lista;


void crear_lista(t_lista * pl);

int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato);

void ordenar_seleccion_lista(t_lista * pl, int (*cmp)(const void *, const void *));

void mostrar_lista(const t_lista * pl);

t_nodo ** buscarMenor(const t_lista * pl, int (*cmp)(const void *, const void *));

void reinsertar_nodos(t_lista * pl, t_lista * men);

#endif // LISTA_H_INCLUDED
