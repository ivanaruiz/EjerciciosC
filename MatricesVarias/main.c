#include "matrices.h"


int main()
{
    int mat[][TAM]={{1,1,1,1,1,1,1},
                    {2,2,2,2,2,2,2},
                    {3,3,3,3,3,3,3},
                    {4,4,4,4,4,4,4},
                    {5,5,5,5,5,5,5},
                    {6,6,6,6,6,6,6},
                    {7,7,7,7,7,7,7}};

    mostrarMatrizCompleta(mat);
    linea

    trianguloArriba(mat);
    linea

    trianguloAbajo(mat);
    linea

    trianguloIzquierda(mat);
    linea

    trianguloDerecha(mat);
    linea

    system("pause");

    return 0;
}


