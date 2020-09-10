#include "arbol.h"

void crearArbol(tArbolBinBusq * p)
{
    *p = NULL;
}

//unica funcion no recursiva. funcion iterativa
//acá no uso recursividad porque la dicha recursividad se usa cuando tengo que recorrer el arbol
//aca voy a un lugar en especifico
//INSERTA EN PRE ORDEN
int insertarArbolBinBusq(tArbolBinBusq * p, const void * d, unsigned tam, int (*cmp)(const void *, const void *))
{
    tNodoArbol * nue;

    //recorro hasta que encuentre un lugar vacio para poner el nodo
    while(*p)
    {
        int res_cmp = cmp(d, (*p)->info);

        if(res_cmp < 0)   //si es menor, me voy a la izquierda
            p = &(*p)->izq;
        else if(res_cmp>0)
            p = &(*p)->der;
        else
            return 0;   //DUPLICADO, no lo inserto
    }


    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return 0; //SIN MEMORIA

    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;

    nue->der = nue->izq = NULL; //como es un nuevo nodo el que se inserta, no tendra hijos
    *p = nue;

    return 1;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////


void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenRecArbolBinBusq(p, 0, params, accion);
}

void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                    void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return ;
    recorrerEnOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
}




/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                  void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerPreOrdenRecArbolBinBusq(p, 0, params, accion);
}

void recorrerPreOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n,
                                     void * params,
                                     void (*accion)(void*, unsigned, unsigned, void *))
{
    if(!*p)
        return;
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                  void (*accion)(void*, unsigned, unsigned, void*))
{
    recorrerPosOrdenRecArbolBinBusq(p, 0, params, accion);
}

void recorrerPosOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                     void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return;
    recorrerPosOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    recorrerPosOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*))
{
    recorrerEnOrdenInversoRecArbolBinBusq(p, 0, params, accion);
}


