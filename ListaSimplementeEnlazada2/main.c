#include "lista.h"

int cmp_ent(const void * e1, const void * e2);

int main()
{

    t_lista pl;
    crear_lista(&pl);
    int vec[] = {2,8,4,6,5,9,4,7,1,3};

    printf("colocamos elementos en una lista ordenada:\n");
    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_orden_lista(&pl, &vec[i], sizeof(int), cmp_ent);
        printf("\n");
        mostrar_lista(&pl);
    }

    printf("\n\nsacamos elementos de lista");
    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        sacar_elem_lista(&pl, &vec[i], sizeof(int), cmp_ent);
        printf("\n");
        mostrar_lista(&pl);
    }

    printf("------------------------------------------");
    printf("\ncolocamos elementos en una lista ordenada:\n");
    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_orden_lista(&pl, &vec[i], sizeof(int), cmp_ent);
        printf("\n");
        mostrar_lista(&pl);
    }

    printf("\n\nsacamos elementos de lista ORDENADA");
    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        sacar_elem_orden_lista(&pl, &vec[i], sizeof(int), cmp_ent);
        printf("\n");
        mostrar_lista(&pl);
    }



    puts("");
    system("pause");
    return 0;
}


int cmp_ent(const void * e1, const void * e2)
{
    int * a1 = (int *) e1;
    int * a2 = (int *) e2;
    return *a1 -*a2;
}



