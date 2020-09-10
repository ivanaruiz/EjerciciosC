/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
    //ESTE EXAMEN ESTÁ CORRECTO. SI BIEN NO ES LA VERSIÓN QUE ENTREGUÉ, ANDA PERFECTO.
    //ESTE EXAMEN ESTÁ CORRECTO. SI BIEN NO ES LA VERSIÓN QUE ENTREGUÉ, ANDA PERFECTO.
    //ESTE EXAMEN ESTÁ CORRECTO. SI BIEN NO ES LA VERSIÓN QUE ENTREGUÉ, ANDA PERFECTO.
    //ESTE EXAMEN ESTÁ CORRECTO. SI BIEN NO ES LA VERSIÓN QUE ENTREGUÉ, ANDA PERFECTO.
    //ESTE EXAMEN ESTÁ CORRECTO. SI BIEN NO ES LA VERSIÓN QUE ENTREGUÉ, ANDA PERFECTO.

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
int  buscar_repetidos(tNodo * act, FILE * fp);
tNodo * buscarMayor(tNodo * act, int * );
tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * );
tNodo * irAlInicio(tNodo * act);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    const tFinal * alu = (const tFinal *)d;

    fprintf(fp, "%-10s %-30s %d %2d\n", alu->dni, alu->apYNom, alu->codMat, alu->calif);
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal * alu1 = (const tFinal *) d1;
    const tFinal * alu2 = (const tFinal *) d2;

    //recordar que uso strcmpi porque estoy comparando cadenas de char
    return strcmpi(alu1->dni,alu2->dni);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    if(!*dest || !orig)
        return 0;

    tFinal * acum = (tFinal *)*dest;
    const tFinal * alum = (const tFinal *) orig;

    acum->calif+= alum->calif;
    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    const tFinal * alu = (const tFinal*) d2;

    fprintf(fp,"   --- Rindio  %d final(es) con un promedio de: %2.0f\n\n",
            cantCalif,
            (float)alu->calif/cantCalif);
}


/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    int contNodos = 0;

    while((*p)->ant)        //voy al principio de la lista
        p = &(*p)->ant;


    fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");

    while(*p)
    {
        contNodos++;

        mostrarFinal_MIO((*p)->info, fp);

        p = &(*p)->sig;
    }

    return contNodos;
}



void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    //no usaré p, usaré un puntero a nodo llamado actual
    tNodo * act = *p;
    tNodo * mayor;

    act = irAlInicio(act);

    int max=0;  //cuando vuelva de la función buscarMayor, me devuelve el nodo
                //con mayor cantidad de duplicados
                //en esta variable max, me quedará albergada esa cantidad

    int primeraVuelta=0;    //esta bandera la uso solo para reacomodarNodos el primer nodo
                            //en caso de que éste no se encuentre al principio de la lista
                            //(no es el ejemplo en este ejercicio, pero puede pasar)

    while(act)
    {
        primeraVuelta++;
        mayor = buscarMayor(act, &max);
        if(max==1)  //esto significa que ya no hay nodos con repeticiones
            return; //entonces no hace falta seguir reordenando
        if(!mayor)
            return;

        //notar que no avanzo con act, porque la función reacomodarNodosNodos, me devolverá
        //la nueva posición de act, que será dónde quedó el último acomodado
        act = reacomodarNodos(act, mayor, &primeraVuelta);
    }
}


tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * primeravez)
{
    tNodo * aux = act;
    tNodo * nue;

    //Solo entra a este if cuando el primer nodo (de toda la lista) que debemos reacomodar,
    //no se encuentra en la primera posición. Entra acá SOLO UNA VEZ(o no) durante
    //toda la función ordenarLista.
    //Es decir mete al nodo en cuestión al inicio de la lista
    if(mayor!= aux && *primeravez==1)
    {
        //primero siepre hacer el desenganche de donde se encuentre
        mayor->ant->sig= mayor->sig;
        mayor->sig->ant= mayor->ant;

        //luego el enganche al inicio
        mayor->sig= aux;
        mayor->ant=NULL;
        aux->ant=mayor;

        aux=mayor;
        act= mayor->sig;
    }


    while(act)
    {
        if(compararFinal_MIO(act->info, mayor->info)==0 && *primeravez!=1)
        {
            nue = act;

            if(act->sig)    //primero desengancho
            {
            act->ant->sig = act->sig;
            act->sig->ant = act->ant;
            }
            else
                act->ant->sig=NULL; //pasa por acá cuando el nodo a desenganchar estaba
                                    //último en la lista. entonces hay que poner null

            //luego engancho, primero nue a los nodos, y luego de los nodos a nue
            //es decir recordar siempre hacer ese "doble" enganche
            nue->sig= aux->sig;
            nue->ant= aux;
            aux->sig->ant= nue;
            aux->sig=nue;

            //finalmente avanzo
            aux= aux->sig;
        }

        *primeravez=2;  //éste ya no lo uso más

        act= act->sig;
    }

    return aux;
}

