#include "itoa.h"


int main()
{
    int n = 7000;
    printf("Numero entero ingresado: %d", n);

    char vec[50];   //aca se guardar� la cadena convertida
    int base= 16;

    //uso la funci�n itoa original para luego comparar con la m�a
    printf("\n\nNumero convertido a cadena de "
           "caracteres: (itoa)    %s\n",itoa(n,vec,base));

    //mi versi�n
    mi_itoa(n, vec, base);

    printf("\nNumero convertido a cadena de caracteres: (mi itoa) %s\n\n", vec);

    system("pause");
    return 0;
}


