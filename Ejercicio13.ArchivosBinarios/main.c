
#include "empleadosyestudiantes.h"

int main()
{
    char * pathEmp= "EMPLEADOS.dat";
    char * pathEst= "ESTUDIANTES.dat";

    if(!cargarArchivos(pathEmp,  pathEst))
        return 1;

    t_empleado emp;
    t_estudiante est;

    FILE * arch1;
    FILE * arch2;

    //el unico archivo que actualizo es el de empleados. el otro solo lo leo para ver promedios
    arch1= fopen(pathEmp, "r+b");
    arch2= fopen(pathEst, "rb");

    //estos son comparadores por apellido y por nombre
    int cmpAp;
    int cmpNom;

    //empiezo leyendo el primer registro de cada archivo y los comparare entre si
    fread(&emp, sizeof(t_empleado),1,arch1);
    fread(&est, sizeof(t_estudiante),1,arch2);

    //dentro de este gran while hare todas las comparacios correspondientes
    //primero por apellido, luego por nombre, y finalmente por dni
    //dado el caso de igualdad entre estas tres cosas, evalúo el promedio para actualizar sueldo
    while(!feof(arch1) && !feof(arch2))
    {
        cmpAp = strcmp(emp.apellido, est.apellido);
        cmpNom= strcmp(emp.nombre , est.nombre);

        compararApellido(cmpAp, cmpNom, &emp, &est, arch1, arch2);
    }


    fclose(arch1);
    fclose(arch2);

    //finalmente leo el archivo actualizado
    printf("\nArchivo actualizado:\n");
    arch1=fopen(pathEmp,"rb");
    fread(&emp, sizeof(emp), 1, arch1);
    while(!feof(arch1))
    {
        printf("\n%d %-11s %-11s %.2lf", emp.dni, emp.apellido, emp.nombre, emp.sueldo);
        fread(&emp, sizeof(emp), 1, arch1);
    }
    fclose(arch1);

    printf("\n\n");
    system("pause");
    return 0;
}


