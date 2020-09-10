#include "alumno.h"
//el tamaño me sirve para saber el tamaño del elemento que tengo
//por ej si estuviera hablando de enteros, sabemos que al hacer vec++, se mueve 4 bytes en adelante
//nuestro struct tiene 36 bytes(es tam), entonces debe moverse vec=vec+tam, para moverse un registro adelante.
//size_t indica tamaños
//usamos punteros a void para tratar variables genericas. tambien la funcion devuelve un puntero a void
void * ord_vec_x_sel(void *vec, size_t ce, size_t tam, int (*cmp) (const void *, const void *))
{
    void * ini= vec;
    void * fin= vec+ (ce-1)*tam;
    void * men;
    while(vec<fin)
        {
        men = buscar_menor(vec, fin, tam, cmp);

        if(vec!= men)
            intercambio(vec, men, tam);

        //asi saltamos al registro siguiente
        vec+= tam;
        }
    return ini;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void * buscar_menor(void *vec, void *fin, size_t tam, int (*cmp) (const void *, const void*))
{
    void * men= vec;

    vec+= tam;

    while(vec<=fin)
    {

        if( cmp(vec, men) <0)
            men=vec;

        vec+=tam;
    }

    return men;
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


void intercambio(void *vec, void *men, size_t tam)
{
    //uso un numero grande en aux
    char aux[1000];

    //copia lo que esta en memoria de vec a aux. lo que copia tiene el tamaño de tam
    memcpy(aux, vec, tam);
    memcpy(vec, men, tam);
    memcpy(men, aux, tam);
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


int cmp_x_dni(const void *a1, const void *a2)
{
    //aca es donde hacemos comparacion por dni, pero notar que el compilador aun no sabe qué tipo de datos son.
    //entonces casteamos a a1 y a2. es decir lo casteamos para que sean del tipo t_alumno
    //y luego lo asignamos a otras dos variables del tipo t_alumno para mas comodidad
    //ahora sí podemos hacer la comparacion, en este entre esas nuevas dos variables de tipo t_alumno
    //y compararlas por dni
    const t_alumno *alu1 = (const t_alumno *)a1;
    const t_alumno *alu2 = (const t_alumno *)a2;

    return alu1->dni - alu2->dni;
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int cmp_x_nya(const void *a1, const void *a2)
{
    const t_alumno *alu1= (const t_alumno *)a1;
    const t_alumno *alu2= (const t_alumno *)a2;

    return strcmpi(alu1->nya , alu2->nya);
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


