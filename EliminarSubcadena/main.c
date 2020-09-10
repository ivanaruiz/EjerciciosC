//Ejercicio de cadenas
//Tenemos una cadena original. Y una subcadena (es decir que debería pertenecer a la cadena original).
//Creamos una función que debe volver la cadena restandole las posiciones que alojan la subcadena.
//Ejemplo1. cad="hola como te va" subcad="como"   resultado: "hola te va"
//Ejemplo2. cad="hola como te va" subcad="holas"  resultado: este es erroneo. que devuelva la cadena original.
//Ejemplo3. cad="hola como te va" subcad="omo te" resultado: "hola c te va"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * eliminar_subcadena(char * cad, char * subcad, int ce_subcad);
void desplazar_posiciones(char * cad, char * elim);
char * mientras_haya_coincidencia(char * cad, char * sub, int *cont);

int main()
{
    char cad[] = "hola como te va";
    char sub[] = "la como te";

    printf("Cadena original:\n%s\n", cad);
    printf("Subcadena a eliminar:\n%s\n\n", sub);

    //cantidad de elementos de la subcadena
    int ce_sub = strlen(sub);   //le resto 1 para que no me cuente el '\0' porque necesito la cant total de letras

    printf("Resultado final:\n");
    strcpy ( cad , eliminar_subcadena(cad, sub, ce_sub));

    printf("%s \n", cad);

    system("pause");
    return 0;
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


//devuelve un puntero a char
char * eliminar_subcadena(char * cad, char * sub, int ce_sub)
{
    //contador de coincidencias entre cadena y subcadena (debe ser haber total coincidencia sino no es válido)
    int cont_let=0;
    char * ini = cad;
    char * ini_elim = cad;
    char * reset_sub = sub;


    while(*cad!= '\0')
    {
        if(*cad == *sub)
        {
            ini_elim = cad;

            //a cont_let lo paso con ampersan (direccion) porque estara modificandose en esa funcion
            //si no lo pasara asi, al volver a esta funcion se resetearia a su valor original, o sea a 0
            strcpy( cad, mientras_haya_coincidencia(cad, sub, &cont_let));

            if(cont_let== ce_sub)    //si entra al if es porque efectivamente se encontró la subcadena y debe borrarse
            {
                desplazar_posiciones(cad, ini_elim);
                return ini;
            }

            //si llega acá es porque coincideron algunas letras pero no todas, es decir que aun no se encontró la subcad
            //por tanto reinicio el contador y tambien la subcadena para seguir buscando
            cont_let=0;
            sub= reset_sub;

        }
        cad++;
    }
    printf("No se encontro coincidencia. Se devuelve cadena original:\n");
    return ini;
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

char * mientras_haya_coincidencia(char * cad, char * sub, int *cont)
{
            while(*cad == *sub && *cad && *sub)
            {
                cad++;
                sub++;
                (*cont)++;
            }
            return cad;
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void desplazar_posiciones(char * cad, char * elim)
{
    while(*cad!= '\0')
    {
        *elim= *cad;
        elim++;
        cad++;
    }
    *elim='\0';
}
