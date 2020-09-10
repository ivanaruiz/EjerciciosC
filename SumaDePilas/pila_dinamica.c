
#include "pila_dinamica.h"


void crear_pila(t_pila *p)
{
    *p = NULL;
}


int pila_vacia(const t_pila *p)
{
    return *p==NULL;
}


int pila_llena(const t_pila *p , unsigned tam_dato)
{
    t_nodo * aux = (t_nodo *)malloc(sizeof(t_nodo));
    void * info  = malloc(tam_dato);

    free(aux);
    free(info);

    return aux==NULL || info==NULL;
}


int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato)
{
    t_nodo * nue = (t_nodo *)malloc(sizeof(t_nodo));

    if(!nue)
    {
        printf("pila llena!\n");
        return 0;
    }

    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        printf("pila llena!\n");
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;
    nue->sig = *p;

    *p= nue;

    return 1;
}



int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato)
{
    t_nodo * elim = *p;

    if(elim==NULL)
        return 0;

    memcpy(d, elim->info, minimo(elim->tam_info, tam_dato));
    *p= elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

void vaciar_pila(t_pila *p)
{
    while(*p)
    {
        t_nodo * aux = *p;
        *p = aux->sig;

        free(aux->sig);
        free(aux);
    }
    printf("\nVacie pila\n");
}



int ver_tope(const t_pila *p, void *d, unsigned tam_dato)
{
    if(*p ==NULL)
        return 0;

    memcpy(d, (*p)->info, minimo((*p)->tam_info, tam_dato));

    return 1;
}

