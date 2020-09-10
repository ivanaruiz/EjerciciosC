#include <stdio.h>
#include <stdlib.h>

double factorial(int n);

int main()
{
    int n = 5;

    printf("Factorial de %d = %.0lf\n", n, factorial(n));

    system("pause");
    return 0;
}



//versi�n para debuggear y ver c�mo funciona
double factorial(int n)
{
    double r;

    if(n==0)
        return 1;

    r = n * factorial(n-1);

    return r;
}

/**
1. Definici�n recursiva del problema
2. Condici�n de corte
//versi�n posta
double factorial(int n)
{
    if(n==0)
        return 1;

    return n * factorial(n-1);
}
**/
