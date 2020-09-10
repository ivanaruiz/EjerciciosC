#include "ordenamiento_generico_metodo_insercion.h"

int main()
{
    int vec[]= {34,13,8,21,1,2,5,3};
    int ce= sizeof(vec)/sizeof(int);

    ordenar(vec,ce, sizeof(int), cmp_ent);

    int i;
    for(i=0; i<ce; i++)
        printf("%d ", vec[i]);

    /////////////////////////////////////

    char vecchar[]= {'c', 'g', 'e', 'd', 'h', 'b', 'f', 'a', 'i'};
    ce= sizeof(vecchar)/sizeof(char);

    ordenar(vecchar, ce, sizeof(char), cmp_char);

    puts("");
    for(i=0; i<ce; i++)
        printf("%c ", vecchar[i]);

    puts("");

    system("pause");
    return 0;
}



