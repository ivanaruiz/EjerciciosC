
#include "alumno.h"

int crear_arch_texto(char *path)
{
    FILE *pf =fopen(path,"wt");
    if(!pf)
        return 0;

    t_alumno alu_vec[]= {
                        {34567891,"Calaz Ezequiel",{1,4,2015},5},
                        {30000000,"Francisco Diego",{9,1,2010},8},
                        {39999999,"Gho Edgardo",{7,7,2017},8},
                        {23456789,"Guatelli Renata",{1,6,2006},10},
                        {29999999,"Htaniuk Jair",{17,4,2016},7},
                        {12345678,"Lopez Hector",{11,9,2003},8.50},
                        {20000000,"Maidana Carlos",{15,5,2002},6.50},
                        {35555555,"Pezzola Federico",{16,3,2016},9.33},
                        };

    int cant_reg= sizeof(alu_vec)/sizeof(t_alumno);

    int i;

    for(i=0; i<cant_reg; i++)
    {
        fprintf(pf, "%08d%-29s%02d%02d%4d%5.2f\n",
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




int leer_arch_bin(char *path)
{
    FILE*pf=fopen(path,"rb");
    if(!pf)
        return 0;
    t_alumno alu;

    fread(&alu , sizeof(t_alumno),1,pf);

    while(!feof(pf))
    {
        printf("%08d%-29s%02d%02d%4d%5.2f\n", alu.dni, alu.nya,
               alu.fec.d,alu.fec.m,alu.fec.a, alu.prom);

        fread(&alu , sizeof(t_alumno),1,pf);
    }

    fclose(pf);

    return 1;
}
