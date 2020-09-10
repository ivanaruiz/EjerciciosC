/* Imprimir por pantalla, bien tabulado y en 3 columnas la tabla ascii, indicando el valor char,
el valor decimal y el valor hexa de la variable */

#include <stdio.h>
#include <stdlib.h>

int main()
{

int codigo;

//empieza en el 32, porque del 0 al 31 son caracteres de control no imprimibles

for(codigo = 32; codigo < 256; codigo++ )
{
    printf("\n  %d  |  %c  |  %x ",  codigo, codigo, codigo );
}

system("pause");
return 0;
}
