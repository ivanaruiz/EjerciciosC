#include "alumno.h"

int leer_arch_ord(char *path)
{
    FILE *pf;
    t_alumno alu;
    pf=fopen(path, "rb");
    if(!pf)
        return 0;

    fread(&alu, sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        printf("%d %s\n", alu.dni, alu.nya);
        fread(&alu, sizeof(t_alumno),1,pf);
    }

    fclose(pf);
    return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


void intercambio(t_alumno *alu, t_alumno *men)
{
    t_alumno aux;
    aux = *alu;
    *alu = *men;
    *men = aux;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


void buscar_menor_y_actualizar( FILE *pf, t_alumno *alu, t_alumno *men, int cv)
{
      while(!feof(pf))
        {

            if(alu->dni < men->dni)
            {
            intercambio(alu, men);

            //primero guardo a alu, para buscar con fseek basta con volver una posicion atras nomas,
            //ya que alu siempre queda con el ultimo registro leido
            fseek(pf, -sizeof(t_alumno),SEEK_CUR);
            fwrite(alu, sizeof(t_alumno),1,pf);
            fseek(pf,0,SEEK_CUR);

            //en cambio para guardar al menor, necesito la "primera posicion" que como dijimos ira incrementando
            //en cada vuelta, por eso en el fseek uso (cv-1)*16
            //con 16 se refiere a porque cada registro del struct ocupa 16 bytes= 4(int)+10(char)+2('\0')
            //por eso al leer el primero registro (cv-1)*16 = (1-1)*16=0
            //pero al leer el segundo registro necesito (cv-1)*16= (2-1)*16 = 16, lo cual es correcto
            //avanzo 16 bytes mas adelante para leer el registro numero 2. y asi sucesivamente
            fseek(pf, (cv-1)*16 ,SEEK_SET);
            fwrite(men, sizeof(t_alumno),1,pf);
            fseek(pf, 0,SEEK_CUR);
            }

        fread(alu, sizeof(t_alumno),1,pf);
        }
}
