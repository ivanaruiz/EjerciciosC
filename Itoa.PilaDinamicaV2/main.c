
#include "pila.h"


void mi_itoa(tPila * p, int num, int base);
char toAscii(int resto, int base);


int main()
{
    int num = 7346346;
    char cad[20];
    int base= 16;

    printf("NUMERO: %d. BASE: %d\n\n", num, base);

    printf("ITOA FUNCION ORIGINAL. PARA COMPARAR CON LA NUESTRA:\n");
    itoa(num, cad, base);
    printf("%s\n", cad);

    tPila p;
    crearPila(&p);

    printf("\nMI VERSION DE ITOA CON PILA DINAMICA:\n");
    mi_itoa(&p, num, base);

    char elem;
    while(!pilaVacia(&p))
    {
        sacarDePila(&p, &elem, sizeof(char));
        printf("%c", elem);
    }

    puts("");
    system("pause");
    return 0;
}

/////////////////FUNCIONES


void mi_itoa(tPila * p, int num, int base)
{
    char elem;
    while(num>0)
    {
        elem = toAscii(num%base, base);
        ponerEnPila(p, &elem, sizeof(char));
        num= num/base;
    }
}


char toAscii(int resto, int base)
{
    if(base==16 && resto>9)
        return resto + '0' + 7;
    return resto+'0';
}
