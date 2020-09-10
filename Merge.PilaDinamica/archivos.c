

#include "archivos.h"

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

int convertir_a_txt(char * path)
{
    FILE *pf= fopen(path, "rb");
    FILE *pftxt= fopen("PRODUCTOS_ACTUALIZADOS.txt", "wt");
    if(!pf || !pftxt)
        return 0;

    t_producto prod;
    fread(&prod, sizeof(t_producto),1,pf);

    while(!feof(pf))
    {
        fprintf(pftxt, "%02d %-11s %5.2f %2d\n", prod.cod, prod.desc, prod.precio, prod.stock);
        fread(&prod, sizeof(t_producto),1,pf);
    }

    printf("\nArchivo binario convertido a archivo de texto: PRODUCTOS_ACTUALIZADOS.txt\n");
    fclose(pf);
    fclose(pftxt);
    return 1;
}
