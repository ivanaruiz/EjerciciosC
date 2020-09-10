#include "alumno.h"

t_alumno * ord_struct_x_sel(t_alumno *vec, int ce)
{
    t_alumno * ini= vec;
    t_alumno * fin= vec+ce-1;
    t_alumno * men;
    while(vec<fin)
        {
        men = buscar_menor(vec, fin);

        if(vec!= men)
            intercambio(vec, men);

        vec++;
        }
    return ini;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

t_alumno * buscar_menor(t_alumno *vec, t_alumno *fin)
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


void intercambio(t_alumno *vec, t_alumno *men)
{
    t_alumno aux= *vec;
    *vec= *men;
    *men= aux;
}
