#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nya[10];
}t_alumno;

int cmp_dni(const void *a1, const void * a2);
int crear(char * path, char * modoApertura);
void intercambio(void * vec, void * men, size_t tam);
void * buscarMenor(void * vec, void * fin, size_t tam, int (*cmp)(const void *, const void *));
void * ord_x_sel(void * vec, size_t ce, size_t tamInfo,
                 int (*cmp)(const void *, const void *));

/*Creamos un archivo binario con datos (desordenados) de alumnos.
Luego lo leemos desde el main y lo ordenamos por dni con metodo de seleccion.
El ordenamiento lo hacemos con datos genéricos.
Finalmente actualizamos el archivo. */

int main()
{
    char * path = "alumnos.dat";

    if(!crear(path, "wb"))
        return 1;


    FILE * fp=fopen(path, "r+b");
    if(!fp)
        return 1;

    t_alumno alu[20];   //20 es un num por default, ya que desconozco la estructura del archivo

    int ce=0;   //este será realmente la cantidad de registros que haya


    //hago la lectura del archivo y lo guardo en esta vector de struct
    printf("Archivo con estructura desordenada:\n");
    fread(&alu[ce], sizeof(t_alumno),1,fp);
    while(!feof(fp))
    {
        printf("%d %9s\n", alu[ce].dni, alu[ce].nya);
        ce++;
        fread(&alu[ce], sizeof(t_alumno),1,fp);
    }

    //ahora ordeno la estructura
    ord_x_sel(&alu, ce, sizeof(t_alumno), cmp_dni);

    //vuelvo al inicio del archivo porque voy a guardar la estructura ya ordenada
    fseek(fp, 0, SEEK_SET);

    //finalmente actualizo el archivo
    for(int i=0; i<ce ; i++)
        fwrite(&alu[i], sizeof(t_alumno),1,fp);


    //nuevamente retrocedo en el archivo hasta el inicio, ahora voy a leer los datos desde alli
    //para comprobar que el archivo quedó correctamente guardado y ordenados
    rewind(fp);
    t_alumno alus;

    printf("\n\nArchivo ordenado genericamente por seleccion:\n");
    fread(&alus, sizeof(t_alumno),1,fp);
    while(!feof(fp))
    {
        printf("%d %9s\n", alus.dni, alus.nya);
        fread(&alus, sizeof(t_alumno),1,fp);
    }
    fclose(fp);

    system("pause");
    return 0;
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


void * ord_x_sel(void * vec, size_t ce, size_t tamInfo,
                 int (*cmp)(const void *, const void *))
{
    void * ini = vec;
    void * fin = vec+ (ce-1)*tamInfo;
    void * men;

    while(vec<fin)
    {
        men = buscarMenor(vec, fin, tamInfo, cmp);
        intercambio(vec, men, tamInfo);
        vec+=tamInfo;
    }

    return ini;
}


void * buscarMenor(void * vec, void * fin, size_t tam, int (*cmp)(const void *, const void *))
{
    void * men = vec;
    vec+=tam;

    while(vec<=fin)
    {
        if(cmp(vec,men)<0)
            men= vec;

        vec+=tam;
    }
    return men;
}


void intercambio(void * vec, void * men, size_t tam)
{
    void * aux = malloc(tam);
    memcpy(aux, vec, tam);
    memcpy(vec, men, tam);
    memcpy(men, aux, tam);
    free(aux);
}


int cmp_dni(const void *a1, const void * a2)
{
    const t_alumno * e1 = (const t_alumno*)a1;
    const t_alumno * e2 = (const t_alumno*)a2;
    return e1->dni - e2->dni;
}


int crear(char * path, char * modoApertura)
{
    FILE *fp = fopen(path, modoApertura);
    if(!fp)
        return 0;

    t_alumno alu_vec[]=    {
                        {3333, "alicia"},
                        {5555, "damian"},
                        {8888, "robertina"},
                        {1111, "celeste"},
                        {2222, "micaela"},
                        {4444, "horacio"},
                        {7777, "alejandro"},
                        {6666, "juan"},
                        };

    fwrite(&alu_vec, sizeof(alu_vec),1,fp);

    fclose(fp);
    return 1;
}
