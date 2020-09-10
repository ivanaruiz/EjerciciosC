#include <stdio.h>
#include <stdlib.h>

/*Programa que crea un archivo de texto desde cero, con datos de alfajores.
Luego abre el txt y pasa los datos a un archivo binario.
Finalmente leo el archivo binario.*/

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}t_alfajor;

int cargar(char * path, char * modoaper);


int main()
{
    char * pathTxt = "alfajores.txt";
    char * pathBin = "alfajores.dat";

    int cant_registros = cargar(pathTxt, "wt");

    if(!cant_registros)
        return 1;

    FILE * fpTxt = fopen(pathTxt, "rt");
    FILE * fpBin = fopen(pathBin, "w+b");   //ya que voy a grabar y también leer (sin cerrar archivo)

    if(!fpTxt || !fpBin)
        return 1;

    t_alfajor alf;

    //ojo con el fscanf, en el "" no uso el mismo formato sino mas simple
    for(int i=0; i<cant_registros; i++)
    {
        fscanf(fpTxt, "%d%19[^\n]%f", &alf.cod, alf.desc, &alf.precio);
        fwrite(&alf, sizeof(t_alfajor),1, fpBin);
    }

    fclose(fpTxt);

    //retrocedo el archivo binario y lo leo
    rewind(fpBin);

    fread(&alf, sizeof(t_alfajor),1,fpBin);
    while(!feof(fpBin))
    {
        printf("%d %19s %05.2f\n", alf.cod, alf.desc, alf.precio);
        fread(&alf, sizeof(t_alfajor),1,fpBin);
    }

    fclose(fpBin);

    system("pause");
    return 0;
}


int cargar(char * path, char * modoaper)
{
    FILE * fp=fopen(path, modoaper);
    if(!fp)
        return 0;

    t_alfajor vec_alf[]=  {
                            {1,"JORGITO",20},
                            {2,"GUAYMALLEN",5},
                            {3,"MILKA",25},
                            {4,"HAVANNA",40},
                            {5,"SUCHARD",30},
                            };

    int cant_reg = sizeof(vec_alf)/sizeof(t_alfajor);

    for(int i=0; i<sizeof(vec_alf)/sizeof(t_alfajor); i++)
    {
        fprintf(fp, "%d%19s%5.2f\n", vec_alf[i].cod, vec_alf[i].desc, vec_alf[i].precio);
    }

    fclose(fp);
    return cant_reg;
}
