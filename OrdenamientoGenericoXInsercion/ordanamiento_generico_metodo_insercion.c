#include "ordenamiento_generico_metodo_insercion.h"


void * ordenar(void * vec, size_t ce, size_t tam, int (*cmp)(const void*, const void*))
{
    void * fin= vec+(ce-1)*tam;
    //estos dos punteros son los que manejaran el subvector ordenado
    void * iniOrd= vec;
    void * finOrd= vec;

    //adelanto el vector un puesto ya que sería en vano que empiece desde el primer puesto
    vec+=tam;

    //vec es el que recorre todo, y va tomando cada posicion para compararla con el vector subordenado
    while(vec<=fin)
    {
        insertar_en_subvec_ord(vec, iniOrd, finOrd, tam, cmp);

        finOrd+=tam;
        vec+=tam;
    }
    return iniOrd;
}

///////////////////////////////////////////////
///////////////////////////////////////////////


void insertar_en_subvec_ord(void *vec, void *iniOrd, void *finOrd, size_t tam,
                            int (*cmp)(const void*, const void*))
{
    while(iniOrd <= finOrd)
    {
        if(cmp (vec, iniOrd) <0 )
            intercambio(vec, iniOrd, tam);


        iniOrd+=tam;
    }
}

///////////////////////////////////////////////
///////////////////////////////////////////////


void intercambio(void *vec, void * iniOrd, size_t tam)
{
    void * aux= malloc(tam);
    if(!aux)
        return;
    memcpy(aux, vec, tam);
    memcpy(vec, iniOrd, tam);
    memcpy(iniOrd, aux, tam);
    free(aux);
}

///////////////////////////////////////////////
///////////////////////////////////////////////

int cmp_ent( const void *a1, const void *a2)
{
    const int * e1 = (const int*) a1;
    const int * e2 = (const int*) a2;

    return *e1- *e2;
}

///////////////////////////////////////////////
///////////////////////////////////////////////

int cmp_char( const void *a1, const void *a2)
{
    const char * e1 = (const char*) a1;
    const char * e2 = (const char*) a2;

    return strcmp(e1,e2);
}
