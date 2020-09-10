#include "fibonacci.h"

int main()
{

    int num;

    printf("Ingrese numero: ");

    validar(&num);

    if( num==1 || fibonacci(num)==1 )
        printf("\n\n\t%d es fibonacci\n\n",num);
    else
        printf("\n\n\t%d NO es fibonacci\n\n",num);

    system("pause");
    return 0;
}






