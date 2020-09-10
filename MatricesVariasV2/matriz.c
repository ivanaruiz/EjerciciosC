#include "matriz.h"

void mostrarMatrizCompleta(int mat[][TAM])
{
    printf("Matriz completa: ");
    linea

    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
            printf("%d  ", mat[i][j]);
        linea
    }
}



void trianguloSup(int mat[][TAM])
{
    int i,j;
    printf("Triangulo superior: "); linea

    for(i=0; i<((TAM-1)/2); i++)
    {
        printf("%*s", 3*i, "");
        for(j=1+i ; j<TAM-1-i ; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        linea
    }
}


void trianguloInf(int mat[][TAM])
{
    int i,j;
    int n=6;
    printf("Triangulo inferior: "); linea



    for(i= (TAM/2)+1; i<TAM; i++)
    {
        printf("%*s",n,"");
        for(j=TAM-i; j<=i-1; j++)
        {
                printf("%d  ", mat[i][j]);
        }

        linea
        n-=3;
    }
}



void trianguloIzq(int mat[][TAM])
{
    int i,j;
    printf("Triangulo izquierdo: "); linea
    for(i=1; i<TAM-1; i++)
    {
        for(j=0; j<i && (i+j<(TAM-1)); j++)
        {
                printf("%d  ", mat[i][j]);
        }
        linea
    }
}

void trianguloDer(int mat[][TAM])
{
    int i,j;
    printf("Triangulo derecho: ");
    linea
    int n=12;

    for(i=1; i<TAM-1; i++)
    {
        printf("%*s",n,"");
        for( j= (i<TAM/2? TAM-i: i+1)  ; j<TAM; j++)
        {
                printf("%d  ", mat[i][j]);
        }

        linea


        if(i<(TAM)/2)
            n-=3;
            else n+=3;

    }
}





