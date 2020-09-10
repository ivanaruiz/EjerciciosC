#include "lista.h"

void crear_lista(t_lista * pl)
{
    *pl = NULL;
}


int lista_vacia(const t_lista *pl)
{
    return *pl==NULL;
}




//pedir memoria para crear un nodo es algo que pesa mucho,
//y siempre es mejor evitarlo si no se sabe si el nodo se usará.
int poner_orden_lista(t_lista * pl, const void * d, unsigned tam_dato, int (*cmp) (const void *, const void *))
{
    t_nodo * nue;
    int res_cmp;

    //mientras que el dato a ingresar sea mayor que el nodo de la lista, sigo recorriendo la lista con el while
    //cuando encuentre uno mayor, corta. si encuentra uno igual, también corta.
    while(*pl && (res_cmp = cmp(d, (*pl)-> info)) > 0)
        pl = &(*pl)->sig;

    //si existe la lista y el resultado de la comparacion fue 0..
    if(*pl && res_cmp==0)
    {
        printf("\nNo se ingreso por ser duplicado");
        return 0;
    }

    nue = (t_nodo *) malloc (sizeof(t_nodo));
    if(!nue)
    {
        printf("lista llena\n");
        return 0;
    }

    //notar que recién aquí reservo memoria para el nodo pues
    //a esta altura ya sabemos que encontramos lugar dónde colocarlo
    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        printf("lista llena\n");
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;
    nue->sig = *pl;

    *pl = nue;

    return 1;
}


/*
//es versión es por si quiero meter incluyendo duplicados
int poner_orden_lista(t_lista * pl, const void * d, unsigned tam_dato, int (*cmp) (const void *, const void *))
{
    while(*pl && cmp(d, (*pl)->info)>0)
        pl =&(*pl)->sig;

    t_nodo * nue;
    if(!(nue = (t_nodo *)malloc(sizeof(t_nodo))) || !(nue->info = malloc(tam_dato)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;

    nue->sig = *pl;
    *pl = nue;

    return 1;
}
*/



void mostrar_lista(const t_lista * pl)
{
    //mientras exista la lista, me voy moviendo
    while(*pl)
    {
        printf("-%d-", *((int*)(*pl)->info));
        pl = &(*pl)->sig;
    }
}


//no necesariamente la lista está ordenada aca
int sacar_elem_lista(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void* , const void*))
{
    //mientras exista la lista y mientras la comparacion sea distinta (es decir que aun no haya encontrado el dato),
    //entonces sigo recorriendo la lista
    while(*pl && cmp(d, (*pl)->info)!= 0 )
    {
        pl = &(*pl)->sig;
    }

    if(!*pl) //si no existe el elemento
    {
        printf("\nel elemento que desea sacar no existe en la lista");
        return 0;
    }

    //encontramos el dato que quiero eliminar
    t_nodo * elim;
    elim = *pl;

    //agrego una copia del dato, capaz para enteros es al pedo, pero sirve para cuando son estructuras y borro por alguna clave
    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));

    //desengancho
    *pl = elim->sig;

    free(elim->info);
    free(elim);
    return 1;

}

//otra versión
/*
int sacar_elem_orden_lista(t_lista * pl, void * d, unsigned tam_dato,
                           int (*cmp)(const void *, const void *))
{
    if(!*pl)
        return 0;

    while(*pl)
    {
        if(cmp((*pl)->info, d) == 0)
        {
            t_nodo * elim = *pl;

            memcpy(d, elim->info, MINIMO(elim->tam_info, tam_dato));

            *pl = elim->sig;

            free(elim->info);
            free(elim);
            return 1;
        }
        pl = &(*pl)->sig;
    }
    return 0;
}
*/


//SOLO FUNCIONA CON LA LISTA ESTA ORDENADA
int sacar_elem_orden_lista(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void* , const void*))
{
    int res_cmp;

    while(*pl && (res_cmp =cmp(d, (*pl)->info)) > 0 )
    {
        pl = &(*pl)->sig;
    }

    if(!*pl || res_cmp!=0) //si no existe la lista o la comparacion fue distinto de 0, es porque no existe elem
    {
        printf("\nel elemento que desea sacar no existe en la lista");
        return 0;
    }

    //encontramos el dato que quiero eliminar
    t_nodo * elim;
    elim = *pl;

    //agrego una copia del dato, capaz para enteros es al pedo, pero sirve para cuando son estructuras y borro por alguna clave
    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));

    //desengancho
    *pl = elim->sig;

    free(elim->info);
    free(elim);
    return 1;
}
