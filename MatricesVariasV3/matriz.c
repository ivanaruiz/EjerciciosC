#include "matriz.h"

void mostrar(int mat[][TAM])
{
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
}

void trianguloSup(int mat[][TAM])
{
    for(int i=0; i<=TAM/2; i++)
    {
        printf("%*s", 2*i, "");

        for(int j=i ; j<TAM - i; j++)
        {
            printf("%d ", mat[i][j]);
        }

        puts("");
    }
}

void trianguloInf(int mat[][TAM])
{
    int num = 6;
    int i,j;

    for(i=(TAM/2); i< TAM; i++)
    {
        printf("%*s", num, "");

        for(j= TAM-i-1; j<=i ; j++)
        {
            printf("%d ", mat[i][j]);
        }

        num-=2;

        printf("\n");
    }
}


void trianguloIzq(int mat[][TAM])
{

    int i,j;

    for(i= 0; i< TAM; i++)
    {
        for(j= 0; i< TAM/2 ? j<= i : j<=TAM-i-1 ; j++)
        {
            printf("%d ", mat[i][j]);
        }

    printf("\n");
    }
}

void trianguloDer(int mat[][TAM])
{

    int i,j;
    int num = 12;

    for(i= 0; i< TAM; i++)
    {
        printf("%*s", num,"");

        for(j=  (i<TAM/2 ?  TAM-i-1  :  i) ; j<TAM; j++)
        {
            printf("%d ", mat[i][j]);
        }

    if(i<TAM/2)
        num-=2;
    else
        num+=2;

    printf("\n");
    }
}
