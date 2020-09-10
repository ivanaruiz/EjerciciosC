#include "alumno.h"


int crear_arch_bin(char *path)
{
    FILE *pf = fopen(path, "wb");
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

    fwrite(&alu_vec, sizeof(alu_vec),1, pf);

    fclose(pf);
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
