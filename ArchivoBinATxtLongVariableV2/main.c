#include "alumno.h"

int main()
{
    if(!crear_arch_bin("alumnos.dat"))
        return 1;

    FILE *archBin = fopen("alumnos.dat", "rb");
    FILE *archTxt = fopen("alumnos.txt", "wt");

    if(!archBin || !archTxt)
        return 1;

    t_alumno alu;

    fread(&alu, sizeof(t_alumno),1,archBin);

    while(!feof(archBin))
    {
        printf("%08d|%s|%02d|%02d|%4d|%05.2f\n", alu.dni, alu.nya, alu.fec.d, alu.fec.m, alu.fec.a, alu.prom );

        fprintf(archTxt,"%08d|%s|%02d|%02d|%4d|%05.2f\n", alu.dni, alu.nya, alu.fec.d, alu.fec.m, alu.fec.a, alu.prom);
        fread(&alu, sizeof(t_alumno),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    system("pause");
    return 0;
}

