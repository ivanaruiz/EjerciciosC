/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
    //ESTE EXAMEN NO LO TUVE QUE HACER PERO EST� CORRECTO
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
#include <string.h>
#include <stdlib.h>
#include <string.h>
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* AC� DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEM�S DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/
//PROTOTIPOS DE FUNCIONES EXTRA QUE US�
tNodo * irAlFinal(tNodo * act);
tNodo * reacomodarNodos(tNodo * act, tNodo * men);
tNodo * buscarMenor(tNodo * act, int * contOcurrenciasXAlumno, int *contNodos);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la informaci�n                                                *//**/

//muestra un registro en particular
void mostrarFinal_MIO(const void *d, FILE *fp)
{
    const tFinal * alu = (const tFinal *)d;

    fprintf(fp, "%-10s %-30s %d %2d\n", alu->dni, alu->apYNom, alu->codMat, alu->calif);
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal * alu1 = (const tFinal *)d1;
    const tFinal * alu2 = (const tFinal *)d2;

    //recordar que comparo dos cadenas de char, por eso uso strcmpi
    return strcmpi(alu1->dni, alu2->dni);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    if(!*dest || !orig)
        return 0;

    tFinal * acumulador = (tFinal *)*dest;
    const tFinal * alu  = (const tFinal *)orig;

    acumulador->calif += alu->calif;

    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    const tFinal * alu = (const tFinal * )d2;

    //estoy redondeando para abajo al hacer %2.0f y castear a float
    fprintf(fp,"   --- Rindio  %d final(es) con un promedio de: %2.0f\n\n",
            cantCalif,
            (float)alu->calif/cantCalif);
}


/**//* para el TDA LISTA                                                  *//**/

//MUESTRA DEL �LTIMO NODO AL PRIMERO DE LA LISTA
//ES DECIR LO MUESTRO "AL REV�S"
int  mostrarDeDerAIzq_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    if(!*p)
        return 0;

    //RECORDAR QUE ME MANEJO MEJOR CON UN PUNTERO A NODO
    //Y NO CON EL PUNTERO A LISTA P
    //EN LAS LISTAS DOBLES ES MEJOR MANEJARSE AS�, DE MANERA TAL DE NO MOVER P
    //A UNA POSICI�N INV�LIDA
    tNodo * act = *p;

    int contNodos = 0;

    fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");

    while(act->sig)         //VOY AL FINAL DE LA LISTA
        act = act->sig;

    while(act)
        {
            contNodos++;
            mostrarFinal_MIO(act->info, fp);
            act = act->ant;
        }

    return contNodos;
}


//CON MENOR NOS REFERIMOS AL QUE TIENE MENOR CANTIDAD DE DUPLICADOS
//ESTA FUNCI�N NO ES EXACTAMENTE IGUAL QUE SI BUSCARA UN MAYOR. LA DIFERENCIA RADICA
//ES QUE , CON CADA ELEMENTO, TENGO QUE RECORRER TODA LA LISTA DE INICIO A FIN, Y NO
//SOLO DESDE ESE ELEMENTO EN CUESTI�N, COMO PASA AL BUSCAR EL MAYOR.
//ES DECIR, ARRANCO CON EL PRIMER ELEMENTO, Y LO BUSCO EN TODA LA LISTA.
//POR DEFECTO ESTE SER� EL MENOR. LUEGO DEBO AVANZAR A ANALIZAR EL SIGUIENTE ELEMENTO,
//PERO PARA BUSCAR SUS DUPLICADOS, VUELVO A BUSCAR DESDE EL INICIO DE LA LISTA.
//Y AS� SUCESIVAMENTE. ESTO SE ENTIENDE MEJOR SI HACE UN BREVE EJEMPLO GR�FICO O EN EXCEL.
tNodo * buscarMenor(tNodo * act, int * contOcurrenciasXAlumno, int *contNodos)
{
    tNodo * inicio = act;
    tNodo * aux = act;
    tNodo * men = act;

    //avanzo un lugar, para no compararse un elemento consigo mismo
    act = act->ant;

    //lo seteo en 1 porque me empieza a contar a partir de los duplicados, pero no me
    //contar�a la primera ocurrencia de un alumno
    int contNodosXAlumno = 1;

    //es 1000 es un n�mero alto por default para encontras obvios n�meros menores a �l
    int min = 1000;

    *contNodos = 0; //este s� lo quiero en 0 porque me cuenta desde el primero

    while(aux)
    {
        contNodosXAlumno = 1;

        (*contNodos)++;


        while(act)
        {
            if(compararFinal_MIO(aux->info, act->info)==0 && act!=aux)
            {
                contNodosXAlumno++;
            }
            act = act->ant;
        }

        //si entra es porque encontr� un menor
        if(contNodosXAlumno<min)
        {
            *contOcurrenciasXAlumno = min = contNodosXAlumno;
            men = aux;
        }

        aux = aux->ant;

        //tengo que volver al inicio de todo, y volver a recorrer para encontrar otro menor
        if(aux)
            act = inicio;

    }
    return men;
}



