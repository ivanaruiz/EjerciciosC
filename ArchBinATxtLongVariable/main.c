/*Programa que convierte un archivo binario a un archivo de texto con formato de longitud variable*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargar_archivo(char *path);

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}t_producto;


int main()
{
    char *prodBin= "productos.dat";
    char *prodTxt= "productos.txt";

    if(!cargar_archivo(prodBin))
        return 1;

    FILE *archBin = fopen(prodBin, "rb");
    FILE *archTxt = fopen(prodTxt, "wt");

    if(!archBin)
        return 1;
    if(!archTxt)
        return 1;

    t_producto prod;

    char texto[100];
    strcpy(texto, "%04d|%s|%05.2f\n");

    fread(&prod, sizeof(t_producto),1,archBin);

    while(!feof(archBin))
    {
        printf("%d %s %.2f\n", prod.cod, prod.desc, prod.precio);

        fprintf(archTxt,texto, prod.cod, prod.desc, prod.precio);

        fread(&prod, sizeof(t_producto),1,archBin);
    }

    fclose(archBin);
    fclose(archTxt);

    system("pause");
    return 0;
}




int cargar_archivo(char *path)
{
    FILE *pf = fopen(path, "wb");

    if(!pf)
        return 0;

    t_producto prod_vec[] = {
                        {1,"LECHE",60},
                        {2,"HARINA",50},
                        {3,"ARROZ",40},
                        {4,"POLENTA",40},
                        {5,"LENTEJAS",30},
                        {6,"LEVADURA",8},
                        };

    fwrite(&prod_vec, sizeof(prod_vec),1,pf);

    fclose(pf);

    return 1;
}

