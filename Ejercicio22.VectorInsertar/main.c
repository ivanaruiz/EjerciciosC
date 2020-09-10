///NO COMPLETO

#include <stdio.h>
#include <stdlib.h>
#define TAM    10

int main()
{
    int vec[TAM] = {};
    int cant = 0;

    mostrar(vec);



    printf("\ncantidad %d", cant);

    int n;
    int pos;

    do{

    printf("\ningresar numero: ");
    scanf("%d", &n);
    printf("ingresar posicion: ");
    scanf("%d", &pos);

    vec[pos-1]= n;

    mostrar(vec);
    cant++;
    printf("\ncantidad %d", cant);

        if(cant==TAM)
        {
            printf("\n\tVECTOR LLENO. ");
            break;
        }

    }   while(cant<=TAM);


    return 0;
}

void mostrar(int vec[])
{
     for(int i = 0; i<TAM; i++)
        printf("%d  ", vec[i]);
}





/*
    char vec[TAM] = {'-','-','-','-','-','-','-','-'};
    int cant = 5;

    mostrar(vec, cant);

    int n, pos;

    printf("\ningresar valor: ");
    scanf("%d",&n);
    printf("\ningresar posicion: ");
    scanf("%d",&pos);

    int cantidad;
    cantidad= ingresar(vec, n, pos, cant);



     mostrar(vec, cantidad);

    return 0;
}


void mostrar(int *vec, int posi)
{
     for(int i = 0; i<posi; i++)
        printf("%d  ", vec[i]);
}



int ingresar(int vec[], int n, int pos, int cant)
{
int aux= TAM;
int posi=pos;
        while(pos<=TAM)
        {
            vec[aux]= vec[aux-1];
            pos++;
            aux--;
        }

        vec[posi-1] = n;
    return posi;
}
*/
