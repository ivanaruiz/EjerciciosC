#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 35;
    int b = 8;

    int acum =0;

    printf("a: %d\n"
           "b: %d\n", a,b);

    while(a >= 1)
    {
        if(a%2!=0)
            acum+= b;

        a = a/2;
        b = b*2;
    }

    printf("Producto (metodo ruso): %d.\n", acum);

    system("pause");
    return 0;
}

/**
El método de multiplicación rusa de dos números naturales, consiste en lo siguiente:
Se divide sucesivamente por 2 (división entera) a uno de sus factores hasta obtener 1.
Paralelamente, se multiplica sucesivamente por 2 al otro factor.
La suma de estos últimos números obtenidos que se correspondan con números impares
obtenidos en las divisiones, es el producto buscado
(se consideran también los factores originales para la suma correspondiente).
Por ejemplo para : 35x8
35  8
17  16
8   32
4   64
2   128
1   256
Para 8,16 y 256 se corresponden con impares (35,17,1)
Por tanto sumamos: 8+16+256= 280
**/
