#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
#include "bicicletas.h"

void listarServicio(bServicios servicio)
{
    printf("       %d      %10s          %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int listarServicios(bServicios servicios[], int tam_s)
{
    int error =-1;
    if( servicios!= NULL && tam_s>0)
    {

        printf("  ------------------------------------------------\n");
        printf("                 LISTADO SERVICIOS                \n");
        printf("  ------------------------------------------------\n");
        printf("        Id        Descripcion        Precio   \n");

        for(int i=0; i<tam_s; i++)
        {
            listarServicio(servicios[i]);
        }

        error = 0;
    }

    return error;
}

int mostrarDescServicios(int id, bServicios servicio[], int tam_s,char descripcionServ[]){
int error=1;

    for (int i = 0; i < tam_s; i++){

        if (id == servicio[i].id)
        {
            strcpy(descripcionServ, servicio[i].descripcion);
            error = 0;
            break;
        }
    }
    return error;
}
