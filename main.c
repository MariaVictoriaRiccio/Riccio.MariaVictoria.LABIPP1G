#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "color.h"
#include "fecha.h"
#include "bicicletas.h"
#include "fecha.h"
#include "tipos.h"
#include "trabajos.h"
#include "servicios.h"
#include "validaciones.h"
#include "clientes.h"
#include "informes.h"

#define TAM_R 5
#define TAM_B 5
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 5
#define TAM_CL 5

int main()
{
    char seguir='s';
    char confirma;
    int proxIdBici=1;
    int idCliente=1;
    int idTrabajo=1;
    bBicicleta rodado[TAM_R];
    bBicicleta bicicletas[TAM_B]=
    {
        {1, "SHIMANO",1000,5000,1,20,0, {1, "JUANA", 'f' } },
        {2, "VAIRO",1000,5001,2,26,0, {2, "LOLA", 'f' } },
        {3, "RAM",1002,5000,3,27.5,0, {3, "FACUNDO", 'm' } },
        {4, "STANLEY",1003,5003,4,29,0, {4,"JAVIER", 'm' } },
        {5, "SAM",1003,5004,5,20,0, {4,"SANDRA", 'f' } },
    };

    bTrabajos trabajos[TAM_TR];

    bClientes clientes[TAM_CL];

    bServicios servicios[TAM_S]=
    {
        {20000,"Limpieza",250},
        {20001,"Parche",300},
        {20002,"Centrado",400},
        {20003,"Cadena",350},
    };

    bTipos tipos[TAM_T]=
    {
        {1000,"Rutera"},
        {1001,"Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"},
    };

    bColores colores[TAM_C]=
    {
        {5000,"Gris"},
        {5001,"Negro"},
        {5002,"Blanco"},
        {5003,"Azul"},
        {5004,"Rojo"},
    };

    //initBicicletas(bicicletas, TAM_B);
    initTrabajo(trabajos, TAM_TR);


    do
    {
        switch(menu())
        {
        case 'A':

            if (altaBicicleta(bicicletas,TAM_B,tipos,TAM_T,colores,TAM_C,proxIdBici,idCliente)==0)
            {
                proxIdBici++;
                idCliente++;

                printf("\n\n   <<< ALTA EXITOSA >>>  \n\n");
            }
            else
            {
                printf("\n\n   <<< ERROR AL REALIZAR EL ALTA >>>  \n\n");
            }
            break;
        case 'B':

            modificarBicicleta(bicicletas,TAM_B,colores, TAM_C,rodado,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 'C':
            bajaBicicleta(bicicletas,TAM_B,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL);
            break;
        case 'D':
            //ordenarBicicletas(bicicletas,TAM_B,tipos,TAM_T);
            mostrarBicicletas(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 'E':
            mostrarTipos(tipos,TAM_T);
            break;
        case 'F':
            mostrarColores(colores,TAM_C);
            break;
        case 'G':
            listarServicios(servicios,TAM_S);
            break;
        case 'H':
            altaTrabajo(trabajos, TAM_TR,bicicletas,TAM_B,servicios,TAM_S,tipos,TAM_T, colores,TAM_C,idTrabajo, clientes,TAM_CL);
            break;
        case 'I':
            listarTrabajos(trabajos, TAM_TR, servicios,TAM_S);
            break;
        case 'J':
            mostrarMenuInformesPrincipal(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL,trabajos,TAM_TR,servicios,TAM_S);
            break;
        case 'K':
            printf("Confirma salida? ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            break;
        }

        system("pause");
    }
    while( seguir == 's');

    return 0;
}
