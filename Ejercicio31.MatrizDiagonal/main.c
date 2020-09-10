#include <stdio.h>
#include <stdlib.h>
#define TAM 50
#define ES_MAT_DIAG     1
#define NO_ES_MAT_DIAG  0

void mostrarMatriz(int mat[][TAM], int orden);
int esMatDiag(int mat[][TAM], int ff, int cc);

/*Desarrollar una función que determine si una matriz cuadrada de enteros
de orden N es matriz diagonal (ceros en todos sus elementos excepto en la
diagonal principal).*/


int main()
{
    int mat[][TAM] ={
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
                };

    mostrarMatriz(mat, 4);

    if(esMatDiag(mat, 4, 4))
        printf("\nEs matriz diagonal.\n");
    else
        printf("\nNo es matriz diagonal.\n");

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


//lo hice en dos partes
int esMatDiag(int mat[][TAM], int ff, int cc)
{
    //primero recorro los elementos que se encuentran sobre la diagonal principal
    for(int i=0; i<ff; i++)
    {
        for( int j=i+1; j<cc  ; j++)
        {
            if(mat[i][j] !=0)           //apenas encuentre un elemento distinto de 0,
                return NO_ES_MAT_DIAG;  //ya puedo cortar la función y devolver la respuesta
        }
    }

    //luego recorro los elementos que se encuentran por debajo de la diagonal principal
    for(int i=0; i<ff; i++)
    {
        for(int j= 0; j<i ; j++)
        {
            if(mat[i][j] !=0)
                return NO_ES_MAT_DIAG;
        }
    }

    //si logramos llegar acá, es porque efectivamente todos esos elementos recorridos fueron 0
    //entonces devolvemos exitosamente un 1 (de TRUE)
    return ES_MAT_DIAG;
}
