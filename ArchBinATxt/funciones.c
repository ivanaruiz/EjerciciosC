#include "productos.h"

int cargar_archivo(char * path)
{
    FILE *pf = fopen(path, "wb");

    if(!pf)
        return 0;

    t_producto vec_prod[]=  {
                            {1,"BANANAS",70},
                            {2,"NARANJAS",60},
                            {3,"MANZADAS",50},
                            {4,"POMELOS",60},
                            {5,"TOMATES",50},
                            };

    fwrite(&vec_prod, sizeof(vec_prod),1, pf);

    fclose(pf);

    return 1;
}
