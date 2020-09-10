#include <stdio.h>
#include <stdlib.h>
#define TAM 50

/*Desarrollar una función que determine si una matriz cuadrada de enteros
de orden N es simétrica*/
/*Para saber si es simétrica, lo que hago es trasponer la matriz, y comparar.
En caso de que la original sea exactamnte igual a la traspuesta, entonces es simétrica.*/

void trasponer(int mat[][TAM], int matT[][TAM], int ff, int cc);
void mostrar(int mat[][TAM], int orden);
int esMatrizSimetrica(int mat[][TAM], int matT[][TAM], int ff, int cc);


int main()
{
    int mat[][TAM] =    {
                        {1,2,3,4},
                        {2,5,6,7},
                        {3,6,8,9},
                        {4,7,9,12},
                        };

    //creo una segunda matriz, que es donde voy a trasponer la primera
    //no la mostraré, será solamente para comparar con la matriz original
    int matT[][TAM] =   {};

    //primero muestro mi matriz original
    printf("Matriz:\n");
    mostrar(mat,4);
    puts("");

    //mando las dos matrices, de la original copiaré a la segunda
    trasponer(mat, matT, 4,4);


    //finalmente comparo ambas matrices
    //si son iguales, entonces la matriz (original) es simétrica
    if(esMatrizSimetrica(mat, matT, 4,4))
        printf("\nES MATRIZ SIMETRICA\n");
    else
        printf("\nNO ES MATRIZ SIMETRICA\n");


    system("pause");
    return 0;
}


void mostrar(int mat[][TAM], int orden)
{
    for(int i=0; i<orden; i++)
    {
        for(int j=0; j<orden; j++)
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


int esMatrizSimetrica(int mat[][TAM], int matT[][TAM], int ff, int cc)
{
    for(int i=0; i<ff; i++)
    {
        for(int j=0; j<cc; j++)
        {
            if(mat[i][j]!= matT[i][j])
                return 0;
        }
    }

    return 1;
}
