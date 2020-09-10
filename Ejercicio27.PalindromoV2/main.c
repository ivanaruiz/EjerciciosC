#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0

/*Desarrollar una funci�n que determine si una palabra es pal�ndromo*/

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
        if(*vec == *fin)    //la condici�n es que las letras sean iguales, entonces seguimos avanzando
        {
            vec++;
            fin--;
        }
        else
        {
            return FALSE;   //si pasamos tan solo una vez por ac�, ya no es pal�ndromo, asi que cortamos
        }
    }
    return TRUE;
}
