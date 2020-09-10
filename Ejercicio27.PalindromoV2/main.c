#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0

/*Desarrollar una función que determine si una palabra es palíndromo*/

int palindromo(char * vec, int ce);

int main()
{
    char vec [] = "reconocer";
    int ce= sizeof(vec)/sizeof(char);
    printf("Palabra: %s\n", vec);

    palindromo(vec, ce-1)   ?   printf("Es palindromo\n")    :    printf("Eo es palindromo\n");

    system("pause");
    return 0;
}

int palindromo(char * vec, int ce)
{
    char * fin = vec + ce -1;

    while(vec<fin)
    {
        if(*vec == *fin)    //la condición es que las letras sean iguales, entonces seguimos avanzando
        {
            vec++;
            fin--;
        }
        else
        {
            return FALSE;   //si pasamos tan solo una vez por acá, ya no es palíndromo, asi que cortamos
        }
    }
    return TRUE;
}
