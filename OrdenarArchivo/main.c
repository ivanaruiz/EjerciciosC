#include "alumno.h"

int main()
{
    char *path = "alumnos.dat";

    FILE *pf=fopen(path, "wb");
    if(!pf)
        return 1;
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

    //esto me da la cantidad de registros creados, en este caso me dara ce=8
    int ce= sizeof(alu_vec)/sizeof(t_alumno);
    fwrite(&alu_vec, sizeof(alu_vec),1,pf);
    fclose(pf);


    //primero creo dos punteros del t_alumno, uno apuntara al inicio de vector, el otro al final
    t_alumno *ini = alu_vec;
    t_alumno *fin = alu_vec +ce -1;

    //necesito dos estructuras, una sera alu, que sera la que avance buscando al menor
    //y otra que sera menor, la cual se le guardara siempre un menor encontrado
    t_alumno alu;

    //cr= es cantidad de registros, esta variabla la uso por los fseek
    //ya que en la primera vuelta al abrir el archivo solo necesitamos hacer una sola lectura de alu
    //pero en las siguientes vueltas el primer registro ya quedó ordenado(sera el menor), asi que necesitaremos
    //leer dos veces a alu, para leer el siguiente registro, por eso cr ira incrementando

    int cr=1;

    while(ini<fin)
    {
    //en cada nueva vuelta se vuelve a abrir el archivo desde cero
    pf=fopen("alumnos.dat", "r+b");

    for(int i=0; i<cr; i++)
        fread(&alu, sizeof(t_alumno),1,pf);

    //por defecto al primer registro ya lo tomo como menor
    t_alumno men= alu;

    buscar_menor_y_actualizar(pf, &alu, &men, cr);

    fclose(pf);

    ini++;
    cr++;
    }


    if(!leer_arch_ord(path))
        return 1;

    system("pause");
    return 0;
}
