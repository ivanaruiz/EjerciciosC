#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Dada la cadena "abcd", imprimir recursivamente:
a- abcd     b- dcba      c- abcddcba      c'- abcdcba

d- abcd     e- d         f- abcd          f'- abcd
   bcd         cd           bcd               bcd
   cd          bcd          cd                cd
   d           abcd         d                 d
                            d                 cd
                            cd                bcd
                            bcd               abcd
                            abcd

g- a        h- abcd      i- a             i'- a
   ab          abc          ab                ab
   abc         ab           abc               abc
   abcd        a            abcd              abcd
                            abcd              abc
                            abc               ab
                            ab                a
                            a
**/

void parteA(const char * c);
void parteB(const char * c);
void parteC(const char * c);
void parteC2(const char * c);
void parteD(const char * c);
void parteE(const char * c);
void parteF(const char * c);
void parteF2(const char * c);
void parteG(char *, char *);
void parteH(char *, char *);
void parteI(char *, char *, char*);
void parteI2(char *, char *, char*);

int main()
{
    char cad [] = "abcd";

    parteA(cad);

    puts("\n=========\n");

    parteB(cad);

    puts("\n=========\n");

    parteC(cad);

    puts("\n=========\n");

    parteC2(cad);

    puts("\n=========\n");

    parteD(cad);

    puts("\n=========\n");

    parteE(cad);

    puts("\n=========\n");

    parteF(cad);

    puts("\n=========\n");

    parteF2(cad);

    puts("\n=========\n");

    char * cota = cad;

    parteG(cad, cota);

    puts("\n=========\n");

    char * fin = cad + strlen(cad);

    parteH(cad, fin);

    puts("\n=========\n");

    parteI(cad, cota, fin);

    puts("\n=========\n");

    parteI2(cad, cota, fin-1);

    puts("");
    system("pause");
    return 0;
}


void parteA(const char * c)
{
    if(*c=='\0')
        return;

    printf("%c", *c);
    parteA(c+1);
}

void parteB(const char * c)
{
    if(!*c)
        return;

    parteB(c+1);
    printf("%c", *c);
}

void parteC(const char * c)
{
    if(*c=='\0')
        return;

    printf("%c", *c);
    parteC(c+1);
    printf("%c", *c);
}

void parteC2(const char * c)
{
    if(!*c)
        return;

    printf("%c", *c);
    parteC2(c+1);

    if(strlen(c)!=1)    //cuando esté en 'd' , es strlen(c)=1 , por tanto que a ese no lo lea
        printf("%c", *c);
}

void parteD(const char * c)
{
    if(*c)
    {
        printf("%s\n", c);
        parteD(c+1);
    }
}

//O también..
/*
void parteD(const char * cad)
{
    if(!*cad)
        return;

    printf("%s\n", cad);
    parteD(cad+1);
}
*/

void parteE(const char * c)
{
    if(!*c)
        return;

    parteE(c+1);
    printf("%s\n", c);
}

void parteF(const char * c)
{
    if(!*c)
        return;

    printf("%s\n", c);
    parteF(c+1);
    printf("%s\n", c);
}

void parteF2(const char * c)
{
    if(!*c)
        return;

    printf("%s\n", c);
    parteF2(c+1);

    if(strlen(c)!=1)
        printf("%s\n", c);
}

void parteG(char * cad, char * cota)
{
   char* primero=cad;
   if(*cota)
   {
       cota++; ///esta en el segundo
       while(primero<cota)
       {
            printf("%c",*primero);
            primero++;
       }
       printf("\n");
       parteG(cad, cota);
   }
}

//OTRA VERSIÓN DE PARTEG
/*
void parteG(const char * cad, const char * reinicio, char * fin)
{
    if(cad==fin)
        return;

    parteG(cad, reinicio, fin-1);

    while(cad<fin)
    {
        printf("%c", *cad);
        cad++;
    }
    puts("");

    cad = reinicio;
}
*/


void parteH(char * cad, char * fin)
{
    if(cad==fin)
        return;

    char * primero= cad;

    while(primero<fin)
    {
        printf("%c", *primero);
        primero++;
    }
    printf("\n");
    parteH(cad, fin-1);
}


void parteI(char * cad, char * cota, char * fin)
{

    if(cota==fin)
        return;

    char* primero=cad;          //TODA ESTA PRIMERA PARTE IMPRIMITE LA PARTE PROGRESIVA(O SEA LA PRIMER PARTE)

    if(*cota)
    {
        cota++; ///esta en el segundo
        while(primero<cota)
        {
            printf("%c",*primero);
            primero++;

        }
        printf("\n");
        parteI(cad, cota, fin);
    }

    primero=cad;    //CUANDO TERMINA, SE PONE ACÁ, Y SIGUE CON LA SEGUNDA PARTE

   while(primero<cota)
   {
        printf("%c",*primero);
        primero++;
   }
   printf("\n");
}




void parteI2(char * cad, char * cota, char * fin)
{
   if(strcmp(cad,fin)==0)
    return;

   char* primero=cad;

   if(*cota)
   {
       cota++; ///esta en el segundo
       while(primero<cota)
       {
            printf("%c",*primero);
            primero++;

       }
       printf("\n");
       parteI2(cad, cota, fin);
   }


   primero=cad;
   if(*cota)
   {
       while(primero<cota)
       {
            printf("%c",*primero);
            primero++;

       }
   printf("\n");
   }
}
