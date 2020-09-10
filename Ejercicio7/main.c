#include "header.h"

int main()
{
    int n;
    ingresoNumero(&n);

    int total= calculo(n);

    if(total==n)
        printf("\n%d es un numero perfecto.\n", n);
    else if(total<n)
        printf("\n%d es un numero deficiente.\n", n);
    else
        printf("\n%d es un numero abundante.\n", n);

    system("pause");
    return 0;
}


void ingresoNumero(int *n)
{
    do
    {
    printf("Ingrese un numero mayor a 0: ");
    fflush(stdin);
    scanf("%d",n);
    }while(*n<= 0);

}


int calculo(int n)
{
int suma = 0;

for(int i= 1; i<n; i++)
{
    if(n%i == 0)
        suma+=i;
}

printf("La suma de los divisores menores a %d es %d", n, suma);
return suma;
}
