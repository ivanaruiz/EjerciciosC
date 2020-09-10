#include "normalizar.h"

int main()
{
    char vec[TAM]= "!!,!pErEZ--,--pEdrO!!,!diEgo!!!,";

    printf("Cadena sin normalizar:\n%s\n", vec);

    normalizar(vec);

    printf("Cadena normalizada:\n%s\n", vec);

    system("pause");
    return 0;
}


