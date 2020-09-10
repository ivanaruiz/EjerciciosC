#include "alumno.h"

int main()
{
    if(!crear_arch_texto("alumnos.txt"))
        return 1;

    FILE *archTxt=fopen("alumnos.txt", "rt");
    FILE *archBin=fopen("alumnos.dat", "wb");

    if(!archTxt || !archTxt)
            return 1;

    char texto[100];
    t_alumno alu;

    while(fgets(texto, sizeof(texto), archTxt))
    {
        //notar que en el sscanf usamos exactamente el mismo formato que en el fprintf
        //incluso hasta el '\n' y con los pipes
        //luego lo separaremos
        sscanf(texto, "%08d|%s|%02d|%02d|%4d|%5f\n",
                    &alu.dni,
                    alu.nya,
                    &alu.fec.d,
                    &alu.fec.m,
                    &alu.fec.a,
                    &alu.prom);

        //lo siguiente lo hago porque no me dejara guardar con los pipes esos
        //con cada registro sacara los pipes
        separar_campos(texto, &alu);

        fwrite(&alu, sizeof(t_alumno),1,archBin);
    }

    fclose(archTxt);
    fclose(archBin);

    if(!leer_arch_bin("alumnos.dat"));
        return 1;

    system("pause");
    return 0;
}


