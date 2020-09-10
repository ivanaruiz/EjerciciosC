#include "matriz.h"


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

    trianguloSup(mat);
    linea

    trianguloInf(mat);
    linea

    trianguloIzq(mat);
    linea

    trianguloDer(mat);
    linea


    system("pause");
    return 0;
}
