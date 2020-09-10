#include "cola_dinamica.h"

int main()
{
    t_cola cola_ent;
    crear_cola(&cola_ent);
    int elem;

    for(int i=0; i < 10 ; i++)
    {
        int r = poner_en_cola(&cola_ent, &i, sizeof(int));
        if(!r)
            printf("cola llena\n");
    }

    while(!cola_vacia(&cola_ent))
    {
        sacar_de_cola(&cola_ent, &elem, sizeof(int));
        printf("%d ", elem);
    }

    system("pause");
    return 0;
}
