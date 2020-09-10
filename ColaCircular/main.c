#include "cola_circular.h"

//es una cola dinámica circular

int main()
{
    t_cola pc;

    crear_cola(&pc);
    int elem;

    int r;

    for(int i=0; i<10; i++)
    {
        r=poner_en_cola(&pc, &i, sizeof(i));
        if(!r)
        {
            printf("Cola llena\n");
        }
    }


    while(!cola_vacia(&pc))
    {
        sacar_de_cola(&pc, &elem, sizeof(int));
        printf("%d ",elem);
    }


    system("pause");
    return 0;
}
