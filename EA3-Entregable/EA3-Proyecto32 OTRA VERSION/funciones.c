/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
    //ESTE EXAMEN EST� CORRECTO. SI BIEN NO ES LA VERSI�N QUE ENTREGU�, ANDA PERFECTO.
    //ESTE EXAMEN EST� CORRECTO. SI BIEN NO ES LA VERSI�N QUE ENTREGU�, ANDA PERFECTO.
    //ESTE EXAMEN EST� CORRECTO. SI BIEN NO ES LA VERSI�N QUE ENTREGU�, ANDA PERFECTO.
    //ESTE EXAMEN EST� CORRECTO. SI BIEN NO ES LA VERSI�N QUE ENTREGU�, ANDA PERFECTO.
    //ESTE EXAMEN EST� CORRECTO. SI BIEN NO ES LA VERSI�N QUE ENTREGU�, ANDA PERFECTO.

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
int  buscar_repetidos(tNodo * act, FILE * fp);
tNodo * buscarMayor(tNodo * act, int * );
tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * );
tNodo * irAlInicio(tNodo * act);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* AC� DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEM�S DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la informaci�n                                                *//**/

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
    //no usar� p, usar� un puntero a nodo llamado actual
    tNodo * act = *p;
    tNodo * mayor;

    act = irAlInicio(act);

    int max=0;  //cuando vuelva de la funci�n buscarMayor, me devuelve el nodo
                //con mayor cantidad de duplicados
                //en esta variable max, me quedar� albergada esa cantidad

    int primeraVuelta=0;    //esta bandera la uso solo para reacomodarNodos el primer nodo
                            //en caso de que �ste no se encuentre al principio de la lista
                            //(no es el ejemplo en este ejercicio, pero puede pasar)

    while(act)
    {
        primeraVuelta++;
        mayor = buscarMayor(act, &max);
        if(max==1)  //esto significa que ya no hay nodos con repeticiones
            return; //entonces no hace falta seguir reordenando
        if(!mayor)
            return;

        //notar que no avanzo con act, porque la funci�n reacomodarNodosNodos, me devolver�
        //la nueva posici�n de act, que ser� d�nde qued� el �ltimo acomodado
        act = reacomodarNodos(act, mayor, &primeraVuelta);
    }
}


tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * primeravez)
{
    tNodo * aux = act;
    tNodo * nue;

    //Solo entra a este if cuando el primer nodo (de toda la lista) que debemos reacomodar,
    //no se encuentra en la primera posici�n. Entra ac� SOLO UNA VEZ(o no) durante
    //toda la funci�n ordenarLista.
    //Es decir mete al nodo en cuesti�n al inicio de la lista
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
                act->ant->sig=NULL; //pasa por ac� cuando el nodo a desenganchar estaba
                                    //�ltimo en la lista. entonces hay que poner null

            //luego engancho, primero nue a los nodos, y luego de los nodos a nue
            //es decir recordar siempre hacer ese "doble" enganche
            nue->sig= aux->sig;
            nue->ant= aux;
            aux->sig->ant= nue;
            aux->sig=nue;

            //finalmente avanzo
            aux= aux->sig;
        }

        *primeravez=2;  //�ste ya no lo uso m�s

        act= act->sig;
    }

    return aux;
}

tNodo * buscarMayor(tNodo * act, int * max)
{
    //este inicio lo necesito porque tendr� dos while, por tanto se resetea constantemente act
    tNodo * inicio = act;
    tNodo * mayor = act;

    act= act->sig;

    //para obtener el m�ximo
    int cont =1;    //lo puse en 1 simplemente porque el primer nodo a evaluar no lo cuenta
    *max=1;

    //estos dos nodos los uso solo para saber cuando en la lista me quedaros varios
    //nodos pero son todos del mismo alumno.
    //esto sucede cuando el contDeNodos y contRepXNodo son iguales
    //pero ojo, tambi�n se puede dar que �sto pase para otras situaciones cuando
    //en los ciclos while se est� examinando el �ltimo nodo, entonces siempre da 1=1
    //eso lo valido igualmente m�s adelante
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

        //aca obtengo el nodo mayor, y tambi�n su cantidad de apariciones
        if(cont>*max)
        {
            *max= cont;
            mayor= inicio;
        }

        //solo entra ac� en el caso de, como dijimos, quedaros varios nodos,
        //pero son todos del mismo alumno, entonces no deseamos reordenar �sto
        //porque ya est�n ordenados
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
    //trabajar� directamente con aux

    //para esta funci�n voy a tener en cuenta que la lista est� ordenada
    //(probar los resultados que da la versi�n del profesor, probarlo tanto
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
                                //(porque est�n apuntando al mismo nodo)
            free(elim->info);
            free(elim);
        }

        //si salgo del while, termin� con un alumno, muestro los resultados
        mostrarProm_MIO(act->info, contFinalesXAlum +1, fp);
        contNodos+= contFinalesXAlum;

        act = act->sig;
    }

    *p=NULL;    //NO OLVIDAR ESTE PASO. AL TERMINAR LA FUNCI�N DEBO DEJAR A P
                //APUNTANDO A ALG�N LADO.
                //EN ESTE CASO HAREMOS QUE APUNTE A NULL PUES VACIAMOS LA LISTA

    return contNodos;
}

**/



//Otra versi�n
//Si bien esta funci�n es m�s larga, es mejor que la anterior
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

    tNodo * act = *p;       //trabajar� con este puntero a nodo act

    while(act->ant)
        act = act->ant;


    while(act)
    {
        contNodos++;

        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
        mostrarFinal_MIO(act->info, fp);

        contNodos+= buscar_repetidos(act, fp);

        //luego de buscar los repetidos, avanzo al siguiente nodo vigente
        //y borro al que le busqu� sus duplicados en la funci�n de arriba
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
    tNodo * aux = act;  //ac� me quedar� el puntero al nodo con el que buscar� repes
    act= act->sig;

    tNodo * elim;
    int cont = 0;
    int encontro=0;
    int ultimo=0;       //esta bandera es para cuando un repetido est� �ltimo en la lista
                        //en ese caso debo hacer que quede en null

    while(act)
    {
        encontro=0;
        ultimo=0;
        if(compararFinal_MIO(act->info, aux->info)==0)  //encontr� duplicado de aux
        {
            encontro=1;
            mostrarFinal_MIO(act->info, fp);
            acumularCalif_MIO(&(aux)->info, &(aux)->tamInfo, act->info, sizeof(tFinal));
            cont++;

            elim = act;

            if(act->sig)    //si el nodo est� en el medio, hago el desenganche
            {
            act->ant->sig = act->sig;
            act->sig->ant = act->ant;

            }
            if(!act->sig)   //si el nodo qued� estaba a lo �ltimo de la lista, seteo ultimo
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

