/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
        //ESTE EXAMEN NO LO TUVE QUE ENTREGAR
        //PERO LOS RESULTADOS ME DAN, ASÍ QUE ESTÁ CORRECTO
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#include "funciones.h"
#include <stdlib.h>
int buscarRepetido(tLista * p, FILE *fp, int * contNodos,
                    int comparar(const void *, const void *),
                                  void mostrar(const void *, FILE *));
int verSiEsUnico(tLista * p, tLista * inicio, int comparar(const void *, const void *));
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    const tFinal * alu = (const tFinal *)d;     //casteo y muestro cada registro pasado
                                                //por parámetro
    fprintf(fp, "%ld %-35s %d  %d\n", alu->DNI, alu->apYNom, alu->codMat, alu->calif);
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal * alu1 = (const tFinal *)d1;
    const tFinal * alu2 = (const tFinal *)d2;

    return alu1->DNI - alu2->DNI;   //compara enteros
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    int contNodos = 0;

    fprintf(fp, "D. N. I. Apellido(s), Nombre(s)              Mat.Cali\n");

        while(*p)
        {
            contNodos++;

            mostrarFinal_MIO((*p)->info, fp);

            p = &(*p)->sig;
        }

    return contNodos;
}


int eliminarYMostrarUnicos_MIO(tLista *p, FILE *fpPant,
                               int comparar(const void *, const void *),
                               void mostrar(const void *, FILE *))
{
    if(!*p)
        return 0;

    int contNodos = 0;

    fprintf(fpPant, "D. N. I. Apellido(s), Nombre(s)              Mat.Cali\n");

    int encontroUnUnico = 0;    //bandera para que no se saltee registros que necesito

    tLista * inicio = p;    //esta lista la pasaré por parámetro a la función verSiEsUnico
                            //nos servirá para recorrer de inicio a fin la lista
    while(*p)
    {
        encontroUnUnico=0;

        if(verSiEsUnico(p, inicio, comparar))       //si entra (==1) es porque es único
        {
            contNodos++;
            encontroUnUnico=1;

            mostrarFinal_MIO((*p)->info, fpPant);   //lo muestro y borro el nodo posteriormente

            tNodo * elim = *p;
            *p = (*p)->sig;                         //desengancho de la lista

            free(elim->info);                       //borro
            free(elim);
        }

        if(*p && !encontroUnUnico)
            p = &(*p)->sig;
    }

    return contNodos;
}



//inicio será siempre el inicio de la lista
//no cambiará
//se recorrerá de principio a fin buscando si hay o no dnis repetidos,
//en cambio p apunta al nodo en cuestión al cual buscamos sus repetidos


int verSiEsUnico(tLista * p, tLista * inicio, int comparar(const void *, const void *))
{
    while(*inicio)
    {
        if(inicio==p)   //en caso de que sean el mismo nodo, debe saltearse éste porque
            inicio = &(*inicio)->sig;                        //es obvio que son iguales

        //si entra al siguiente if, es porque encontró otro registro del mismo alumno
        //por tanto ya no es único, entonces retorno un 0 (de falso) y corto el ciclo
        if(*inicio && compararFinal_MIO((*inicio)->info, (*p)->info)==0)
            return 0;

        //luego procedo a seguir avanzando en la lista
        if(*inicio)
            inicio = &(*inicio)->sig;
    }
    //si llegué acá es porque no hubo repetidos, entonces retorno 1 (VERDADERO)
    return 1;
}



int eliminarYMostrarRepetidos_MIO(tLista *p, FILE *fpPant,
                                  int comparar(const void *, const void *),
                                  void mostrar(const void *, FILE *))
{
    if(!*p)
        return 0;

    int contNodos = 0;

    int encontroRepetidos = 0;

    fprintf(fpPant,"D. N. I. Apellido(s), Nombre(s)              Mat.Cali\n");

    while(*p)
    {
        encontroRepetidos=0;

        encontroRepetidos = buscarRepetido(p, fpPant, &contNodos, compararFinal_MIO, mostrarFinal_MIO);

        if(encontroRepetidos)   //si entra es porque encontró duplicados, así que borro
        {                       //ese nodo (el primero de los duplicados)
            tNodo * elim = *p;
            *p = (*p)->sig;

            free(elim->info);
            free(elim);
        }

        if(*p && !encontroRepetidos)
            p = &(*p)->sig;
    }

    return contNodos;
}



int buscarRepetido(tLista * p, FILE *fp, int * contNodos,
                    int comparar(const void *, const void *),
                                  void mostrar(const void *, FILE *))
{
    tNodo * aux = *p;   //apuntará al nodo al que le buscaré sus duplicados
    p = &(*p)->sig;

    int encontroRepetidos = 0;  //este contador me sirve para:
                                //cuando encuentre el primer duplicado, éste se pone en 1.
                                //es el único caso donde debo contar un contNodos de más,
                                //puesto que el nodo inicial (al que apunta aux) no lo conté
                                //antes, ya que no sabía si iba a ver duplicados.
                                //y además, porque cuando está en 1, debe mostrar en el txt
                                //ese registro al apunta aux

    int encontro=0; //esta bandera es la que uso usualmente para que no se saltee registros

    while(*p)
    {
        encontro=0;
        if(compararFinal_MIO((*p)->info, aux->info)==0) //mismo alumno
        {
            encontro=1;
            encontroRepetidos++;

            (*contNodos)++;

            if(encontroRepetidos==1)    //por acá pasará solo una vez, solo cuando encuentre
            {                           //al primer duplicado (en caso de que haya)
                (*contNodos)++;         //solo en este caso, cuento el nodo inicial
                mostrarFinal_MIO(aux->info, fp);    //y lo muestro (al que apunta aux)
            }


            mostrarFinal_MIO((*p)->info, fp);   //con éste sí muestro los duplicados

            tNodo * elim = *p;                  //y los borro
            *p= (*p)->sig;

            free(elim->info);
            free(elim);
        }

        if(*p && !encontro)
            p = &(*p)->sig;
    }

    if(encontroRepetidos>0)
        return 1;

    else return 0;  //no encontró repetidos
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

