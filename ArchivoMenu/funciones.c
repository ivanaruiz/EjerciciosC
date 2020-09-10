#include "productos.h"


void menu()
{
    printf("\n1. Crear archivo \n2. Leer archivo \n3. Modificar archivo \n4. Salir");
    printf("\nQue desea hacer?: ");
}




int crear(char * path)
{
    t_producto prod;
    FILE *pf;

    pf= fopen(path, "wb");

    if(!pf)
    {
        printf("no se puede abrir archivo");
        return FALSO;
    }

    do
    {
        printf("Ingresar codigo: ");
        scanf("%d", &prod.cod);
            if(prod.cod==FALSO)
                break;   //no retorno un FALSO en este caso porque sino me tira un error
                                //en el main debido al if
        printf("Ingresar producto: ");
        fflush(stdin);
        gets(prod.desc);
        printf("Ingresar precio: ");
        scanf("%f", &prod.precio);

        fwrite(&prod, sizeof(t_producto), 1, pf);
    }while(prod.cod!=FALSO);

    printf("\nArchivo creado.");
    fclose(pf);

    return VERDADERO;
}



int leer(char *path)
{
FILE *pf;
pf= fopen(path, "rb");
t_producto prod;

if(!pf)
{
    printf("no se pudo abrir el archivo");
    return FALSO;
}
fread(&prod, sizeof(t_producto),1, pf);
while(!feof(pf))
{
    printf("\n%2d %15s %8.2f", prod.cod, prod.desc, prod.precio);
    fread(&prod, sizeof(t_producto),1, pf);
}

fclose(pf);
return VERDADERO;
}


int modificar(char *path)
{
    int seencuentra= FALSO;
    int cod;
    float pre;
    printf("\nIngrese el codigo del producto que desea cambiar: ");
    fflush(stdin);
    scanf("%d", &cod);


    t_producto prod;
    FILE *pf;
    pf=fopen(path, "r+b");

    if(!pf)
    {
        printf("no se pudo abrir el archivo");
        return FALSO;
    }

    fread(&prod, sizeof(t_producto),1, pf);
    while(!feof(pf))
    {
        if(prod.cod == cod)
        {
            seencuentra= VERDADERO;
            printf("\nIngrese nuevo precio a modificarle: ");
            scanf("%f", &pre);

            prod.precio= pre;
            fseek(pf, -sizeof(t_producto), SEEK_CUR);
            fwrite(&prod, sizeof(t_producto),1,pf);
            fseek(pf, 0, SEEK_CUR);
        }

        fread(&prod, sizeof(t_producto),1, pf);
    }

    if(!seencuentra)
        printf("No se encuentra el producto");

    fclose(pf);
    return VERDADERO;
}
