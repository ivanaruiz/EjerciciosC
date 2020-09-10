#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Desarrollar una función que elimine la primera aparación de un elemento determinado
de un arreglo de enteros.
*/

/*Haré una función genérica lo cual es mejor, y también lo probaré con un vector de char*/

int buscar(void * vec, size_t ce, void * n, size_t tamInfo, int (*cmp)(const void*, const void*));
int cmp_enteros(const void * a1, const void * a2);
int cmp_char(const void * a1, const void * a2);
void eliminar( void * vec, void * fin, size_t tamInfo);


int main()
{
    int vec[] = {3,1,2,3,3,4,5,3,6,7,3};
    int ce = sizeof(vec)/sizeof(int);

    printf("VECTOR ORIGINAL DE ENTEROS:\n");
    for(int i=0; i<ce; i++)
        printf("%d ", vec[i]);

    int n = 3;
    int cont=buscar(vec, ce, &n, sizeof(int), cmp_enteros);

    printf("\nVECTOR CON ELIMINACION DE TODAS LAS APARICIONES DEL NUM %d:\n", n);
    for(int i=0; i<ce-cont; i++)
        printf("%d ", vec[i]);


    printf("\n***********************\nVECTOR ORIGINAL DE CHAR:\n");
    char vec_char[] = {'b','b','b','c','b','e'};
    ce = sizeof(vec_char)/sizeof(char);

    for(int i=0; i<ce; i++)
        printf("%c ", vec_char[i]);

    char c = 'b';
    cont= buscar(vec_char, ce, &c, sizeof(char), cmp_char);

    printf("\nVECTOR CON ELIMINACION DE TODAS LAS APARICIONES DE LETRA %c:\n", c);
    for(int i=0; i<ce-cont; i++)
        printf("%c ", vec_char[i]);

    puts("");
    system("pause");
    return 0;
}


int buscar(void * vec, size_t ce, void * n, size_t tamInfo, int (*cmp)(const void*, const void*))
{
    void * fin = vec + (ce-1)*tamInfo;
    int cont=0;     //contador de apariciones
    int pasar=0;    //es una bandera

    while(vec<=fin)
    {
        pasar=0;
        if(cmp(vec, n)==0)
        {
            eliminar(vec, fin, tamInfo);
            cont++;
            pasar=1;
        }
        if(!pasar)
            vec+=tamInfo;
    }
    return cont;
}

void eliminar( void * vec, void * fin, size_t tamInfo)
{
    while(vec<=fin) //recorro desde donde encontré el caracter a eliminar hasta el final
    {
        memcpy(vec, vec+tamInfo, tamInfo);
        vec+=tamInfo;
    }
}

int cmp_enteros(const void * a1, const void * a2)
{
    int * e1 = (int*) a1;
    int * e2 = (int*) a2;
    return *e1-*e2;
}

int cmp_char(const void * a1, const void * a2)
{
    char * e1 = (char*) a1;
    char * e2 = (char*) a2;
    return *e1-*e2;
}
