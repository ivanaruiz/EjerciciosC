#include "pila_circular.h"

void crear_pila(t_pila * p)
{
    *p = NULL;
}

int pila_vacia(const t_pila *p)
{
    return *p == NULL;
}

//siempre vamos a poner en el segundo elemento
//excepto el primer nodo, que es primero y "segundo"
//algo así como que el primer nodo se apunta a sí mismo
int poner_en_pila(t_pila * p, const void * d, unsigned tam_dato)
{
    t_nodo * nue;

    if((nue = (t_nodo *)malloc(sizeof(t_nodo)))==NULL ||
            (nue->info = malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;
    }

    //ahora cargamos la informacion al nodo

    nue->tam_info = tam_dato;
    memcpy(nue->info, d, tam_dato);

    //el enganche
    //cuando hay un solo nodo, el sig (del nodo) se apunta a si mismo

    if(!*p) //si aun no existen nodos en la pila..
    {
        nue->sig = nue; //se autoapunta
        //asigno el puntero p a este nuevo nodo
        *p = nue;
    }
    else    //paso por el else cuando inserto mas datos
    {
        nue->sig = (*p)->sig;   //pensar siempre que estoy insertando en el segundo elemento
                                //por eso uso hago que el sig de nue sea (*p)->sig
        (*p)->sig = nue;
    }

    return 1;
}

//otra manera de encararlo
/*
int poner_en_pila(t_pila * p, const void * d, unsigned tam_dato)
{
    t_nodo * nue;

    if((nue = (t_nodo *)malloc(sizeof(t_nodo)))==NULL ||
            (nue->info = malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;
    }

    //ahora cargamos la informacion al nodo

    nue->tam_info = tam_dato;
    memcpy(nue->info, d, tam_dato);

    //el enganche
    //cuando hay un solo nodo, el sig (del nodo) se apunta a si mismo

    if(!*p)
        *p = nue;               //asigno el puntero p a este nuevo nodo

    else
        nue->sig = (*p)->sig;   //pensar siempre que estoy insertando en el segundo elemento
                                //por eso uso hago que el sig de nue sea (*p)->sig

    (*p)->sig = nue;

    return 1;
}
*/


int sacar_de_pila(t_pila *p, void * d, unsigned tam_dato)
{
    t_nodo * elim;

    if(!*p)   //primero verifico si la pila esta vacia
    {
        printf("pila vacia\n");
        return 0;
    }

    //hay que sacar el segundo elemento de la pila
    elim = (*p)->sig; //porque es el segundo
    //asi reesguardé el nodo que voy a eliminar

    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));

    //lo desengancho al nodo elim
    if( elim == elim->sig)  //si entro por aca es porque se trata del ultimo nodo, o sea que esto daría igual
        *p = NULL;          //ya que al haber un solo nodo, se autoapunta
    else
        (*p)->sig = elim->sig;  //si vengo por aca, estoy desenganchando siempre el segundo nodo

    free(elim->info);
    free(elim);

    return 1;
}


int pila_llena(const t_pila *p, unsigned tam_info)
{
    t_nodo  *   aux  =  (t_nodo *)malloc(sizeof(t_nodo));
    void    *   info =  malloc(tam_info);

    free(aux);
    free(info);

    return aux ==NULL || info == NULL;
}


int ver_tope(const t_pila *p, void * d, unsigned tam_info)
{
    if(*p== NULL)
        return 0;

    memcpy(d, (*p)->sig->info, MINIMO(tam_info, (*p)->sig->tam_info));
    //recordar que con (*p)-> sig, apunto al segundo nodo

    return 1;
}


void vaciar_pila(t_pila *p)
{
    while (*p)
    {
        t_nodo * aux = (*p)->sig;   //apunto al segundo nodo

        if(*p==aux) //si entra aca es porque quedó un solo nodo
            *p = NULL;

        else    //si viene por aca es porque hay mas de un nodo
            (*p)->sig = aux->sig;   //desengancha el segundo siempre

        free(aux->info);
        free(aux);
    }
}


