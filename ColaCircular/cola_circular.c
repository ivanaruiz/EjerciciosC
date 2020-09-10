#include "cola_circular.h"

void crear_cola(t_cola * pc)
{
    *pc = NULL;
}

//ponemos en el segundo elemento
//el ultimo va a estar apuntando siempre al primero
//*pc va a estar apuntando al ultimo
//asi que cuando inserte un nuevo elemento, pc apuntara a este elemento
int poner_en_cola(t_cola *pc, const void * d, unsigned tam_dato)
{
    t_nodo * nue;

    if(( nue = (t_nodo *)malloc(sizeof(t_nodo))) == NULL  ||
        (nue->info = malloc(tam_dato)) == NULL)
    {
        free(nue);
        return 0;
    }

    nue->tam_info = tam_dato;
    memcpy(nue->info, d, tam_dato);

    if(*pc == NULL) //entro por acá si es el primer nodo el que estoy poniendo..
    {
        nue->sig = nue; //se autoapunta
    }
    else    //para cuando hay mas de uno nodo ya insertado
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }

    *pc = nue;  //siempre pc apuntara a mi nuevo nodo, que es el ultimo

    return 1;
}

//saco el segundo elemento siempre
int sacar_de_cola(t_cola *pc, void * d, unsigned tam_dato)
{
    t_nodo * elim;

    if(*pc== NULL)
        return 0;


    elim = (*pc)->sig;
    memcpy(d, elim->info, minimo(tam_dato, elim->tam_info));

    if(elim == elim->sig)   //es decir que hay un solo nodo, si elim==elim->sig se autoapuntan, son el mismo
    {
        *pc = NULL;
    }
    else    //es decir que hay mas de un nodo
    {
        (*pc)->sig = elim->sig; //desengancho, y engancho el ultimo con el siguiente nodo al que elimino
    }

    free(elim->info);
    free(elim);

    return 1;
}


int cola_vacia(const t_cola * pc)
{
    return *pc == NULL;
}
