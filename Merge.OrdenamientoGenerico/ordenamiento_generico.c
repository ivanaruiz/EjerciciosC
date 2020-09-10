#include "archivos.h"

void * ordenar(void * vec, size_t ce, size_t tam, int (*cmp)(const void*, const void*))
{
    void *ini=vec;
    void *fin= vec+(ce-1)*tam;
    int hubocambios= 1;

    while(ini<fin && hubocambios== 1)
    {
        hubocambios=0;

        while(vec<fin)
        {
            if(cmp(vec, vec+tam) >0 )
                    {
                    intercambio(vec, vec+tam, tam);
                    hubocambios= 1;
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

/////////////////////////////////////////////////////////////
//Funcion de comparacion: compareremos por codigo de producto
/////////////////////////////////////////////////////////////

int cmp_cod(const void *a1, const void* a2)
{
    const t_producto *e1= (const t_producto *)a1;
    const t_producto *e2= (const t_producto *)a2;

    return e1->cod - e2->cod;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void intercambio(void *a1, void *a2, size_t tam)
{
    void * aux= malloc(tam);
    memcpy(aux, a1, tam);
    memcpy(a1, a2, tam);
    memcpy(a2, aux, tam);
    free(aux);
}
