#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) ((X)<(Y) ? (X):(Y))

typedef struct s_nodo
{
    void * info;            //puntero al dato
    unsigned tam_info;      //el tamaño del dato
    struct s_nodo * sig;    //puntero al siguiente nodo
}t_nodo;


//necesito algo que me diga dónde empieza esta lista
//es decir necesito un puntero a nodo, algo que nos diga "esta es la lista, aca comienza"
typedef t_nodo * t_pila;    //es un puntero a nodo
//esta es la pila de comienzo digamos

//prototipos
void crear_pila(t_pila *p);
int pila_vacia(const t_pila *p);
int poner_en_pila(t_pila *p, const void * d, unsigned tam_info);
int sacar_de_pila(t_pila *p, void * d, unsigned tam_info);
int ver_tope(const t_pila *p, void * d, unsigned tam_info);


#endif // PILA_H_INCLUDED
