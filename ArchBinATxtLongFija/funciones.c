#include "productos.h"

int cargar_archivo(char * path)
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
