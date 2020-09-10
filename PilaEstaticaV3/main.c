
#include "pila_estatica.h"


int main()
{
    t_pila p;
    crear_pila(&p);


    if(pila_vacia(&p))
        printf("pila vacia\n");

    else
        printf("pila no vacia\n");


    if(!pila_llena(&p, sizeof(p)))
        printf("pila llena");
    else
        printf("pila no llena");



    vaciar_pila(&p);


    if(pila_vacia(&p))
        printf("pila vacia\n");

    else
        printf("pila no vacia\n");


    if(!pila_llena(&p, sizeof(p)))
        printf("pila llena");
    else
        printf("pila no llena");

    char d='m';
    poner_en_pila(&p, &d, sizeof(char));

    sacar_de_pila(&p, &d, sizeof(char));
    printf("\n%c\n", d);



    system("pause");
    return 0;
}