tNodo * buscarMayor(tNodo * act, int * max)
{
    //este inicio lo necesito porque tendré dos while, por tanto se resetea constantemente act
    tNodo * inicio = act;
    tNodo * mayor = act;

    act= act->sig;

    //para obtener el máximo
    int cont =1;    //lo puse en 1 simplemente porque el primer nodo a evaluar no lo cuenta
    *max=1;

    //estos dos nodos los uso solo para saber cuando en la lista me quedaros varios
    //nodos pero son todos del mismo alumno.
    //esto sucede cuando el contDeNodos y contRepXNodo son iguales
    //pero ojo, también se puede dar que ésto pase para otras situaciones cuando
    //en los ciclos while se está examinando el último nodo, entonces siempre da 1=1
    //eso lo valido igualmente más adelante
    int contDeNodos=0;
    int contRepXNodo=0;


    while(inicio)
    {
        cont = 1;

        contRepXNodo=0;
        contDeNodos=0;

        while(act)
        {
            contDeNodos++;

            if(compararFinal_MIO(act->info, inicio->info)==0)
            {
                contRepXNodo++;
                cont++;
            }

           act= act->sig;
        }

        //aca obtengo el nodo mayor, y también su cantidad de apariciones
        if(cont>*max)
        {
            *max= cont;
            mayor= inicio;
        }

        //solo entra acá en el caso de, como dijimos, quedaros varios nodos,
        //pero son todos del mismo alumno, entonces no deseamos reordenar ésto
        //porque ya están ordenados
        if(contDeNodos==contRepXNodo && !act && mayor!=act && cont==*max)
        {
            mayor = NULL;   //le ponemos en NULL y en el main hacemos un return
            return mayor;
        }

        inicio = inicio->sig;

        if(inicio)
            act= inicio->sig;
    }

    return mayor;
}


tNodo * irAlInicio(tNodo * act)
{
    while(act->ant)
        act = act->ant;
    return act;
}


 /**
int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    //no voy a trabajar con p
    //trabajaré directamente con aux

    //para esta función voy a tener en cuenta que la lista está ordenada
    //(probar los resultados que da la versión del profesor, probarlo tanto
    //con la lista desordenada y ordenada.

    //por lo tanto lo que haremos es movernos siempre con act para adelante
    //y borrar el nodo anterior a cuando avanzo, es decir, siempre el primero de la lista

    if(!*p)
        return 0;

    int contNodos = 0;
    int contFinalesXAlum = 0;

    tNodo * act = *p;

    while(act->ant) //primero voy al inicio
        act= act->ant;


    while(act)
    {
        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
        contNodos++;
        contFinalesXAlum=0;

        mostrarFinal_MIO(act->info, fp);

        //si entro a este while es porque el alumno se comienza a repetir
        while(act->sig && comparar(act->info, act->sig->info)==0)
        {
            contFinalesXAlum++;
            mostrarFinal_MIO(act->sig->info, fp);
            acumularCalif_MIO(&(act)->sig->info, &(act)->tamInfo, act->info, sizeof(tFinal));

            tNodo * elim = act;
            act= act->sig;      //avanzo con act antes de borrar el nodo elim
                                //(porque están apuntando al mismo nodo)
            free(elim->info);
            free(elim);
        }

        //si salgo del while, terminé con un alumno, muestro los resultados
        mostrarProm_MIO(act->info, contFinalesXAlum +1, fp);
        contNodos+= contFinalesXAlum;

        act = act->sig;
    }

    *p=NULL;    //NO OLVIDAR ESTE PASO. AL TERMINAR LA FUNCIÓN DEBO DEJAR A P
                //APUNTANDO A ALGÚN LADO.
                //EN ESTE CASO HAREMOS QUE APUNTE A NULL PUES VACIAMOS LA LISTA

    return contNodos;
}

**/



//Otra versión
//Si bien esta función es más larga, es mejor que la anterior
//pues tiene en cuenta listas desordenadas
int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    if(!*p)
        return 0;

    int contNodos = 0;

    tNodo * act = *p;       //trabajaré con este puntero a nodo act

    while(act->ant)
        act = act->ant;


    while(act)
    {
        contNodos++;

        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
        mostrarFinal_MIO(act->info, fp);

        contNodos+= buscar_repetidos(act, fp);

        //luego de buscar los repetidos, avanzo al siguiente nodo vigente
        //y borro al que le busqué sus duplicados en la función de arriba
        tNodo *elim =act;
        act= act->sig;

        free(elim->info);
        free(elim);
    }

    *p= NULL;   //RECORDAR DE PONER A P APUNTANDO A NULL AL FINALIZAR

    return contNodos;
}


int buscar_repetidos(tNodo * act, FILE * fp)
{
    tNodo * aux = act;  //acá me quedará el puntero al nodo con el que buscaré repes
    act= act->sig;

    tNodo * elim;
    int cont = 0;
    int encontro=0;
    int ultimo=0;       //esta bandera es para cuando un repetido está último en la lista
                        //en ese caso debo hacer que quede en null

    while(act)
    {
        encontro=0;
        ultimo=0;
        if(compararFinal_MIO(act->info, aux->info)==0)  //encontró duplicado de aux
        {
            encontro=1;
            mostrarFinal_MIO(act->info, fp);
            acumularCalif_MIO(&(aux)->info, &(aux)->tamInfo, act->info, sizeof(tFinal));
            cont++;

            elim = act;

            if(act->sig)    //si el nodo está en el medio, hago el desenganche
            {
            act->ant->sig = act->sig;
            act->sig->ant = act->ant;

            }
            if(!act->sig)   //si el nodo quedó estaba a lo último de la lista, seteo ultimo
            {
                ultimo =1;
            }

        }
        if(ultimo)
        {
            act= act->ant;
            act->sig = NULL;
        }
        else
            act = act->sig;     //avanzo en la lista


        if(encontro==1)         //finalmente si hubo un duplicado, libero el contenido
        {
            free(elim->info);
            free(elim);
        }
    }

    mostrarProm_MIO(aux->info, cont+1, fp);

    return cont;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

