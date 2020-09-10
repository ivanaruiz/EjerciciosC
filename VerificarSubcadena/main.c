/*Ejercicio de cadenas
Tendremos un vector con nuestra cadena original.  Y otro subvector que será una subcadena.
Debemos verificar si la subcadena se encuentra correctamente dentro de la cadena original.
Ejemplo2 cad: "hola pepe". subcadena: "la pe"   VERIFICA.
Ejemplo1 cad: "hola pepe". subcadena: "holaa"   NO VERIFICA.
Ejemplo3 cad: "hola pepe". subcadena. "hola pepe"  VERIFICA.
Ejemplo4 cad: "holas pepe". subcadena: "hola pepe" NO VERIFICA.
Para este último caso debo setear el contador a 0 despues de todo un ciclo ya que
al haber coincidencia en el primer hola y luego se corta con la s.
Luego seguira contando con pepe, lo cual es inválido.
Además tengo que resetear sub al inicio para que vuelva a buscar coincidencias.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERDADERO 1
#define FALSO 0

int verificar_subcadena(char * cad, char * sub, int ce_subc);

int main()
{
    char cad[] = "holas pepe";
    char sub[] = "olas pe";

    int ce_sub = sizeof(sub) -1; //cantidad de elementos de subcadena
    //en este caso le resto 1 por el '\0' porque necesito saber la cantidad justa de letras, lo necesitare para la funcion

    printf("Cadena original: %s\n", cad);
    printf("Busco subcadena: %s\n", sub);

    //uso una ternaria
    printf( verificar_subcadena(cad, sub, ce_sub) ? "VERIFICA\n" : "NO VERIFICA\n");

    system("pause");
    return 0;
}



//////////////////////////////////////////////
//////////////////////////////////////////////



int verificar_subcadena(char * cad, char * sub, int ce_subcad)
{
    char * reset_sub = sub;
    int cont=0; //contador que sirve para comparar si la coincidencia de letras con la subcadena es total
    //en caso de ser menor es porque no hubo total coincidencia, entonces no verificaria
    //este contador debe ser igual a ce_sub para que verifique
    //esto es para los casos en que cad="hola pepe" y sub="holaa". no deberia verificar
    //pues sub es 5. y el contador es 4.

    while(*cad!='\0')
    {
        if(*cad == *sub)
        {
            while(*cad == *sub && *cad!='\0')   //mientras hay coincidencia,
            {                                   //que empiece el contador
                cad++;
                sub++;
                cont++;
            }
            if(cont==ce_subcad) //una vez que terminó el while, me fijo si el contador quedó igual o fue incompleto
                return VERDADERO;   //o sea hubo total coincidencia, entonces verifica

            //si pasa por aca es porque no hubo total coincidencia, (era otra palabra),
            //entonces seteo el contador, y seteo sub hasta su inicio (para nueva busqueda)
            cont= 0 ;
            sub = reset_sub;
        }
        cad++;
    }

    //si llegamos acá es porque no se encontró sub dentro de cad
    return FALSO;
}




