#include "lista.h"


void crear_lista(t_lista * pl)
{
    *pl = NULL;
}


int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato)
{
    //creo el nodo
    t_nodo * nue = (t_nodo *) malloc (sizeof(t_nodo));

    if(!nue)
    {
        printf("lista llena\n");
        return 0;
    }

    //creo la memoria para la informacion y valido que esa memoria haya sido creada
    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        printf("lista llena\n");
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;
    nue->sig = NULL;

    while(*pl)  //recorro hasta que *p1==NULL, que sería hasta el último nodo que tenía antes
    {
        pl = &(*pl)->sig;
    }

    *pl = nue;

    return 1;
}





void mostrar_lista(const t_lista * pl)
{
    while(*pl)
    {
        printf("%d ", (*(int*)(*pl)->info));    //casteamos para mostrar
        pl = &(*pl)->sig;
    }
}

/**
1-buscar el menor
2-intercambiar
3-avanzar
**/



t_nodo ** buscar_menor(const t_lista * pl, int (*cmp)(const void *, const void *))
{
    //el menor es el primero de la lista (por ahora)
    //menor quedó apuntando a la lista

    //asi digo que lo constante es el segundo puntero
    //o sino podria usar const t_lista * men
    //voy a asumir que el menor es el primero de una lista
    //const t_lista * men = pl;
    t_nodo *const* men = pl;

    if(!*pl)
        return 0;

    //para no comparar con el mismo elemento, leo un nodo mas
    pl = &(*pl)->sig;   // me movi uno para adelante
    //es decir pl queda apuntando al miembro siguiente del primer nodo


    while(*pl)
    {
        if(cmp((*pl)->info , (*men)->info)<0)
        {
            men = pl;
            //si el pl es menor que men, entonces hago eso
            //es decir cuando encuentro uno menor, men pasa apuntar a lo mismo que apunta pl
        }
        pl = &(*pl)->sig;
    }
    return (t_nodo **) men; //lo casteo
}

//recibe dos punteros a lista
void intercambio_info_nodos(t_lista * n1, t_lista * n2)
{
    //intercambio los punteros
    void * aux  = (*n1)->info;
    (*n1)->info = (*n2)->info;
    (*n2)->info = aux;

    //intercambiar los tamaños
    unsigned aux_tam;
    aux_tam = (*n1)->tam_info;
    (*n1)->tam_info = (*n2)->tam_info;
    (*n2)->tam_info = aux_tam;
}

//reinsertor el nodo 2 en el lugar del 1
//este metodo es mas eficiente que el otro, aunque se puede usar cualquiera de los dos
void reinsertar_nodo_menor(t_lista * pl, t_lista * men)
{
    t_nodo * aux = *men;
    *men = aux->sig;    //o también *men= (*men)->sig;      //desengancho

    aux->sig = *pl;     //lo engancho donde corresponde
    *pl = aux;
}



void ordenar_seleccion_lista(t_lista * pl, int (*cmp)(const void *, const void *))
{
    if(!*pl)
        return;


    t_lista * inicio = pl;

    while((*pl)->sig)   //esto me ahorra la ultima comparacion, me sirve mas que while(*pl)
                        //ya que en la seleccion, el ultimo elemento ya esta ordenado
    {
        //a la funcion de buscar_menor le paso la lista
        t_nodo ** men = buscar_menor(pl, cmp);
        //también podría haber declarado t_lista men;  y haber trabajado así

        //me fijo si el menor que acabo de encontrar es el mismo o no,
        //para no hacer un intercambio al pedo en caso de que sean iguales

        if(pl!=men)
        {
            //dos opciones viables de intercambio:
            //1- intercambiamos la informacion y su tamaño
            //2- intercambiamos todo el nodo

       //     intercambio_info_nodos(pl, men);    //1ª
            reinsertar_nodo_menor(pl, men);     //2ª

            puts("");
            mostrar_lista(inicio);
            puts("");
        }
        pl = &(*pl)->sig;
    }

}


