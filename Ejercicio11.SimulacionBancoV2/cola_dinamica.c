#include "cola_dinamica.h"

void crear_cola(t_cola * pc)
{
    pc->pri = pc->ult = NULL;
}

int poner_en_cola(t_cola * pc, const void * d, unsigned tam_dato)
{
    t_nodo * nue = (t_nodo *) malloc(sizeof(t_nodo));
    if(!nue)
    {
        printf("cola llena\n");
        return 0;
    }

    nue->info = malloc(tam_dato);
    if(!nue->info)
    {
        printf("cola llena\n");
        free(nue);
        return 0;
    }

    nue->tam_info = tam_dato;
    memcpy(nue->info, d, tam_dato);
    nue->sig = NULL;    //siempre es NULL, porque será el ultimo

    //ahora lo engancho en la pila
    //evalúo si la la cola está vacía
    if(pc->ult)     //si existe pc->ult , o sea pc->ult !=NULL, es porque hay nodos antes, entonces engancho
        pc->ult->sig = nue;
    else    //en caso de que ult sea null, etntonces pri es null también, o sea no existen nodos aún
        pc->pri = nue;

    //al ultimo siempre lo tengo que setear
    pc->ult = nue;

    return 1;
}

//se elimina el nodo del frente
int sacar_de_cola(t_cola * pc, void * d, unsigned tam_dato)
{
    t_nodo * elim = pc->pri;

    if(!elim)
    {
        printf("cola vacia\n");
        return 0;
    }

    pc->pri = elim->sig;
    memcpy(d, elim->info, minimo(tam_dato, elim->tam_info));

    free(elim->info);
    free(elim);

    if(pc->pri == NULL)  //por si borré un nodo y nada mas quedó en la cola
        pc->ult= NULL;

    return 1;
}


int cola_vacia(const t_cola * pc)
{
    return pc->pri ==NULL;  //if(pc->pri==NULL) return 1;
}

int cola_llena(const t_cola * pc, unsigned tam_dato)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));
    void * info = malloc(tam_dato);

    free(aux);
    free(info);

    return aux==NULL || info==NULL;
}

void vaciar_cola(t_cola * pc)
{
    while(pc->pri)
    {
        t_nodo * aux = pc->pri;
        pc->pri = aux->sig;
        free(aux->info);
        free(aux);
    }

    pc->ult = NULL;
}

//es como ver el primero de la cola
int ver_frente_de_cola(const t_cola * pc, void * d, unsigned tam_dato)
{
    if(pc->pri == NULL)
        return 0;

    memcpy(d, pc->pri->info, minimo(tam_dato, pc->pri->tam_info));
    return 1;
}
