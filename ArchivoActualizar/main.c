
#include "alumno.h"


int main()
{
    char * path = "ALUMNOS.dat";

    //intentaremos guardar el archivo en la siguiente funcion
    //y que me devuelva un entero para ver si logró hacerlo
    if(!cargarArchivo(path, "wb"))
    {
        printf("No se pudo cargar el archivo!");
        return 1;
    }


    if(!leerArchivo(path, "rb"))
        return 1;

    printf("\n\nProcedemos a cambiar el archivo.."
            "\nAlumnos con fecha de ingreso menor al anio 2000, tendran estado Inactivo(I)\n");


    //FINALMENTE AQUI ACTUALIZAMOS EL ARCHIVO Y LO VOLVEMOS A GUARDAR
    t_alumno alu;
    FILE *pf;

    pf=fopen(path, "r+b");

    if(!pf)
        {
            printf("no se pudo abrir el archivo");
            return 1;
        }

    fread(&alu, sizeof(t_alumno),1,pf);

    while(!feof(pf))
    {
        if(alu.fecha.a<2000)
        {
            alu.estado= 'I';
            fseek(pf, -sizeof(t_alumno),SEEK_CUR);
            fwrite(&alu, sizeof(t_alumno),1,pf);
            fseek(pf,0, SEEK_CUR);
        }
        fread(&alu, sizeof(t_alumno),1,pf);
    }
    fclose(pf);



    printf("\n\nArchivo actualizado.\n");

    if(!leerArchivo(path, "rb"))
        return 1;

    puts("");
    system("pause");
    return 0;
}


