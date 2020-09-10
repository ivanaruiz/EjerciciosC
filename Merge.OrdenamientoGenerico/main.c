#include "archivos.h"
//ESTE PROYECTO ANDA BIEN, PROBADO CON DOS LOTES DE PRUEBAS

int main()
{
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

    //necesito saber qué cantidad de registros hay creados
    int cant_ini= sizeof(vec_prod)/sizeof(t_producto);

    fwrite(&vec_prod, sizeof(vec_prod), 1, archProd);

    fclose(archProd);

    //creo el archivo de movimientos pero lo hago en una funcion
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



    //este contador será para ver cuántos registros mas agregare al archivo de productos al final
    int cant_nuevos=0;
    //seran registros que estaban en movimientos.dat pero no en productos.dat


    //aca empieza el merge propiamente dicho y la actualizacion de productos.dat
    archProd =fopen(pathProd, "r+b");
    FILE * archMovs =fopen(pathMovs, "rb");

    if(!archProd || !archMovs)
        return 1;

    t_producto prod;
    t_producto movs;
    t_producto reg_nuevos[20];  //aca guardare los nuevos registros que iran a parar a productos.dat luego
                                //el 20 es un numero aproximado

    fread(&prod, sizeof(t_producto),1,archProd);
    fread(&movs, sizeof(t_producto),1,archMovs);


    while(!feof(archProd) &&  !feof(archMovs))  //cuando por lo menos uno de los archivos termine, se corta el ciclo
    {
        if(prod.cod==movs.cod)
        {
            prod.stock+= movs.stock;

            fseek(archProd, -sizeof(t_producto),SEEK_CUR);
            fwrite(&prod, sizeof(t_producto),1,archProd);
            fseek(archProd, 0, SEEK_CUR);

            fread(&prod, sizeof(t_producto),1,archProd);
            fread(&movs, sizeof(t_producto),1,archMovs);
        }

        else if(prod.cod<movs.cod)
        {
            fread(&prod, sizeof(t_producto),1,archProd);
        }

        //para por este if cuando algun registro está en movs y no está en prods,
        //asi que guardo tal registro en el vector reg_nuevos
        else if(prod.cod>movs.cod)
        {
            reg_nuevos[cant_nuevos].cod= movs.cod;
            strcpy(reg_nuevos[cant_nuevos].desc, "");
            reg_nuevos[cant_nuevos].precio=0;
            reg_nuevos[cant_nuevos].stock= movs.stock;

            cant_nuevos++;

            fread(&movs, sizeof(t_producto),1,archMovs);
        }
    }//cierro el while del merge


    //estos dos ciclos es para ver si alguno de los archivos aun no habia finalizado su recorrido
    //en caso de que asi sea, se siguen leyendo y guardando los datos
    while(!feof(archProd))  //si archMovs terminó primero..
    {
        fread(&prod, sizeof(t_producto),1,archProd);
    }
    while(!feof(archMovs))  //si archProds terminó primero..
    {
        //nuevamente guardo los registros que quedaron en movs.dat que no estaban en prods.dat
        reg_nuevos[cant_nuevos].cod= movs.cod;
        strcpy(reg_nuevos[cant_nuevos].desc, "");
        reg_nuevos[cant_nuevos].precio=0;
        reg_nuevos[cant_nuevos].stock= movs.stock;

        cant_nuevos++;
        fread(&movs, sizeof(t_producto),1,archMovs);
    }


    fclose(archMovs);   //cierro este archivo ya que no lo necesito mas

    //y guardo los nuevos registros en productos.dat, se guardaran al final del archivo
    fwrite(&reg_nuevos,sizeof(t_producto),cant_nuevos,archProd);

    fclose(archProd);


    //tengo que crear un nuevo vector ya que tiene una determinada cantidad, que seran el total de registros=
    //cant_ini + cant_nuevos
    //por eso no puedo usar los otros dos vectores(vec_prod y reg_nuevos, ya que cada uno tiene una cantidad distinta)
    t_producto vec[cant_ini + cant_nuevos];
    //este vector es el que utilizaré luego para ordenar

    //con esta funcion voy a volcar los datos grabados en el archivo al vector
    if(!pasar_a_vec(vec, cant_ini+cant_nuevos, pathProd))
        return 1;

    //finalmente abro archProd una vez mas para ordenar y volver a guardar
    archProd=fopen(pathProd,"r+b");
    if(!archProd)
        return 1;

    ordenar(vec, cant_ini + cant_nuevos, sizeof(t_producto), cmp_cod);

    printf("\nArchivo ordenado:\n");

    //guardamos el archivo ya ordenado
    fwrite(&vec, sizeof(vec),1,archProd);
    fclose(archProd);

    printf("=====================================\n"
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
    printf("=====================================\n"
           "==Archivo productos.dat actualizado==\n"
           "=====================================\n");
        if(!leer_arch_prod(pathProd))
        return 1;
    }

    system("pause");
    return 0;
}


