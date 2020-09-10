#include "Pila_estatica.h"



void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}



int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes+sizeof(unsigned))
    {
        printf("pila llena\n");
        return 0;
    }

    p->tope-= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);

    p->tope-= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}



int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    int tam_aux;

    if(p->tope == TAM_PILA)
        return 0; //pila_vacia

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));

    memcpy(d, p->pila+p->tope + sizeof(unsigned), minimo(tam_aux, cantBytes));

    return 1;
}


int  pilaVacia_MIO(const tPila *p)
{
    return p->tope==TAM_PILA;
}



int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tam_aux;

    if(p->tope == TAM_PILA)
        return 0;   //pila_vacia

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));
    p->tope+= sizeof(unsigned);

    memcpy(d, p->pila+p->tope, minimo(tam_aux, cantBytes));
    p->tope+= tam_aux;

    return 1;
}

