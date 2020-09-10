#include "lista.h"

void crear_lista(t_lista * pl)
{
    *pl = NULL;
}


int lista_vacia(const t_lista *pl)
{
    return *pl==NULL;
}


int poner_primero_lista(t_lista * pl, const void * d, unsigned tam_dato)
{
    t_nodo * nue = (t_nodo*) malloc(sizeof(t_nodo));

    if(!nue)
    {
        printf("lista llena\n");
        return 0;
    }

    //reservo memoria para el tamaño que me dijeron que mide el dato
    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        free(nue);
        return 0;   //LISTA LLENA
    }

    //ya llegados aqui, es porque tengo creado el nodo de la lista

    nue->tam_info = tam_dato;
    memcpy(nue->info, d, tam_dato);
    nue->sig = *pl;     //*pl apuntaba a un nodo anterior, por eso se le asigno a nue->sig
                        //asi enlazo este nodo con el nodo anterior

    *pl = nue;          //ahora pl apunta a mi nuevo nodo como primero en la lista

    return 1;
}


int sacar_primero_lista(t_lista * pl, void * d, unsigned tam_dato)
{
    t_nodo * elim = *pl;    //mi nodo elim apunta al primer nodo de la lista(que es a lo que apunta pl)
    if(!elim)
    {
        printf("lista vacia\n");
        return 0;
    }

    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));

    //ya copiado el dato a sacar, hago que pl apunte al siguiente nodo que existe, por eso le pongo elim->sig
    *pl = elim->sig;

    free(elim->info);
    free(elim);
    return 1;
}

//vamos a tener que recorrer la lista hasta el ultimo elemento (nodo) para poder insertar allí
//es decir ponemos al final de la lista
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


    while(*pl)  //recorro hasta que *p1==NULL, que sería hasta el último nodo que tenía antes
    {
        pl = &(*pl)->sig;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;

    nue->sig = NULL;
    *pl = nue;

    return 1;
}


