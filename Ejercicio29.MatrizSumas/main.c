
#include "matriz.h"

int main()
{
    int mat[][TAM] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    mostrar(mat, 3, 3);

    puts("\nSuma de elementos ubicados...\n");

    printf("...sobre la diagonal principal (no incluye diagonal):  %d\n", sumaDiagPrin(mat, 3,3));
    printf("...sobre la diagonal principal (incluye diagonal):     %d\n", sumaDiagPrinIncluyeDiag(mat, 3,3));
    printf("...sobre la diagonal secundaria (no incluye diagonal): %d\n", sumaDiagSecun(mat, 3,3));
    printf("...sobre la diagonal secundaria (incluye diagonal):    %d\n", sumaDiagSecunIncluyeDiag(mat, 3,3));

    puts("");

    printf("...por debajo de la diagonal principal (no incluye diagonal):  %d\n", sumaDiagPrinInferior(mat, 3,3));
    printf("...por debajo de la diagonal principal (incluye diagonal):     %d\n", sumaDiagPrinInferiorIncluyeDiag(mat, 3,3));
    printf("...por debajo de la diagonal secundaria (no incluye diagonal): %d\n", sumaDiagSecunInferior(mat, 3,3));
    printf("...por debajo de la diagonal secundaria (incluye diagonal):    %d\n", sumaDiagSecunInferiorIncluyeDiag(mat, 3,3));

    puts("");
    system("pause");
    return 0;
}





