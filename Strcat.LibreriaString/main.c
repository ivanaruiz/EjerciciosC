#include "strcat.h"

int main()
{
    char t1[TAM];
    char t2[TAM];

    printf("Ingresar primer texto: ");
    fflush(stdin);
    gets(t1);
    printf("Ingresar segundo texto: ");
    fflush(stdin);
    gets(t2);

    printf("t1: %s\n", t1);
    printf("t2: %s\n", t2);

    mi_strcat(t1,t2);

    printf("t1 concatenado: %s\n",t1);

    system("pause");
    return 0;
}


char * mi_strcat(char *t1, const char *t2)
{
    while(*t1!= '\0')   //recorro hasta la ultima letra ingresada del texto1
    {                   //ya que luego de ella es donde empezaré a copiar t2
        t1++;
    }

    while(*t2!= '\0')
    {
        *t1= *t2;       //copio el texto2 a la continuacion del texto1
        t1++;
        t2++;
    }

    *t1= '\0';
    return t1;
}

