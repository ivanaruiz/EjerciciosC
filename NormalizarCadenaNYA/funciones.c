#include "normalizar.h"

void normalizar(char *vec)
{
    char *ptr= vec;
    char *ptrFin= vec+TAM-1;
    char *ini=vec;
    int hubocoma= FALSO;
    int contPalabras=0;

    while(ptr<ptrFin)
    {
        if(ESLETRA(*ptr))
        {
            contPalabras++;         //contara las palabras solo para evaluar el tema de las comas
            *ptr= toupper(*ptr);    //a la primera letra de cada palabra la pone en mayus

            while(ESLETRA(*ptr))
            {
               *vec=*ptr;
                vec++;
                ptr++;
                *ptr= tolower(*ptr);
            }
            *vec=' ';
            vec++;
        }

        if(ESCOMA(*ptr) && hubocoma==FALSO)
        {
            if(contPalabras!=0) ///si hubo coma y sin embargo aun no contó palabras, no es coma valido, ejemplo: ",rUiz  ivAnA "
                                ///si entra al if, es porque esa situacion no pasó
            {
            *(vec-1)=*ptr;      ///retrocedo un lugar para poner la coma, ya que el vec me quedo adelantado
            *vec=' ';
            vec++;
            hubocoma=VERDADERO; ///cambio el estado asi si encuentra una coma mas, no la considere
            }
        }
        ptr++;
    }   ///ciero while grande



    if(ESCOMA(*(vec-2)))    ///esto es para el caso en que encontró una sola coma y al final de la cadena lista ej "Ruiz Ivana,"
    {
        *(vec-2)= 32;       ///de ser asi, que pise esa coma con un espacio
        hubocoma=0;         ///y setee de nuevo hubocoma para que entre en el siguiente if
    }


    *vec='\0';


    if(hubocoma==FALSO) ///si no hubo ninguna coma, entonces debo ponerla yo
    {
        ptr=ini;
        colocarComa(ptr, ptrFin);
    }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////




void colocarComa(char *ptr, char *ptrFin)
{
     while(*ptr!='\0')
        {
            if(ESESPACIO(*ptr))
            {
                *ptr=',';   ///pongo la coma pero ahora me quede sin espacios entre palabras
                ptr++;

                while(ptrFin>ptr)   ///para arreglar eso, debo correr todas las letras luego de la coma, una posicion mas adelante
                {
                    *ptrFin= *(ptrFin-1);   ///empiezo del final, voy corriendo todas las letras hasta llegar a la coma
                    ptrFin--;
                }
                *ptr=32;
                break;  ///una vez que encontro un espacio y puso la coma, no es necesario seguir mas
            }
            ptr++;
        }
}
