/*Este proyecto es la continuacion del proyecto llamado Archivo.
Solo lee el archivo creado en el otro proyecto.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Archivo/alumno.h"  //le paso la ruta del .h que contiene la estructura


int main()
{
    int i=0;
    t_alumno alu;
    FILE * arch;
    arch = fopen("../Archivo/Alumnos.dat","rb");  //busco en la carpeta del otro proyecto

    printf("Archivo de alumnos: ");
    printf("\n--------------------------");

    fread(&alu, sizeof(t_alumno),1, arch);

    while(!feof(arch))
    {
        printf("\n%d - %s - %c - \nNotas: ", alu.dni, alu.nya, toupper(alu.sexo));

        while(alu.notas[i]!='\0')
        {
            printf("%d ", alu.notas[i]);
            i++;
        }
        i=0;

        printf("\nPromedio: %.2f", alu.prom);
        fread(&alu, sizeof(t_alumno),1, arch);
        printf("\n--------------------------");
    }

    fclose(arch);

    printf("\n\n");
    system("pause");
    return 0;
}
