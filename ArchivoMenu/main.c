#include "productos.h"

int main()
{
    int opc;
    char * path= "PROD.dat";

    menu();

    do
    {
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1: if(!crear(path))
                {
                    printf("\nno se pudo realizar");
                    return 1;
                }
                printf("\n");
                system("pause");
                break;

        case 2: if(!leer(path))
                {
                     printf("\nno se pudo realizar");
                     return 1;
                }
                printf("\n");
                system("pause");
                break;

        case 3: if(!modificar(path))
                {
                    printf("no se pudo realizar");
                    return 1;
                }
                printf("\n");
                system("pause");
                break;


        case 4:     printf("\n\tAdios.\n");
                    system("pause");
                    return 1;

        default:    printf("\nNada por hacer.\n");
    }
    printf("\n");

    menu();

    } while(opc!= 4);


    system("pause");
    return 0;
}







