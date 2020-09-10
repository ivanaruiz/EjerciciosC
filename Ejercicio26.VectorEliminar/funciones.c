#include "header.h"
#define aviso 1

void mostrar(int *vec, int ce)
{
    int *ptr = vec;
    for(int i=0; i<ce; i++)
    {
        printf("%d  ", *ptr);
        ptr++;
    }
    printf("\n");
}


int buscar(int *vec, int ce, int n)
{
    int *ptr= vec;
    int i;
    int cant=0;
    for(i=0; i<(ce-cant); i++)
    {
        if(*ptr==n)
        {
            borrar(vec, ce, n , i);
            cant++;
        }

        ptr++;
    }
    return cant;
}


void borrar(int vec[], int ce, int n , int i)
{
    printf("\nSe ha borrado el %d\n", n);
            vec[i] = vec[i+1];

                for(int j= i++ ; j<ce-1; j++)
                {
                    vec[j] = vec[j+1];
                }

}
