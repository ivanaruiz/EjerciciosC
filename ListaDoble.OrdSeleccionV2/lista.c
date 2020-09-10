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




t_nodo * buscarMenor(t_nodo * act, int (*cmp)(const void *, const void *), int * encontroMenor)
{
    t_nodo * men = act;
    act= act->sig;

    *encontroMenor = 0;

    while(act)
    {
        if(cmp(act->info, men->info) < 0)
        {
            *encontroMenor = 1;
            men = act;
        }
        act= act->sig;
    }
    return men;
}



void reinsertarNodos(t_nodo * act, t_nodo * men)
{
    t_nodo * aux = men;


    if(men->sig)                //desengacho cuando el nodo está en el medio
    {
        men->ant->sig = men->sig;
        men->sig->ant = men->ant;
    }
    else
        men->ant->sig = NULL;   //desengancho cuando el nodo está al final


    if(!act->ant)               //engancho el nodo al inicio
        aux->ant = NULL;
    else                        //sino engancho al nodo en el medio
    {
        aux->ant = act->ant;
        act->ant->sig = aux;
    }

    aux->sig= act;              //finalmente termino de enganchar al nodo
    act->ant = aux;
}



void ordenar_lista_x_seleccion(t_lista * pl,
                               int (*cmp)(const void *, const void *))
{
    t_nodo * act = *pl;

    act= irAlInicio(act);

    int encontroMenor = 0;  //bandera


   while(act)
    {
        t_nodo * men;

        men = buscarMenor(act, cmp, &encontroMenor);

        if(men!=act)
            reinsertarNodos(act, men);

        if(!encontroMenor)  //si no encontró ningún menor, entonces que avanze act
            act = act->sig; //para empezar a comparar con otro numero
    }
}
