#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,m,a;
}t_fecha;

typedef struct
{
    int leg;
    char nya[20];
    t_fecha fec;
}t_empleado;


int cargar(char * path, char * modoApertura);


int main()
{
    char * path = "alumnos.txt";

    if(!cargar(path, "wt"))
        return 1;


    FILE * fp = fopen(path, "rt");
    if(!fp)
        return 1;

    char linea[100];


    while(fgets(linea, 100, fp))
    {
        printf("%s", linea);
    }

    fclose(fp);

    system("pause");
    return 0;
}

///////////////////////////////////////////////////////


int cargar(char * path, char * modoApertura)
{
    FILE * fp= fopen(path, modoApertura);
    if(!fp)
        return 0;

    t_empleado emp_vec[]=   {
                    {1, "carlos perez", {3,2,1998} },
                    {2, "alicia santillan", {15,4,2005} },
                    {3, "veronica diaz", {26,1,1997} },
                    {4, "diego duarte", {2,10,2002} },
                    {5, "rigoberta sanchez", {10,8,2015} },
                    };

    for(int i=0; i<sizeof(emp_vec)/sizeof(t_empleado); i++)
    {

    fprintf(fp, "%d %19s %02d/%02d/%4d\n", emp_vec[i].leg, emp_vec[i].nya,
                                        emp_vec[i].fec.d, emp_vec[i].fec.m, emp_vec[i].fec.a );
    }
    fclose(fp);
    return 1;
}
