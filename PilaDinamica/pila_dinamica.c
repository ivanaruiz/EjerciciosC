#include "pila_dinamica.h"

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


//para poner en la pila, tengo que crear un nodo
//cada nuevo nodo asignado queda "adelante de todo",
//es decir la pila del main quedara apuntando a este ultimo nodo creado
//y es ultimo nodo apuntara (con nue->sig) al anterior nodo viejo creado
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

    //llegados acá, pude crear exitosamente el nodo
    nue->tam_info = tam_dato;
    nue->sig = *p;  //con esto hago que el nuevo nodo apunte al anterior nodo creado,
                    //que era al que punta la pila p en el main
    memcpy(nue->info, d, tam_dato);

    *p = nue;   //ahora p apunta a este nuevo nodo creado
                //en el main p apuntara a este nodo
    return 1;   //si pasa por aca es VERDADERO
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



//voy a sacar lo que este en el tope de la pila
//es decir el ultimo insertado
int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato)
{
    //declaro una variable auxiliar
    //es el nodo que voy a eliminar
    //necesito la var auxiliar porque como voy a mover los punteros,
    //voy a perder datos
    //entonces creo puntero elim, que apuntara inicialmente al ultimo nodo creado
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
    *p= elim->sig;  //ahora pila p apuntara a otro nodo, el siguiente

    //ahora que copié las cosas, libero la memoria
    free(elim->info);
    free(elim);
    return 1;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

