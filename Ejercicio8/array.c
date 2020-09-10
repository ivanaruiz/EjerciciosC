#include "array.h"



void resolver(char * texto)
{
    int cantPal=0;              //un contador de palabras
    int cantLet=0;              //contaremos la cantidad de letras de cada palabra
    int maxLongPal=0;           //aca guardamos la cantidad de letras que tenga la palabra con mayor longitud
    char * ppIni;               //puntero al inicio de la primera palabra
    char * ppFin;               //puntero al final de la primera palabra
    int ban=0;                  //la bandera solo es un indicador para la primera palabra, si esta en 0 y encuentra la
                                //primera palabra, se posiciona en la primera letra y ppIni apuntara alli, entonces
                                //ban se setea en 1, asi que ya ppIni no se mueve
    int huborepe=0;
    int cantLetPP=0;            //cantidad de letras de la primera palabra
    int cantVecesRepetidas=0;   //esta variable la mandaremos como parametro para ver si hubo repe de la primera palabra



    while(*texto != '\0')
    {
        if(ES_LETRA(*texto) )
        {
            cantPal++;

            while(ES_LETRA(*texto) )
            {
                if(cantPal==1)  //si es la primera palabra, voy a contar su cant de letras
                {
                    cantLetPP++;
                    if(ban==0)  //esta bandera es para la primera letra encontrada de la primera palabra,
                                //ppIni apuntara a ella.
                    {
                        ppIni= texto;
                        ban=1;
                    }
                }

                if(cantPal>=2)  //si es cualquier otra palabra menos la primera, me fijo si es repe de la primera o no
                    huborepe= buscarRepe(ppIni, ppFin, texto, cantLetPP, &cantVecesRepetidas);
                //en cantVecesRepetidas le pasé la direccion porque sino al usar nuevamente esta funsion se setea esa variable

                cantLet++;
                texto++;
            }   //cuando sale de este while es porque terminó una palabra
            if(cantPal==1)  //si terminamos de recorrer la primera palabra, usamos el ppFin para indicarlo que ahi terminó
                ppFin= texto;
        }

        if(cantLet>maxLongPal)  //con este if buscamos a la palabra con mayor cant de letras
            maxLongPal= cantLet;

        cantLet=0;  //al terminar de recorrer una palabra, seteamos en cero para volver a contar letras de la prox pal
        texto++;

    }//cierro while grande

    mostrar_resultados(ppIni,ppFin, huborepe, cantPal, maxLongPal);



}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

int buscarRepe(char *ppIni, char* ppFin, char* texto, int cantLetPP, int *cantVecesRepetidas)
{
    int cantLetPR=0;


    while(ES_LETRA(*texto) && *texto==*ppIni)
    {
        //este if es para los casos invalidos tipo "hola" - "ahola" lo cual no debe contarse
        //por eso se fija en el caracter anterior
        //si es una letra, significa que la palabra empezó antes, entonces corta y sale
        if(cantLetPR==0 && ES_LETRA(*(texto-1)))
            break;
        ppIni++;
        texto++;
        cantLetPR++;
    }

    //la segunda parte del if es para los casos tipo "hola" - "holas" lo cual no es valido
    //por eso se fija en el caracter siguiente
    //si hay mas letras, es porque continuaba la palabra, entonce no debe contarse como repe
    if(cantLetPP==cantLetPR && !ES_LETRA(*texto))
        *cantVecesRepetidas= *cantVecesRepetidas+1;

    return *cantVecesRepetidas;

}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

void mostrar_resultados(char * ppIni, char* ppFin, int huborepe, int cantPal, int maxLongPal)
{

    printf("Primera palabra: ");
    while(ppIni<ppFin)
    {
        printf("%c", *ppIni);
        ppIni++;
    }

    printf("\nCantidad de repeticiones de la primera palabra: %d\n", huborepe);
    printf("Cantidad de palabras: %d\n", cantPal);
    printf("Longitud de la palabra mas larga: %d\n", maxLongPal);
}
