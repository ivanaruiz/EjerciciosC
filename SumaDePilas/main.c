
#include "pila_dinamica.h"


int main()
{
    t_pila p1;
    t_pila p2;
    t_pila p3;

    crear_pila(&p1);
    crear_pila(&p2);
    crear_pila(&p3);

    //estos vectores los uso solo para mostrar
    int vec1[9];    //los declaré de 9 porque es el maximo que usaré
    int vec2[9];    //pero podría hacer de mas numeros, entonces esto cambiaría

    //pongo en ambas pilas
    for(int i=1; i<10; i ++)
    {
        poner_en_pila(&p1, &i, sizeof(i));
    }


    int num=9;
    for(int i=0; i<3 ; i++)
    {
        poner_en_pila(&p2, &num, sizeof(int));
    }


    int elem1;
    int elem2;
    int suma=0;
    int carry=0;

    //desempilo y apilo en la pila de resultados
    int i=0;
    while(!pila_vacia(&p1) || !pila_vacia(&p2))
    {
        //notar que hago pregunto por pila vacia dos veces, por qué?
        //esto es porque capaz uno de las pilas es mas corta que la otra
        //en ese caso, si ya esa pila quedó vacia, que ponga ceros
        //y siga desempilando la otra
        if(!pila_vacia(&p1))
            sacar_de_pila(&p1, &elem1, sizeof(elem1));
        else
            elem2=0;


        vec1[i] = elem1;

        if(!pila_vacia(&p2))
            sacar_de_pila(&p2, &elem2, sizeof(elem2));
        else
            elem2=0;


        vec2[i] = elem2;

        suma=elem1+elem2+carry;
        if(suma>9)
        {
            suma= suma%10;
            carry=1;
        }
        else
            carry=0;

        poner_en_pila(&p3, &suma, sizeof(suma));

        i++;
    }

    //si el último carry quedó en 1, también lo meto en la pila p3
    if(carry==1)
        poner_en_pila(&p3, &carry, sizeof(carry));


    //estos for son solo para mostrar ambos vectores,
    //ya que si lo hacía al desempilar p1 y p2, me quedaban al revés
    printf("\t");
    for(i=8; i>=0; i--)
    {
        printf("%d ", vec1[i]);
    }
    printf("\n   +\n");
    printf("\t");
    for(i=8; i>=0; i--)
    {
        printf("%d ", vec2[i]);
    }


    //finalmente desempilo p3 con los resultados
    printf("\n====================================\n");
    if(carry==0)
        printf("\t");
    else
        printf("      ");
    while(!pila_vacia(&p3))
    {
        sacar_de_pila(&p3, &suma, sizeof(suma));
        printf("%d ", suma);
    }

    puts("");
    system("pause");
    return 0;
}


