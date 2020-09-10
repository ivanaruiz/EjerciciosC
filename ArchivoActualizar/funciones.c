#include "alumno.h"


int cargarArchivo(char * path, char * modoApertura)
{
    //creamos un vector de estructura
    t_alumno alu_vec[]=
                {
                {11111, "Alicia Martinez", 'F', 8,{7,9}, {1,2,2005}, 'A'},
                {22222, "Martin Gomez", 'M', 5,{4,5,6}, {3,4,1999}, 'A'},
                {33333, "Roberto Ariel", 'M', 2,{2,2}, {1,7,1997}, 'A'},
                {44444, "Silvia Fuentes", 'F', 8.5,{8,9}, {1,5,2002}, 'A'},
                {55555, "Ximena Santos", 'F', 7,{6,8}, {1,9,1998}, 'A'},
                };

    FILE * pf;
    pf = fopen(path, modoApertura);

    if(!pf) //es igual a pf==0
    {
        printf("no se pudo abrir");
        return 0;
    }

    //los struct con vectores los puedo guardar de dos maneras:

    //1º forma:
    //fwrite(alu_vec, sizeof(t_alumno),5,pf);
    //aca leo el tam de la estructura y le digo que lea 5 registros

    //2º forma
    fwrite(alu_vec, sizeof(alu_vec),1,pf);
    //aca directamente le digo que lea el tamaño del vector, asi que lee 1 registro(el vector entero)

    fclose(pf);
    printf("Archivo cargado...");


    return 1;
}



int leerArchivo(char * path, char * modoApertura)
{
    t_alumno alu;

    FILE * pf = fopen(path, modoApertura);

    if(!pf)
    {
        printf("no se pudo abrir");
        return 0;
    }


    fread(&alu, sizeof(t_alumno),1,pf);

    while(!feof(pf))
    {
        printf("\n%d %20s %4c %5.2f %3d/%d/%d %4c", alu.dni, alu.nya, alu.sexo, alu.prom, alu.fecha.d, alu.fecha.m, alu.fecha.a, alu.estado);
        fread(&alu, sizeof(t_alumno),1,pf);
    }
    fclose(pf);




    return 1;
}
