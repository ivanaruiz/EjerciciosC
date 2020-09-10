#include "alumno.h"


int main()
{
    char * aluTxt= "alumnos.txt";
    char * aluBin= "alumnos.dat";

    if(!crear_arch_texto(aluTxt))
        return 1;

    FILE *archTxt= fopen(aluTxt, "rt");
    FILE *archBin= fopen(aluBin, "wb");

    if(!archBin || !archTxt)
        return 1;

    //convertire el archivo de texto a binario
    t_alumno alu;
    char linea[100];

    while(fgets(linea, sizeof(linea),archTxt))
    {
        sscanf(linea, "%08d%29[^\n]%02d%02d%4d%5f\n",
               &alu.dni,
               alu.nya,
               &alu.fec.d,
               &alu.fec.m,
               &alu.fec.a,
               &alu.prom);

        fwrite(&alu, sizeof(t_alumno),1,archBin);
    }
    fclose(archBin);
    fclose(archTxt);

    //ya leo el archivo binario convertido
    if(!leer_arch_bin(aluBin))
        return 1;


    system("pause");
    return 0;
}
