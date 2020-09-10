#include "arbol.h"
#include "producto.h"

void crearArbol(tArbolBinBusq * p)
{
    *p = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//mas abajo hay otra versión parecida de esta función
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * d, unsigned cantReg, unsigned tam)
{
    if(*p || !d)
        return 0;

    return cargarDesdeDatosOrdenadosRec(p, d, 0, cantReg-1, tam);
}

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * d, int li, int ls, unsigned tam)
{
    int m = (li+ls)/2;
    int r;

    if(li>ls)
        return 1;

    (*p) = (tNodoArbol *)malloc(sizeof(tNodoArbol));

    if(*p == NULL || ((*p)->info = malloc(tam)) == NULL)
    {
        free(*p);
        return 0;
    }


    memcpy((*p)->info , d+(tam*m), tam);
    (*p)->tamInfo = tam;


    (*p)->izq = (*p)->der = NULL;


    if((r=cargarDesdeDatosOrdenadosRec(&(*p)->izq, d, li, m-1, tam)) != 1)
        return 1;
    return cargarDesdeDatosOrdenadosRec(&(*p)->der, d, m+1, ls, tam);
}



//OTRA VERSIÓN
/*
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * d, unsigned cantReg, unsigned tam)
{
    if(*p || !d)
        return 0;

    return cargarDesdeDatosOrdenadosRec(p, d, 0, cantReg-1, tam);
}

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * d, int li, int ls, unsigned tam)
{
    int m = (li+ls)/2;
    int r;

    if(li>ls)
        return 1;

    tNodoArbol * nue = (tNodoArbol *)malloc(sizeof(tNodoArbol));

    if(!nue)
        return 0;

    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    //acá ya copio al nodo nue creado lo que haya en el vector en cierta posición
    //la posición es m
    //para llegar a la posición se la sumo al vector (recordar multiplicar por el tamaño del dato
    memcpy(nue->info, d+(tam*m), tam);
    nue->tamInfo = tam;

    *p = nue;

    nue->izq = nue->der = NULL;

    if((r=cargarDesdeDatosOrdenadosRec(&(nue)->izq, d, li, m-1, tam)) != 1)
        return 1;
    return cargarDesdeDatosOrdenadosRec(&(nue)->der, d, m+1, ls, tam);
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenRecArbolBinBusq(p, 0, params, accion);
}

void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                    void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return ;
    recorrerEnOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*))
{
    recorrerEnOrdenInversoRecArbolBinBusq(p, 0, params, accion);
}

void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*))
{
    if(!*p)
        return;
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->der, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
