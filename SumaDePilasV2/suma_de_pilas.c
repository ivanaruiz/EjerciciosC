#include "pila_dinamica.h"
#include "suma_de_pilas.h"

void sumar(t_pila * p1, t_pila * p2, t_pila * pRES)
{
    int suma=0;
    int carry=0;
    int elem1, elem2;

    while(!pila_vacia(p1) && !pila_vacia(p2))   //deja de loopear cuando por lo menos una de las pilas este vacia
    {
        sacar_de_pila(p1, &elem1, sizeof(elem1));
        sacar_de_pila(p2, &elem2, sizeof(elem2));

        suma=elem1+elem2+carry;
        if(suma>9)
        {
            carry=1;
            suma=suma%10;
        }
        else
            carry=0;

        poner_en_pila(pRES,&suma, sizeof(suma));
    }


    while(!pila_vacia(p1))
    {
        sacar_de_pila(p1, &elem1, sizeof(elem1));
        suma= elem1+carry;
        if(suma>9)
        {
            carry=1;
            suma=suma%10;
        }
        else
            carry=0;

        poner_en_pila(pRES,&suma, sizeof(suma));
    }

    while(!pila_vacia(p2))
    {
        sacar_de_pila(p2, &elem2, sizeof(elem2));
        suma= elem2+carry;
        if(suma>9)
        {
            carry=1;
            suma=suma%10;
        }
        else
            carry=0;

        poner_en_pila(pRES,&suma, sizeof(suma));
    }


    poner_en_pila(pRES,&carry, sizeof(carry));

}


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


int abrir_archivo(FILE **pf, char * path, char * modo_apertura)
{
    *pf = fopen(path, modo_apertura);
    if(!*pf)
        return TODO_MAL;

    return TODO_BIEN;
}



////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


void guardar_suma_en_txt(FILE * pf, t_pila *pRes)
{
    int elem;
    while(!pila_vacia(pRes))
    {
        sacar_de_pila(pRes, &elem, sizeof(elem));
        fprintf(pf, "%d ", elem);
    }
}
