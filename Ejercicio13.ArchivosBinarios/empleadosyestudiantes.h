#ifndef EMPLEADOSYESTUDIANTES_H_INCLUDED
#define EMPLEADOSYESTUDIANTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dni;
    char apellido[12];
    char nombre[12];
    double sueldo;
}t_empleado;

typedef struct
{
    int dni;
    char apellido[12];
    char nombre[12];
    float promedio;
}t_estudiante;


//prototipos
int cargarArchivos(char * nomArchEmp, char *nomArchEst);
void compararApellido(int cmpAp, int cmpNom, t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2);
void compararNombre(int cmpNom, t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2);
void compararDni(t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2);

/*
Ejercicio13. Práctico2.
Se dispone de dos archivos binarios: <"empleados"> y <"estudiantes">.
Cada registro del primer archivo contiene los campos:
- <dni>,<apellido>,<nombre>y<sueldo>
en tanto que los del segundo:
- <dni>,<apellido>,<nombre>y<promedio>
Ambos archivos estan ordenados alfabeticamente por <apellido>/<nombre>/<dni>
Ambos archivos deben ser leidos solo una vez y no deben ser almacenados en arrays.
El sueldo es double y el promedio es float.
Escriba un programa que leyendo ambos archivos, actualice el sueldo de aquellos empleados
que tengas un registro de estudiante con un promedio superior a 7 en un 7.28%
*/
#endif // EMPLEADOSYESTUDIANTES_H_INCLUDED
