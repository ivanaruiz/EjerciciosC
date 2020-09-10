#include "pila_dinamica.h"

int main()
{
    int elem;
    t_pila pila_enteros;

    crear_pila(&pila_enteros);


    if(pila_vacia(&pila_enteros))                //if(pila_vacia(&pila_enteros))==1
        printf("la pila esta vacia\n");

    if(pila_llena(&pila_enteros, sizeof(int)))
        printf("la pila esta llena\n");



    int i;
    for(i=0; i<10; i++)
    {
        if(!poner_en_pila(&pila_enteros, &i, sizeof(i)))
            printf("pila llena!");
    }
    printf("Pila cargada!\n");

    ver_tope(&pila_enteros, &elem, sizeof(elem));
    printf("El tope es %d \n", elem);


    while(!pila_vacia(&pila_enteros))
    {
        sacar_de_pila(&pila_enteros, &elem, sizeof(elem));
        printf("%d ", elem);
    }

    //vuelvo a llenar la pila
    for(i=0; i<10; i++)
    {
        if(!poner_en_pila(&pila_enteros, &i, sizeof(i)))
            printf("pila llena!");
    }
    ver_tope(&pila_enteros, &elem, sizeof(elem));
    printf("El tope es %d \n", elem);



    vaciar_pila(&pila_enteros);



    puts("");
    system("pause");
    return 0;
}


