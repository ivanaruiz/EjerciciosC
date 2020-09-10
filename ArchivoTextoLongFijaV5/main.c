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

    int cant_reg = cargar(path, "wt");

    if(!cant_reg)
        return 1;


    FILE * fp = fopen(path, "rt");
    if(!fp)
        return 1;

    t_empleado emp;

    //el fscanf tiene el mismo formato que el fprintf, solo cambio la s por [^\n]
    //la función me devuelve un entero
    //por eso lo igual a la cantidad de registros que tengo
    //en caso de coincidir, entonces printeo correctamente

    while(fscanf(fp, "%d%19[^\n]%02d%02d%4d", &emp.leg, emp.nya, &emp.fec.d, &emp.fec.m, &emp.fec.a)==cant_reg)
    {
        printf("%d %s %02d/%02d/%4d\n", emp.leg, emp.nya, emp.fec.d, emp.fec.m, emp.fec.a);
    }

    fclose(fp);

    system("pause");
    return 0;
}

//////////////////////////////////////

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

    fprintf(fp, "%d%19s%02d%02d%4d\n", emp_vec[i].leg, emp_vec[i].nya,
                                        emp_vec[i].fec.d, emp_vec[i].fec.m, emp_vec[i].fec.a );
    }

    //me guardo la cantidad de registros que grabo y devuelvo esa cantidad
    int cant_reg = sizeof(emp_vec)/sizeof(t_empleado);

    fclose(fp);

    return cant_reg;
}
