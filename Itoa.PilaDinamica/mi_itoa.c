


#include "mi_itoa.h"



void mi_itoa(int num, int base)
{
    t_pila p;
    crear_pila(&p);

    char caracter;
    int resto;


    while(num>0)
    {
        resto= num%base;

        caracter=toasci(resto);

        poner_en_pila(&p, &caracter, sizeof(caracter));

        num= num/base;
    }


    while(!pila_vacia(&p))
    {
        sacar_de_pila(&p, &caracter, sizeof(caracter));
        printf("%c", caracter);
    }

}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

char toasci(int resto)
{
    char car;
    if(resto>9)
        car= resto+48+7;
    else
        car= resto+48;

    return car;
}





