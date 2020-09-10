#include <stdio.h>
#include <stdlib.h>
#define TAM 50

/*Desarrollar una función para obtener la transpuesta de una matriz dada*/

void trasponer(int mat[][TAM], int matT[][TAM], int ff, int cc);
void mostrar(int mat[][TAM], int ff, int cc);


int main()
{
    int mat[][TAM] =    {
                        {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16},
                        };

    //creo una segunda matriz, que es donde voy a trasponer la primera
    int matT[][TAM] =   {
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}
                        };

    //primero muestro mi matriz original
    printf("Matriz:\n");
    mostrar(mat,4,4);
    puts("");

    //mando las dos matrices, de la original copiaré a la segunda
    trasponer(mat, matT, 4,4);
    puts("");

    //finalmente veo la matriz traspuesta
    printf("Matriz traspuesta:\n");
    mostrar(matT,4,4);

    puts("");
    system("pause");
    return 0;
}

void mostrar(int mat[][TAM], int ff, int cc)
{
    for(int i=0; i<ff; i++)
    {
        for(int j=0; j<cc; j++)
            printf("%3d ", mat[i][j]);

        puts("");
    }
}


void trasponer(int mat[][TAM], int matT[][TAM], int ff, int cc)
{
    for(int i=0; i<ff; i++)
        for(int j=0; j<cc; j++)
            matT[j][i] = mat[i][j]; //copio a la segunda matriz, notar que intercambio i por j
}



