#include "archivos.h"
#include "pila_dinamica.h"
//Este proyecto funciona correctamente

int main()
{
    t_pila p;
    crear_pila(&p);

    char * pathProd= "PRODUCTOS.dat";
    char * pathMovs = "MOVIMIENTOS.dat";

    //primero creamos el archivo productos.dat
    //esta hecho en el main ya que luego necesito este vector
    FILE * archProd =fopen(pathProd, "wb");
    if(!archProd)
        return 0;

    t_producto vec_prod[]=  {
                            {1, "LECHE", 60, 50},
                            {2, "HARINA", 40, 40},
                            {4, "ARROZ", 35, 20},
                            {5, "POLENTA", 25, 15},
                            {6, "GALLETAS", 30, 45},
                            {8, "MAYONESA", 55, 15},
                            {9, "MOSTAZA", 45, 10},
                            {10, "MANTECA", 50, 25},
                            {13, "YOGUR", 55, 20},
                            {14, "CAFE", 70, 30},
                            {16, "AZUCAR", 40, 30},
                            {17, "YERBA", 65, 20},
                            {19, "JUGO", 60, 40},
                            {20, "GASEOSA", 80, 35},
                            };

    //cantidad inicial de registros de este archivo, lo necesito ya que luego tendre mas registros
    int cant_ini= sizeof(vec_prod)/sizeof(t_producto);

    fwrite(&vec_prod, sizeof(vec_prod), 1, archProd);

    fclose(archProd);

    //creo archivo movimientos.dat
    if(!crear_arch_mov(pathMovs))
        return 1;

    //leo inicialmente ambos archivos
    printf("=========================\n"
           "==Archivo productos.dat==\n"
           "=========================\n");
    if(!leer_arch_prod(pathProd))
        return 1;
    printf("\n===========================\n"
             "==Archivo movimientos.dat==\n"
             "===========================\n");
    if(!leer_arch_prod(pathMovs))
        return 1;
    system("pause");



    //este cant sera para ver cuántos registros mas agregare al archivo de productos al final
    int cant_nuevos=0;
    //seran registros que estaban en movimientos.dat pero no en productos.dat


    //aca empieza el merge propiamente dicho y la actualizacion de productos.dat
    archProd =fopen(pathProd, "r+b");
    FILE * archMovs =fopen(pathMovs, "rb");

    if(!archProd || !archMovs)
        return 1;

    t_producto prod;
    t_producto movs;


    fread(&prod, sizeof(t_producto),1,archProd);
    fread(&movs, sizeof(t_producto),1,archMovs);

    while(!feof(archMovs) && !feof(archProd))   //cortará el ciclo cuando por lo menos uno de los archivos finalice
    {
        if(prod.cod==movs.cod)
        {
            prod.stock+= movs.stock;

            fseek(archProd, -sizeof(t_producto),SEEK_CUR);
            fwrite(&prod, sizeof(t_producto),1,archProd);
            fseek(archProd, 0, SEEK_CUR);

            poner_en_pila(&p, &prod, sizeof(t_producto));

            fread(&prod, sizeof(t_producto),1,archProd);
            fread(&movs, sizeof(t_producto),1,archMovs);
        }

        else if(prod.cod<movs.cod)
        {
            poner_en_pila(&p, &prod, sizeof(t_producto));
            fread(&prod, sizeof(t_producto),1,archProd);
        }

        else if(prod.cod>movs.cod)
        {
            poner_en_pila(&p, &movs, sizeof(t_producto));
            cant_nuevos++;  //aca encontró un registro nuevo en movs.dat asi que incremento
            fread(&movs, sizeof(t_producto),1,archMovs);
        }
    }//cierro el while del merge


    //estos dos ciclos es para ver si alguno de los archivos aun no habia finalizado su recorrido
    //en caso de que asi sea, se siguen leyendo y apilando
    while(!feof(archProd))  //si archMovs terminó primero..
    {
        poner_en_pila(&p, &prod, sizeof(t_producto));
        fread(&prod, sizeof(t_producto),1,archProd);
    }
    while(!feof(archMovs))  //si archProds terminó primero..
    {
        poner_en_pila(&p, &movs, sizeof(t_producto));
        cant_nuevos++;
        fread(&movs, sizeof(t_producto),1,archMovs);
    }

    fclose(archMovs);
    fclose(archProd);
    //con esto ya terminé el merge
    //la pila me sirvió ya que los datos se han apilado en orden, por lo tanto no es necesario hacer un ordenamiento


    //este vector tendra los registros que tenia vec_prod pero ademas tendra los registros nuevos
    //es este nuestro vector final digamos, el que finalmente volcaremos al archivo ordenado y bien actualizado
    t_producto vec[cant_ini + cant_nuevos];


    archProd=fopen(pathProd, "r+b");
    if(!pathProd)
        return 1;

    int i;
    //en el for voy a recorrer hasta la cantidad total de registros: cant_ini + cant_nuevos
    //voy a desapilar en algun struct, como por ejemplo, prod, y colocar los datos en el vector vec
    for(i=0; i< cant_ini + cant_nuevos; i++)
    {
        sacar_de_pila(&p, &prod, sizeof(t_producto));

        vec[i].cod = prod.cod;
        strcpy(vec[i].desc, prod.desc);
        vec[i].precio = prod.precio;

        //esto es para los stocks que quedaron en negativos, no es valido, asi que seteo en 0
        if(prod.stock<0)
            vec[i].stock=0;
        else
            vec[i].stock = prod.stock;
    }
    //sin embargo, al desapilar quedaron los datos en orden inverso, por tanto hare un for mas para ordenar eso


    //con este for leo en el orden correcto, y ya guardo finalmente los datos del vector en el archivo
    for(i= cant_nuevos + cant_ini -1; i>=0 ; i--)
    {
        fwrite(&vec[i], sizeof(t_producto),1,archProd);
    }
    fclose(archProd);



    printf("\n=====================================\n"
             "==Archivo productos.dat actualizado==\n"
             "=====================================\n");
    if(!leer_arch_prod(pathProd))
        return 1;


    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Este paso es optativo, preguntamos al usuario si desea modificar los campos vacios o dejarlos como estan
    //////////////////////////////////////////////////////////////////////////////////////////////////////////


    char opc;
    printf("\nDesea rellenar los campos nuevos vacios? (s/n): ");
    scanf("%c", &opc);
    fflush(stdin);
    if(opc=='s' || opc=='S')
    {
       if(!rellenar_campos_vacios(pathProd))
        return 1;

        printf("\n=====================================\n"
                 "==Archivo productos.dat actualizado==\n"
                 "=====================================\n");

        if(!leer_arch_prod(pathProd))
        return 1;
    }

    if(!convertir_a_txt(pathProd))
        return 1;

    system("pause");
    return 0;
}
