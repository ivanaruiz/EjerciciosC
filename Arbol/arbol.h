#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define reservarMemoriaNodo(X,Y,Z,W)  (((X)= (typeof(X))malloc(Y)) == NULL || ((Z) = malloc(W)) ==NULL ? free(X) , 0:1)
#define MINIMO(X,Y) ((X)<=(Y) ? (X):(Y))
typedef struct sNodoArbol
{
    void * info;
    unsigned tamInfo;
    struct sNodoArbol * izq;
    struct sNodoArbol * der;
}tNodoArbol;

typedef tNodoArbol * tArbolBinBusq;



void crearArbol(tArbolBinBusq * p);

int insertarArbolBinBusq(tArbolBinBusq * p, const void * d, unsigned tam, int (*cmp)(const void *, const void *));


void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                    void (*accion)(void *, unsigned, unsigned, void *));
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *));
void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                  void (*accion)(void *, unsigned, unsigned, void *));
void recorrerPreOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n,
                                     void * params,
                                     void (*accion)(void*, unsigned, unsigned, void *));
void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                  void (*accion)(void*, unsigned, unsigned, void*));
void recorrerPosOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                     void (*accion)(void *, unsigned, unsigned, void *));
void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*));
void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                           void (*accion)(void *, unsigned, unsigned, void *));

//funciones mias
int contarNodos(const tArbolBinBusq * p);
int contarRecNodos(const tArbolBinBusq * p, unsigned n, unsigned * cont);
int contarNodosV2(const tArbolBinBusq * p);
int contarNodosV2Rec(const tArbolBinBusq * p, unsigned * cont);
int esArbolBinCompleto(const tArbolBinBusq * p);
int esArbolBinBalanceado(const tArbolBinBusq * p);

int alturaArbolBin(const tArbolBinBusq * p);
int alturaArbolBinRec(const tArbolBinBusq * p, unsigned n, unsigned * maxAltra);

int contarNodosHastaAlturaBalanceada(const tArbolBinBusq * p, unsigned * altura);
int contarRecNodosHastaAlturaBalanceada(const tArbolBinBusq * p, unsigned n, unsigned * alturaMax, unsigned * contNodos);

int buscarElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam,
                       int (*comparar)(const void *, const void *));

int buscarMenorElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam,
                            int (*comparar)(const void *, const void *));

int buscarMayorElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam,
                            int (*comparar)(const void *, const void *));

int buscarRaizArbolBin(const tArbolBinBusq * p, void * d, unsigned tam);

int sumarElemArbolBin(const tArbolBinBusq * p);
int sumarElemArbolBinRec(const tArbolBinBusq * p, unsigned n, void * acum, unsigned tamAcum);

void vaciarArbol(tArbolBinBusq * p);
void podarArbol(tArbolBinBusq * p);

void mostrarNodosConAmbosHijos(const tArbolBinBusq * p, void (*accion)(void*, unsigned, unsigned, void *));
void mostrarHijos(const tArbolBinBusq * p, void (*accion)(void*, unsigned, unsigned, void*));

int eliminarSoloHijo(tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *));
int eliminarCualquierNodoMenosRaiz(tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *));

void podarHastaConvertirAArbolCompleto(tArbolBinBusq * p, int (*cmp)(const void *, const void *));
void podarHastaNivel(tArbolBinBusq* p, unsigned n, unsigned tope);

const tArbolBinBusq * mayorNodoNoClaveArbol(const tArbolBinBusq * p,
                                            const tArbolBinBusq * mayor,
                                            int (*cmp)(const void *, const void*));
int mayorElemNoClaveArbol(const tArbolBinBusq * p, void * d, unsigned tam,
                          int (*cmp)(const void *, const void*));

/*
void podarHastaConvertirAArbolCompleto(tArbolBinBusq * p, int (*comparar)(const void *, const void *));
int buscarLadoIzq(tArbolBinBusq * p, tNodoArbol * aux, unsigned n, int (*comparar)(const void *, const void *), int * li);
int buscarLadoDer(tArbolBinBusq * p, tNodoArbol * aux, unsigned n, int (*comparar)(const void *, const void *), int * ld);
void podarHastaNivel(tArbolBinBusq * p, int hasta, unsigned n);
*/


//funciones del profe
unsigned alturaArbolBin2(const tArbolBinBusq * p);
unsigned cantNodosArbolBin(const tArbolBinBusq * p);
int eliminarRaizArbolBinBusq(tArbolBinBusq * p);
tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq * p);
tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq * p);
#endif // ARBOL_H_INCLUDED
