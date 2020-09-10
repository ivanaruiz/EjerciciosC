#include "arbol.h"

void crearArbol(tArbolBinBusq * p)
{
    *p = NULL;
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * ds, unsigned cantReg,
                                          unsigned (*leer) (void **, void *, unsigned, void * params),
                                          void * params)
{
    if(*p || !ds)
        return 0;

    return cargarDesdeDatosOrdenadosRec(p, ds, leer, 0, cantReg-1, params);
}


//esto es lo que mandé en la función (p, pf, leerDesdeArchivoBin, 0, cantReg-1 , &tamInfo)
int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * pf,
                                 unsigned (*leer)(void **, void *, unsigned, void * params),
                                 int li, int ls, void * params)
{
    int m= (li+ls)/2;   //la media
    int r;

    if(li>ls)   //condicion de corte de recursividad
    {
        return 1;
    }

    //carga el nodo en el arbol
    (*p) = (tNodoArbol*) malloc(sizeof(tNodoArbol));
    if(!*p || !((*p)->tamInfo = leer(&(*p)->info, pf, m, params)))  //recordar que en params está &tamInfo
    {
        free(*p);
        return 0; //SIN MEM
    }

    (*p)->izq = (*p)->der = NULL;

    //luego se va a la izq del vector, notar que le pasa un nuevo ls (que seria m-1)
    if((r=cargarDesdeDatosOrdenadosRec(&(*p)->izq, pf, leer, li, m-1, params)) != 1)
        return 1;
    //luego de cargar el lado izq del vector, cargo el lado derecho
    return cargarDesdeDatosOrdenadosRec(&(*p)->der, pf, leer, m+1, ls, params);
}

/////////////////////////////////////////////////////////////
//*********************************************************//
/////////////////////////////////////////////////////////////

//esto es lo que mandé en la primera llamada a la función
//    recorrerEnOrdenArbolBinBusq(&ar, pf, imprimirArch);
//notar que pf es params
//esto es lo que mandé en la segundo llamada a la función
//    recorrerEnOrdenArbolBinBusq(&ar, pf, imprimirArch);
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenRecArbolBinBusq(p, 0, params, accion);   //el 0 de niveles (n)
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

//voy a leer desde el archivo binario creado
//y luego llamar a la función recursiva para cargar cada dato del archivo
int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path,
                                         unsigned tamInfo)
{
    int cantReg, r;
    FILE * pf;
    if(*p)
        return 1;
    if(!(pf=fopen(path, "rb")))
       return 0;
    fseek(pf, 0L, SEEK_END);        //me voy al final del archivo
    cantReg = ftell(pf)/tamInfo;    //para calcular cant de reg. ftell me devuelve la posicion del puntero
    r = cargarDesdeDatosOrdenadosRec(p, pf, leerDesdeArchivoBin, 0, cantReg-1 , &tamInfo);  //0 es li
    //notar que pf lo mando como el dato que voy a leer, o sea tipo void *
    //&tamInfo será el int

    fclose(pf);
    return r;
}

unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params)
{
    unsigned tam=  *((int*)params);
    *d = malloc(tam);
    if(!*d)
        return 0;
    fseek((FILE*)pf, pos*tam, SEEK_SET);
    return fread(*d, tam, 1, (FILE*)pf);
}
