#include "productos.h"

/*
Este programa crea un archivo binario.
Y luego lo lee y lo convierte a un archivo de texto con formato de longitud fija.
*/

int main()
{
    char * pathBin= "productos.dat";
    char * pathTxt= "productos.txt";

    //primero voy a crear el archivo binario de productos
    if(!cargar_archivo(pathBin))
        return 1;

    FILE * pfBin = fopen(pathBin, "rb");
    FILE * pfTxt = fopen(pathTxt, "wt");

    if(!pfBin && !pfTxt)
        return 1;


    t_producto prod;

    fread(&prod, sizeof(t_producto),1,pfBin);

    while(!feof(pfBin))
    {
        printf("%d %s %.2f\n", prod.cod, prod.desc, prod.precio);

        //en esta sig linea lo guardo en archivo de texto con formato de longitud fija
        fprintf(pfTxt,"%04d%-19s%05.2f\n", prod.cod, prod.desc,prod.precio);
        fread(&prod, sizeof(t_producto),1,pfBin);
    }

    fclose(pfBin);
    fclose(pfTxt);

    system("pause");
    return 0;
}

