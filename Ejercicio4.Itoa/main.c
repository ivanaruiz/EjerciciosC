#include "itoa.h"


int main()
{
    int n = 7000;
    printf("Numero entero ingresado: %d", n);

    char vec[50];   //aca se guardará la cadena convertida
    int base= 16;

    //uso la función itoa original para luego comparar con la mía
    printf("\n\nNumero convertido a cadena de "
           "caracteres: (itoa)    %s\n",itoa(n,vec,base));

    //mi versión
    mi_itoa(n, vec, base);

    printf("\nNumero convertido a cadena de caracteres: (mi itoa) %s\n\n", vec);

    system("pause");
    return 0;
}


