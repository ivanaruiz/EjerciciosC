
#include "archivos.h"


int leer_arch_prod(char *path)
{
    FILE *pf= fopen(path, "rb");
    if(!pf)
        return 0;
    t_producto prod;
    fread(&prod, sizeof(t_producto),1,pf);
    while(!feof(pf))
    {
        printf("%02d %-11s %5.2f %3d\n", prod.cod, prod.desc, prod.precio, prod.stock);
        fread(&prod, sizeof(t_producto),1,pf);
    }
    fclose(pf);

    return 1;
}



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



int crear_arch_mov(char * path)
{
    FILE *pf =fopen(path, "wb");
    if(!pf)
        return 0;

    t_producto vec_mov[]=   {
                            {2,"", 0,20},
                            {3,"", 0,-10},
                            {5,"", 0,-20},
                            {7,"", 0,15},
                            {11,"", 0,5},
                            {12,"", 0,-30},
                            {14,"", 0,10},
                            {15,"", 0,15},
                            {17,"", 0,-15},
                            };

    fwrite(&vec_mov, sizeof(vec_mov),1,pf);
    fclose(pf);
    return 1;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



int rellenar_campos_vacios(char *path)
{
    FILE  *pf=fopen(path, "r+b");
    if(!pf)
        return 0;

    t_producto prod;
    fread(&prod, sizeof(t_producto),1,pf);

    while(!feof(pf))
    {
        if(strcmp(prod.desc, "")==0)
        {
            printf("Ingrese detalle para producto cod %d: ", prod.cod);
            fflush(stdin);
            gets(prod.desc);
            printf("Ingrese precio para ese producto: ");
            scanf("%f", &prod.precio);

            fseek(pf, -sizeof(t_producto),SEEK_CUR);
            fwrite(&prod, sizeof(t_producto),1,pf);
            fseek(pf, 0, SEEK_CUR);
        }
        fread(&prod, sizeof(t_producto),1,pf);
    }

    fclose(pf);
    return 1;
}




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//aca voy a pasar los datos grabados en el archivo al vector para luego ordenar
//ademas arregleo el tema de los stocks que quedaron en negativo
//estos mismos son invalidos, asi que los seteo en 0
int pasar_a_vec(t_producto *vec, int ce, char *path)
{
    FILE *pf= fopen(path, "rb");
    if(!pf)
        return 1;

    t_producto prods;

        fread(&prods, sizeof(t_producto),1,pf);
    int i=0;
    puts("");
    while(!feof(pf))
    {
            vec[i].cod= prods.cod;
            strcpy(vec[i].desc, prods.desc);
            vec[i].precio= prods.precio;

            if(prods.stock<0)
                vec[i].stock=0;
            else
                vec[i].stock= prods.stock;

            fread(&prods, sizeof(t_producto),1,pf);
            i++;
    }
    fclose(pf);

    return 1;
}

