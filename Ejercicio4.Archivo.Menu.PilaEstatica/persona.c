#include "persona.h"


int grabar_desde_cero(t_pila * p, char * path)
{
    FILE* pf= fopen(path, "wb");
    if(!pf)
        return 0;

   t_persona leer;

    while(!pila_vacia(p))
    {
        sacar_de_pila(p, &leer, sizeof(t_persona) );

        fwrite(&leer, sizeof(t_persona),1,pf);

    }

    fclose(pf);
    return 1;
}

//////////////////////////////////////////
//////////////////////////////////////////

int leer_arch( char* path, char * modo_de_lectura)
{
    FILE * pf= fopen(path, modo_de_lectura);
    if(!pf)
        return 0;
    t_persona pers;

    fread(&pers, sizeof(t_persona),1,pf);
    int hay_registros=0;

    while(!feof(pf))
    {
        hay_registros=1;
        printf("%d %s\n", pers.dni, pers.nya);
        fread(&pers, sizeof(t_persona),1,pf);
    }

    fclose(pf);

    if(hay_registros==0)    //si el archivo quedó sin registros, entonces borro el archivo
        remove(path);

    return 1;
}


//////////////////////////////////////////
//////////////////////////////////////////

void menu()
{
    printf("Que desea hacer?: ");
    printf("\n1) cargar mas datos en la pila"
           "\n2) ver tope de pila"
           "\n3) sacar de pila un elemento"
           "\n4) sacar y ver todos los elementos"
           "\n5) vaciar pila"
           "\n6) salir"
           "\nOpcion elegida: ");
}

//////////////////////////////////////////
//////////////////////////////////////////

int crear_arch_bin(char * path, char * modo_de_escritura)
{
    FILE * pf= fopen(path, modo_de_escritura);
    if(!pf)
        return 0;

    t_persona pers[] =  {
                        {1, "freddie mercury"},
                        {2, "robert smith"},
                        {3, "martin gore"},
                        {4, "siouxsie sioux"},
                        };
    fwrite(&pers, sizeof(pers),1,pf);
    fclose(pf);
    return 1;
}

//////////////////////////////////////////
//////////////////////////////////////////

void actualizar_arch(t_pila * p, char * path)
{
    t_persona leer;

    while(!pila_vacia(p))
    {
        sacar_de_pila(p, &leer, sizeof(t_persona));

        if(!buscar_en_arch(&leer, path))
            printf("no se encontro\n");
    }
}

//////////////////////////////////////////
//////////////////////////////////////////

int buscar_en_arch(t_persona * pers_leer, char * path)
{
    FILE *pf= fopen(path, "r+b");
    if(!pf)
        return 0;

    t_persona pers;

    int existe=0;

    fread(&pers, sizeof(t_persona),1,pf);

    while(!feof(pf))
    {
        if(pers_leer->dni == pers.dni)
            existe=1;

        fread(&pers, sizeof(t_persona),1,pf);
    }

    if(existe==0)
        fwrite(pers_leer, sizeof(t_persona),1,pf);


    fclose(pf);
    return 1;
}
