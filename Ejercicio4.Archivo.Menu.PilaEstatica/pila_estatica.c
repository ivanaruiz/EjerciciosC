
#include "pila_estatica.h"


void crear_pila(t_pila *p)
{
    p->tope = TAM_PILA;
}

int pila_vacia(const t_pila *p)
{
    return p->tope == TAM_PILA; //retorna un 0 si es falso , 1 si es verdadero
                                //ej if(p->tope== TAM_PILA)         339==340 NO!
                                //          return 1;                   entonces devuelve 0
}

int pila_llena(const t_pila *p, unsigned cant_bytes)
{
    return p->tope < cant_bytes + sizeof(unsigned);     //en sizeof(unsigned)=4 //cant_bytes=344
}                                                       //devuelve un 1(V) en caso de que la condicion del return se compla


void vaciar_pila(t_pila *p)
{
    p->tope= TAM_PILA;
    printf("vaciamos toda la pila!\n");
}


int poner_en_pila(t_pila *p, const void *d, unsigned cant_bytes)    //recordar cant_bytes=344, los bytes del struct
{
    if(p->tope < cant_bytes + sizeof(unsigned) )
    {
        printf("la pila esta llena!\n");
        return 0;
    }

    //me muevo para atras y guardo el dato con memcpy
    p->tope -= cant_bytes;
    memcpy(p->pila + p->tope, d, cant_bytes);

    //me vuelvo a mover para atras y guardo el tamaño
    p->tope -= sizeof(unsigned);
    memcpy(p->pila+ p->tope, &cant_bytes, sizeof(unsigned));

    return 1;
}


int sacar_de_pila(t_pila *p, void *d, unsigned cant_bytes)
{
    unsigned tam_dato;

    if(p->tope == TAM_PILA)
    {
        printf("la pila esta vacia!\n");
        return 0;
    }

    memcpy(&tam_dato, p->pila + p->tope, sizeof(unsigned));
    p->tope+= sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cant_bytes, tam_dato));
    p->tope+= tam_dato;
    return 1;
}

int ver_tope(const t_pila *p, void * d, unsigned cant_bytes)
{
    unsigned tam_info;

    if(p->tope == TAM_PILA)
    {
        printf("la pila esta vacia!\n");
        return 0;
    }


    memcpy(&tam_info, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cant_bytes, tam_info));
        return 1;
}
