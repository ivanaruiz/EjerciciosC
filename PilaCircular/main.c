#include "pila_circular.h"
//es una pila dinámica pero circular

int main()
{
    t_pila p;

    crear_pila(&p);
    int elem;

    int r;

    for(int i=0; i<10; i++)
    {
        r=poner_en_pila(&p, &i, sizeof(i));
        if(!r)
        {
            printf("Pila llena\n");
        }
    }


    while(!pila_vacia(&p))
    {
        sacar_de_pila(&p, &elem, sizeof(int));
        printf("%d ",elem);
    }

    system("pause");
    return 0;
}