void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,
                                        void (*accion)(void*, unsigned, unsigned, void*))
{
    if(!*p)
        return;
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->der, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int contarNodos(const tArbolBinBusq * p)
{
    unsigned cont=0;

    contarRecNodos(p, 0, &cont);

    return cont;
}

int contarRecNodos(const tArbolBinBusq * p, unsigned n, unsigned * cont)
{

    if(!*p)
        return 0;

    (*cont)++;
    contarRecNodos(&(*p)->der, n+1, cont);
    contarRecNodos(&(*p)->izq, n+1, cont);

    return *cont;
}

//es casi igual per no le mandé el nivel como parámetro a la función recursiva
int contarNodosV2(const tArbolBinBusq * p)
{
    unsigned cont = 0;
    contarNodosV2Rec(p, &cont);
    return cont;
}

int contarNodosV2Rec(const tArbolBinBusq * p, unsigned * cont)
{
    if(!*p)
        return 0;
    (*cont)++;
    contarNodosV2Rec(&(*p)->izq, cont);
    contarNodosV2Rec(&(*p)->der, cont);
    return *cont;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int alturaArbolBin(const tArbolBinBusq * p)
{
    unsigned maxAltura=0;

    alturaArbolBinRec(p, 0, &maxAltura);
    return maxAltura+1; //le sumo 1 porque los niveles arrancan de 0
}

int alturaArbolBinRec(const tArbolBinBusq * p, unsigned n, unsigned * maxAltura)
{
    if(!*p)
        return 0;

    if(n> *maxAltura)
        *maxAltura= n;

    alturaArbolBinRec(&(*p)->izq, n+1, maxAltura);
    alturaArbolBinRec(&(*p)->der, n+1, maxAltura);

    return *maxAltura;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//cuando cada nodo tiene exactamente dos hijos,
//y ambas ramas (izq y der) tienen mismo nivel
//la condición matemática para que esto pase es cn = ((2elevado a la h)-1)
//donde cn= cantidad de nodos , y h= altura
//el segundo ejemplo de árbol es un arbol binario completo
int esArbolBinCompleto(const tArbolBinBusq * p)
{
    if(!*p)
        return 0;

    int nodos = contarNodos(p);
    int altura = alturaArbolBin(p);

    if(nodos== pow(2,altura) -1)
        return 1;
    return 0;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//debo ser un árbol completo hasta un nivel anterior a la altura que tenga el árbol
//es decir, si tiene 4 niveles, debe ser completo por lo menos hasta el nivel 3
//en el nivel 4 no importa lo que pase.
int esArbolBinBalanceado(const tArbolBinBusq * p)
{
    if(!*p)
        return 0;

    unsigned altura = alturaArbolBin(p) - 1;
    unsigned nodos = contarNodosHastaAlturaBalanceada(p, &altura );

    if(nodos== pow(2,altura) -1)    //acá verifico si está balanceado
        return 1;
    return 0;
}


int contarNodosHastaAlturaBalanceada(const tArbolBinBusq * p, unsigned * altura)
{
    unsigned cont=0;

    contarRecNodosHastaAlturaBalanceada(p, 0, altura, &cont);

    return cont;
}

int contarRecNodosHastaAlturaBalanceada(const tArbolBinBusq * p, unsigned n, unsigned * alturaMax, unsigned * contNodos)
{
    if(!*p || n>= *alturaMax)
        return 0;

    (*contNodos)++;
    contarRecNodosHastaAlturaBalanceada(&(*p)->izq, n+1, alturaMax, contNodos);
    contarRecNodosHastaAlturaBalanceada(&(*p)->der, n+1, alturaMax, contNodos);

    return *contNodos;
}

//DEJO OTRA VERSIÓN DE LO MISMO
/*
int esArbolBinBalanceado(const tArbol * p)
{
    if(!*p)
        return 0;

    unsigned altura = alturaArbol(p) -1;
    unsigned nodos  = 0;
    nodos = contarNodosHastaNivel(p, altura-1, 0, &nodos);

    if(nodos== pow(2,altura)-1)
        return 1;
    return 0;
}

int contarNodosHastaNivel(const tArbol * p, unsigned altura, unsigned n, unsigned * nodos)
{
    if(!*p)
        return 0;

    if(n>altura)
        return 0;

    (*nodos)++;
    contarNodosHastaNivel(&(*p)->izq, altura, n+1, nodos);
    contarNodosHastaNivel(&(*p)->der, altura, n+1, nodos);

    return *nodos;
}
*/
/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int buscarElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam,
                       int (*comparar)(const void *, const void *))
{
    if(!*p)
        return 0;

    while(*p)
    {
        int res_cmp = comparar(d, (*p)->info);

        if(res_cmp==0)
            return 1;       //SE ENCONTRÓ EL DATO, ENTONCES SALGO
        else if(res_cmp <0)
            p = &(*p)->izq;
        else if(res_cmp>0)
            p = &(*p)->der;
    }
    return 0;   //SI LLEGÓ ACÁ ES PORQUE RECORRIÓ TODO EL ARBOL Y NO ESTABA
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int buscarMenorElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return 0;

    while((*p)->izq)
        p = &(*p)->izq;

    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}



int buscarMayorElemArbolBin(const tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return 0;

    while((*p)->der)
        p = &(*p)->der;

    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int buscarRaizArbolBin(const tArbolBinBusq * p, void * d, unsigned tam)
{
    if(!*p)
        return 0;

    memcpy(d, (*p)->info, tam);
    return 1;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int sumarElemArbolBin(const tArbolBinBusq * p)
{
    unsigned acum = 0;
    sumarElemArbolBinRec(p, 0, &acum, sizeof(acum));
    return acum;
}

int sumarElemArbolBinRec(const tArbolBinBusq * p, unsigned n, void * acum, unsigned tamAcum)
{
    if(!*p)
        return 0;

    //recordar castear porque en este caso deseo sumar enteros
    int * acumu= (int*) acum;
    int * dato = (int*) (*p)->info;

    *acumu+= *dato;
    sumarElemArbolBinRec(&(*p)->izq, n+1, acum, sizeof(int));
    sumarElemArbolBinRec(&(*p)->der, n+1, acum, sizeof(int));

    return * acumu;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//recorro el árbol y voy borrando desde los elementos inferiore hasta la raiz
//es decir siempre los nodos hijos
void vaciarArbol(tArbolBinBusq * p)
{
    if(!*p)
        return;

    while((*p)->izq || (*p)->der)   //entra siempre que no es nodo hijo
    {
        vaciarArbol(&(*p)->izq);
        vaciarArbol(&(*p)->der);
    }

    tNodoArbol * elim = *p;
    free(elim->info);
    free(elim);

    *p = NULL;
}


/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

void podarArbol(tArbolBinBusq * p)
{
    if(!*p)
        return;


    if(!(*p)->izq && !(*p)->der)
    {
        tNodoArbol * elim;
        elim = (*p)->info;
        free(elim->info);
        free(elim);
        *p = NULL;
        return;
    }

    podarArbol(&(*p)->izq);
    podarArbol(&(*p)->der);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

void mostrarNodosConAmbosHijos(const tArbolBinBusq * p,
                               void (*accion)(void*, unsigned, unsigned, void *))
{
    if(!*p)
        return;

    if((*p)->izq && (*p)->der)
        accion((*p)->info, (*p)->tamInfo, 0,0);

    mostrarNodosConAmbosHijos(&(*p)->izq, accion);
    mostrarNodosConAmbosHijos(&(*p)->der, accion);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////
void mostrarHijos(const tArbolBinBusq * p, void (*accion)(void*, unsigned, unsigned, void *))
{
    if(!*p)
        return;

    if(!(*p)->izq && !(*p)->der)
        accion((*p)->info, (*p)->tamInfo, 0, 0);

    mostrarHijos(&(*p)->izq, accion);
    mostrarHijos(&(*p)->der, accion);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//elimina un nodo hijo que se mandó por parámetro
int eliminarSoloHijo(tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return 0;

    while(*p)
    {
        int res_cmp = comparar(d, (*p)->info);

        if(res_cmp <0)
            p = &(*p)->izq;
        else if(res_cmp >0)
            p = &(*p)->der;

        else if(res_cmp==0)       //encontró al nodo
        {
            if(!(*p)->izq && !(*p)->der)    //verifico que sea hijo nodo hijo realmente
            {
                free((*p)->info);
                free(*p);
                *p = NULL;
                return 1;       //y salgo exitosamente
            }
            else
                return 0; //si llega aca es porque no era nodo hijo
        }
    }
    return 0;   //si llega acá es porque no encontró al nodo
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//ES UNA VERSIÓN DISTINTA A LA DE ELIMINAR RAIZ
//FUNCIONA PERO PUEDE DEJAR EL ARBOL DESBALANCEADO Y ADEMÁS ES UN QUILOMBO
int eliminarCualquierNodoMenosRaiz(tArbolBinBusq * p, void * d, unsigned tam, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return 0;

    while(*p)
    {
        if(comparar(d, (*p)->info) <0)
            p = &(*p)->izq;
        else if(comparar(d, (*p)->info) >0)
            p = &(*p)->der;
        else                                //lo encontró, entonces procede a borrar y enganchar segun cada caso
        {
            if(!(*p)->izq && !(*p)->der)    //entra por aca solo cuando es solo hijo
            {
                *p = NULL;
            }
            else if((*p)->izq && !(*p)->der)    //cuando tiene un hijo solo del lado izq
            {
                *p = (*p)->izq;

            }
            else if((*p)->der && !(*p)->izq)    //cuando tiene un hijo solo del lado der
            {
                *p = (*p)->der;
            }
            else if((*p)->der && (*p)->izq)     //cuando tiene ambos hijos, entonces elige uno
                                                //elegirá segun cuál de las dos esté mas cercano en cuanto a diferencia de enteros
            {
                tNodoArbol * aux;

                int * dato = (int*)d;           //saco las diferencias del dato con respecto a cada lado
                int dif1 =  *dato -  *(int*)((*p)->izq->info);
                int dif2 =  (*dato -  *(int*)((*p)->der->info))  * (-1) ;

                if(comparar( &dif1 ,  &dif2 ) <= 0) //si viene por acá, es porque el hijo izq es el mas cercano (o sin iguales)
                {
                    aux = (*p)->der;                //el auxiliar me sirve para no perder al lado derecho
                    *p = (*p)->izq;                 //borro el nodo que queria borrar y engancho al siguiente
                    while((*p)->der)                //luego avanzo por si ese nodo tenia mas ramas
                    {
                        p = &(*p)->der;
                    }
                    (*p)->der = aux;                //engancho al auxiliar
                }
                else        //si viene por aca es porque el hijo derecho es mas cercano al dato
                {
                     aux = (*p)->izq;
                     *p = (*p)->der;
                    while((*p)->izq)
                    {
                        p = &(*p)->izq;
                    }
                    (*p)->izq = aux;
                }
            }
            return 1;
        }
    }
    return 0;   //si vino por acá es porque no encontró el dato
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////



//FUNCIONA PERFECTO
void podarHastaConvertirAArbolCompleto(tArbolBinBusq * p, int (*cmp)(const void *, const void *))
{
    //primero obtengo la altura del arbol
    unsigned alturaDelArbol = alturaArbolBin(p);
    printf("\naltura del arbol: %d\n", alturaDelArbol);

    if(alturaDelArbol==1)   //significa que hay un solo nodo, entonces salgo
        return;

    //vamos a ir podando desde abajo hasta que sea arbol completo
    //por eso iremos decrementando la altura.
    //cuando sea completo, cortamos el ciclo
    do
        {
        podarHastaNivel(p, 0, alturaDelArbol-1);
        alturaDelArbol--;
        }
        while(esArbolBinCompleto(p)==0);
}



void podarHastaNivel(tArbolBinBusq* p, unsigned n, unsigned tope)
{
    if(!*p)
        return;

    if(n>=tope)
        {
            tNodoArbol * elim = *p;
            free(elim->info);
            free(elim);
            *p = NULL;
            return;
        }
    podarHastaNivel(&(*p)->izq, n+1, tope);
    podarHastaNivel(&(*p)->der, n+1, tope);
}

//ESTA ES OTRA VERSION PERO NO ANDA SIEMPRE BIEN
//LA ANTERIOR ES SIEMPRE EFECTIVA
/*
void podarHastaConvertirAArbolCompleto(tArbolBinBusq * p, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return;

    //creo un puntero a nodo que apunte a la raiz, me servira para comparar
    tNodoArbol * aux = *p;

    //voy a obtener hasta qué nivel el arbol es binario de cada lado
    int li, ld, hasta = 0;
    li = buscarLadoIzq(p, aux, 0, comparar, &li);
    ld = buscarLadoDer(p, aux, 0, comparar, &ld);

    //una vez obtenido, saco el menor de ellos. este sera entonces el nivel hasta donde voy a podar
    hasta =  li < ld?  li : ld;

    podarHastaNivel(p, hasta, 0);
}

void podarHastaNivel(tArbolBinBusq * p, int hasta, unsigned n)
{
    if(n>hasta) //no me tengo que pasar a otro nivel
        return;

    if(n==hasta)
    {
        if((*p)->izq)
            (*p)->izq = NULL;

        if((*p)->der)
            (*p)->der = NULL;

        return;
    }
    podarHastaNivel(&(*p)->izq, hasta, n+1);
    podarHastaNivel(&(*p)->der, hasta, n+1);
}


int buscarLadoIzq(tArbolBinBusq * p, tNodoArbol * aux, unsigned n, int (*comparar)(const void *, const void *), int * li)
{
    if(n>*li)
        *li= n;
    if(comparar((*p)->info , aux->info )> 0)
        return *li;

    if((*p)->izq && (*p)->der)
    {
        *li=n;
        buscarLadoIzq(&(*p)->izq, aux, n+1, comparar, li);
        buscarLadoIzq(&(*p)->der, aux, n+1, comparar, li);
    }
    return *li;
}

int buscarLadoDer(tArbolBinBusq * p, tNodoArbol * aux, unsigned n, int (*comparar)(const void *, const void *), int * ld)
{
    if(n>*ld)
        *ld= n;
    if(comparar((*p)->info , aux->info )< 0)
        return *ld;

    if((*p)->izq && (*p)->der)
    {
        *ld=n;
        buscarLadoDer(&(*p)->izq, aux, n+1, comparar, ld);
        buscarLadoDer(&(*p)->der, aux, n+1, comparar, ld);
    }
    return *ld;
}
*/
/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////



//VERSION APUNTE
unsigned alturaArbolBin2(const tArbolBinBusq * p)
{
    int hi, hd;
    if(!*p)
        return 0;
    hi = alturaArbolBin2(&(*p)->izq);
    hd = alturaArbolBin2(&(*p)->der);
    return (hi>hd ? hi : hd) +1;
}


//VERSION APUNTE
unsigned cantNodosArbolBin(const tArbolBinBusq * p)
{
    if(!*p)
        return 0;
    return  cantNodosArbolBin(&(*p)->izq) +
            cantNodosArbolBin(&(*p)->der) +
            1;
}

//SI BIEN ESTA VERSION DEL PROFE, SE BASA EN BORRAR LA RAIZ, EL PLANTEO SIRVE PARA TODOS LOS DEMAS NODOS.
//DIFIERE DE MI FUNCION DE ELIMINARNODO, SI BIEN LA MIA TAMBIEN BORRA CORRECTAMENTE LA RAIZ
//PERO NO ELIGE EL MISMO NODO A REEMPLAZAR QUE EN ESTA FUNCION.
//ENTONCES QUÉ NODO USA DE REEMPLAZO ESTA FUNCION AL BORRAR LA RAIZ?
//SE FIJA DE CADA LADO IZQ Y DER DE LA RAIZ
//SE FIJA CUÁL ES EL SUBARBOL MAS ALTO (IZQ O DER) Y ELIGE ESE LADO PARA BUSCAR UN REEMPLAZO
/** TOMEMOS UN EJEMPLO DE ARBOL
                          100
            50		                    150
    25              75	         125             175
10     30         60          110  130         160  190
                55  70                                          **/

/**NO PUEDE TOMAR AL 50 NI AL 150, PUES SI ELIGE ALGUNO DE ELLOS, LOS NUMEROS HIJOS QUE
ESTAN A LA DERECHA DEL 50 (EJ 75,60,22,70), DEBERIAN IR A PARAR AL OTRO LADO Y EL ARBOL SE DESBALANCEA.
LO MISMO PASA SI TOMO EL 150. LOS VALORES HIJOS DE LA IZQ (EJ 125,110,130)
VAN A PARAR AL OTRO LADO IZQ DEL ARBOL Y TAMBIEN SE DESBALANCEA.
ENTONCES DEBERIA TOMAR LOS NUMEROS MAS PROXIMOS A LA RAIZ.
SI LA RAIZ ES 100, DEL LADO IZQ EL MAS PROXIMO ES EL 75. Y DEL LADO DER EL MAS PROX ES 110.
CUAL ELIJO?
SI ELIJO EL 110 POR PARECER MAS FACIL DE UBICAR, SE DESBALANCEA EL ARBOL.
PUESTO QUE EL LADO DERECHO TIENE UNA MENOR ALTURA.
ENTONCES ELIJO EL 75 DEL LADO IZQ, PUES AL TENER ESE LADO UN MAYOR NIVEL, NO SE DESBALANCEARA EL ARBOL.
EL NODO REMPLAZO NO APUNTARA AL 75. SINO AL ANTERIOR, EN ESTE CASO, EL 50.
**/
int eliminarRaizArbolBinBusq(tArbolBinBusq * p)
{
    tNodoArbol ** remp; //NOTAR CÓMO DECLARÉ A REMP, ES COMO UN tARBOL
    tNodoArbol  * elim;

    if(!*p)     //ARBOL VACIO
        return 0;

    //borro la raiz, en realidad libero la información que hay dentro
    free((*p)->info);

    //cuando hay un solo nodo en el árbol..
    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return 1;
    }

    //entonce me fijo cual de las dos alturas es la mas grande
    //si la altura del arbol es mas grande la de la izq, lo que tnego que hacer
    //es encontrar el mayor nodo de la izq (como en nuestro caso encontramos el 75)
    //si el lado derecho es el de mayor altura, entonces buscamos el nodo menor del lado izq
    remp = alturaArbolBin2(&(*p)->izq) > alturaArbolBin2(&(*p)->der) ?
        mayorNodoArbolBinBusq(&(*p)->izq) :
        menorNodoArbolBinBusq(&(*p)->der);

    elim = *remp;
    //ya lo paso como raiz a mi nuevo nodo elegido
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    //tener en cuenta ademas que este nodo elegido siempre tendra un solo hijo,
    //o será el de la izq, o de la derecha
    //PERO ADEMAS ES IMPORTANTE DESTACAR QUE SI ERA NODO SIN HIJOS,
    //COMO DEBO PONERLO EN NULL, AL HACER LA SIGUIENTE LÍNEA, SI NO ENCUENTRA HIJOS,
    //SE PONE EN NULL AUTOMÁTICAMENTE
    *remp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}


tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;
    while((*p)->der)
        p = &(*p)->der;
    return (tNodoArbol **) p;
}

tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;
    while((*p)->izq)
        p = &(*p)->izq;
    return (tNodoArbol **) p;
}


//OTRA FORMA DE RESOLVER, (MUY SIMILAR, MISMO PLANTEO)
//PERO ES UNA VERSIÓN MÍA
/*

tArbol * mayorNodoLadoIzq(tArbol * p)
{
    if(!*p)
        return NULL;

    while((*p)->der)
        p = &(*p)->der;

    tArbol * nue = p;

    return nue;
}


tArbol * menorNodoLadoDer(tArbol * p)
{
    if(!*p)
        return NULL;

    while((*p)->izq)
        p = &(*p)->izq;

    tArbol * nue = p;

    return nue;
}


void eliminarRaiz(tArbol * p, int (*cmp)(const void *, const void *))
{
    if(!*p)
        return;

    free((*p)->info);

    unsigned hi = alturaArbol(&(*p)->izq);
    unsigned hd = alturaArbol(&(*p)->der);


    tArbol * reemp;
    reemp = hi>hd ? mayorNodoLadoIzq(&(*p)->izq)  :  menorNodoLadoDer(&(*p)->der);

    printf("nodo a elegir: %d\n\n", *(int*)((*reemp)->info));

    tNodo * elim;
    elim = *reemp;

    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

}


*/

//esta versión es del apunte
//me trae el nodo mayor del arbol
int mayorElemNoClaveArbol(const tArbolBinBusq * p, void * d, unsigned tam,
                          int (*cmp)(const void *, const void*))
{
    const tArbolBinBusq * mayor = p;

    if(!*p)
        return 0;

    mayor= mayorNodoNoClaveArbol(&(*p)->izq, mayor, cmp);
    mayor= mayorNodoNoClaveArbol(&(*p)->der, mayor, cmp);

    memcpy(d, (*mayor)->info, MINIMO(tam, (*mayor)->tamInfo));
    return 1;
}


const tArbolBinBusq * mayorNodoNoClaveArbol(const tArbolBinBusq * p,
                                            const tArbolBinBusq * mayor,
                                            int (*cmp)(const void *, const void*))
{
    if(!*p)
        return mayor;
    if(cmp((*p)->info, (*mayor)->info)>0)
        mayor = p;

    mayor = mayorNodoNoClaveArbol(&(*p)->izq, mayor, cmp);
    mayor = mayorNodoNoClaveArbol(&(*p)->der, mayor, cmp);
    return mayor;
}
