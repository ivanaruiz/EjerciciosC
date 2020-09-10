#include <stdio.h>
#include <stdlib.h>
#define TAM 50
#define ES_MAT_IDEN     1
#define NO_ES_MAT_IDEN  0

void mostrarMatriz(int mat[][TAM], int orden);
int esMatrizIdentidad(int mat[][TAM], int ff, int cc);

/*Desarrollar una función que determine si una matriz cuadrada de enteros
de orden N es matriz identidad (matriz diagonal, con unos en la diagonal
principal y ceros en los restantes).*/


int main()
{
    int mat[][TAM] ={
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
                };

    mostrarMatriz(mat, 4);

    if(esMatrizIdentidad(mat, 4, 4))
        printf("\nEs matriz identidad.\n");
    else
        printf("\nNo es matriz identidad.\n");

    puts("");
    system("pause");
    return 0;
}


void mostrarMatriz(int mat[][TAM], int orden)
{
    for(int i =0; i<orden; i++)
    {
        for(int j=0; j<orden; j++)
            printf("%d ", mat[i][j]);

        puts("");
    }
}



int esMatrizIdentidad(int mat[][TAM], int ff, int cc)
{
    //recorro toda la matriz
    for(int i=0; i<ff; i++)
    {
        for( int j = 0; j<cc  ; j++)
        {
            //acá me fijo en la diagonal,
            //si algún elemento es distinto de 1, entonces corto el ciclo y hago return
            if(i==j && mat[i][j]!=1)
                return NO_ES_MAT_IDEN;

            //y acá me fijo en los restantes números, es decir fuera de la diagonal
            //apenas encuentre un elemento distinto de 0, corto el ciclo y salgo
            if(i!=j && mat[i][j]!=0)
                return NO_ES_MAT_IDEN;

        }
    }

    //si logré llegar acá, es porque fue exitosamente una matriz identidad
    return ES_MAT_IDEN;
}