tNodo * reacomodarNodos(tNodo * act, tNodo * men)
{
    //ESTE AUX ME SERVIR� PARA REINSERTAR LOS NODOS DUPLICADOS JUNTO A AUX
    tNodo * aux = act;

    //ENTRA AC� CUANDO EL MENOR ES IGUAL QUE AUX (QUE ES DONDE DEBO REINSERTAR A MENOR)
    //POR TANTO ES EN VANO HACER ESTO (ORDENARLO)
    //AS� QUE AVANZO CON AUX Y CON ACT
    if(compararFinal_MIO(aux->info, men->info)==0)
    {
        aux= aux->ant;
        act= aux->ant;
    }
    else
        act= act->ant;


    int encontro = 0;


    while(act)
    {
        if(compararFinal_MIO(act->info, men->info)==0 && aux!=men )
        {
            encontro = 1;

            tNodo * nue = act;

            if(act->ant)   //DESENGANCHO EL REPETIDO CUANDO EST� RODEADO DE OTROS NODOS
            {
            act->sig->ant = act->ant;
            act->ant->sig = act->sig;
            }
            else
                act->sig->ant = NULL;   //LO DESENGANCHO SI ES QUE ERA EL PRIMERO DE LA LISTA


            //LUEGO LO INSERTO DONDE CORRESPONDE, QUE ES JUNTO A AUX
            //PARA ESO ME AYUDO CON OTRO PUNTERO A NODO, AUXANT
            //ES DECIR METO AL NODO NUE ENTRE AMBOS
            tNodo * auxant = aux->sig;
            nue->ant = aux;
            nue->sig = auxant;

            auxant->ant = nue;
            aux->sig = nue;

        }
        act = act->ant;     //FINALMENTE SIGO

    }

    //SI NO ENCONTR� NING�N DUPLICADO EN TODA LA LISTA, AVANZO Y DEVUELVO ESA POSICION
    if(encontro==0)
        aux= aux->ant;

    return aux;
}

//TAMBI�N RECORRO DEL FINAL AL INICIO DE LA LISTA, ORDENANDO POR MENOR FRECUENCIA
//DE DUPLICADOS DE ALUMNOS
void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return;

    tNodo * act = *p;
    act = irAlFinal(act);

    tNodo * men;

    int contOcurrenciasXAlumno;
    int contNodos;

    while(act)
    {
        men = buscarMenor(act, &contOcurrenciasXAlumno, &contNodos);

        //si entra ac�, es porque en la lista pudo haber quedado un solo alumno
        //pero con varios registros (o capaz un solo registro, da igual en ese caso)
        //eso quiere decir que no hace falta que ordene esos registros
        //lo importante es destacar que siempre entra ac� con el �ltimo alumno
        if(contOcurrenciasXAlumno==contNodos)
            break;

        //entra ac� cuando el menor encontrado ya est� posicionado donde debo ordenar
        //y adem�s no tiene duplicados (pues contOcurrenciasXAlumno==1)
        //en ese caso no es necesario ordenar, entonces paso a otro nodo (a otro anterior)
        if(act==men && contOcurrenciasXAlumno==1)
            act = act->ant;

        //para todas las dem�s situaciones debo reordenar los nodos en cuesti�n
        else
            act = reacomodarNodos(act, men);
    }
}


