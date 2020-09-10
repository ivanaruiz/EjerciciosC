#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodoArbol
{
    void * info;
    unsigned tamInfo;
    struct sNodoArbol * izq;
    struct sNodoArbol * der;
}tNodoArbol;

typedef tNodoArbol * tArbolBinBusq;

void crearArbol(tArbolBinBusq * p);

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * d, unsigned cantReg, unsigned tam);

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * d, int li, int ls, unsigned tam);

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *));
void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                    void (*accion)(void *, unsigned, unsigned, void *));

void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*));

void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                           void (*accion)(void *, unsigned, unsigned, void *));

#endif // ARBOL_H_INCLUDED
