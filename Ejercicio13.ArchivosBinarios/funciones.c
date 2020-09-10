
#include "empleadosyestudiantes.h"

//en esta funcion se crearan ambos archivos desde 0, con todos los datos ya incorporados
int cargarArchivos(char * nomArchEmp, char *nomArchEst)
{
    FILE *pfEmp;
    pfEmp= fopen(nomArchEmp,"wb");

    if(!pfEmp)
    {
        printf("no se pudo abrir el archivo");
        return 0;
    }

    t_empleado vec_emp[]=   {
                            {222,"Alvarez","Belen",30000},
                            {112,"Balbin","Marcos",30000},
                            {444,"Diaz","Daniela",30000},
                            {111,"Duarte","Marcelo",30000},
                            {103,"Estevez","Camila",30000},
                            {123,"Estevez","Roberto",30000},
                            {777,"Fernandez","Maria",30000},
                            {555,"Gomez","Laura",30000},
                            {666,"Marmol","Lucas",30000},
                            {115,"Murillo","Sandra",30000},
                            {226,"Murillo","Sandra",30000},
                            {472,"Rodriguez","Laura",30000},
                            };

    fwrite(&vec_emp, sizeof(vec_emp),1,pfEmp);

    fclose(pfEmp);


    FILE *pfEst;
    pfEst= fopen(nomArchEst,"wb");

    if(!pfEst)
    {
        printf("no se pudo abrir el archivo");
        return 0;
    }

    t_estudiante vec_est[]=   {
                            {222,"Alvarez","Belen",9},
                            {444,"Diaz","Daniela",6},
                            {888,"Diaz","Pedro",7},
                            {111,"Duarte","Marcelo",8},
                            {101,"Estevez","Alicia",4},
                            {102,"Estevez","Americo",2},
                            {103,"Estevez","Camila",8},
                            {333,"Fernandez","Maria",8},
                            {777,"Fernandez","Maria",9},
                            {999,"Fernandez","Miguel",4},
                            {555,"Gomez","Laura",9},
                            {666,"Marmol","Lucas",4},
                            {226,"Murillo","Sandra",8},
                            {552,"Tapia","Roxana",8},
                            {515,"Zarate","Cintia",8},
                            };

    fwrite(&vec_est, sizeof(vec_est),1,pfEst);

    fclose(pfEst);

    return 1;

}



////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////




void compararApellido(int cmpAp, int cmpNom, t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2)
{
    if(cmpAp==0)
    {
        compararNombre(cmpNom, emp, est, arch1, arch2);
    }

    //los siguientes casos es cuando los apellidos son distintos

    else if(cmpAp>0) //si pasa por aca es porque solo debo avanzar con el archivo de estudiantes
    {
        fread(est, sizeof(t_estudiante),1,arch2);
    }
    else    //si paso por aca es cmpAp<0, es decir que el registro de est es menor, asi que debo leer a emp
    {
        fread(emp, sizeof(t_empleado),1,arch1);
    }
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void compararNombre(int cmpNom, t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2)
{
    if(cmpNom==0)
    {
        compararDni(emp, est, arch1, arch2);

    }
    //en estos dos casos, tienen el apellido igual pero los nombres son distintos, asi que comparo cual avanzara primero
    else if(cmpNom>0)
        fread(est, sizeof(t_estudiante),1,arch2);
    else
        fread(emp, sizeof(t_empleado),1,arch1);
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


void compararDni(t_empleado *emp, t_estudiante *est, FILE * arch1, FILE* arch2)
{
    if(emp->dni==est->dni)
    {
        if(est->promedio>7) //llegados acá, encontramos el empleado que es estudiante y tiene prom>7, actualizamos
        {
            emp->sueldo+= emp->sueldo*7.28/100;
            fseek(arch1,-sizeof(t_empleado), SEEK_CUR);
            fwrite(emp, sizeof(t_empleado),1,arch1);
            fseek(arch1,0, SEEK_CUR);
        }

        //resultó ser la misma persona,
        //pero tanto si el prom fue >7 o <7, ahora debemos leer los sig dos registros
            fread(emp, sizeof(t_empleado),1,arch1);
            fread(est, sizeof(t_estudiante),1,arch2);


    }//eran diferentes personas, con igual nombre y apellido, pero distinto dni
    else if(emp->dni>est->dni)
        fread(est, sizeof(t_estudiante),1,arch2);

    else
        fread(emp, sizeof(t_empleado),1,arch1);

}



