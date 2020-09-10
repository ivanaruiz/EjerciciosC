
#include "matriz.h"

void mostrar(int mat[][TAM], int ff, int cc)
{
    for(int i = 0 ; i<ff; i++)
    {
        puts("");
        for(int j=0; j<cc; j++)
        {
            printf("%d ", mat[i][j]);
        }
    }
}

//1)
int sumaDiagPrin(int mat[][TAM], int ff, int cc)
{
    int suma=0;

    for(int i=0; i<ff-1; i++)
    {
        for(int j=i+1; j <cc; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//2)
int sumaDiagPrinIncluyeDiag(int mat[][TAM], int ff, int cc)
{
    int suma=0;

    for(int i=0; i<ff; i++)
    {
        for(int j=i; j <cc; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//3)
int sumaDiagSecun(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=0; i< ff-1; i++)
    {
        for(int j=0 ; j < cc-1-i; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//4)
int sumaDiagSecunIncluyeDiag(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=0; i< ff; i++)
    {
        for(int j=0 ; j < cc-i; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//5)
int sumaDiagPrinInferior(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=1; i< ff; i++)
    {
        for(int j= 0 ; j < i; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//6)
int sumaDiagPrinInferiorIncluyeDiag(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=0; i< ff; i++)
    {
        for(int j= 0 ; j <= i; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//7)

int sumaDiagSecunInferior(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=1; i< ff; i++)
    {
        for(int j= cc-i ; j < cc; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}

//8)
int sumaDiagSecunInferiorIncluyeDiag(int mat[][TAM], int ff, int cc)
{
    int suma=0;


    for(int i=0; i< ff; i++)
    {
        for(int j= cc-1-i ; j < cc; j++)
        {
            suma+= mat[i][j];
        }
    }
    return suma;
}