int poner_pos_lista(t_lista * pl, const void * d, unsigned tam_dato, unsigned pos)
{
    //si la pos es 1, este while no se tiene que ejecutar
    //si es 2 por ejemplo, el while se ejecuta una vez
    //y la segunda ya no (por el pos--), asi corto en el momento en que quiero cortar
    while(*pl && pos>1)
    {
        pl = &(*pl)->sig;
            if(*pl)
                pos--;
    }

    //esta validacion depende de la definicion del problema
    //si pos==0 , me tirara posicion invalida
    if(pos!=1)
    {
        printf("Posicion invalida\n");
        return 0;
    }

    t_nodo * nue = (t_nodo *) malloc (sizeof(t_nodo));

    if(!nue)
    {
        printf("lista llena\n");
        return 0;
    }

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


int sacar_pos_lista(t_lista * pl, void * d, unsigned tam_dato, unsigned pos)
{
    while(*pl && pos>1) //a medida que avanzo, mi pos ingresado decrementa, asi de esta manera recorro el while esa cant de veces
    {
        pl = &(*pl)->sig;
            if(*pl) //hago esto porque cuando llegue al ultimo nodo va a entrar igual al while, y recien en el paso anterior se cancela
                pos--;
    }

    if(pos!= 1) //deberia quedarme el pos (que fui decrementando) en 1 para que sea correcto
    {
        printf("posicion invalida\n");
        return 0;
    }

    memcpy(d, (*pl)->info, MINIMO(tam_dato, (*pl)->tam_info));

    free( (*pl)->info);
    free(*pl);

    *pl= (*pl)->sig;    //engancho el nodo anterior con el nodo siguiente al nodo que borré de equis posicion
    return 1;
}



int sacar_ultimo_lista(t_lista * pl, void * d, unsigned tam_dato)
{
    if(*pl == NULL)
    {
        printf("Lista vacia\n");
        return 0;
    }

    while( (*pl)->sig )  //mientras que no sea NULL..
    {
        pl = &(*pl)->sig;
    }

    memcpy(d, (*pl)->info, MINIMO(tam_dato, (*pl)->tam_info));

    free((*pl)->info);
    free(*pl);

    *pl= NULL;

    return 1;
}


int ver_primero_lista(const t_lista * pl, void * d, unsigned tam_dato)
{
    if(*pl==NULL)
    {
        printf("Lista vacia\n");
        return 0;
    }

    memcpy(d, (*pl)->info, MINIMO(tam_dato , (*pl)->tam_info));
    return 1;
}


int ver_ultimo_lista( const t_lista * pl, void * d, unsigned tam_dato)
{
    if(*pl== NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    while((*pl)->sig)    //mientras que no sea null, avanzo
    {
        pl = &(*pl)->sig;
    }

    memcpy(d, (*pl)->info, MINIMO(tam_dato, (*pl)->tam_info));

    return 1;
}


void vaciar_lista(t_lista * pl)
{
    while(*pl)
    {
        t_nodo * aux = *pl; //apunta siempre al primero, a medida que voy borrando
        *pl =  aux->sig;    //lo desengancho

        free(aux->info);
        free(aux);
    }
    printf("Vaciamos lista\n");
}

int lista_llena(const t_lista * pl, unsigned tam_dato)
{
    t_nodo * aux  = (t_nodo *)malloc(sizeof(t_nodo));
    void   * info = malloc(tam_dato);

    free(aux);
    free(info);

    return aux==NULL || info==NULL;
}

int contar_elem_lista(const t_lista *pl)
{
    int cont=0;

    if(*pl== NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    while(*pl)
    {
        pl = &(*pl)->sig;
        cont++;
    }

    return cont;
}


void mostrar_lista(const t_lista * pl)
{
    while(*pl)
    {
        printf("%d ", (*(int*)(*pl)->info));    //casteamos para mostrar
        pl = &(*pl)->sig;                       //recordar el casteo dentro del while porque
    }                                           //estoy casteando cada registro (cada (*pl)->info)
}

//modifica el contenido de una posicion dada
int modificar_nodo(t_lista * pl, const void * d , unsigned tam_dato, unsigned pos)
{
    while(*pl && pos>1) //busco la posición
    {
        pl = &(*pl)->sig;
            if(*pl)
                pos--;
    }

    if(pos!= 1)
    {
        printf("posicion invalida\n");
        return 0;
    }

    //modifico
    memcpy( (*pl)->info, d, MINIMO(tam_dato, (*pl)->tam_info ));
    return 1;
}

//modifico elemento de una lista no necesariamente ordenada (solo modifica la primera ocurrencia)
//le paso el dato viejo y el dato nuevo
int modificar_elem_unidad(t_lista * pl, void * d, unsigned tam_info, void *nd, unsigned tam_info_nuevo,
                          int (*cmp)(const void *, const void *))
{
    if(!*pl)
        return 0;

    while(*pl)  //avanza hasta el final
    {
        if((cmp((*pl)->info, d))==0)    //si llega acá lo encontró (al dato viejo a modificar)
        {
            memcpy((*pl)->info , nd , tam_info_nuevo);  //lo modifico y sale exitosamente
            return 1;
        }
        pl= &(*pl)->sig;
    }

    printf("\nNo se encontro el dato que desea modificar.\n");
    return 0;   //si llega acá es porque no lo encontró
}

//otra version
/*
int modificar_elem_unidad(t_lista * pl, void * d, unsigned tam_dato, void * nd, unsigned tam_nuevo, int(*cmp)(const void *, const void *))
{
    int res_cmp;
    while(*pl && (res_cmp= cmp(d, (*pl)->info)) !=0 )
    {
        pl = &(*pl)->sig;
    }

    if(!*pl)
    {
        printf("no existe el elemento a buscar\n");
        return 0;
    }

    if(res_cmp==0)
        memcpy( (*pl)->info, nd, MINIMO(tam_nuevo, (*pl)->tam_info) );


    return 1;
}
*/

//modifica todas las ocurrencias del dato que voy a modificar
int modificar_elem_todos(t_lista * pl, void * d, unsigned tam_dato, void * nd, unsigned tam_nuevo, int(*cmp)(const void *, const void *))
{
    int encontro_alguno=0;

    while (*pl)
    {
        if(*pl && cmp(d, (*pl)->info) ==0)
        {
            memcpy( (*pl)->info, nd, MINIMO(tam_nuevo, (*pl)->tam_info));
            encontro_alguno=1;
        }

        pl = &(*pl)->sig;
    }

    if(!encontro_alguno)
    {
        printf ("no se encontro el elemento a buscar\n");
                return 0;
    }

    else
        return 1;
}


//elimina la primera ocurrencia de un dato que quiero borrar
int eliminar_elem_unidad(t_lista *pl, void * d, unsigned tam_info,
                         int (*cmp)(const void*, const void*))
{
    if(!*pl)
        return 0;

    while(*pl)
    {
        if(cmp ((*pl)->info, d)==0 )    //lo encontró
        {
            free((*pl)->info);          //lo libera
            free(*pl);

            *pl = (*pl)->sig;           //hace el enganche del anterior con el siguiente

            return 1;                   //corta el ciclo
        }
        pl = &(*pl)->sig;
    }
    printf("\nNo se encontro el elemento que desea eliminar.\n");
    return 0;
}


/* otra versión
int eliminar_elem_unidad(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *))
{
    if(*pl ==NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    t_nodo * elim = *pl;
    int res_cmp;
    while(*pl && (res_cmp = cmp(d, (*pl)->info)) !=0 )
    {
        pl= &(*pl)->sig;
    }

    if(!*pl)
    {
        printf("no se encuentra el elemento buscado\n");
        return 0;
    }

    if(res_cmp==0)
    {
        elim= *pl;
        memcpy(elim->info, d, MINIMO(tam_dato, elim->tam_info));
    }

    *pl= elim->sig;

    free(elim->info);
    free (elim);
    return 1;
}
*/

//elimina todas las ocurrencias de un dato dado
int eliminar_elem_todos(t_lista * pl, void * d, unsigned tam_info,
                        int(*cmp)(const void *, const void *))
{
    if(!*pl)
        return 0;

    int encontro=0;

    while(*pl)
    {
        encontro=0;

        if(cmp((*pl)->info, d) == 0)
        {
            free((*pl)->info);
            free(*pl);

            *pl = (*pl)->sig;

            encontro=1;
        }

        if(encontro==0)         //hago esto porque cuando encuentra uno, y el siguiente es el mismo, se lo saltea
            pl = &(*pl)->sig;   //asi que si se encontró el dato buscado(int encontro=1), se saltea este paso
    }

    return 1;
}


/*otra versión de lo anterior
int eliminar_elem_todos(t_lista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *))
{
    int se_encontro=0;
    int pasar=0;

    if(*pl ==NULL)
    {
        printf("lista vacia\n");
        return 0;
    }


    while(*pl)
    {
        pasar=0;
        if(*pl && cmp(d, (*pl)->info) == 0)
        {
            se_encontro=1;

            t_nodo * elim = *pl;
            memcpy(elim->info, d, MINIMO(tam_dato, elim->tam_info));

            if(elim->sig==NULL)
            {
                *pl = NULL;
                free(elim->info);
                free (elim);
                return 1;
            }

            else
            {
                *pl= elim->sig;
                pasar=1;
            }


            free(elim->info);
            free (elim);

        }

    if(!pasar)
        pl= &(*pl)->sig;

    }

    if(!se_encontro)
    {
        printf("no se encontro el elemento buscado\n");
        return 0;
    }
    else
        return 1;
}

*/


int eliminar_elem_pares(t_lista * pl)
{
    if(!*pl)
        return 0;

    int encontro =0;

    while(*pl)
    {
        encontro =0;
        if( (*(int*)(*pl)->info) %2==0)
        {
            encontro=1;
            t_nodo * elim = *pl;

            free((*pl)->info);
            free(*pl);

            *pl = elim->sig;    //desenganché y enganché pl al siguiente del que liberé
        }

        if(!encontro)
            pl = &(*pl)->sig;   //esto es para que no se saltee nodos (cuando encuentra pares)
    }

    return 1;
}

//ESTA ES LA MEJOR VERSIÓN Y MÁS SENCILLA
//ABAJO HAY DOS VERSIONES MÁS
int eliminar_duplicados(t_lista * pl, int (*cmp)(const void *, const void *))
{
    if(!*pl)
        return 0;

    while(*pl)
    {
        buscarCadaNodo(pl, cmp);

        pl = &(*pl)->sig;
    }
    return 1;
}


void buscarCadaNodo(t_lista * pl, int (*cmp)(const void *, const void *))
{
    t_nodo * ori = *pl;
    pl = &(*pl)->sig;

    int encontro_repetido = 0;

    while(*pl)
    {
        encontro_repetido=0;

        if(cmp((*pl)->info, ori->info)==0)
        {
            encontro_repetido=1;

            free((*pl)->info);
            free(*pl);

            *pl = (*pl)->sig;
        }

        if(*pl && !encontro_repetido)
            pl = &(*pl)->sig;
    }
}


//si hay elementos duplicados, solo deja el primero de ellos, el resto los elimina
//lo que hace esta función es tener un nodo auxiliar que apunte al primero,
//luego se recorre toda la lista buscando duplicados y eliminando en caso de que se encuentre.
//una vez recorrida(eso se hace dentro de otra función),
//el nodo auxiliar debe apuntar al siguiente elemento de la lista,
//y volver a buscar duplicando recorriendo otra vez
//y así sucesivamente

/**
int eliminar_duplicados(t_lista * pl, int (*cmp)(const void *, const void *))
{
    if(!*pl)
        return 0;

    while(*pl)
    {
        t_nodo * aux = *pl;

        pl = &(*pl)->sig;

        if(*pl)
            recorrer_lista_y_eliminar_duplicados(pl, aux, cmp);

    }
    return 1;
}


void recorrer_lista_y_eliminar_duplicados(t_lista * pl, t_nodo * aux, int (*cmp)(const void *, const void *))
{
    int encontro=0;

        while(*pl)
        {
            encontro=0;
            if(cmp(aux->info, (*pl)->info)==0)
            {
                encontro=1;
                t_nodo * elim = *pl;

                *pl = (*pl)->sig;

                free((elim)->info);
                free(elim);
            }
            if(encontro==0)
                pl = &(*pl)->sig;
        }
}
**/

//Esta es otra versión
//Pero es mucho más eficiente la anterior
/*
int recorrer_lista_y_eliminar_duplicadoscados(t_lista * pl, int (*cmp)(const void*, const void *))
{
    if(*pl==NULL)
    {
        printf("lista vacia\n");
        return 0;
    }
    int pasar=0;
    t_lista * pri= pl;
    int incremento=0;
    int total;

    //no era necesario pedir memoria para un nodo
    //solo tenia que hacer que apunte a otro nodo , es decir un t_nodo * aux = *pl;
    t_nodo * aux = (t_nodo *)malloc(sizeof(t_nodo));
    aux= *pl;
    pl = &(*pl)->sig;

    while( (*pl))
    {
        incremento++;

        while(*pl)
        {
            pasar=0;
            if(cmp (aux->info, (*pl)->info)== 0)
            {
                t_nodo * elim = (t_nodo *)malloc(sizeof(t_nodo));
                elim= *pl;

                pasar=1;

                if( elim->sig == NULL)
                //if((*pl)->sig==NULL)
                {
                    *pl = NULL;
                }
                else
                {
                    *pl= (*pl)->sig;
                }
                free(elim->info);
                free(elim);
            }
        if(!pasar && *pl)

            pl = &(*pl)->sig;
        }//ciero while interno

    if(aux->sig!=NULL)
    {
        pl = pri;
        total= incremento;

        while(total)
        {
            total--;
            pl = &(*pl)->sig;
        }
            aux = * pl;

        if((*pl)->sig != NULL)
        {
            pl = &(*pl)->sig;
        }
        else
            return 1;
    }
    else
        return 1;


    }

//    aux->sig= NULL;

    return 1;
}

*/

