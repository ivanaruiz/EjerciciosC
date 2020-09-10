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

    //cuando hago fgets, me quedó todo un registro en texto. ej 1 JORGITO 20.
    //pero los datos están todo juntos, debo separarlos
    while(fgets(texto, sizeof(texto), archTxt))
    {
        if(!strchr(texto, '\n'))
            return 1;

        //lo que hago con sscanf es que separo esos datos y los guardo correctamente en el struct
        sscanf(texto, "%4d%19[^\n]%5f", &alf.cod, alf.desc, &alf.precio);
        fwrite(&alf, sizeof(t_alfajor),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    if(!leer_archivo_bin(prodBin))
        return 1;


    system("pause");
    return 0;
}





