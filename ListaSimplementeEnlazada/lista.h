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

int lista_vacia(const t_lista *pl);

int lista_llena(const t_lista *pl, unsigned tam_dato);

//es como poner_en_pila
int poner_primero_lista(t_lista * pl, const void * d, unsigned tam_dato);

//es como sacar_de_pila
int sacar_primero_lista(t_lista * pl, void * d, unsigned tam_dato);

//es como poner_en_cola, poner al final en la lista
int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato);

int poner_pos_lista(t_lista * pl, const void * d, unsigned tam_dato, unsigned pos);

int sacar_ultimo_lista(t_lista * pl, void * d, unsigned tam_dato);

int ver_primero_lista(const t_lista * pl, void * d, unsigned tam_dato);
int ver_ultimo_lista( const t_lista * pl, void * d, unsigned tam_dato);

void vaciar_lista(t_lista * pl);

int sacar_pos_lista(t_lista * pl, void * d, unsigned tam_dato, unsigned pos);

int contar_elem_lista(const t_lista *pl);

void mostrar_lista(const t_lista * pl);

int modificar_nodo(t_lista * pl, const void * d, unsigned tam_dato, unsigned pos);

int modificar_elem_unidad(t_lista * pl, void * d, unsigned tam_dato, void * nd, unsigned tam_nuevo, int(*cmp)(const void *, const void *));

int modificar_elem_todos(t_lista * pl, void * d, unsigned tam_dato, void * nd, unsigned tam_nuevo, int(*cmp)(const void *, const void *));

int eliminar_elem_unidad(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *));

int eliminar_elem_todos(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *));

int eliminar_elem_pares(t_lista * pl);

int eliminar_duplicados(t_lista * pl, int (*cmp)(const void*, const void *));
void recorrer_lista_y_eliminar_duplicados(t_lista * pl, t_nodo * aux, int (*cmp)(const void *, const void *));
void buscarCadaNodo(t_lista * pl, int (*cmp)(const void *, const void *));
#endif // LISTA_H_INCLUDED
