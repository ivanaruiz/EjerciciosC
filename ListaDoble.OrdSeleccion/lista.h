#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y)    ((x)<=(y) ? (x):(y))

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * ant;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_lista;


void crear_lista(t_lista * pl);
int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato);
t_nodo * irAlInicio(t_nodo * act);
int mostrar_lista(t_lista * pl);
t_nodo * buscarMenor(t_nodo * act, int (*cmp)(const void *, const void *));
void intercambio_info_nodos(t_nodo * n1, t_nodo * n2);
void ordenar_lista_x_seleccion(t_lista * pl,
                               int (*cmp)(const void *, const void *));

#endif // LISTA_H_INCLUDED
