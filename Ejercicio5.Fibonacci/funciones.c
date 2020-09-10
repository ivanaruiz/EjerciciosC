#include "fibonacci.h"


///solo valido que el numero ingresado sea mayor a 0
void validar (int *num)
{
    do
    {
        scanf("%d", num);
        if(*num<1)
                    printf("Numero invalido. Vuelva a ingresar el numero: ");
    }while(*num<1);

}

//////////////////////////////////////////////////////////////////////


int fibonacci(int num)
{
    int pt, st = 1; ///pt= primer termino. st= segundo termino
    int suma = 1;

    do
    {
        pt= st;
        st= suma;
        suma = pt+st;

        mostrarLista(suma, num);    ///esto no lo pide pero lo hago optativo

    }while(suma < num);


        if(suma==num)   ///aca encontre fibonacci
            return FIBO;
        else
            return NOFIBO;
}


//////////////////////////////////////////////////////////////////////



void mostrarLista(int suma, int num)
{
///entra a este if la primera vuelta, ya que la suma de los dos primeros terminos es 2
    if(suma==2)
        printf("\nLista fibonacci hasta el numero %d: \n1  1  ", num);

///para el resto de las vueltas, entra a este if y muestra el resto de la lista
///con esto ademas, evito que no imprima un numero mayor al numero ingresado
    if(suma<=num)
            printf("%d  ", suma);

}
