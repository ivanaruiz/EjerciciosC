#include <stdio.h>
#include <stdlib.h>
#define CONVERSOR_MAYUS_MINUS(X,Y)  ( (X-Y==32) || (Y-X)==32)

/*Determinar la cantidad de ocurrencias de una sub cadena en una cadena.
Hay dos modos.
Encontrar ANA en anana se puede decir que está una vez o dos veces
(según quién lo mire), asi que hay que darles el gusto a ambas formas de verlo.
*/

void probarCadenas();
int contarOcurrencias1_MIO(const char *cad, const char *sub);
int contarOcurrencias2_MIO(const char *cad, const char *sub);
int mi_strlen(const char * sub);


int main()
{
    probarCadenas();
    system("pause");
    return 0;
}


void probarCadenas()
{
    char   *cad[2] = { "Es El Anana De Ana Y La Manzana De Juana y de Susana",
                       "aAaAAaAA"  },
           *sub[]  = { "ANA", " ", " de ", "", "aa" };
    int     veces1,
            veces2,
            ciclo;


    printf("Buscando en la cadena \"%s\".\n", cad[0]);
    ciclo = 0;
    while(ciclo < 4)
    {
        veces1 = contarOcurrencias1_MIO(cad[0], sub[ciclo]);
        veces2 = contarOcurrencias2_MIO(cad[0], sub[ciclo]);
        printf("Se encontro %2d y %2d veces la subcadena \"%s\".\n",
               veces1, veces2, sub[ciclo]);
        ciclo++;
    }
    veces1 = contarOcurrencias1_MIO(cad[1], sub[ciclo]);
    veces2 = contarOcurrencias2_MIO(cad[1], sub[ciclo]);
    printf("Finalmente en \"%s\" se encuentra \"%s\" %2d y %2d veces.\n",
            cad[1], sub[ciclo], veces1, veces2);

    puts("/////////////////////////////////////////////////\n");
}




int contarOcurrencias1_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int ce= mi_strlen(sub);

    if(ce==0)   //para el caso de sub="", que sencillamente devuelva 1 para no hacer todo el cálculo siguiente
        return 1;

    int cont_letras=0;  //contador de letras de una (posible) ocurrencia
    int cont_ocurrencias=0;

    while(*cad != '\0')
    {
        if(*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) )
        {
            while( (*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) ) && *cad!='\0' && *sub!='\0')
            {
                cad++;
                sub++;
                cont_letras++;
            }
            if(cont_letras==ce) //con esto verifico si realmente se trata de la misma palabra
            {
                cont_ocurrencias++;
                if(ce!=1)   //salvo las casos en que sub sea de 1 caracter, ejemplo sub=" "
                    cad--;
            }
            //en caso de no ser la misma palabra, reseteo a sub para una próxima búsqueda
            cont_letras=0;
            sub= reset_sub;
            cad--;
        }
        cad++;
    }
    return cont_ocurrencias;
}


int contarOcurrencias2_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int ce= mi_strlen(sub);

    if(ce==0)
        return 1;

    int cont_letras=0;
    int cont_ocurrencias=0;

    while(*cad != '\0')
    {
        if(*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub)  )
        {
            while( (*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) ) && *cad!='\0' && *sub!='\0')
            {
                cad++;
                sub++;
                cont_letras++;
            }
            if(cont_letras==ce)
            {
                cont_ocurrencias++;
            }

            cont_letras=0;
            sub= reset_sub;
            cad--;
        }
        cad++;
    }
    return cont_ocurrencias;
}


int mi_strlen(const char * sub)
{
    int cant_de_caracteres=0;

    while(*sub!= '\0')
    {
        cant_de_caracteres++;
        sub++;
    }
    return cant_de_caracteres;
}
