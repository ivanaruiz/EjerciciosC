#include <stdio.h>
#include <stdlib.h>
#define ES_LETRA(x) (((x)>='a' && (x)<='z') || ((x)>='A' && (x)<='Z'))

/*Dado un array de char que contiene un texto compuesto por palabra que termina en '.'
(o en su defecto en caracter nulo '\0', escriba un programa en que determine e informe:
 a-cuál es la primer palabra y cuántas veces se repite en el texto
 b-cuántas palabras tiene el texto
 c-longitud de la palabra más larga */

void resolver(char * cad);
int buscarRepe(char * iniPriPal, char * finPriPal, char * cad, int cont);
void mostrarResultados(char * iniPriPal, char * finPriPpal, int contPal, int longMaxPal);

int main()
{
    char cad[] = "hola ahola totito hola holas como estas";

    printf("%s\n", cad);

    resolver(cad);

    printf("\n%s\n", cad);

    system("pause");
    return 0;
}

void resolver(char * cad)
{
    char * iniPriPal = cad;
    char * finPriPal;

    int contLetrasPorPal=0;
    int longMaxPal=0;
    int contPal =0;

    while(*cad!='\0')
    {
        if(ES_LETRA(*cad))
        {
            contLetrasPorPal=0;
            contPal++;

            //si estamos en la primera palabra, solo defino a iniPriPal
            if(contPal==1)
                iniPriPal = cad;

            //si ya estamos en la segunda palabra, puedo ir a la funcion a buscar los repes de priPal
            if(contPal==2)
                printf("\nRepes primera palabra: %d", buscarRepe(iniPriPal, finPriPal, cad, longMaxPal ));

            while(ES_LETRA(*cad))
            {
                contLetrasPorPal++;
                cad++;
            }

            //si ya terminamos de recorrer la primera palabra, entonces ya definimos su fin
            if(contPal==1)
                finPriPal = cad;

            if(contLetrasPorPal>longMaxPal)
                longMaxPal=contLetrasPorPal;

        }
        cad++;
    }

    mostrarResultados(iniPriPal, finPriPal, contPal, longMaxPal);

}

//lo que hago para encontrar un repe es, recorrer el resto de cad, y cuando encuentre igualdad
//de letras, que empieze un contador de letras
//este debe ser igual al longMaxPalabra, que ya lo obtuvimos en la función anterior
//además de eso debe tener en cuenta el caracter anterior y el posterior al de la supuesta repe
int buscarRepe(char * iniPriPal, char * finPriPal, char * cad, int cont)
{
    int repe =0;
    int contLetras=0;
    char * resetear = iniPriPal;

    while(*cad!='\0')
    {
        if(ES_LETRA(*cad))
        {
            contLetras=0;

            while(*cad==*iniPriPal && iniPriPal<finPriPal)
            {
                //esto sirve para los casos tipo "hola" - "ahola" que NO son iguales
                //por lo tanto se fija en ese caracterer anterior
                if(contLetras==0 && ES_LETRA(*(cad-1)))
                    break;

                contLetras++;
                cad++;
                iniPriPal++;
            }

            iniPriPal = resetear;


            //la segunda parte del if es para los casos tipo "hola" - "holas" que tampoco es válido
            //por eso se fija que el siguiente caracter no sea letra (o sea que no continúe la palabra)
            if(cont==contLetras && !ES_LETRA(*cad))
                repe++;
        }

        cad++;
    }
    return repe;
}


void mostrarResultados(char * iniPriPal, char * finPriPal, int contPal, int longMaxPal)
{
    printf("\na)Primera palabra: ");
    while(iniPriPal<finPriPal)
    {
        printf("%c", *iniPriPal);
        iniPriPal++;
    }

    puts("");
    printf("b)Cantidad de palabras: %d\n", contPal);
    printf("c)Longitud de la palabra mas larga: %d\n", longMaxPal);
}
