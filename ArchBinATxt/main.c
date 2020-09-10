#include "productos.h"


int main()
{
    char * prodBin = "productos.dat";
    char * prodTxt = "productos.txt";

    if(!cargar_archivo(prodBin))
        return 1;


    FILE * archBin = fopen(prodBin, "rb");
    FILE * archTxt = fopen(prodTxt, "wt");

    if(!archBin || !archTxt)
        return 1;

    char formato[100];

    char opc;

    do
    {
    printf("Que formato desea usar para guardar el archivo de texto: variable o fijo? (v/f): ");
    fflush(stdin);
    gets(&opc);
    }
    while(opc!='f' && opc!='F' && opc!= 'v' && opc!= 'V');

    if(opc=='f' || opc=='F')
    {
        strcpy(formato, "%04d%-19s%5.2f\n");
        fprintf(archTxt,"Longitud fija:\n");
    }

    if(opc=='v' || opc=='V')
    {
        strcpy(formato, "%04d|%s|%5.2f\n");
        fprintf(archTxt, "Longitud variable:\n");
    }


    t_producto prod;

    fread(&prod, sizeof(t_producto),1,archBin);

    while(!feof(archBin))
    {
        fprintf(archTxt, formato, prod.cod, prod.desc, prod.precio);
        fread(&prod, sizeof(t_producto),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    printf("\nArchivo binario convertido a archivo de texto.\n\n");

    system("pause");
    return 0;
}

