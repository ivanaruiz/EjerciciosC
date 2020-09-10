
#include "alumno.h"

int main()
{
    int cod;
    t_alumno alu;
    FILE* arch;
    arch= fopen("alumnos.dat", "wb");

    if(!arch)
        return 1;

    do
    {
        printf("Ingrese dni: ");
        fflush(stdin);
        scanf("%d", &alu.dni);
        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        gets(alu.nya);
        printf("Ingrese sexo: ");
        fflush(stdin);
        gets(&alu.sexo);

        guardarNotas(&alu);

        fwrite(&alu, sizeof(t_alumno),1,arch);

        printf("\n\n\tPara dejar de guardar registros ingrese 0. \n\tPara continuar guardando ingrese cualquier numero: ");

        fflush(stdin);
        scanf("%d", &cod);

        printf("\n----------------------------------\n");

    }while(cod!=0);

    fclose(arch);
    printf("\nArchivo guardado\n");

    system("pause");
    return 0;
}



void guardarNotas(t_alumno *alu)
{
    int i=0;
    float suma=0;

    do  {
        printf("Ingrese notas hasta ingresar nota 0 para salir: ");
        scanf("%d", &alu->notas[i]);
        suma+= alu->notas[i];
        i++;
        }while(alu->notas[i-1] !=0);    //notar que es i-1, porque anteriormente hice i++

    i--;    //hago esto para que no me guarde el 0 último que ingresó
    alu->prom= suma/i;
}
