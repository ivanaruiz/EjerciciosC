#include "empleado.h"

int cargar_archivo(char * path)
{

t_empleado emp_vec[]=   {
                    {1, "carlos perez", {3,2,1998} },
                    {2, "alicia santillan", {15,4,2005} },
                    {3, "veronica diaz", {26,1,1997} },
                    {4, "diego duarte", {2,10,2002} },
                    {5, "rigoberta sanchez", {10,8,2015} },
                    };

FILE *pf;

pf=fopen(path,"wt");

if(!pf)
{
    return 0;
}

int i;

//prestar atencion al formato
//el - significa que pongo del texto pegado a la parte izquierda
//los ceros son para completar
//ejemplo %02d significa que se imprimiran dos digitos, pero si es por un 4, rellena con 0. por ejemplo ->  04
for(i=0; i<5; i++)
{
    fprintf(pf, "%02d%-19s%02d%02d%4d\n", emp_vec[i].leg, emp_vec[i].nya,
                                            emp_vec[i].fec.d, emp_vec[i].fec.m, emp_vec[i].fec.a);
}

fclose(pf);
return 1;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////


int leer_archivo(FILE * pf, t_empleado *emp)
{
    return
    fscanf(pf,"%2d%19[^\n]%2d%2d%4d", &emp->leg, emp->nya, &emp->fec.d, &emp->fec.m, &emp->fec.a)==5;

    //fscanf devuelve un entero
    //el [^\n] se refiere a que lea y levante el texto hasta que encuentre el \n
    //el formato debe ser igual al que usamos para hacer fprintf al grabar el arch de texto
    //pero sin los ceros. tambien ojo con la cadena de texto. prestar atencion ahi
}

