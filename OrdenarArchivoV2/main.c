#include "alumno.h"

int main()
{
    //primero crearemos el archivo binario desordenado
    char *path = "alumnos.dat";

    FILE *pf=fopen(path, "wb");
    if(!pf)
        return 1;
    t_alumno vec[]=    {
                            {3333, "alicia"},
                            {5555, "damian"},
                            {8888, "robertina"},
                            {1111, "celeste"},
                            {2222, "micaela"},
                            {4444, "horacio"},
                            {7777, "alejandro"},
                            {6666, "juan"},
                            };

    //esto me da la cantidad de registros creados, en este caso me dara ce=8
    int ce= sizeof(vec)/sizeof(t_alumno);
    fwrite(&vec, sizeof(vec),1,pf);
    fclose(pf);



    //ahora vamos a actualizar el archivo
    pf= fopen(path, "r+b");
    ordenar(vec, ce);

    //la funcion ordenar me devuelve un puntero del tipo t_alumno ya ordenado, con fwrite lo vuelvo a guardar(a vec)
    fwrite(&vec, sizeof(vec), 1, pf);

    fclose(pf);


    if(!leer_arch_ord(path))
        return 1;

    system("pause");
    return 0;
}

