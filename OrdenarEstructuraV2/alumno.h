#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dni;
    char nya[30];
}t_alumno;

t_alumno * ord_struct_x_sel(t_alumno *vec, int ce, int ordenar_0dni_1nya);
t_alumno * buscar_menor_dni(t_alumno *vec, t_alumno *fin);
void intercambio(t_alumno *vec, t_alumno *men);
t_alumno * buscar_menor_nya(t_alumno *vec, t_alumno *fin);

//Este programa crea una estructura simple, y luego la ordena segun el dni, y luego por nombre

//Notar que la resolucion es casi identica a ordenar un simple vector de enteros (como el ejercicio
//VectorOrdenamientoXSeleccionV2), solo que en las funciones uso punteros a estructura. y funciona igual.

//Tener en cuenta que estas funciones usan como parametros (y ademas devuelven) datos del tipo t_alumno,
//que es una estructura. en estos casos asi, los prototipos deben ir debajo del struct. ya que si los ponemos
//por arriba de él, el compilador no es capaz de reconocer a los prototipos ya que aun no esta definida la estructura.


#endif // ALUMNO_H_INCLUDED