//CON ESTA SIMPLE FUNCI�N VOY AL FINAL DE LA LISTA, AL �LTIMO NODO.
tNodo * irAlFinal(tNodo * act)
{
    while(act->sig)
        act = act->sig;
    return act;
}


//VOY A VACIAR LA LISTA DEL FINAL AL PRINCIPIO, ES DECIR DE DERECHA A IZQUIERDA
//ESTA FUNCI�N SIRVE M�S EFICIENTEMENTE PARA LISTAS QUE FUERON PREVIAMENTE ORDENADAS
//EN CASO DE QUE APAREZCA UN ERROR CON ESTA FUNCI�N, BORRAR LO QUE TENGA QUE VER
//LA BANDERA ENCONTR�
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
    int contNodosXAlumno = 0;

    tNodo * act = *p;
    tNodo * elim;

    act= irAlFinal(act);


    while(act)
    {
        int encontro=0; //ESTA BANDERA SIRVE PARA SABER CU�LES NODOS NO TUVIERON REPETIDOS
                        //(ES DECIR ALUMNOS CON UN �NICO REGISTRO), EN ESE CASO COMO NO ENTRA
                        //AL WHILE INTERNO, NO ESTAR�A LIBERANDO EL NODO EN CUESTI�N (FREE),
                        //Y SIMPLEMENTE AVANZAR�A A OTRO NODO.
                        //POR TANTO SI NO ENTR�, NO HUBO REPETIDOS, Y EL ALUMNO ES �NICO,
                        //ENTONCES GRACIAS A ESA BANDERA DEJADA EN 0 , FUERA DEL WHILE,
                        //LIBERO EL CONTENIDO DE ESE NODO

        contNodos++;
        contNodosXAlumno = 0;

        fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
        mostrarFinal_MIO(act->info, fp);

        //COMPARO DE A DOS ELEMENTOS CONSECUTIVOS
        //POR ESO ES QUE SIRVE MEJOR PARA LISTAS ORDENADAS
        while(act->ant && compararFinal_MIO(act->info, act->ant->info)==0)
        {
            encontro=1;
            contNodosXAlumno++;
            mostrarFinal_MIO(act->ant->info, fp);

            //NOTAR QUE ACUMULO SIEMPRE EN EL SEGUNDO NODO, COMO UNA ACUMULACI�N SUCESIVA DIGAMOS
            acumularCalif_MIO(&(act)->ant->info, &(act)->ant->tamInfo, act->info, sizeof(tFinal));

            elim = act;

            if(act)
                act= act->ant;

            free(elim->info);
            free(elim);
        }

        contNodos+=contNodosXAlumno;
        mostrarProm_MIO(act->info, contNodosXAlumno +1, fp);

        //TERMIN� DE ANALIZAR UN NODO, SIGO CON OTRO (UNO ANTERIOR)
        if(act)
            act= act->ant;

        //SI ENTRA AC� ES PORQUE ERA UN ALUMNO �NICO, AS� QUE LIBERO EL CONTENIDO Y AVANZO
        if(encontro==0)
        {
            elim= act->sig;
            free(elim->info);
            free(elim);
        }
    }

    *p = NULL;  //COMO VACI� LA LISTA, RECORDAR DEJAR P APUNTANDO A NULL AL FINAL

    return contNodos;
}




/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

