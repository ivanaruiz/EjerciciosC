#include "suma_de_pilas.h"
#include "pila_dinamica.h"

/*Hace una suma de pilas y guarda el resultado en un txt*/
int main()
{

    int vec1[]={9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8};
    int vec2[]=      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8};


    t_pila p1, p2, pRES;

    crear_pila(&p1);
    crear_pila(&p2);
    crear_pila(&pRES);

    for(int i=0; i<sizeof(vec1)/sizeof(int) ; i++)
    {
        if(!poner_en_pila(&p1, &vec1[i], sizeof(int)))
            return 1;
    }

    for(int i=0; i<sizeof(vec2)/sizeof(int) ; i++)
    {
        if(!poner_en_pila(&p2, &vec2[i], sizeof(int)))
            return 1;
    }

    sumar(&p1,&p2,&pRES);



    FILE *pf;
    abrir_archivo(&pf, ARCHIVO_PATH, "wt");

    guardar_suma_en_txt(pf, &pRES);

    fclose(pf);


    system("pause");
    return 0;
}


