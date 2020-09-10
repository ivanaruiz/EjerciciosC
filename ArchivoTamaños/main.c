#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    char desc[30];
    int stock;
    float precio;
}t_producto;


int main()
{
    int tam_arch, cant_reg;
    char * path= "PRODUCTOS.dat";

    t_producto prod[]=  {
                        {1, "leche", 40, 50},
                        {2, "arroz", 30, 40},
                        {3, "harina", 50, 45},
                        {4, "fideos", 40, 35},
                        {5, "gaseosa", 100, 80},
                        {6, "atun", 20, 60},
                        };


    FILE * pf;
    pf = fopen(path, "w+b");    //NOTAR QUE USAMOS w+b
                                //esto es porque vamos a crear un arch pero tambien lo leeremos

    if(!pf)
    {
        printf("no se pudo abrir");
        return 1;
    }

    //primero guardo el archivo
    fwrite(&prod, sizeof(prod), 1, pf);


    tam_arch= ftell(pf);    //me dice cuánto ocupa en bytes todo el struct con el vector de 6 registros
    cant_reg= tam_arch/sizeof(t_producto);


    printf("\nTamanio del struct: %d", tam_arch);
    printf("\nCantidad de registros: %d", cant_reg);


    //AHORA LEO EL ARCHIVO

    //USAREMOS FSEEK PARA IR AL INICIO DEL ARCHIVO
    //(notar que no cerramos el archivo despues de haber guardado registros
    fseek(pf, 0, SEEK_SET);
    //usar esto es lo mismo: rewind(pf);

    t_producto pro;

    fread(&pro, sizeof(t_producto), 1, pf);
    while(!feof(pf))
    {
        printf("\n%d %10s %5d %7.2f", pro.cod, pro.desc, pro.stock, pro.precio);
        fread(&pro, sizeof(t_producto), 1, pf);
    }


    fclose(pf);

    system("pause");
    return 0;
}
