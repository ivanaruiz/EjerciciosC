#include "primo.h"

int main()
{
    int n;

    //pido un número mayor a 0
    do
    {
        printf("Ingrese numero: ");
        scanf("%d", &n);
    }while(n<=0);

    //uso una ternaria
    primonoprimo(n) ?   printf("Es primo.\n")  :   printf("No es primo.\n");

    system("pause");
    return 0;
}



int primonoprimo(int n)
{
int i;

for(i=2; i<n ; i++)    ///empiezo en 2, porque los numeros primos son del 2 en adelante
    {
        if(n%i==0)     ///si tan solo un resto da 0, indica que ese numero tiene divisores(o sea es no primo)
            return NOPRIMO;
    }
    //si llegamos acá es porque hizo todo el bucle y no tuvo divisores, por tanto es primo
    return PRIMO;
}




