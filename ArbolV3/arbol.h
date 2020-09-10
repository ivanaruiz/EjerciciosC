#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define reservarMemoriaNodo(X,Y,Z,W)  (((X)= (typeof(X))malloc(Y)) == NULL || ((Z) = malloc(W)) ==NULL ? free(X) , 0:1)
typedef struct sNodoArbol
{
    void * info;
    unsigned tamInfo;
    struct sNodoArbol * izq;
    struct sNodoArbol * der;
}tNodoArbol;

typedef tNodoArbol * tArbolBinBusq;

void crearArbol(tArbolBinBusq * p);

//esta funcion carga desde cualquier lado, de un set de datos, de un arch binario, de texto, etc
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * ds, unsigned cantReg,
                                          unsigned (*leer) (void **, void *, unsigned, void * params),
                                          void * params);
int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * ds,
                                 unsigned (*leer)(void **, void *, unsigned, void * params),
                                 int li, int ls, void * params);
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

int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path,
                                         unsigned tamInfo);
unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params);



#endif // ARBOL_H_INCLUDED
