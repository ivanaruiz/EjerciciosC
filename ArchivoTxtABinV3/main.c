#include "alfajor.h"



int main()
{
    char *prodTxt = "alfajores.txt";
    char *prodBin = "alfajores.dat";

    if(!cargar_archivo(prodTxt))
        return 1;

    FILE *archTxt = fopen(prodTxt, "rt");
    FILE *archBin = fopen(prodBin, "wb");

    if(!archBin || !archTxt)
        return 1;

    t_alfajor alf;
    char texto[100];


    int i;
    for(i=0; i<5; i++)
    {
        //esta linea levanta el texto del archivo de texto, levanta linea por linea
        fgets(texto, sizeof(texto), archTxt);
        sscanf(texto, "%d%s%f", &alf.cod, alf.desc, &alf.precio);
        fwrite(&alf, sizeof(t_alfajor),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    if(!leer_archivo_bin(prodBin))
        return 1;


    system("pause");
    return 0;
}





