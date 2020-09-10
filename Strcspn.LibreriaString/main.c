#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funci�n que simula la funci�n de strcspn de la librer�a string.*/
/*Cuenta el n�mero de caracteres de una cadena apuntada por s1 que no contenga
ninguno de los caracteres en la cadena apuntada por s2.*/
/*La funci�n retorna el n�mero de caracteres le�dos de la subcadena hasta
que halla alguno de los caracteres de s2. El caracter nulo no se cuenta.*/
/*Tener en cuenta que devuelve el menor. Por ejemplo*/
/*s1: "hola a todos"   s2 : "al"
Primero busca la 'a' que es la primera letra de s2, la busca en s1 y cuenta cu�ntos
caracteres hay antes de la primera 'a'. En este caso es cont: 3.
Luego busca la letra 'l' que es la siguiente y �ltima letra de s2, la busca en s1.
Notamos que en este caso el contador nos da 2. Por tanto ese es valor que devuelve.
*/

size_t mi_strcspn(const char * s1, const char * s2);
size_t buscar(const char * s1, const char * s2);

int main()
{
    char s1[] = "hola a todos";
    char s2[] = "abcd";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    //ac� pruebo la funci�n original para comparar con la m�a
    printf("Strcspn:    %d\n", strcspn(s1, s2));

    //ac� hago mi versi�n de strcspn
    printf("Mi strcspn: %d\n", mi_strcspn(s1,s2));

    system("pause");
    return 0;
}


size_t mi_strcspn(const char * s1, const char * s2)
{
    size_t menor  = 1000;  //pongo un n�mero grande por default
    size_t cont   = 0;

    while(*s2!='\0')    //es en este ciclo recorro s2, en la funci�n interna recorrer� s1
    {
        cont = buscar(s1,s2);   //notar que s1 se recorrer� varias veces, se recorrer� tantas veces
                                //como tantos caracteres tenga s1
        if(cont < menor)
            menor = cont;

        s2++;
    }
    return menor;       //siempre devuelvo el menor
}


size_t buscar(const char * s1, const char * s2)
{
    size_t cont = 0;

    while(*s1!='\0')    //ac� recorro s1
    {
        if(*s1==*s2)    //cuando encuentre la letra, entonces ya puedo devolver el contador
        {
            return cont;
        }
        cont++;
        s1++;
    }
    return cont++;      //si llego hasta ac�, es porque no encontr� la letra, entonces
                        //devuelve toda la cantidad de letras que hay en s1
}
