#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
int validarColores(bColores colores[], int tam_c, int id)
{
    int esValido = 0;
    if(colores != NULL && tam_c > 0 && id >=5000 )
    {
    for (int i = 0; i < tam_c; i++){
        if (colores[i].id == id)
        {
            esValido = 1;
            break;
        }
    }
    }
    return esValido;
}


int validarIdTipo(bTipos tipos[], int tam_t, int id){
    int esValido = 0;
    if( tipos != NULL && tam_t > 0 && id >=1000 )
    {
        for( int i=0; i<tam_t; i++ )
        {
            if( tipos[i].id == id ){
                esValido=1;
                break;
            }
        }
    }

    return esValido;
}



int validarMarca(char cadena[]){
int error=0;
int i=0;

    if (isalpha(cadena[i])!=0){
        i++;
        error=1;

}
return error;
}

int validarServId(bServicios servicios[], int tam_s, int id )
{
    int esValido = 0;

    if(servicios!= NULL && tam_s>0 && id>= 20000){

        for(int i=0; i<tam_s;i++ )
        {
            if( servicios[i].id == id ){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}



int validarFecha(int dia, int mes, int anio){
int error=1;

if (dia<0 || dia>31 || mes<0 || mes >12 || anio!=2020){
system("cls");
printf("ERROR EN EL INGRESO DE LA FECHA\n");
}else{

error=0;
}
return error;
}


int validarSexo(char sexo){
int error=1;
if(sexo!='f' && sexo !='m' && sexo!='F' && sexo !='M'){
error=0;
}
return error;
}




int validarIdBici(bBicicleta bicicletas[], int tam_b, int auxIdBici)
{
    int esValido = 1;

    if(bicicletas!= NULL && tam_b>0){

        for(int i=0; i<tam_b;i++ )
        {
            if( bicicletas[i].id == auxIdBici ){
                esValido = 0;
                break;
            }
        }
    }

    return esValido;
}
