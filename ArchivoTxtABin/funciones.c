#include "alfajor.h"


int leer_archivo_bin(char *path)
{
    FILE *pf;
    pf= fopen(path, "rb");
    if(!pf)
        return 0;
    t_alfajor alf;
    fread(&alf, sizeof(t_alfajor),1,pf);
    while(!feof(pf))
    {
        printf("%04d %-19s %05.2f\n", alf.cod, alf.desc, alf.precio);
        fread(&alf, sizeof(t_alfajor),1,pf);
    }
    fclose(pf);

    return 1;
}



int cargar_archivo(char * path)
{
    FILE *pf = fopen(path, "wt");

    if(!pf)
    {
        printf("no se puede abrir");
        return 0;
    }


    t_alfajor vec_alf[]=  {
                            {1,"JORGITO",20},
                            {2,"GUAYMALLEN",5},
                            {3,"MILKA",25},
                            {4,"HAVANNA",40},
                            {5,"SUCHARD",30},
                            };

    for(int i=0; i<sizeof(vec_alf)/sizeof(t_alfajor); i++)
    {
        fprintf(pf,"%04d%-19s%05.2f\n", vec_alf[i].cod, vec_alf[i].desc, vec_alf[i].precio);
    }

    fclose(pf);
    return 1;
}
