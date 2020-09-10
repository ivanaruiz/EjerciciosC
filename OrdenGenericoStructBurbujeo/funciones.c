#include "ordenarstruct.h"


void * ordenar(void *vec, size_t ce, size_t tam, int (*cmp) (const void* , const void*))
{
    void *ini=vec;
    void *fin= vec+(ce-1)*tam;
    int hubocambios= VERDADERO;

    while(ini<fin && hubocambios== VERDADERO)
    {
        hubocambios=FALSO;

        while(vec<fin)
        {
            if(cmp(vec, vec+tam) >0 )
                    {
                    intercambio(vec, vec+tam, tam);
                    hubocambios= VERDADERO;
                    }
            vec+=tam;
        }
        //ante una pasada, vec quedó adelantado, asi que vuelvo a poner al inicio para la siguiente pasada
        vec=ini;
        //retrocedo con fin ya que en cada iteracion queda la ultima posiicion ordenada con el numero mayor
        //asi que la busqueda se achica en cada iteracion
        fin-=tam;

    }
    return ini;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

void intercambio(void *a1, void *a2, size_t tam)
{
    //reservo memoria dinamica con malloc. creo una variable de tipo puntero a void.
    void *aux= malloc(tam);
        if(!aux)
            return ;
    memcpy(aux, a1, tam);
    memcpy(a1, a2, tam);
    memcpy(a2, aux, tam);
    //si o si debo liberar la memoria dinamica que utilicé
    free(aux);
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_ent(const void *e1, const void *e2)
{
    const t_producto *a1= (const t_producto*) e1;
    const t_producto *a2= (const t_producto*) e2;
    return a1->cod - a2->cod;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


int cmp_float(const void *e1, const void *e2)
{
    const t_producto *a1 = (const t_producto*) e1;
    const t_producto *a2 = (const t_producto*) e2;

    return a1->precio - a2->precio;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_char(const void* e1, const void* e2)
{
    const t_producto *a1 = (const t_producto*) e1;
    const t_producto *a2 = (const t_producto*) e2;

    return strcmp(a1->prod , a2->prod);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
