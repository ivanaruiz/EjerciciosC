#include "empleados.h"

int cargar_archivo(char * path)
{

t_empleado emp_vec[]=   {
                    {1, "carlos perez", {3,2,1998} },
                    {2, "alicia santillan", {15,4,2005} },
                    {3, "veronica diaz", {26,1,1997} },
                    {4, "diego duarte", {2,10,2002} },
                    {5, "rigoberta sanchez", {10,8,2015} },
                    };

FILE * pf = fopen(path,"wt");

if(!pf)
    return 0;

int cant_reg = sizeof(emp_vec)/sizeof(t_empleado);

for(int i=0; i< cant_reg; i++)
{
    fprintf(pf, "%02d%-19s%02d/%02d/%4d\n", emp_vec[i].leg, emp_vec[i].nya,
                                            emp_vec[i].fec.d, emp_vec[i].fec.m, emp_vec[i].fec.a);
}

fclose(pf);
return cant_reg;
}
