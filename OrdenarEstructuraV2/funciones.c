#include "alumno.h"

t_alumno * ord_struct_x_sel(t_alumno *vec, int ce, int ordenar_0dni_1nya)
{
    t_alumno * ini= vec;
    t_alumno * fin= vec+ce-1;
    t_alumno * men;
    while(vec<fin)
        {
        if(ordenar_0dni_1nya==0)
            men = buscar_menor_dni(vec, fin);
        else
            men = buscar_menor_nya(vec, fin);

        if(vec!= men)
            intercambio(vec, men);

        vec++;
        }
    return ini;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

t_alumno * buscar_menor_dni(t_alumno *vec, t_alumno *fin)
{
    t_alumno * men= vec;

    vec++;

    while(vec<=fin)
    {
        if(vec->dni < men->dni)
            men=vec;

        vec++;
    }

    return men;
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

t_alumno * buscar_menor_nya(t_alumno *vec, t_alumno *fin)
{
    t_alumno * men= vec;

    vec++;

    while(vec<=fin)
    {
        if(strcmp(vec->nya, men->nya) < 0 )
            men=vec;

        vec++;
    }

    return men;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void intercambio(t_alumno *vec, t_alumno *men)
{
    t_alumno aux= *vec;
    *vec= *men;
    *men= aux;
}
