#include <stdio.h>
#include <stdlib.h>
#define TAM 50
void debajo_diag_ppal(int mat[][TAM], int ord);
void triangulo_izq(int mat[][TAM], int ord);
void triangulo_sup(int mat[][TAM], int ord);
void mostrar_matriz(int mat [][TAM], int fil, int col);
int main()
{
    //int i, j;
    int mat1 [3][TAM]= {{  1,  2,  3},
                        { 44,  5,  6},
                        {  7,  8,944}};
    int mat2 [7][TAM]= {{  1,  2,  3, 78, 26, 27, 28},
                        { 44,  5,  6, 55, 42, 47, 48},
                        {  7,  8,944, 56, 22, 27, 28},
                        { 45, 25, 16,  5, 12, 17, 18},
                        { 14, 12,  1,  3, 55, 57, 58},
                        { 11, 11, 11,  1, 51, 51, 58},
                        { 12, 12, 12,  2, 52, 52, 58}
                        };
//    char mat3 [3][TAM]= {"Hola Mundo", "Hello world", "Bonjour monde"};
//
//    ///printf("%p - %p - %p", mat1, mat1[1], &mat1[1][0]);
//    ///printf("\n%d\n", mat1[0][1]);
//
//    for(i=0; i<3;i++)
//        printf("\n%s\n", mat3[i]);

    triangulo_sup(mat2, 7);
    printf("\n\n");
    mostrar_matriz(mat2, 7,7);
    return 0;
}
void debajo_diag_ppal(int mat[][TAM], int ord)
{
    int i, j;
    for(i=1; i<ord; i++)
    {
        for(j=0;j<i;j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}
void mostrar_matriz(int mat [][TAM], int fil, int col)
{
    int i,j;
    for(i=0; i<fil; i++)
    {
        for(j=0;j<col;j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}
void triangulo_izq(int mat[][TAM], int ord)
{
    int i,j;
    for(i=1; i<ord-1; i++)
    {
        for(j=0 ; j<i && j<(ord-i-1) ; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}
void triangulo_sup(int mat[][TAM], int ord)
{
    int i,j;
    for(i=0; i<ord/2; i++)
    {
        printf("%*s",3*i, "");
        for(j=i+1;j<(ord-i-1);j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
}
/**
diag principal => j = i
diag sec       => j = ord - i - 1
*/
