#include "pila_estatica.h"
#include "persona.h"


int main()
{
    char * path = "datos.dat";

    if(!crear_arch_bin(path, "wb"))
        return 1;

    FILE * pf = fopen(path, "rb");

    t_persona pers;

    t_pila p;

    crear_pila(&p);

    fread(&pers, sizeof(t_persona),1,pf);

    while(!feof(pf))
        {
        if(!poner_en_pila(&p, &pers, sizeof(t_persona)))
            return 1;

        fread(&pers, sizeof(t_persona),1,pf);
        }
    fclose(pf);


    t_persona pers_leer;


    int opc;
    menu();

    do{

    scanf("%d", &opc);

        switch(opc)
        {
        case 1:
                printf("ingrese dni: ");
                scanf("%d", &pers_leer.dni);
                printf("ingrese nombre: ");
                fflush(stdin);
                gets(pers_leer.nya);

                if(!poner_en_pila(&p, &pers_leer, sizeof(t_persona)))
                   printf("no se pudo cargar mas datos en la pila!\n");
                else
                    printf("\tcarga exitosa\n");
                break;

        case 2: if(ver_tope(&p, &pers_leer, sizeof(t_persona)))
                    printf("\t%d %s\n", pers_leer.dni, pers_leer.nya);

                break;

        case 3: if(sacar_de_pila(&p, &pers_leer, sizeof(t_persona)))
                    printf("\t%d %s\n", pers_leer.dni, pers_leer.nya);

                break;

        case 4: while(!pila_vacia(&p))
                {
                    if(sacar_de_pila(&p, &pers_leer, sizeof(t_persona)))
                        printf("\t%d %s\n", pers_leer.dni, pers_leer.nya);
                }
                break;

        case 5: while(!pila_vacia(&p))
                {
                    vaciar_pila(&p);
                }

                break;

        case 6: break;

        default: printf("\tNada por hacer.\n");
                break;
        }

        system("pause");
        system("cls");
        menu();

    }while(opc!=6);


    printf("Que desea hacer?\n"
           "1) Grabar el archivo desde cero con lo que haya en la pila\n"
           "2) Dejar el archivo como esta y solo grabar los nuevos registros que haya en la pila\n"
           "Cualquier otro numero) No grabar nada"
           "Opcion elegida: ");


    scanf("%d", &opc);

    if(opc==1)
    {
        if(!grabar_desde_cero(&p, path))
            return 1;

    }
    else if(opc==2)
    {
        actualizar_arch(&p, path);
    }



    if(!leer_arch(path, "rb"))
        return 1;




    system("pause");
    return 0;
}

