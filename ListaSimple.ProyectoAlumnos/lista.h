#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y) ((x)<=(y) ? (x):(y))
#include "alumno.h"

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_lista;



void crear_lista(t_lista * pl);

int lista_vacia(const t_lista *pl);

int cargar_lista(t_lista * pl);

int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato);

int mostrar_lista(t_lista * pl);

int actualizar_lista(t_lista * pl, int (*cmp_dni)(const void * a1, const void * a2),
                                    int (*cmp_mat)(const void * a1, const void * a2));

void buscar_repetido(t_lista * pl, int (*cmp_dni)(const void *, const void *),
                                    int (*cmp_mat)(const void * a1, const void * a2));

void actualizar_datos(void * d1, void * d2);

void ordenar_lista_burbujeo(t_lista * pl, int (*cmp_dni)(const void *, const void *), int ce);

void ordenar_de_a_pares(t_lista * pl, int (*cmp_dni)(const void *, const void *), int * ce);

void intercambio(t_lista * pl, t_lista * men);


#endif // LISTA_H_INCLUDED
