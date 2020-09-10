/*
Construir un programa que lea un numero natural n y calcule la suma de los
numeros pares menores que n
*/

#include <stdio.h>
#include <stdlib.h>

void validarNumero(int *n);

int main()
{
    int i, n;
    int suma=0;
    printf("Ingrese numero: ");
    validarNumero(&n);

    for(i=0; i<n; i= i+2)
    {
        suma+= i;
    }
    printf("\n\nLa suma de los numeros pares menores a %d es: %d\n\n", n, suma);

    system("pause");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////

void validarNumero(int *n)
{
    do
    {
        scanf("%d", n);
        fflush(stdin);
        if(*n<0)
            printf("Numero invalido! Vuelva a ingresar un numero natural: ");
    }
    while(*n < 0);
}
