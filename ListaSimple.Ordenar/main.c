#include "lista.h"

int cmp_enteros(const void * a1, const void * a2);

int main()
{
    t_lista pl;
    crear_lista(&pl);

    int vec[] = {2,4,8,6,1,7,5,9,3};

    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_ultimo_lista(&pl, &vec[i] , sizeof(int));
    }

    mostrar_lista(&pl);

    ordenar_seleccion_lista(&pl, cmp_enteros);

    puts("");

    mostrar_lista(&pl);

    system("pause");
    return 0;
}

int cmp_enteros(const void * a1, const void * a2)
{
    int * e1 = (int *) a1;
    int * e2 = (int *) a2;
    return *e1-*e2;
}
