#include "pila_estatica.h"

//Cómo saber calcular el espacio de mi pila y cuánto llenarla. En este caso dijimos que es de 200 bytes en el define.
//TAM_PILA 200
//como nosotros declaramos que lo usaremos con una pila de enteros, esto indica que cada numero ocupa 4 bytes,
//pero ademas necesito otros 4 bytes para indicar que el elemento pesa eso (ver explicacion en la funcion poner_en_pila).
//por lo que se podria decir que "para cada entero necesitare 8 bytes", es decir 4 para el dato, y 4 para el tamaño del
//dato. por tanto dividimos 200/8 = 25. Eso indica que podre guardar 25 numeros enteros.
//mas de eso, la pila me dira que esta lleno y no me dejara hacerlo

int main()
{
    t_pila pila_enteros;

    crear_pila(&pila_enteros);

    int i;

    //notar que solo me dejara llenar la pila hasta el entero 25. mas de eso me dira pila llena
    for(i=0; i<10; i++)
    {
        if(!poner_en_pila(&pila_enteros, &i, sizeof(i)))
            return 1;
    }

    int elem;
    if(ver_tope(&pila_enteros, &elem, sizeof(elem)))
       printf("el tope es %d\n", elem);


    while(!pila_vacia(&pila_enteros))
    {
        sacar_de_pila(&pila_enteros, &elem, sizeof(elem));
        printf("%d ", elem);
    }

    system("pause");
    return 0;
}
