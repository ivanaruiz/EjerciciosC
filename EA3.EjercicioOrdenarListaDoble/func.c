#include "lista.h"


void crear_lista(tLista * pl)
{
    *pl = NULL;
}

int poner_ultimo_lista(tLista * pl, const void * d, unsigned tam_dato)
{
    tNodo * act = *pl;
    tNodo * nue;

    if(act)
        while(act->sig)
            act = act->sig;

    if((nue = (tNodo *)malloc(sizeof(tNodo)))== NULL ||
        (nue->info = malloc(tam_dato)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;
    nue->sig = NULL;
    nue->ant = act;
    if(act)
        act->sig = nue;
    *pl = nue;
    return 1;
}



int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    int contNodos = 0;

    if(!*p)
        return 0;   //lista vacía

    //voy al principio de la lista
    while((*p)->ant)
    {
        p = &(*p)->ant;
    }

    fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
    //recorro la lista, muestro y cuento
    while(*p)
    {
        contNodos++;
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
    }

    return contNodos;
}



void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(!d)
        return;

    const tAlumno * alum = (const tAlumno*) d;

    printf("%8s %c\n", alum->apyn, alum->let);
  //  fprintf(fp, "%s\n", alum->apyn);
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tAlumno * alum1 = (const tAlumno *) d1;
    const tAlumno * alum2 = (const tAlumno *) d2;

    return strcmpi(alum1->apyn, alum2->apyn);
}
