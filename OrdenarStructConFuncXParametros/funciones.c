#include "alumno.h"

t_alumno * ord_struct_x_sel(t_alumno *vec, int ce, int (*cmp) (const t_alumno *, const t_alumno *))
{
    t_alumno * ini= vec;
    t_alumno * fin= vec+ce-1;
    t_alumno * men;

    while(vec<fin)
        {
        men = buscar_menor(vec, fin, cmp);

        if(vec!= men)
            intercambio(vec, men);

        vec++;
        }
    return ini;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

t_alumno * buscar_menor(t_alumno *vec, t_alumno *fin, int (*cmp) (const t_alumno *, const t_alumno *))
{
    t_alumno * men= vec;

    vec++;

    while(vec<=fin)
    {
        //aca ya uso cmp y SÌ le pongo parentesis ya que SÍ la va a ejecutar
        if( cmp(vec, men) <0)
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

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//es una funcion por parametro
//actua como una especia de strcmp
//compara estructuras
int cmp_x_dni(const t_alumno *a1, const t_alumno *a2)
{
    return a1-> dni - a2->dni;

    //la resta actua como un strcmp
    //si la resta es 0, es que ambos son iguales, y devuelve el 0 en ese caso
}

//como las estructuras no las voy a modificar en estas funciones, las paso como constantes
int cmp_x_nya(const t_alumno *a1, const t_alumno *a2)
{
    return strcmpi(a1->nya , a2->nya);
}
