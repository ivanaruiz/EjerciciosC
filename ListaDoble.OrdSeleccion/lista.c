#include "lista.h"


void crear_lista(t_lista * pl)
{
    *pl = NULL;
}



//esta función inserta elementos pero NO EN ORDEN
int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato)
{
    t_nodo * auxsig = *pl;
    t_nodo * auxant = auxsig!=NULL ? auxsig->ant : NULL;


    t_nodo * nue;
    if((nue = (t_nodo *)malloc(sizeof(t_nodo)))== NULL ||
        (nue->info = malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;   //sin memoria
    }


    memcpy(nue->info , d, tam_dato);
    nue->tam_info = tam_dato;

    //ENGANCHO
    //PRIMERO DE NUE HACIA LOS NODOS AUXSIG Y AUXANT
    nue->sig = auxsig;
    nue->ant = auxant;

    //Y LUEGO DE LOS NODOS AUXSIG Y AUXANT A NUE
    if(auxsig)
    {
        auxsig->ant = nue;
    }
    if(auxant)
    {
        auxant->sig = nue;
    }


    //NO OLVIDAR SIEMPRE APUNTAR PL AL NUEVO NODO CON EL QUE TRABAJÉ
    *pl = nue;

    return 1;
}


//VOY AL INICIO DE UNA LISTA
t_nodo * irAlInicio(t_nodo * act)
{
    while(act->ant)
        act= act->ant;

    return act;
}



int mostrar_lista(t_lista * pl)
{
    if(*pl== NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    t_nodo * act = *pl;

    int cont = 0;

    act= irAlInicio(act);


    while(act)
    {
        printf("%d ", *(int*)act->info);
        cont++;
        act= act->sig;
    }

    return cont+1;
}




t_nodo * buscarMenor(t_nodo * act, int (*cmp)(const void *, const void *))
{
    t_nodo * men = act;
    act= act->sig;

    while(act)
    {
        if(cmp(act->info, men->info) < 0)
        {
            men = act;
        }
        act= act->sig;
    }
    return men;
}


//NO REINSERTA NODOS. INTERCAMBIA PUNTEROS Y TAMAÑOS
void intercambio_info_nodos(t_nodo * n1, t_nodo * n2)
{
    //intercambio los punteros
    void * aux  = (n1)->info;
    (n1)->info = (n2)->info;
    (n2)->info = aux;
    //intercambiar los tamaños
    unsigned aux_tam;
    aux_tam = (n1)->tam_info;
    (n1)->tam_info = (n2)->tam_info;
    (n2)->tam_info = aux_tam;
}



void ordenar_lista_x_seleccion(t_lista * pl,
                               int (*cmp)(const void *, const void *))
{
    t_nodo * act = *pl;

    act= irAlInicio(act);


    while(act)
    {
        t_nodo * men;

        men = buscarMenor(act, cmp);

        intercambio_info_nodos(act, men);

        act=act->sig;
    }

}
