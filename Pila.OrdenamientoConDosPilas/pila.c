#include "pila.h"


//inicializo un puntero que no apunta a nada
void crear_pila(t_pila *p)
{
    *p= NULL;   //con esto digo que el puntero del main apunte a nada, o sea null.
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



int pila_vacia(const t_pila *p)
{
    return *p==NULL;    //pregunto si p del main apunta a NULL
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato)
{
    t_nodo * nue = (t_nodo *) malloc(sizeof(t_nodo));   //pido memoria  //creo nodo

    if(!nue)    //valido que esa memoria que pedi se haya podido reservar   //si el nodo nuevo es nulo..
    {
        return 0;   //0 de falso, es decir PILA LLENA
    }

    //ahora debo reservar memoria para el dato

    nue->info= malloc(tam_dato);

    //verifico si pudo reservar memoria
    if(!nue->info)  //nue->info==NULL?
    {
        free(nue);
        return 0;   //PILA LLENA
    }

    nue->tam_info = tam_dato;
    nue->sig = *p;  //con esto hago que el nuevo nodo apunte al anterior nodo creado, que era al que punta la pila p en el main
    memcpy(nue->info, d, tam_dato);

    *p = nue;   //ahora p apunta a este nuevo nodo creado
                //en el main p apuntara a este nodo
    return 1;   //si pasa por aca es VERDADERO
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato)
{

    t_nodo * elim = *p;

    //primero valido que la pila no este vacia
    if(!*p)
    {
        return 0;
    }


    //primero recupero el dato
    //tengo que evaluar que no me esten pidieron algo con un tamaño distinto
    memcpy(d, elim->info, MINIMO(elim->tam_info, tam_dato));
    //elijo el minimo de esos dos valores para copiar, porque si agarra el mayor puede pisar valores
    *p= elim->sig;  //ahora pila p apuntara a otro nodo

    //ahora que copie las cosas libero la memoria
    free(elim->info);
    free(elim);
    return 1;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


int ver_tope(const t_pila *p, void *d, unsigned tam_dato)
{
    if(*p ==NULL)
        return 0;

    memcpy(d, (*p)->info, MINIMO((*p)->tam_info, tam_dato));

    return 1;
}
