
#include <stdio.h>
#include <stdlib.h>
typedef int entero;

int main()
{
    entero x = 25;

    int *p;

    p = &x;


    printf("\n %d - Valor de x", x);
    printf("\n %d - Direccion de x en decimal", &x);
    printf("\n %p - Direccion de x en hexadecimal", &x);
    printf("\n %x - Direccion de x en hexadecimal", &x);

    printf("\n\n");

    printf("\n %d - Direccion de x (desde el puntero p)", p);
    printf("\n %p - Direccion de x (desde el puntero p) en hexadecimal", p);
    printf("\n %d - El contenido del puntero p", *p);
    printf("\n %d - La direccion del puntero p", &p);
    printf("\n %p - La direccion del puntero p en hexadecimal", &p);

    printf("\n\n\n\n\n\n");


    int dato= 30;
    int *ptr;

    ptr = &dato;
    *ptr=50;        ///ojo esta modificando el contenido de dato!!!

    printf("Dato = %d ", dato);



    int vec[10];
    int ce = 5;
    cargarvector(vec,ce);
    imprimirvector(vec,ce);


    return 0;
}


    ///notar que no creo un nuevo puntero
void cargarvector(int *pv,int ce)
{
    int i=0;
    printf("\n\n\ncargue %d elementos al vector: ",ce);
    for(i=0; i<ce; i++)
    {
        scanf("%d", pv);
        pv++;
    }
}


void imprimirvector(int *pv,int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        printf("%d ",*pv);
        pv++;
    }
}

