/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

void buscarMismaCtaCte(tLista * p, int comparar(const void *, const void *), FILE *fpPant,
                       int * contNodos);
tLista * buscarMenor(tLista * p, int comparar(const void *, const void *));
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    //casteo e imprimo cada registro
    const tMovi * movi = (const tMovi*)d;

    fprintf(fp, "%-15s %9.2lf\n", movi->ctaCte, movi->saldo);
}


int compararMovim_MIO(const void *d1, const void *d2)
{
    const tMovi * a1 = (const tMovi *)d1;
    const tMovi * a2 = (const tMovi *)d2;

    return strcmpi(a1->ctaCte,a2->ctaCte);  //compara cadenas de char
}


int esCtaCte002_MIO(const void *d)
{
    const tMovi * mov = (const tMovi *)d;

    //considero que la longitud siempre será como la que muestra el ejercicio
    //si fueran distintas longitudes, tendría que optar por otro algoritmo más complejo

    if(mov->ctaCte[14]=='2' && mov->ctaCte[13]=='0' && mov->ctaCte[12]=='0')
        return 1;   //VERDADERO, ES DECIR ES CTACTE

    return 0;       //FALSO
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    if(!*dest || !ori)
        return 0;

    tMovi * acum = (tMovi *)*dest;
    const tMovi * movi = (const tMovi *)ori;

    //va a acumular en el primer registro ctaCte
    //(siempre tratándose de registros que son iguales,
    //es decir movimientos de la misma ctaCte)
    acum->saldo += movi->saldo;

    return 1;
}

//muestra el total acumulado de una ctaCte en particular
void mostrarTotal_MIO(const void *d, FILE *fp)
{
    const tMovi * acum = (const tMovi*)d;

    fprintf(fp," Total cliente: %9.2lf\n\n", acum->saldo);
}


/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    int contNodos = 0;

    fprintf(fp,"Nro Cuenta Banc   Importe\n");

    while(*p)   //recorro toda la lista, cuento nodos y muestro cada registro
    {
        mostrarMovim_MIO((*p)->info, fp);   //notar cómo paso a (*p)->info
                                            //pues solo le paso un registro
        p = &(*p)->sig;
        contNodos++;
    }

    return contNodos;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *), FILE * fp)
{
    tLista * men = p;

    while(*p)
    {
        men = buscarMenor(p, compararMovim_MIO);

        if(men!=p)  //hace el intercambio solo cuando encuentra un menor
                    //en caso de no encontrar uno menor, avanza al siguiente nodo
        {
            tNodo * aux = *men;
            *men = (*men)->sig;

            aux->sig= *p;
            *p = aux;
        }

        p=&(*p)->sig;
    }
}

tLista * buscarMenor(tLista * p, int comparar(const void *, const void *))
{
    tLista * men= p;
    p= &(*p)->sig;

    while(*p)
    {
        if(comparar((*p)->info, (*men)->info)<0)
        {
            men = p;
        }
        p= &(*p)->sig;
    }
    return men;
}


int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{
    if(!*p)
        return 0;

    int contNodos = 0;

    fprintf(fpPant, "Nro Cuenta Banc   Importe\n");

    int encontroCtaCte=0;   //el uso de esta bandera es porque cuando encuentra una ctaCte,
                            //y si el siguiente registro también es ctaCte, se lo saltea.
                            //Entonces lo soluciono poniendo en 1 cuando encuentre ctaCte
                            //(en el if) y luego al salir evalúo si está en 1 o 0.
    while(*p)
    {
        encontroCtaCte=0;

        if(comparar2((*p)->info)==1)    //si entra es porque encontró una nueva ctaCte
        {
            encontroCtaCte=1;
            contNodos++;

            mostrarMovim_MIO((*p)->info, fpPant);

            buscarMismaCtaCte(p, comparar, fpPant, &contNodos);

            mostrarTotal_MIO((*p)->info, fpPant);

            //una vez que terminé de mostrar todas los registros de una misma ctaCte
            //encontrada, y también haber mostrado su total,
            //procedo a eliminar al primero de ellos encontrado
            //(al resto los fui borrando en la función buscarMismaCtaCte)

            tNodo * elim = *p;
            *p = (*p)->sig;     //lo desengancho

            free(elim->info);
            free(elim);
        }


        if(*p && encontroCtaCte==0)
            p = &(*p)->sig;
    }
    return contNodos;
}


void buscarMismaCtaCte(tLista * p, int comparar(const void *, const void *), FILE *fp,
                       int * contNodos)
{
    tNodo * aux = *p;       //acá apunto al primer registro de la ctaCte hallada
    p = &(*p)->sig;         //avanzo para empezar a buscar registros iguales a ella

    int coincidencia=0;     //bandera con el mismo uso que en la función anterior

    while(*p)
    {
        coincidencia = 0;
        if(compararMovim_MIO((*p)->info, aux->info)==0) //si entra, halló otra igual
        {
            (*contNodos)++;
            coincidencia=1;

            mostrarMovim_MIO((*p)->info, fp);

            acumularMoviSaldo_MIO(&(aux)->info, &(aux)->tamInfo, (*p)->info, sizeof(tMovi));

            tNodo * elim = *p;  //apunto al registro que voy a borrar
            *p = (*p)->sig;     //desengancho

            free((elim)->info); //borro
            free(elim);
        }

        if(*p && coincidencia==0)  //PARA QUE NO ME TIRE UN SEGMENTATION FAULT
            p = &(*p)->sig;
    }
}


int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    int contNodos=0;

    while(*p)
    {
        contNodos++;

        mostrarMovim_MIO((*p)->info, fp);

        tNodo * elim = *p;
        *p= elim->sig;

        free(elim->info);
        free(elim);
    }
    return contNodos;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

