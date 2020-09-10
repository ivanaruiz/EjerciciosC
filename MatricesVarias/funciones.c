#include "matrices.h"

void mostrarMatrizCompleta(int mat[][TAM])
{
    int i,j;
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
            printf("%d  ", mat[i][j]);
        linea
    }
}



void trianguloArriba(int mat[][TAM])
{
    int i,j;

    for(i=0; i<TAM; i++)
    {

        for(j=0; j<TAM; j++)
        {
            if(i<j && (i+j)<(TAM-1))
                printf("%d  ", mat[i][j]);
                    else
                        printf("-  ");
        }
        linea
    }
}


void trianguloAbajo(int mat[][TAM])
{
    int i,j;

    for(i=0; i<TAM; i++)
    {

        for(j=0; j<TAM; j++)
        {
            if(i>j && (i+j)>=TAM)
                printf("%d  ", mat[i][j]);
                    else
                        printf("-  ");
        }
        linea
    }
}



void trianguloIzquierda(int mat[][TAM])
{
    int i,j;

    for(i=0; i<TAM; i++)
    {

        for(j=0; j<TAM; j++)
        {
            if(i>j && (i+j)<(TAM-1))
                printf("%d  ", mat[i][j]);
                    else
                        printf("-  ");
        }
        linea
    }
}

void trianguloDerecha(int mat[][TAM])
{
    int i,j;

    for(i=0; i<TAM; i++)
    {

        for(j=0; j<TAM; j++)
        {
            if(i<j && (i+j)>=(TAM))
                printf("%d  ", mat[i][j]);
                    else
                        printf("-  ");
        }
        linea
    }
}





/*otra manera de resolver*/
/*void triangulo(int mat[][TAM])
{
    int i,j;

    for(i=0; i<(TAM-1)/2; i++)
    {

        for(j=1; j<(TAM-1); j++)
        {
            if(i<j && (i+j)!= (TAM-1))

            printf("%d ", mat[i][j]);

        }
        linea
    }
}
*/

