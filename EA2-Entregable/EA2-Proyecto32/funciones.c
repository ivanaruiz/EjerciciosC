/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/
        //ESTE EXAMEN FUE APROBADO//ESTE EXAMEN FUE APROBADO
        //ESTE EXAMEN FUE APROBADO//ESTE EXAMEN FUE APROBADO
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
        //ESTE EXAMEN FUE APROBADO//ESTE EXAMEN FUE APROBADO
        //ESTE EXAMEN FUE APROBADO//ESTE EXAMEN FUE APROBADO
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
        //ESTE EXAMEN FUE APROBADO//ESTE EXAMEN FUE APROBADO
void buscarMismaCtaCte(tLista * p, tNodo * aux, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int * contNodos,
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                    void mostrar(const void *, FILE *));
tNodo ** buscarMenor(tLista * p, tLista * aux, int comparar(const void *, const void *),
                            int * encontroMenor);
void reinsertarNodos(tLista * aux, tLista * men, tLista *pri);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi * movi = (const tMovi*)d;

    fprintf(fp, "%-15s %9.2lf\n", movi->ctaCte, movi->saldo);
}


int compararMovim_MIO(const void *d1, const void *d2)
{
    const tMovi * e1 = (const tMovi*) d1;
    const tMovi * e2 = (const tMovi*) d2;

    return strcmpi(e1->ctaCte , e2->ctaCte);
}


int esCtaCte002_MIO(const void *d)
{
    const tMovi * mov = (const tMovi*)d;

    //considero que la longitud siempre será como la que muestra el ejercicio
    //si fueran distintas longitudes, tendría que optar por otro algoritmo más complejo

    if(mov->ctaCte[12]=='0' && mov->ctaCte[13]=='0' && mov->ctaCte[14]=='2')
        return 1;   //VERDADERO, ES DECIR ES CTACTE

    return 0;       //FALSO
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    if(*dest==NULL || ori == NULL)
        return 0;

    tMovi  * acum = (tMovi*)*dest;
    const tMovi  * movi = (const tMovi*) ori;

    //va a acumular en el primer registro ctaCte
    //(siempre tratándose de registros que son iguales,
    //es decir movimientos de la misma ctaCte)
    acum->saldo += movi->saldo;

    return 1;
}


void mostrarTotal_MIO(const void *d, FILE *fp)
{
    const tMovi * acum = (const tMovi*)d;
    fprintf(fp, " Total cliente: %9.2lf\n\n", acum->saldo);
}


/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    int contNodos = 0;

    fprintf(fp, "Nro Cuenta Banc   Importe\n");

    while(*p)
    {
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
        contNodos++;
    }

    return contNodos;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tNodo  ** men = p;
    tLista * aux = p;
    tLista * pri = p;
    int encontroMenor=0;    //con este entero, identifico si debo avanzar al siguiente nodo,
                            //puesto que ya no se encontraron otros menores a él
    p = &(*p)->sig;

    while(*p)
    {
            encontroMenor=0;
            men = buscarMenor(p, aux, comparar, &encontroMenor);

            if(encontroMenor)
            {
                reinsertarNodos(aux, men, pri);
                aux = &(*aux)->sig;
            }

            else    //si no encontró menor, avanzo al siguiente nodo para evaluar
            {
                aux = &(*aux)->sig;
                p = &(*aux)->sig;
            }
    }
}

void reinsertarNodos(tLista * aux, tLista * men, tLista *pri)
{
    tNodo * menor = *men;

    *men = ((*men)->sig)  ?   (*men)->sig   :    NULL;

    menor->sig = *aux;
    *aux = menor;

    aux=pri;
}


tNodo ** buscarMenor(tLista * p, tLista * aux, int comparar(const void *, const void *),
                            int * encontroMenor)
{
    while(*p)
    {
        if(comparar( (*p)->info,  (*aux)->info )<0 )
        {
            aux = p;
            *encontroMenor=1;
        }
        p = &(*p)->sig;
    }
    return (tNodo**)aux;
}



int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{
    if(*p==NULL)
        return 0;

    fprintf(fpPant, "Nro Cuenta Banc   Importe\n");

    int contNodos = 0;
    int encontroCtaCte = 0; //el uso de esta bandera es porque cuando encuentra una ctaCte,
                            //y si el siguiente registro también es ctaCte, se lo saltea.
                            //Entonces lo soluciono poniendo en 1 cuando encuentre ctaCte
                            //(en el if) y luego al salir evalúo si está en 1 o 0.

    while(*p)
    {
        encontroCtaCte=0;

        if(comparar2((*p)->info))   //si entra es porque encontró una nueva ctaCte
        {
            encontroCtaCte = 1;
            contNodos++;

            tNodo * aux = *p;

            mostrarMovim_MIO((*p)->info, fpPant);

            *p = aux->sig;      //desenganche

            buscarMismaCtaCte(p, aux, fpPant, comparar, &contNodos, acumular, mostrar);

            mostrarTotal_MIO(aux->info, fpPant);

            free(aux->info);
            free(aux);
        }

        if(*p && !encontroCtaCte)
            p = &(*p)->sig;
    }

    return contNodos;
}


void buscarMismaCtaCte(tLista * p, tNodo * aux, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int * contNodos,
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                    void mostrar(const void *, FILE *))
{
    int coincidencia=0; //bandera con el mismo uso que en la función anterior

    while(*p)
    {
        coincidencia=0;
        if( comparar((*p)->info, aux->info)==0)
        {
            (*contNodos)++;     coincidencia=1;

            mostrarMovim_MIO((*p)->info, fpPant);
            acumularMoviSaldo_MIO(&(aux)->info, &(aux)->tamInfo, (*p)->info, sizeof(tMovi));

            free((*p)->info);   //borro el nodo y desengancho
            free(*p);
            *p = (*p)->sig;
        }

        if(!coincidencia)
            p = &(*p)->sig;
    }
}



int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    if(*p==NULL)
        return 0;

    int contNodos = 0;

    while(*p)
    {
        contNodos++;

        tNodo * aux = *p;
        *p = aux->sig;

        mostrar(aux->info, fp);
        free(aux->info);
        free(aux);
    }

    return contNodos;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

