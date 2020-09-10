#include <stdio.h>
#include <stdlib.h>

/*Programa que pide datos de alumnos por teclado y luego los guarda en un archivo de texto.
El programa termine cuando se ingrese un alumno con legajo 0. */

int cargar( char * path);

typedef struct
{
    int leg;
    char nya[20];
    float prom;
}t_alumno;


int main()
{
    char * path= "ALUMNOS.txt";

    if(!cargar(path))
        return 1;

    system("pause");
    return 0;
}


int cargar(char * path)
{
    FILE * pf = fopen(path, "wt");
    t_alumno alu;

    if(!pf)
        return 0;

    do
    {
        printf("ingresar legajo: ");
        fflush(stdin);
        scanf("%d", &alu.leg);
        printf("ingresar nombre: ");
        fflush(stdin);
        gets(alu.nya);
        printf("ingresar promedio: ");
        fflush(stdin);
        scanf("%f", &alu.prom);

        if(alu.leg!=0)
            fprintf(pf,"%04d%-19s%05.2f\n", alu.leg, alu.nya, alu.prom);

    }while(alu.leg!=0);

    fclose(pf);

    return 1;
}

