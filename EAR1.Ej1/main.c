#include <stdio.h>
#include <stdlib.h>
#define CONVERSOR_MAYUS_MINUS(X,Y)  ( (X-Y==32) || (Y-X)==32)
void sustituir(char * cad, int ce, char * sub, int ce1, char * reem, int ce2);

char * invertir_cadena(char * ini, char * fin);

char* InvertirCadena(char* cadena);

int main()
{
    char cad[50] = "int funcion(int seIntegra, int noIntegra);";

    char pal[] = "int";
    char reem[] = "unsigned int";

    sustituir(cad, sizeof(cad)/sizeof(char), pal, (sizeof(pal)/sizeof(char))-1, reem, (sizeof(reem)/sizeof(char)) -1);

    printf("%s", cad);

    return 0;
}

void sustituir(char * cad, int ce, char * sub, int ce1, char * reem, int ce2)
{

    char * dire_inicial = cad;

    char * ini_buscado;
    char * fin_buscado;
    char * reset_sub = (char*)sub;
    char * reset_reem;
    int carac_agregar = ce2-ce1;
    char * fin;
    char * acopiar;
    int adelantos=0;
    char * restantes;
    char * hastaaqui;

    InvertirCadena(reem);
    reset_reem= reem;

    int cont_letras=0;

    while(*cad != '\0')
    {
        if(*cad == *sub  || CONVERSOR_MAYUS_MINUS(*cad,*sub) )
        {
            ini_buscado = cad;

            while( (*cad == *sub  || CONVERSOR_MAYUS_MINUS(*cad,*sub)) && *cad!='\0' && *sub!='\0')
            {
                cad++;
                sub++;
                cont_letras++;
            }
            if(cont_letras==ce1)    //CUANDO ENTRÓ ACA ES PORQUE DEFINITIVAMENTE ENCONTRO PALABRA A REEMPLAZAR
            {
                fin_buscado = cad;

                while(  *cad!= '\0'  )
                {
                    cad++;
                    adelantos++;
                    if(adelantos==carac_agregar)
                    {
                        restantes=cad;
                        hastaaqui=cad;
                    }
                }

                if(adelantos<carac_agregar)
                {
                    restantes=cad+(carac_agregar-adelantos);
                    hastaaqui=cad+(carac_agregar-adelantos);

                }
                acopiar = cad;

                while(carac_agregar)
                {
                    acopiar++;
                    carac_agregar--;
                }
                fin= acopiar;

                while(fin>=restantes)
                {
                    *fin=*cad;
                    fin--;
                    cad--;
                }
                while(restantes>ini_buscado)
                {
                    *fin= *reem;
                    fin--;
                    restantes--;
                    reem++;
                }
                if(cad<ce)
                {
                cad= hastaaqui;
                cad--;
                }
                else
                    break;
            }
            cont_letras=0;
            sub= reset_sub;
            reem= reset_reem;
            adelantos=0;
            carac_agregar = ce2-ce1;

        }
        cad++;
    }
}





char* InvertirCadena(char* cadena)
{
    char* aux=cadena;
    char* cad2=cadena;
    char letra;


    while(*cad2)
    {
        cad2++;
    }
     cad2--;

    while(cad2>aux)
    {
        letra=*cad2;
        *cad2=*aux;

        *aux=letra;

        cad2--;
        aux++;
    }
    return cadena;
}
