#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) ((X)<(Y) ? (X):(Y))

//defino la estructura del nodo
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

typedef struct
{
    char nombre[10];
    int edad;
}t_alumno;

void crear_pila(t_pila *p);
int pila_llena(const t_pila *p, unsigned tam_info);
int pila_vacia(const t_pila *p);
int poner_en_pila(t_pila *p, const void * d, unsigned tam_info);
int sacar_de_pila(t_pila *p, void * d, unsigned tam_info);
int ver_tope(const t_pila *p, void * d, unsigned tam_info);
void vaciar_pila(t_pila *p);


#endif // PILA_DINAMICA_H_INCLUDED
