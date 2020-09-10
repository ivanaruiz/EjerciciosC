
#include "main.h"



int main()
{
    printf("sizeof float        :%u\n"
           "sizeof double       :%u\n"
           "sizeof long double  :%u\n", sizeof(float), sizeof(double), sizeof(long double));

    system("pause");

    mostrarFF();

    system("pause");

    mostrarFD();

    system("pause");

    mostrarFL();


    return 0;
}


void mostrarFF()
{
    float ff=5.7234567451234562222f;

    printf("\nMostrando un float \n");
    printf("Mostrando 5.7234567451234562222 con %%f\n"
           "          %f\n", ff);
    puts  ("          1-23456789012345678901234567890\n");


    printf("Mostrando 5723.4567451234562222 con %%f\n"
           "          %f\n", ff*1000);
    puts  ("          1234-56789012345678901234567890\n");


    printf("Mostrando 5.7234567451234562222 con %%.10f\n"
           "          %.10f\n", ff);
    puts  ("          1-23456789012345678901234567890\n");


    ff = 123222123433222111333444.1112223330f;
    printf("Mostrando 123222123433222111333444.1112223330 con %%f\n"
           "          %f\n", ff);
    puts  ("          123456789012345678901234-567890\n");
    puts  ("Parece ser que los primeros siete digitos tienen precision?\n"
           "Podremos afirmar que el octavo esta redondeado?");

}
void mostrarFD()
{
    printf("\n\nMostrando un double \n");

    double fd=5.7234567451234562222;


    printf("Mostrando 5.7234567451234562222 con %%lf\n"
           "          %f\n", fd);
    puts  ("          1-23456789012345678901234567890\n");


    printf("Mostrando 5723456.7451234562222 con %%lf\n"
           "          %f\n", fd*1000000);
    puts  ("          1234567-89012345678901234567890\n");


    printf("Mostrando 5.7234567451234562222 con %%.20lf\n"
           "          %.20f\n", fd);
    puts  ("          1-23456789012345678901234567890\n");


    fd = 123222123433222111333444.1112223330;
    printf("Mostrando 123222123433222111333444.1112223330 con %%lf\n"
           "          %f\n", fd);
    puts  ("          123456789012345678901234-567890\n");

    puts  ("Parece ser que los primeros quince digitos tienen precision?\n"
           "Podremos afirmar que a partir del siguien hace 'lo que puede'?");




}
void mostrarFL()
{
    printf("\n\nMostrando un long double \n");

    long double fl=5.72345674512345622223434L;


    printf("Mostrando 5.72345674512345622223434 con %%lf\n"
           "          %lf\n", fl);
    puts  ("          1-23456789012345678901234567890\n");


    printf("Mostrando 5723456.74512345622223434 con %%lf\n"
           "          %lf\n", fl*1000000);
    puts  ("          1234567-89012345678901234567890\n");


    printf("Mostrando 5.72345674512345622223434 con %%.30lf\n"
           "          %.30lf\n", fl);
    puts  ("          1-23456789012345678901234567890\n");


    fl = 1232221234332221113337444.1112223330L;
    printf("Mostrando 1232221234332221113337444.1112223330 con %%lf\n"
           "          %lf\n", fl);
    puts  ("          123456789012345678901234-567890\n");

    puts  ("Para ver estos resultados tuve que ir a Project -> Build options\n"
           "y en los #define agregue __USE_MINGW_ANSI_STDIO\n"
           "Sin embargo en la materia no trabajaremos con los long double.\n");

}


