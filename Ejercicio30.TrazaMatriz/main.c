#include "matriz.h"

int main()
{
    int mat[][TAM] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
                };

    mostrarMatriz(mat, 3,3);

    printf("\nTraza diagonal principal : %d", trazaDiagPrincipal(mat, 3,3));
    printf("\nTraza diagonal secundaria: %d\n", trazaDiagSecundaria(mat, 3,3));

    system("pause");
    return 0;
}


void mostrarMatriz(int mat[][TAM], int ff, int cc)
{
    for(int i =0; i<ff; i++)
    {
        puts("");
        for(int j=0; j<cc; j++)
        {
            printf("%d ", mat[i][j]);
        }
    }

}


int trazaDiagPrincipal(int mat[][TAM], int ff, int cc)
{
    int suma=0;
    for(int i=0; i<ff; i++)
    {
        for(int j=i ; j<=i ; j++)
        {
            suma+=mat[i][j];
        }
    }
    return suma;
}


int trazaDiagSecundaria(int mat[][TAM], int ff, int cc)
{
    int suma=0;
    for(int i=0; i<ff; i++)
    {
        for(int j= cc-i-1 ; j<= cc-i-1 ; j++)
        {
            suma+=mat[i][j];
        }
    }
    return suma;
}
