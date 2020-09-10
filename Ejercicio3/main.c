#include "header.h"

int main()
{
    int n;
    float tol;

    ingresoDatos(&n, &tol);

    printf("e^%d = %.10lf\n", n, calculo(n,tol));

    system("pause");
    return 0;
}






