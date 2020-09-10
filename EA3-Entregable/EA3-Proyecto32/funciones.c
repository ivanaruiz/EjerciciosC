/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/
        //ESTE EXAMEN FUE APROBADO////ESTE EXAMEN FUE APROBADO//
        //ESTE EXAMEN FUE APROBADO////ESTE EXAMEN FUE APROBADO//
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
        //ESTE EXAMEN FUE APROBADO////ESTE EXAMEN FUE APROBADO//
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
        //ESTE EXAMEN FUE APROBADO////ESTE EXAMEN FUE APROBADO//
void reacomodarElPrimero(tNodo * inicio, tNodo * mayor);
tNodo * reacomodarLosSiguientes(tNodo * auxAnt, tNodo * auxSig, tNodo * mayor,
             int (*comparar)(const void *, const void *));
tNodo * buscarMayor(tNodo * inicio, int (*comparar)(const void *, const void *), int * max);
tNodo * irInicio(tLista *p);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(!d)
        return;

    const tFinal * alum = (const tFinal*) d;
    fprintf(fp, "%s %-30s %d %2d\n", alum->dni, alum->apYNom, alum->codMat, alum->calif);
}

int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal * alum1 = (const tFinal *) d1;
    const tFinal * alum2 = (const tFinal *) d2;

    //recordar que uso strcmpi porque estoy comparando cadenas de char
    return strcmpi(alum1->dni, alum2->dni);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    if(*dest == NULL || orig== NULL)
        return 0;

    tFinal * acum = (tFinal *) *dest;
    const tFinal * alum = (const tFinal *) orig;

    acum->calif += alum->calif;
    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    const tFinal * prom = (const tFinal *) d2;

    fprintf(fp,"   --- Rindio  %d final(es) con un promedio de: %2.0f\n\n",
            cantCalif, (float)prom->calif/cantCalif);
}


/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;           //lista vacía

    int contNodos = 0;


    while((*p)->ant)        //voy al principio de la lista
        p = &(*p)->ant;

    fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");

    while(*p)               //recorro la lista, muestro y cuento
    {
        contNodos++;
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
    }
    return contNodos;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return;

    tNodo   * mayor;
    tNodo   * inicio = irInicio(p);
    tNodo   * auxSig,
            * auxAnt;

    int primeraVez=0;   //esta variable la uso solo para el primer mayor encontrado

    while(inicio)
    {
        int cont=0;     //es la cantidad de repeticiones del nodo mayor que encuentre
        primeraVez++;

        mayor = buscarMayor(inicio, comparar, &cont);

        if(cont<=1)     //cuando ya no hay nodos que se repitan, simplemente salgo
            return;     //es decir puede haber varios nodos, pero todos distintos alumnos

        if(primeraVez==1)       //entro cuando se trata del primer nodo que ordenaré
        {
            if(mayor!=inicio)   //cuando mi primer mayor es el primer nodo de la lista,
            {                   //no hace falta reordenarlo, como en nuestro ejemplo
                reacomodarElPrimero(inicio, mayor);
            }
            auxAnt = mayor;
            auxSig = auxAnt->sig;
        }
        else    //para todos los siguientes nodos que voy a reacomodar
            {auxSig= inicio;
            auxAnt = auxSig->ant;}

        inicio = reacomodarLosSiguientes(auxAnt, auxSig, mayor, comparar);
        //la función me devolveó el lugar donde los notos anteriores a él ya quedaron
        //ordenados, ahora solo queda seguir recorriendo la lista a partir de este nodo
    }
}

//con esta función, acomodo el primer nodo al principio de la lista
void reacomodarElPrimero(tNodo * inicio, tNodo * mayor)
{
    //siempre primero desengancho al nodo de dónde lo tengo que sacar
    mayor->sig->ant = mayor->ant;
    mayor->ant->sig = mayor->sig;

    //y luego lo engancho al inicio
    mayor->sig = inicio;
    mayor->ant = NULL;

    inicio->ant = mayor;
}

tNodo * reacomodarLosSiguientes(tNodo * auxAnt, tNodo * auxSig, tNodo * mayor,
             int (*comparar)(const void *, const void *))
{
    tNodo * aux = auxSig;

    while(aux)
    {   //cuando encuentre los nodos correspondientes, haré los desenganches y enganches
        if((comparar(mayor->info , aux->info )==0 && auxSig!=aux))
        {
            if(aux->sig)
                {aux->ant->sig = aux->sig;  //desengancho de donde estaba
                aux->sig->ant = aux->ant;}
            else
                aux->ant->sig = NULL;   //para cuando el nodo estaba último en la lista


            //siempre es un doble enganche, es decir como una doble flecha que sale de
            //cada lado del nodo
            aux->sig = auxSig;      //lo engancho donde corresponde
            aux->ant = auxAnt;

            auxSig->ant = aux;
            auxAnt->sig = aux;

            auxAnt= auxAnt->sig;
        }
        else if(comparar(mayor->info , aux->info )==0  && aux->sig)
            {auxSig = auxSig->sig;
            auxAnt = auxAnt->sig;}

        aux = aux->sig; //finalmente avanzo para seguir buscando los otros nodos
    }
    return auxSig;
}

//con mayor nos referimos al que tiene mas ocurrencias
tNodo * buscarMayor(tNodo * inicio, int (*comparar)(const void *, const void *), int * max)
{
    tNodo * maxNodo = inicio;
    tNodo * aux = inicio;

    while((inicio)->sig)
    {
        int cont=0;
        while(aux)
        {
            if(comparar( (inicio)->info, (aux)->info)==0)
                cont++;

            aux= aux->sig;
        }
        if(cont>*max)
            {*max=cont;
            maxNodo = inicio;}  //acá encontramos al de mayor ocurrencia (por ahora)

        inicio= (inicio)->sig;
        aux = inicio;
    }
    return maxNodo;
}

tNodo * irInicio(tLista *p)
{
    while((*p)->ant)
            p = &(*p)->ant;
    tNodo * aux= *p;
    return aux;
}

//esta función sirve solo para listas ordenadas (así es el caso).
//para hacer con listas desordenadas/ordenadas, lo resolví en otro proyecto
int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    if(!*p)
        return 0;

    //como me pide que no varíe a donde apunta p, voy a usar otros punteros a nodos
    tNodo * act = *p;

    int contFinalesXAlumno=0;
    int contNodos = 0;

    if(act)
    {
        while(act->ant)         //voy al inicio de la lista
            act = act->ant;

        while(act)
        {
            contFinalesXAlumno=0;
            contNodos++;
            fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
            mostrarFinal_MIO(act->info, fp);


                //si entro a este while es porque el alumno se comienza a repetir
                while(act->sig && compararFinal_MIO(act->info, act->sig->info)==0)
                {
                tNodo *aux = act->sig;

                mostrarFinal_MIO(act->sig->info, fp);
                acumularCalif_MIO(&(act)->sig->info, &(act)->tamInfo, (act)->info, sizeof(tFinal));

                free(act->info);
                free(act);
                act = aux;
                contNodos++;
                contFinalesXAlumno++;
                }

                mostrarProm_MIO((act)->info, contFinalesXAlumno+1, fp);
                act = (act)->sig;
        }
        *p = NULL;
    }
    return contNodos;
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

