#include "header.h"

void ingresoDatos(int *n, float *tol)
{
    do
    {
    printf("Ingrese numero entero: ");
    fflush(stdin);
    scanf("%d", n);
    }   while(*n<0);

    do
    {
    printf("Ingrese una tolerancia entre 0(no inclusive) y 1(inclusive): ");
    fflush(stdin);
    scanf("%f", tol);
    }
    while(*tol<= 0 || *tol>1);
}


double calculo (int n, float tol)
{
    double term = 1;    ///empieza en 1 ya que el primer termino es 1 segun la regla
    int i =1;           ///este numero es un entero que ira incrementando de a 1, para ir obteniendo el factorial
    double acum=1;      ///aca se iran sumando todos los terminos

    while(term >= tol)
    {
        term= pow(n,i) /factorial(i);
        acum+= term;
        i++;
    }
    return acum;
}



double factorial(int val)
{
    double fact = 1;
    for(int i=1; i<= val; i++)
        fact*=i;
    return fact;
}
