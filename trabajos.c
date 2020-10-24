#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "fecha.h"
#include "trabajos.h"
#include "tipos.h"
#include "validaciones.h"
#include "clientes.h"


int initTrabajo(bTrabajos trabajos[], int tam_tr)
{
    int error=1;

    if (trabajos!= NULL && tam_tr>0)
    {
        for (int i=0; i<tam_tr; i++)
        {
            trabajos[i].isEmpty=1;
        }
        error=0;
    }
    return error;

}
int buscarTrabajoLibre(bTrabajos trabajos[], int tam_tr)
{
    int indice = -1;

    for( int i = 0; i < tam_tr; i++ )
    {
        if( trabajos[i].isEmpty )
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int altaTrabajo(bTrabajos trabajo[], int tam_tr, bBicicleta bicicletas[],int tam_b,bServicios servicios[], int tam_s,bTipos tipo[],int tam_t,bColores colores[], int tam_c, int idTrabajo, bClientes clientes[], int tam_cl)
{
    int error = 1;
    int indice;
    int auxIDbici;
    int auxIDServicio;
    bTrabajos nuevoTrabajo;
    system("clear");

    if(trabajo!= NULL && tam_tr > 0 && idTrabajo > 0 )
    {

        printf("  ----------------------------------\n");
        printf("         ALTA DE TRABAJO            \n");
        printf("  -----------------------------------\n");

        indice = buscarTrabajoLibre(trabajo, tam_tr);


        if(indice == -1)
        {
            printf("No se pueden dar de alta mas trabajos");
            printf("El sistema esta completo\n");
        }
        else
        {
            nuevoTrabajo.id = idTrabajo;
            nuevoTrabajo.isEmpty = 0;

  mostrarBicicletas(bicicletas,tam_b,colores,tam_c,tipo,tam_t,clientes,tam_cl);

            printf("INGRESE ID DE LA BICICLETA: ");
            scanf("%d", &auxIDbici);
     while(validarIdBici(bicicletas,tam_b,auxIDbici)==1){
      printf("ERROR. REINGRESE ID EXISTENTE \n");
            scanf("%d", &auxIDbici);
      }

           nuevoTrabajo.idBicicleta= auxIDbici;

            listarServicios(servicios, tam_s);
            printf("\n  INGRESE ID SERVICIO: ");
            scanf("%d", &auxIDServicio);

            while(validarServId(servicios,tam_s,auxIDServicio) == 0 )
            {
                printf("ID DE SERVICIO INEXISTENTE. \n POR FAVOR REINGRESE ID: \n");
                scanf("%d", &auxIDServicio);
            }
           nuevoTrabajo.idServicio=auxIDServicio;


            printf("INGRESE FECHA: dd/mm/aaaa\n");
            scanf("%d/%d/%d",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);

            while (validarFecha(nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes,nuevoTrabajo.fecha.anio)!=0)
            {
                printf("FECHA INVALIDA. REINGRESE LA FECHA: dd/mm/aaaa: \n");
            scanf("%d/%d/%d",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
            }

            trabajo[indice]=nuevoTrabajo;
            error = 0;
        }
    }

    return error;

}




void listarTrabajo(bTrabajos trabajo, bServicios servicios[], int tam_s)
{
    char descServicio[20];
    mostrarDescServicios(trabajo.idServicio, servicios, tam_s, descServicio);

    printf("          %d      %20s        %d/%d/%d\n\n",
           trabajo.idBicicleta,
           descServicio,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio);
}

int listarTrabajos(bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_s)
{
    int error= 1;
    printf("   ---------------------------------------------------\n");
    printf("                 LISTADO DE TRABAJOS                  \n");
    printf("   ---------------------------------------------------\n");
    printf("    ID BICICLETA           TRABAJO       FECHA DE TRABAJO\n");
    for(int i = 0; i < tam_tr; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            listarTrabajo(trabajos[i],servicios,tam_s);
            error = 0;
        }
    }
    return error;
}
