#include "empleados.h"

/*Grabo un archivo de texto con datos de empleados.
Luego abro el txt y muestro esos datos por pantalla.*/

int main()
{
    char * path = "empleados.txt";

    int cant_registros = cargar_archivo(path);

    if(!cant_registros)
        return 1;

    FILE * pf = fopen(path, "rt");

    if(!pf)
        return 1;

    char linea[100];


    for(int i=0; i<cant_registros; i++)
        printf("%s", fgets(linea, 100, pf));


    fclose(pf);

    system("pause");
    return 0;
}




