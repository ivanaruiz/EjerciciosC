
#include "pila_dinamica.h"

void crear_pila(t_pila *p)
{
    *p= NULL;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato)
{
    t_nodo * nue = (t_nodo *)malloc(sizeof(t_nodo));

    if(!nue)
        return 0;

    nue->info = malloc(tam_dato);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info , d, tam_dato);
    nue->sig= *p;
    nue->tam_info = tam_dato;

    *p= nue;

    return 1;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


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


int pila_vacia(const t_pila *p)
{
    return *p==NULL;
}
