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

    mostrar(mat);
    puts("");

    trianguloSup(mat);
    puts("");

    trianguloInf(mat);
    puts("");
    puts("");

    trianguloIzq(mat);
    puts("");

    trianguloDer(mat);
    puts("");

    system("pause");
    return 0;
}

