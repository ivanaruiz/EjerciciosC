#include "normalizar.h"

int main()
{
    char cad[]= ".#{hOLa ,. - pePE###";
    int ce = sizeof(cad)/sizeof(char);

    printf("%s", cad);

    normalizar(cad, ce);

    printf("\n\nCadena normalizada: \n%s\n\n", (cad));

    system("pause");
    return 0;
}



void normalizar(char * cad, int ce)
{
    char * avanzar = cad;
    char * mayus = cad;

    //avanzar es el puntero que va a analizar cada posicion
    //en cad vamos a colocar la frase que iremos normalizando

    while(*avanzar!= '\0')
    {
       if(ESLETRA(*avanzar))
            {
                while(ESLETRA(*avanzar))
                {
                    *cad= tolower(*avanzar);
                    cad++;
                    avanzar++;
                }
                *cad= 32;   //agrego un espacio, ya que terminó con una palabra
                cad++;
            }
            avanzar++;
    }
    *cad='\0';  //fin de cadena

    *mayus = toupper(*mayus);
}


