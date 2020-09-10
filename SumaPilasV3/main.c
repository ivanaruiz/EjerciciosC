#include "pila.h"

/*Hago suma de pilas dinámicas.
Por consola voy a mostrar solo el resultado, es decir la pila 3.
Esto es solo para ver el algoritmo del programa, y no tanto el tema gráfico,
ya que para mostrar correctamente una suma tiene que estar en orden las unidades, decenas, etc.
*/

/*En este ejemplo estoy sumando:
6 5 4 3 2 1 0   p1
        9 9 9   p2
=============
6 5 4 4 2 0 9    */


int main()
{
    t_pila p1;
    t_pila p2;
    t_pila p3;

    crear_pila(&p1);
    crear_pila(&p2);
    crear_pila(&p3);

    for(int i=6; i>=0; i--)
    {
        poner_en_pila(&p1, &i, sizeof(int));
    }

    int num=9;
    for(int i =0; i<3; i++)
    {
        poner_en_pila(&p2, &num, sizeof(int));
    }

    int elem1;
    int elem2;
    int elem3;
    int carry=0;

    //mientras que por lo menos una de las pilas tenga aun contenido, el while sigue
    while(!pila_vacia(&p1) || !pila_vacia(&p2))
    {
        //notar que llamo a primitiva de pila_vacia nuevamente
        //esto es porque si alguna de las pilas es mas corta(menos elementos) que la otra
        if(!pila_vacia(&p1))
            sacar_de_pila(&p1, &elem1, sizeof(int));
        else elem1=0;

        if(!pila_vacia(&p2))
            sacar_de_pila(&p2, &elem2, sizeof(int));
        else elem2=0;

        //hago la suma propiamente dicha
        elem3 = elem1+elem2+carry;
        if(elem3>9)
        {
            carry=1;
            elem3= elem3%10;
        }
        else
            carry=0;

        //finalmente voy apilando los resultados en p3
        poner_en_pila(&p3, &elem3, sizeof(int));
    }

    //si quedó el última carry, también se apila
    if(carry==1)
        poner_en_pila(&p3, &carry, sizeof(int));

    //desempilo p3 con los resultados
    printf("Pila resultado:\n");
    int elim;
    while(!pila_vacia(&p3))
    {
        sacar_de_pila(&p3, &elim, sizeof(int));
        printf("%d ", elim);
    }


    puts("");
    system("pause");
    return 0;
}
