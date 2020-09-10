
#include "empleado.h"

/*Programa donde primero guardo un archivo de texto con datos de empleados.
Luego abro el archivo de texto, leo los registros y los printeo por consola.*/

int main()
{
    if(!cargar_archivo("empleados.txt"))
        return TODO_MAL;


    FILE *pf;
    pf=fopen("empleados.txt", "rt");
    t_empleado emp;

    if(!pf)
    {
        return TODO_MAL;
    }

    while(leer_archivo(pf, &emp))
    {
        printf("%d %s %02d %02d %d \n", emp.leg, emp.nya, emp.fec.d, emp.fec.m, emp.fec.a);
        //el modo en que lo muestre en pantalla no tiene nada que ver con
        //el formato en que guardé el texto
    }


    fclose(pf);

    system("pause");
    return 0;
}




