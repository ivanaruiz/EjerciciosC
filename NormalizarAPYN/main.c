#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ES_LETRA(x) ( (x>='a' && x<='z') || (x>='A' && x<='Z') )

void normalizar(char * vec, int ce);
void ponerComa(char * inicio);

int main()
{
    char vec[] = "  ,rUiZ  . iVAnA, ?!·vIctoria!!,   ";
    int ce = sizeof(vec)/sizeof(char);

    printf("%s\n", vec);

    normalizar(vec, ce);

    printf("%s\n", vec);

    return 0;
}


void normalizar(char * vec, int ce)
{
    char * avanzar= vec;
    char * inicio = vec;
    int huboComa=0;         //dos banderas
    int primeraPalabra=0;

    while(*avanzar!='\0')
    {
        if(ES_LETRA(*avanzar))  //en este if y while normalizo cada palabra encontrada
        {
            primeraPalabra=1;
            *avanzar = toupper(*avanzar);   //acá va la primera letra de cada palabra
            while(ES_LETRA(*avanzar))
            {
                *vec= *avanzar;
                vec++;
                avanzar++;
                *avanzar = tolower(*avanzar);
            }
            *vec=32;    //espacio
            vec++;
        }

        //en el siguiente if evalúo el tema de las comas
        //si hubo una coma antes de la primera palabra, entonces esa coma no cuenta
        //por tanto no entra a este if y se borra esa coma inválida
        //además si luego ya hubo una coma válida, no debe tener en cuenta las siguientes comas
        //por eso uso las dos banderas
        if(*avanzar==',' && huboComa==0 && primeraPalabra==1)
        {
            huboComa=1;
            vec--;              //retrocedo(ya que tenía un espacio), y pongo la coma
            *vec= *avanzar;
            vec++;
            *vec=32;
            vec++;
            avanzar++;
        }
        avanzar++;
    }

    //este if es para cuando habia una coma LUEGO de la ultima palabra,
    //por tanto tampoco es una coma válida, y debe borrarse
    vec-=2;
    if(*vec==',')
    {
        *vec= '\0';
        huboComa=0;     //lo vuelvo a setear ya que era coma inválida
    }
    else
    {
        vec++;
        *vec= '\0';
    }

    if(huboComa==0)     //finalmente si la frase quedó sin comas, debo agregarla yo
        ponerComa(inicio);
}

void ponerComa(char * inicio)
{
    while(*inicio!= '\0')
    {
        if(*inicio==32)
        {
            *inicio= ',';
            return;
        }
        inicio++;
    }
}
