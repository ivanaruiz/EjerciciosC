#include <stdio.h>
#include <stdlib.h>
#define TAM 50

/*Desarrollar una función para trasponer, in situ, una matriz cuadrada*/
/*Es decir NO tengo que crear otra matriz auxiliar*/

void trasponerInSitu(int mat[][TAM], int ff, int cc);
void mostrar(int mat[][TAM], int orden);


int main()
{
    int mat[][TAM] =    {
                        {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16},
                        };


    printf("Matriz:\n");
    mostrar(mat,4 );
    puts("");


    trasponerInSitu(mat, 4,4);
    puts("");


    printf("Matriz traspuesta in situ:\n");
    mostrar(mat,4);

    puts("");
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


void trasponerInSitu(int mat[][TAM], int ff, int cc)
{
    //recorro los elementos que se encuentran SOBRE la diagonal principal
    //esos elementos son los que debo intercambiar con los que se encuentran POR DEBAJO
    //de la misma diagonal principal

    for(int i=0; i<ff-1; i++)
        for(int j= i+1; j<cc; j++)
        {
            //creo un auxiliar y hago el intercambio
            int aux = mat[j][i];
            mat[j][i] = mat[i][j];
            mat[i][j] = aux;
        }
}



