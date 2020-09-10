#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int d, m, a;
}t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    t_fecha f_ing;
    char estado;
} t_alumno;

int cargar_archivo(char * path);
int leer_alumno_de_arch(FILE* pf, t_alumno * alu);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FILE * pf;
    t_alumno alu;

    char texto[54];
    if(!cargar_archivo("alus.txt"))
    {
        printf("No se pudo cargar el archivo");
        return 1;
    }
    pf = fopen("alus.txt", "rt");
    if(!pf)///if(pf == NULL)
    {
        printf("No se pudo abrir el archivo");
        return 1;
    }
//    while(fgets(texto, sizeof(texto), pf))
//    {
//        if(!strchr(texto, '\n'))
//        {
//            return 2;
//        }
//        sscanf(texto, "%8d%29[^\n]%c%5f%2d%2d%4d%c",
//                &alu.dni,
//                alu.apyn,
//                &alu.sexo,
//                &alu.promedio,
//                &alu.f_ing.d,
//                &alu.f_ing.m,
//                &alu.f_ing.a,
//                &alu.estado);
//
//        printf("%d %s %c %.2f %02d/%02d/%4d %c\n",
//                alu.dni,
//                alu.apyn,
//                alu.sexo,
//                alu.promedio,
//                alu.f_ing.d,
//                alu.f_ing.m,
//                alu.f_ing.a,
//                alu.estado);
//    }
    while(leer_alumno_de_arch(pf, &alu))
    {
        printf("%d %s %c %.2f %02d/%02d/%4d %c \n",
                alu.dni,
                alu.apyn,
                alu.sexo,
                alu.promedio,
                alu.f_ing.d,
                alu.f_ing.m,
                alu.f_ing.a,
                alu.estado);
    }

    fclose(pf);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int leer_alumno_de_arch(FILE* pf, t_alumno * alu)
{
    return fscanf(pf, "%8d%29[^\n]%c%5f%2d%2d%4d%c\n",
                &alu->dni,
                alu->apyn,
                &alu->sexo,
                &alu->promedio,
                &alu->f_ing.d,
                &alu->f_ing.m,
                &alu->f_ing.a,
                &alu->estado) == 8;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



int cargar_archivo(char * path){
    t_alumno alu_vec[] = {
                        {90, "Sa, Lia", 'F', 7.5,{1,2,2005}, 'A'},
                        {98, "Jose Perez", 'M', 8, {1,2,1999}, 'A'},
                        {110, "Alumno uno", 'F', 7.5, {1,2,2005}, 'I'},
                        {120, "Alumno dos", 'M', 7.5, {1,2,2015}, 'A'},
                        {130, "Alumno tres", 'M', 8, {1,2,2000}, 'A'},
                        {140, "Alumno cuatro", 'F', 7.5, {1,2,1998}, 'A'},
                        {150, "Alumno cinco", 'F', 4, {1,2,1997}, 'A'},
                        };
    FILE * pf = fopen(path, "wt");
    int i;
    if(!pf)///if(pf == NULL)
    {
        return 0;
    }
    ///fwrite(alu_vec, sizeof(t_alumno), 7, pf);
    ///fwrite(alu_vec, sizeof(alu_vec), 1, pf);
    for (i=0;i<7;i++){
        fprintf(pf,"%08d%-29s%c%05.2f%02d%02d%4d%c\n",
                alu_vec[i].dni,
                alu_vec[i].apyn,
                alu_vec[i].sexo,
                alu_vec[i].promedio,
                alu_vec[i].f_ing.d,
                alu_vec[i].f_ing.m,
                alu_vec[i].f_ing.a,
                alu_vec[i].estado);
    }
//    for (i=0;i<7;i++){
//        fprintf(pf,"%d|%s|%c|%.2f|%02d/%02d/%4d|%c\n",
//                alu_vec[i].dni,
//                alu_vec[i].apyn,
//                alu_vec[i].sexo,
//                alu_vec[i].promedio,
//                alu_vec[i].f_ing.d,
//                alu_vec[i].f_ing.m,
//                alu_vec[i].f_ing.a,
//                alu_vec[i].estado);
//    }
    fclose(pf);
    return 1;
}
