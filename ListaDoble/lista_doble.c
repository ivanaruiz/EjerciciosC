#include "lista_doble.h"

void crear_lista(tLista * pl)
{
    *pl = NULL;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

//no acepta duplicados

int poner_orden_lista(tLista * pl, const void * d, unsigned tam_dato, int (*cmp)(const void *, const void *))
{
    //estos me ayudaran
    tNodo * auxsig = *pl;
    tNodo * auxant = auxsig!=NULL ? auxsig->ant : NULL; //por si estaba la lista vacía, hago el if


    while(auxsig && cmp(d, auxsig->info)>0) //si entra por aca, me muevo a la derecha
                                            //mientras que d sea mayor a auxsig->info
    {
        auxant = auxsig;            //ojo con el orden
        auxsig = auxsig->sig;       //siempre asignar primero el que va "atras", en este caso es auxant
    }

    //ahora si es que me tengo que mover a la izquierda..
    while(auxant && cmp(d, auxant->info)<0) //esto quiere decir que d es menor que auxant->info
    {
        auxsig = auxant;
        auxant = auxant->ant;
    }

    //y si son iguales..
    if( (auxsig && cmp(d, auxsig->info)==0) || (auxant && cmp(d, auxant->info)==0))
    {
        printf("hay duplicado\n");
        return 0;
    }

    //por qué hacemos el if del malloc luego del los while?
    //no es eficiente hacer reservas de memoria que luego no me sirvan y liberarlas
    //llamar a memoria con malloc es una llamada a sistema, y las llamadas a sist son costosas en tiempo
    //si arriba el dato hubiera dado duplicado por ej, y hubiera hecho
    //malloc antes, hubiera sido al pedo reservar memoria, por eso la reservo luego de los ciclos
    //es preferible estar seguros de que hago malloc porque realmente la utilizare
    tNodo * nue;

    //en todo este if ya pido memoria para el nodo y para el tamaño del dato
    if((nue = (tNodo *)malloc(sizeof(tNodo)))== NULL ||
        (nue->info = malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;   //sin memoria
    }

    memcpy(nue->info , d, tam_dato);
    nue->tam_info = tam_dato;

    //engancho el nodo a los nodos auxsig y auxant
    nue->sig = auxsig;
    nue->ant = auxant;

    //y ahora los nodos auxiliares se enganchan con mi nodo nuevo
    //(es como un ida y vuelta, como una doble flecha digamos que sale de cada lado del nodo nuevo)
    //aca debo preguntar si existen porque en caso de no existir, al hacer esto me tirará SEGMENTATION FAULT
    if(auxsig)
    {
        auxsig->ant = nue;
    }
    if(auxant)
    {
        auxant->sig = nue;
    }

    *pl = nue;

    return 1;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

//me acepta los elementos duplicados
int poner_orden_lista_duplicados(tLista * pl, void *d , unsigned tam_dato,
                                 int (*cmp)(const void*, const void *))
{
    tNodo * auxsig = *pl;
    tNodo * auxant = (!auxsig ? NULL : auxsig->ant);

    while(auxsig && cmp(auxsig->info, d)<0)
    {
        auxant= auxsig;
        auxsig= auxsig->sig;
    }

    while(auxant && cmp(auxant->info,d)>0)
    {
        auxsig= auxant;
        auxant= auxant->ant;
    }

    tNodo * nue;

    if((nue = (tNodo*)malloc(sizeof(tNodo)))== NULL || (nue->info=malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;

    nue->sig = auxsig;
    nue->ant = auxant;

    if(auxant)
        auxant->sig = nue;

    if(auxsig)
        auxsig->ant = nue;

    *pl = nue;

    return 1;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

//en realidad es como un vaciar lista, así que estaría de más esta función aunque funciona
//no considerarla
//y también hay otra función que es sacar elementos de la lista (de a uno)s
int sacar_orden_lista(tLista * pl, void * d , unsigned tam_dato)
{
    if(*pl==NULL)
    {
        printf("no existe lista\n");
        return 0;
    }


    while((*pl)->ant)   //voy hasta el principio de la lista
        *pl = (*pl)->ant;


    tNodo * elim = *pl;
    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));


    //desengancho
    if((*pl)->sig)
        (*pl)->sig->ant = NULL;


    if(!(*pl)->ant && !(*pl)->sig)
        *pl= NULL;

    //finalizo dejando a *pl apuntando a cierto nodo, ya que asi trabajan las listas dobles
    if(*pl)
        *pl= (*pl)->sig;    //voy a dejar a pl apuntando siempre al siguiente nodo del que saqué,
                            //ej si saqué al 1, quedará apuntando al 2
    //esto es porque si estoy sacando todos los elementos con un ciclo, no tendre que recorrer toda la lista otra vez la prox vez

    free(elim->info);
    free(elim);

    return 1;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

int lista_vacia(const tLista * pl)
{
    return *pl==NULL;
}


//////////////////////////////////////////////
//////////////////////////////////////////////

int ver_primer_elem_lista(tLista * pl, void * d, unsigned tam_dato)
{
    if(!*pl)
        return 0;

    while((*pl) && (*pl)->ant)   //voy hasta el principio de la lista, si (*pl) apunta al primero se saltea esta parte
    {
        *pl = (*pl)->ant;
    }

    memcpy(d, (*pl)->info, MINIMO(tam_dato, (*pl)->tam_info));

    return 1;
}
//////////////////////////////////////////////
//////////////////////////////////////////////


int ver_ultimo_elem_lista(tLista * pl, void * d, unsigned tam_dato)
{
    if(!*pl)
        return 0;


    while(*pl && (*pl)->sig)    //voy al final de la lista
        *pl = (*pl)->sig;


    memcpy(d, (*pl)->info, MINIMO(tam_dato, (*pl)->tam_info));

    return 1;
}

//////////////////////////////////////////////
//////////////////////////////////////////////


int mostrar_lista(tLista * pl)
{
    if(*pl== NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    int cont = 0;

    while((*pl) && (*pl)->ant)   //voy hasta el principio de la lista, si (*pl) apunta al primero se saltea esta parte
    {
        *pl = (*pl)->ant;
    }


    while(*pl && (*pl)->sig)
    {
        printf("%d ", *(int*)(*pl)->info);
        *pl = (*pl)->sig;
        cont++;
    }

    printf("%d ", *(int*)(*pl)->info);  //para el último registro, ya que el while anterior no me lo agarra

    return cont+1;
}

int mostrarDeIzqADer(const tLista * pl, void(*mostrar)(const void *))
{
    if(!*pl)
        return 0;

    int contNodos = 0;

    tNodo * act = *pl;

    while(act->ant)
        act= act->ant;

    while(act)
    {
        contNodos++;
        mostrar_movimiento(act->info);
        act = act->sig;
    }
    return contNodos;
}

//////////////////////////////////////////////
//////////////////////////////////////////////
 /**
void buscar_los_repes(tLista * pl, int (*cmp)(const void*, const void *))
{
    //ESTE NODO TAMBIÉN SERVIRÁ PARA QUE PL NO TERMINÉ APUNTANDO A NULL
    tNodo * reiniciar = *pl;

    //ESTE ES EL QUE VAMOS A COMPARAR BUSCANDO SUS DUPLICADOS
    //DIGAMOS ÉSTE SERÍA "EL ORIGINAL"
    tNodo * aux = *pl;

    //AVANZO UN LUGAR PARA QUE NO SE COMPARE A SÍ MISMO
    *pl= (*pl)->sig;

    int encontro=0;

    tNodo * elim;

    while(*pl)
    {
        encontro=0;

        if(cmp(aux->info, (*pl)->info)==0)  //ENCONTRÓ UN DUPLICADO
        {
            tNodo * auxsig = (*pl)->sig;
            tNodo * auxant = (*pl)->ant;

            encontro=1;
            elim = *pl;

            if(auxsig)
            {
            auxant->sig = auxsig;   //DESENGANCHO AL NODO
            auxsig->ant = auxant;
            }
            else                    //SI ENTRA POR ACÁ, ES PORQUE EL DUPLICADO ESTÁ EN LA ÚLTIMA POSICIÓN
            {                       //DE LA LISTA
                auxant->sig = NULL;
            }
        }
        if(*pl)
            *pl = (*pl)->sig;


        if(encontro)                //FINALMENTE SI ENCONTRÓ (1), LIBERO EL NODO
        {
            free(elim->info);
            free(elim);
        }
    }
    *pl= reiniciar;                 //RECORDAR APUNTAR PL A ALGÚN LUGAR VÁLIDO
}
**/


void buscar_los_repes(tNodo * act, int (*cmp)(const void * , const void *))
{
    tNodo * ori = act;
    act= act->sig;

    int encontro=0;
    tNodo * elim;

    while(act)
    {
        encontro=0;
        if(cmp(act->info, ori->info)==0)
        {
            encontro=1;
            elim = act;

            //creo dos punteros a nodos auxilares. ambos "rodean" a act
            tNodo * auxant = act->ant;
            tNodo * auxsig = act->sig;

            //aca hago todos los desenganches correctamente
            if(auxant)
                auxant->sig = auxsig;
            if(auxsig)
                auxsig->ant = auxant;
        }
        act= act->sig;  //cuando finalmente avancé con act, procedo a liberar a elim

        if(encontro)
        {
            free(elim->info);
            free(elim);
        }
    }
}

//ESTA FUNCIÓN ESTÁ CORRECTA. NO USAR LA OTRA.
void eliminar_duplicados(tLista * pl, int (*cmp)(const void*, const void *))
{
    if(!*pl)
        return ;

    tNodo * act = *pl;  //conviene usar act y no pl

    while(act->ant)
        act= act->ant;

    while(act)
    {
        buscar_los_repes(act, cmp);
        act = act->sig;
    }
}


//recordar que hacemos dos recorridos (un while dentro de otro while)
//eliminamos los duplicados y dejamos el original
/**
void eliminar_duplicados(tLista * pl, int (*cmp)(const void*, const void *))
{
    if(!*pl)
        return ;

    //VAMOS AL PRINCIPIO DE LA LISTA
    while((*pl)->ant)
    {
        *pl = (*pl)->ant;
    }

    //ESTE NODO LO USAREMOS PARA EL FINAL
    //PUESTO QUE ES PROBABLE QUE PL TERMINE APUNTANDO A NULL,
    //DEBEMOS MODIFICAR ESTO PUESTO QUE NO SE PERMITE EN LISTA DOBLE
    //DEBE QUEDAR APUNTANDO A ALGÚN LUGAR ESPECÍFICO
    //ENTONCES HAREMOS QUE APUNTE AL INICIO DE LA LISTA
    tNodo * inicio = *pl;

    while(*pl)
    {
        if((*pl)->sig)
            buscar_los_repes(pl, cmp);

        if(*pl)
            *pl = (*pl)->sig;
    }

    *pl = inicio;   //FINALMENTE DEJAMOS QUE PL APUNTE AL INICIO DE LA LISTA
}
**/

//////////////////////////////////////////////
//////////////////////////////////////////////


int insertarAlFinal(tLista * pl, const void * d, unsigned tam_dato)
{
    tNodo * act = *pl;

    if(act)
        while(act->sig)
            act= act->sig;


    tNodo * nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo)))== NULL || (nue->info=malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;

    nue->sig = NULL;
    nue->ant = act;

    if(act)
        act->sig = nue;
    *pl = nue;
    return 1;
}


int insertarAlComienzo(tLista * pl, const void * d, unsigned tam_dato)
{
    tNodo * act = *pl;

    if(act)
        while(act->ant)
            act= act->ant;

    tNodo * nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo)))== NULL || (nue->info=malloc(tam_dato))==NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;

    nue->sig = act;
    nue->ant = NULL;

    if(act)
        act->ant= nue;

    *pl = nue;

    return 1;
}

//esta función es mucho más eficiente que la de sacar_elem_ordenado
int eliminarPorClave(tLista * pl, void * d, unsigned tam_dato,
                     int (*comparar)(const void *, const void *))
{
    if(!*pl)
        return 0;

    tNodo * act = *pl;
    int     aux;

    while(act && comparar(d, act->info)>0)
        act= act->sig;

    while(act && comparar(d, act->info)<0)
        act = act->ant;

    aux = comparar(act->info, d);

    if(aux == 0)    //encontró la clave
    {
        tNodo * auxant = act->ant;  //no importa si hay algun null
        tNodo * auxsig = act->sig;

        //acá desengancho a act, que es donde está mi clave
        if(auxant)
            auxant->sig = auxsig;

        if(auxsig)
            {
            auxsig->ant = auxant;
            *pl = auxsig;            //tengo que dejar apuntando a p algun lado
            }
        else
            *pl = auxant;

        memcpy(d, act->info, MINIMO(tam_dato, act->tam_info));
        free(act->info);
        free(act);
        return 1;
    }
    return 0;
}


//saca un elemento en particular que mando por parámetro
int sacar_elem_ord(tLista * pl, void * d, unsigned tam_dato, int (*cmp)(const void *, const void *))
{
    if(*pl==NULL)
    {
        printf("lista vacia\n");
        return 0;
    }

    tNodo * auxsig = *pl;
    tNodo * auxant = auxsig!=NULL ? *pl : NULL; //por si estaba la lista vacía, hago el if

    tNodo * elim;

    while(auxsig && cmp(d, auxsig->info)>0) //si entra por aca, me muevo a la derecha
                                            //mientras que d sea mayor a auxsig->info
    {
        auxant = auxsig;
        auxsig = auxsig->sig;
    }

    if(auxsig==NULL)    //es porque no lo encontro
        return 0;

    //ahora si es que me tengo que mover a la izquierda..
    while(auxant && cmp(d, auxant->info)<0) //esto quiere decir que d es menor que auxant->info
    {
        auxsig = auxant;
        auxant = auxant->ant;
    }

    if(auxant== NULL)   //es porque no lo encontro
        return 0;

    //y si son iguales.. y es el primer nodo que encontré
    if( (cmp(d, auxsig->info)==0 || cmp(d, auxant->info)==0) && (auxant== auxsig))
    {

        memcpy(d, auxsig->info, MINIMO(tam_dato, auxsig->tam_info));
        elim = auxsig;

        if(auxsig->sig && !auxant->ant)
        {
            auxsig= auxsig->sig;
            *pl= auxsig;
            auxsig->ant= NULL;
        }
        if(auxant->ant && !auxsig->sig)
        {
            auxant= auxant->ant;
            *pl= auxant;
            auxant->sig= NULL;
        }
        if(auxsig->sig && auxant->ant)
        {
            auxant= auxant->ant;
            auxsig= auxsig->sig;
            auxant->sig = auxsig;
            auxsig->ant = auxant;
            *pl = auxsig;
        }

    }



    else if( (auxsig && cmp(d, auxsig->info))==0 )
    {
        memcpy(d, auxsig->info, MINIMO(tam_dato, auxsig->tam_info));

        elim = auxsig;


        if(auxsig->sig!=NULL)
        {
        auxsig= auxsig->sig;
        auxant->sig = auxsig;
        auxsig->ant = auxant;
        }
        else
            auxant->sig=NULL;

    }


    else if( (auxant && cmp(d, auxant->info))==0 )
    {
        memcpy(d, auxant->info, MINIMO(tam_dato, auxant->tam_info));
        elim = auxant;


        if(auxant->ant!=NULL)
        {
        auxant= auxant->ant;
        auxant->sig = auxsig;
        auxsig->ant = auxant;
        }
        else
            auxsig->ant=NULL;
    }

    free(elim->info);
    free(elim);

    return 1;
}

//OTRA VERSIÓN DE LA FUNCIÓN ANTERIOR
/*
int sacar_elem_ord(tLista * pl, void * d, unsigned tam_dato, int (*cmp)(const void*, const void *))
{
    if(!*pl)
        return 0;

    tNodo * auxsig = *pl;
    tNodo * auxant = (!auxsig ? NULL : auxsig->ant);

    tNodo * elim;

    //ENTRA A ESTE IF EN CASO DE QUE HAYA UN SOLO EN LA LISTA
    if(cmp(auxsig->info, d)==0 && !auxant && !auxsig->sig)
    {
        memcpy(d, auxsig->info, MINIMO(auxsig->tam_info, tam_dato));
        elim = auxsig;
        free(elim->info);
        free(elim);
        *pl= NULL;  //RECORDAR QUE PL DEBE APUNTAR A ALGO AL FINAL, EN ESTE CASO A NULL PUES VACIÉ LISTA
        return 1;
    }

    //SINO RECORRO A LA DERECHA
    while(auxsig && cmp(auxsig->info, d)<0)
    {
        auxant = auxsig;
        auxsig = auxsig->sig;
    }

    //SI ENTRA ACÁ ES PORQUE NO ENCONTRÓ EL NODO EN CUESTIÓN
    if(!auxsig)
        return 0;

    //SINO RECORRO A LA IZQUIERDA
    while(auxant &&  cmp(auxant->info,d)>0)
    {
        auxsig = auxant;
        auxant = auxant->ant;
    }

    //SI ENTRA ACÁ ES PORQUE NO ENCONTRÓ EL NODO EN CUESTIÓN
    if(!auxant && cmp(auxsig->info, d)!=0)
        return 0;


    //ACÁ SÍ ENCONTRÓ EL NODO
    if(cmp(auxsig->info, d)==0)
    {
        memcpy(d, auxsig->info, MINIMO(auxsig->tam_info, tam_dato));
        elim = auxsig;


        //DESENGANCHO
        if(auxsig->sig && auxant)   //ACÁ ES CUANDO EL NODO EN CUESTIÓN ESTÁ EN EL MEDIO DIGAMOS,
        {                           //O SEA ENTRE OTROS NODOS
        auxant->sig = auxsig->sig;
        auxsig->sig->ant= auxant;
        }
        else if(auxant)             //SI ENTRA ACÁ ES PORQUE ERA EL ÚLTIMO NODO DE LA LISTA
            auxant->sig=NULL;
        else                        //O EL PRIMERO
            auxsig->sig->ant= NULL;


        //LUEGO DE DESENGANCHAR, TENGO QUE DEJAR PL APUNTANDO A ALGÚN LADO (QUE EXISTA OBVIAMENTE)
        if(auxant)
            *pl = auxant;
        else
            *pl = auxsig->sig;

    }


    //O ENCONTRÓ AL NODO PERO POR ESTE LADO

    else if(cmp(auxant->info, d)==0)
    {
        memcpy(d, auxant->info, MINIMO(auxant->tam_info, tam_dato));
        elim = auxant;

        //DESENGANCHE
        if(auxant->ant)     //NODO RODEADO DE OTROS NODOS
        {
        auxsig->ant = auxant->ant;
        auxant->ant->sig = auxsig;
        }
        else                //ERA EL PRIMER NODO DE LA LISTA
        {
            auxsig->ant = NULL;
        }
        *pl = auxsig;       //DEJO PL APUNTANDO A ALGO
    }


    FINALMENTE LIBERO EL NODO Y RETORNO UN 1 DE QUE LO ENCONTRÓ
    free(elim->info);
    free(elim);

    return 1;
}
*/

//////////////////////////////////////////////
//////////////////////////////////////////////

//muestro un registro en particular
void mostrar_movimiento(void * d)
{
    int * mov = (int*)d;
    printf("%d ", *mov);
}

int vaciar_lista(tLista * pl)
{
    if(!*pl)
        return 0;

    int cont = 0;

    tNodo * act = *pl;

    while(act->ant)         //voy al inicio
        act= act->ant;


    while(act)
    {
        cont++;
        mostrar_movimiento(act->info);

        tNodo * elim = act;

        act= act->sig;

        free(elim->info);
        free(elim);
    }

    *pl = NULL;         //RECORDAR SIEMPRE ESTA PARTE

    return cont;
}



//////////////////////////////////////////////
//////////////////////////////////////////////
/**

int sacar_orden_lista(tLista * pl, void * d , unsigned tam_dato)
{
    if(*pl==NULL)
    {
        printf("no existe lista\n");
        return 0;
    }

    //mi puntero auxiliar va a empezar apuntando a donde apunta pl
    tNodo * aux = *pl;
    tNodo * elim;


    while(aux->ant)   //voy hasta el principio de la lista
        aux = aux->ant;


    if(( elim = (tNodo*)malloc(sizeof(tNodo))) ==NULL ||  (elim->info = malloc(tam_dato))==NULL )
    {
        free(elim);
        return 0;
    }

    elim = aux;

    memcpy(d, elim->info, MINIMO(tam_dato, elim->tam_info));

    //desengancho
    if(aux->sig)
        aux->sig->ant = NULL;

    if(!aux->ant && !aux->sig)
        *pl= NULL;

    *pl= aux->sig;  //voy a dejar a pl apuntando siempre al siguiente nodo del que saqué,
                    //ej si saqué al 1, quedará apuntando al 2
    //esto es porque si estoy sacando todos los elementos con un ciclo, no tendre que recorrer toda la lista otra vez la prox vez

    free(elim->info);
    free(elim);

    return 1;
}

**/


