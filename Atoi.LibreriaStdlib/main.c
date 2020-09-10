#include <stdio.h>
#include <stdlib.h>

/*Programa que simula la función de atoi de la librería stdlib.*/
/*Convierte una cadena de caracteres a una representación de enteros.*/
/*Ej char cad[1592]  -> int num = atoi(cad) ->  num = 1592 */
/*Lo que hago en atoi es desmenuzar cada caracter. Ejemplo el primero es 1.
Entonces hace la cuenta ascii 49-48 (que son 1-0 en ascii) = 1 (el 1 ya es entero).
Ese 1 lo paso a un int dig;
Luego en un int num = 0;  hago num = (num*10) + dig
Es decir hace:  num = (0*10)+1 = 1 . Y así sucesivamente. */

int mi_atoi(const char * cad);


int main()
{
    char cad [] = "1234";

    printf("Cadena de char:  %s\n", cad);

    puts("\nConvertimos a entero.");

    printf("Mi atoi: %d\n",  mi_atoi(cad));

    system("pause");
    return 0;
}


int mi_atoi(const char * cad)
{
    int num = 0;    //este el número resultante final
    int dig = 0;    //aca guardo digito a digito a medida que desmenuzo cad

    while(*cad!= '\0')      //recorro toda la cadena
    {
        dig = *cad - 48;    //le resto el 48 ascii (que es 0) y obtengo el entero
                            //ej si tengo un 1(49), hace 49-48 = 1 (1 entero)

        num = (num*10) + dig;   //y voy acumulando en el número resultante

        cad++;
    }

    return num;
}
