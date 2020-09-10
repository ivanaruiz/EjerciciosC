#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Compara la cadena apuntada por t1 con la cadena apuntada por t2.
int strcmp(const char * t1, const char * t2);
La función retorna un número entero mayor, igual o menor que cero,
apropiadamente según la cadena apuntada por t1 es mayor, igual,
o menor que la cadena apuntada por t2.
*/

int mi_strcmp(const char * t1, const char * t2);

int main()
{
    char t1[] = "HoLaasdf";
    char t2[] = "holas";

    printf("t1: %s\n",t1);
    printf("t2: %s\n",t2);

    //uso strcmp original solo para comparar con la mía
    int i= strcmp(t1,t2);
    if(i==0)
        printf("Son iguales");
    else if(i>0)
        printf("t1 es mayor a t2");
    else printf("t1 es menor a t2");

    //acá ya uso mi strcmp
    puts("\nmi_strcmp");

    i= mi_strcmp(t1,t2);
    if(i==0)
        printf("Son iguales\n");
    else if(i>0)
        printf("t1 es mayor a t2\n");
    else printf("t1 es menor a t2\n");


    system("pause");
    return 0;
}


int mi_strcmp(const char * t1, const char * t2)
{
    while(*t1!='\0' && *t2!='\0' && *t1==*t2)
    {
        t1++;
        t2++;
    }

    if(*t1<*t2)
        return -1;
    if(*t2>*t1 || *t1)
        return 1;

    return 0;   //si retornamos 0 es porque son iguales
}
