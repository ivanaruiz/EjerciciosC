#include <stdio.h>
#include <stdlib.h>
/**
    streams - flujo
    FILE
*/
typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    int notas[50];
} t_alumno;
///typedef unsigned size_t;
//struct s_alumno
//{
//    int dni;
//    char apyn[30];
//    char sexo;
//    float promedio;
//    int notas[50];
//};
//
//typedef struct s_alumno t_alumno;
int main()
{
    FILE * pf;
//    struct s_alumno alu;
    t_alumno alu = {12345678, "Sa, Lia", 'F', 7.5, {7,8}};
    t_alumno alu2;
    t_alumno alu_vec[] = {
                        {12345678, "Sa, Lia", 'F', 7.5, {7,8}},
                        {23456789, "Jose Perez", 'M', 8, {7,8, 9}}
                        };
    pf = fopen("alus.dat", "wb");
    fwrite(alu_vec, sizeof(t_alumno), 2, pf);
    system("pause");
    fclose(pf);
    system("pause");
    pf = fopen("alus.dat", "rb");
    fread(&alu2, sizeof(t_alumno), 1, pf);
    printf("\n%s", alu2.apyn);

    fread(&alu2, sizeof(t_alumno), 1, pf);
    printf("\n%s", alu2.apyn);
    fclose(pf);


    return 0;
}
