#include "pila.h"


void crearPila(tPila * p)
{
    *p = NULL;
}

int ponerEnPila(tPila * p, const void * d, unsigned tam_dato)
{
    tNodo * nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);

    nue->sig = *p;
    *p = nue;

    return 1;
}

int pilaVacia(const tPila *p)
{
    return *p==NULL;
}

int sacarDePila(tPila * p, void * d, unsigned tam_dato)
{
    tNodo * aux = *p;

    if(!*p)
        return 0;

    memcpy(d, (*p)->info, minimo((*p)->tamInfo, tam_dato));

    *p = aux->sig;

    free(aux->info);
    free(aux);

    return 1;
}
