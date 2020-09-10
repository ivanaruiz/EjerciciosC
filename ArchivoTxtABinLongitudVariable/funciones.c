#include "alumno.h"


int crear_arch_texto(char *path)
{
    FILE *pf= fopen(path, "wt");

    if(!pf)
        return 0;

    t_alumno alu_vec[]= {
                        {34567891,"Calaz Ezequiel",{1,4,2015},5},
                        {30000000,"Francisco Diego",{9,1,2010},8},
                        {39999999,"Gho Edgardo",{7,7,2017},8},
                        {23456789,"Guatelli Renata",{1,6,2006},10},
                        {29999999,"Htaniuk Jair",{17,4,2016},7},
                        {12345678,"Lopez Hector",{11,9,2003},8.50},
                        {20000000,"Maidana Carlos",{15,10,2008},9},
                        {35555555,"Pezzola Federico",{16,3,2016},9.33},
                        };
    int i;
    for(i=0; i<sizeof(alu_vec)/sizeof(t_alumno) ; i++)
    {
        fprintf(pf, "%08d|%s|%02d|%02d|%4d|%05.2f\n",
                    alu_vec[i].dni,
                    alu_vec[i].nya,
                    alu_vec[i].fec.d,
                    alu_vec[i].fec.m,
                    alu_vec[i].fec.a,
                    alu_vec[i].prom);
    }


    fclose(pf);
    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void separar_campos(char *texto, t_alumno *alu)
{
    //strrchr es una funcion que busca en la cadena de texto, el ultimo '\n',
    //que sera el final de la cadena
    char *aux;
    aux= strrchr(texto, '\n');
    *aux= '\0';

    //aca strrchr busca al ultimo pipe, que viene antes de promedio
    //a alu->prom se le asignara lo que viene luego del ultimo pipe, que es el %5f de prom
    //sscanf entonces asigna ese float a alu->prom, y luego al pipe lo pisa con un contrabarra cero
    aux=strrchr(texto, '|');
    sscanf(aux+1, "%5f", &alu->prom);
    *aux= '\0';


    aux=strrchr(texto, '|');
    sscanf(aux+1, "%4d", &alu->fec.a);
    *aux= '\0';

    aux=strrchr(texto, '|');
    sscanf(aux+1, "%2d", &alu->fec.m);
    *aux= '\0';

    aux=strrchr(texto, '|');
    sscanf(aux+1, "%2d", &alu->fec.d);
    *aux= '\0';

    aux=strrchr(texto, '|');
    strcpy(alu->nya, aux+1);
    *aux= '\0';

    //como ya no quedo nada mas que el dni en texto, entonces directamente lo asigno a alu->dni
    sscanf(texto, "%d", &alu->dni);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


int leer_arch_bin(char *path)
{
    FILE *pf = fopen(path, "rb");

    if(!pf)
        return 0;

    t_alumno alu;

    fread(&alu, sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        printf("%08d|%s|%02d|%02d|%4d|%05.2f\n",alu.dni,alu.nya,alu.fec.d,
                alu.fec.m,alu.fec.a,alu.prom);
        fread(&alu, sizeof(t_alumno),1,pf);
   }
   fclose(pf);
   return 1;
}
