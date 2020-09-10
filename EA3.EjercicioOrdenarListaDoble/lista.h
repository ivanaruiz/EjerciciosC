#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y)    ((x)<=(y) ? (x):(y))

typedef struct
{
    char apyn[8];
    char let;
}tAlumno;

typedef struct s_nodo
{
    void * info;
    unsigned tam_info;
    struct s_nodo * ant;
    struct s_nodo * sig;
}tNodo;

typedef tNodo * tLista;
void crear_lista(tLista * pl);
int poner_ultimo_lista(tLista * pl, const void * d, unsigned tam_dato);
int mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp);
void mostrarFinal_MIO(const void *d, FILE *fp);

void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *));
int  compararFinal_MIO(const void *d1, const void *d2);


/**
void reacomodarElPrimero(tNodo * inicio, tNodo * mayor);
tNodo * reacomodarLosSiguientes(tNodo * auxAnt, tNodo * auxSig, tNodo * mayor,
             int (*comparar)(const void *, const void *));
tNodo * buscarMayor(tNodo * inicio, int (*comparar)(const void *, const void *), int * max);
tNodo * irInicio(tLista *p);
**/


int  buscar_repetidos(tNodo * act, FILE * fp);
tNodo * buscarMayor(tNodo * act, int * );
tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * );
tNodo * irAlInicio(tNodo * act);
#endif // LISTA_H_INCLUDED
