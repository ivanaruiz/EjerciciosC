/**Esta versión es más corta que la otra. Y no muestra la lista de fibonacci, sino que tan solo
te dice si el número en cuestión es fibonacci o no**/

#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0

int fibonacci(int n);

int main()
{
    int n;
    puts("Ingrese numero: ");
    scanf("%d", &n);

    fibonacci(n) || n==1    ?   printf("%d es fibonacci.\n",n)   :   printf("%d no es fibonacci.\n",n);

    system("pause");
    return 0;
}

//////////////////////////////

int fibonacci(int n)
{
    int pt = 1; //primer término
    int st = 1; //segundo término
    int res = 0;

    while(n>res)
    {
        res = pt + st;
        pt = st;
        st = res;
    }

    if(n==res)
        return TRUE;
    else
        return FALSE;
}

/*
En la serie de fibonacci, cada termino es la suma de los dos anteriores y los dos
primeros terminos son 1
serie: 1 1 2 3 5 8 13 21 ...
desarrollar una funcion para determinar si un entero pertenece a la serie de fibonacci
*/
