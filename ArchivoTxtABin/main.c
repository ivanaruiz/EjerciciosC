#include "alfajor.h"

int main()
{
    char * prodTxt = "alfajores.txt";
    char * prodBin = "alfajores.dat";

    if(!cargar_archivo(prodTxt))
        return 1;

    FILE *archTxt = fopen(prodTxt, "rt");
    FILE *archBin = fopen(prodBin, "wb");

    if(!archBin || !archTxt)
        return 1;

    t_alfajor alf;


    while(fscanf(archTxt, "%d%s%f", &alf.cod, alf.desc, &alf.precio)!=0 && !feof(archTxt))
    {
        fwrite(&alf, sizeof(t_alfajor),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    if(!leer_archivo_bin(prodBin))
        return 1;


    system("pause");
    return 0;
}
