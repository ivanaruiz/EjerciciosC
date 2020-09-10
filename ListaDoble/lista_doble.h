#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y)    ((x)<=(y) ? (x):(y))

//lista va a apuntar al nodo donde se hizo la ultima operacion
//vamos a usar punteros auxiliares para movernos por la lista
//los punteros auxi  liares son punteros a nodo, no a lista
typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * ant;
    struct s_nodo * sig;
}tNodo;

typedef tNodo * tLista;

void crear_lista(tLista * pl);
int poner_orden_lista(tLista * pl, const void * d, unsigned tam_dato, int (*cmp)(const void *, const void *));
int lista_vacia(const tLista * pl);
int sacar_orden_lista(tLista * pl, void * d , unsigned tam_dato);
int ver_ultimo_elem_agregado(const tLista * pl, void * d, unsigned tam_dato);
int ver_primer_elem_lista(tLista * pl, void * d, unsigned tam_dato);
int ver_ultimo_elem_lista(tLista * pl, void * d, unsigned tam_dato);
int contar_elementos(tLista * pl);
int poner_orden_lista_duplicados(tLista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *));
int mostrar_lista(tLista * pl);
void eliminar_duplicados(tLista * pl, int (*cmp)(const void*, const void *));
int sacar_elem_ord(tLista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *));
int vaciar_lista(tLista * pl);
void mostrar_movimiento(void * d);
//void buscar_los_repes(tLista * pl, int (*cmp)(const void*, const void *));
void buscar_los_repes(tNodo * pl, int (*cmp)(const void*, const void *));
int insertarAlFinal(tLista * pl, const void * d, unsigned tam_dato);
int insertarAlComienzo(tLista * pl, const void * d, unsigned tam_dato);
int mostrarDeIzqADer(const tLista * pl, void(*mostrar)(const void *));
int eliminarPorClave(tLista * pl, void * d, unsigned tam_dato,
                     int (*comparar)(const void *, const void *));
#endif // LISTA_DOBLE_H_INCLUDED
