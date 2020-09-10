#include "header.h"



int main()
{
    int vec[cel] =  {2,6,7,9,3,8};

    mostrar(vec,cel);

    int pos;
    ingresoPos(&pos, cel);

    borrar(vec, cel, pos-1);

    printf("\n\n");
    mostrar(vec,cel-1);  ///como borré una posicion, la ultima posicion ya no la muestro

    system("pause");
    return 0;
}
