#include "alumno.h"


t_alumno* ordenar(t_alumno *vec, int ce)
{
    t_alumno *ini= vec;
    t_alumno *fin= vec+ce-1;
    t_alumno *men;

    while(vec < fin)
    {
        men= buscar(vec, fin);

        if(vec!=men)
            intercambio(vec, men);

        vec++;
    }

    return ini;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


t_alumno *buscar(t_alumno *vec, t_alumno *fin)
{
    t_alumno *men;
    men= vec;
    vec++;

        while(vec<=fin)
        {
        if(vec->dni < men->dni)
            men= vec;

        vec++;
        }
    return men;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void intercambio(t_alumno *vec, t_alumno *men)
{
    t_alumno aux;
    aux= *vec;
    *vec= *men;
    *men= aux;

}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

int leer_arch_ord(char *path)
{
    FILE *pf;
    t_alumno alu;
    pf=fopen(path, "rb");
    if(!pf)
        return 0;

    fread(&alu, sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        printf("%d %s\n", alu.dni, alu.nya);
        fread(&alu, sizeof(t_alumno),1,pf);
    }

    fclose(pf);

    system("pause");
    return 1;
}

