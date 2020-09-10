#include <stdio.h>
#include <stdlib.h>

void mostrar (int *vec, int ce);
int* ordenar(int *vec, int ce);
void intercambio(int *vec);

int main()
{
    int vec[] = {4,8,2,9,6,3,1,5,7};
    int ce= sizeof(vec)/sizeof(int);


    mostrar(vec, ce);

    ordenar(vec, ce);

    mostrar(vec, ce);

    system("pause");
    return 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void mostrar (int *vec, int ce)
{
    int i;
    for(i=0; i<ce; i++)
        printf("%d ", vec[i]);

    printf("\n");
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


int * ordenar(int *vec, int ce)
{

    int *ini=vec;
    int *avanza= vec;
    int *fin= vec+ce-1;

    while(avanza<fin)
    {
        while(vec<fin)
        {
            if(*vec > *(vec+1) )
                    intercambio(vec);


            vec++;
        }
        avanza++;
        vec=ini;
    }
    return ini;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

void intercambio(int *vec)
{
    int aux = *vec;
    *vec= *(vec+1);
    *(vec+1) = aux;
}

