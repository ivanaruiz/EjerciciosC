#include "seno.h"

void ingresoDatos(int *n, float*tol)
{
    printf("Ingresar numero: ");
    fflush(stdin);
    scanf("%d", n);
    do
    {
    printf("Ingresar tolerancia entre 0 y 1: ");
    fflush(stdin);
    scanf("%f", tol);
    }while(*tol<=0 || *tol>=1);
}


long double seno(int n, float tol)
{
    long double acum = 0;
    long double term =1;
    int expo = 1;
    int paso= 1;


    while(term>tol)
    {
        term= pow(n,expo) / factorial(expo);

        if(paso%2!=0)
            acum+= term;
        else
            acum-= term;

        expo+=2;
        paso++;

        if(term<0)  ///por si da negativo, obtengo el valor absoluto para seguir entrando al while
            term= term*(-1);
    }

    return acum;
}



long double factorial(int expo)
{
    long double fact = 1;
    for(int i=1; i<= expo; i++)
        fact*=i;

    return fact;
}
