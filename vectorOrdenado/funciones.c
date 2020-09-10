#include "vector.h"


void mostrar(int vec[])
{
    for(int i=0; i<TAM; i++)
        printf("%d  ", vec[i]);
    printf("\n\n");
}



void ordenar(int vec[])
{
    int aux=0;

    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            if(vec[j] > vec[j+1])
            {
            aux= vec[j];
            vec[j]= vec[j+1];
            vec[j+1] = aux;
            }
        }
    }
}
