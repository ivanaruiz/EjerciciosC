#include "itoa.h"
#include <math.h>

int main()
{
    int n = -256;
    printf("Numero entero ingresado: %d", n);

    char vec[50];   //aca se guardar� la cadena convertida
    int base[4]= {2,8,10,16};


    //muestro c�mo funciona la funci�n itoa original para luego comparar con la m�a

    int i;
    printf("\nConvertido a:\nbase 2\t\tbase 8\t\tbase 10\t\tbase 16\t\t\n");
    for(i=0; i<4; i++)
        printf("%s\t\t",itoa(n,vec,base[i]));


    printf("\n\n");

    //mi propia versi�n
    printf("\nConvertido a:\nbase 2\t\tbase 8\t\tbase 10\t\tbase 16\t\t\n");
    for(i=0; i<4; i++)
        printf("%s\t\t",mi_itoa(n,vec,base[i]));


    printf("\n\n");


    system("pause");
    return 0;
}
