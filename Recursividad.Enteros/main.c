#include <stdio.h>
#include <stdlib.h>
#define linea puts("\n====");

/*Ejercicios de recursividad con un número entero.
Mostrar por pantalla:
1) 1234
2) 4321
3)  1
    12
    123
    1234
4)  1234
    123
    12
    1
*/

void parteA(int num);
void parteB(int num);

void parteG(int num);
void parteH(int num);


int main()
{
    int num = 1234;

    parteA(num);
    linea
    parteB(num);
    linea
    parteG(num);
    linea
    parteH(num);
    linea

    system("pause");
    return 0;
}

void parteA(int num)
{
    if(num==0)
        return;

    parteA(num/10);
    printf("%d", num%10);
}

void parteB(int num)
{
    if(num==0)
        return;

    printf("%d", num%10);
    parteB(num/10);
}

void parteG(int num)
{
    if(num==0)
        return;

    parteG(num/10);
    printf("%d\n", num);
}

void parteH(int num)
{
    if(num==0)
        return;

    printf("%d\n", num);
    parteH(num/10);
}


