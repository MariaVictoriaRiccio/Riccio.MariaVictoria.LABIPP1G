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

eFecha fecha;

int mostrarMenuInformesPrincipal(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c,bTipos tipos[],int tam_t,bClientes clientes[],int tam_cl,bTrabajos trabajos[], int tam_tr, bServicios servicios[],int tam_serv)
{
    char seguir = 's';
    char confirma;
    do
    {
        switch(menuInformes())
        {
        case 1:
            system("cls");
            informarBicicletasxColor(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 2:
            informarBicicletasxTipo(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 3:
            informarBicicletasDeMenorRodado(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T);
            break;
        case 4:
            informarBicicletasSeparadasSegunTipo(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 5:
            informarBicicletasColoryTipoxUsuario(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 6:
            colorMasElegidoPorLosClientes(bicicletas,TAM_B,colores,TAM_C);
            break;
        case 7:
            trabajosRealizadosAunaBicicleta(bicicletas,TAM_B,colores,TAM_C,trabajos,TAM_TR,servicios,TAM_S,tipos,TAM_T,clientes,TAM_CL);
            break;
        case 8:
//          informeTotalaPAgarPorServUnaBicicleta(bicicletas,TAM_B,trabajos,TAM_TR,servicios,TAM_S);
            break;
        case 9:
            serviciosRealizadosXfecha(trabajos,TAM_TR,servicios,TAM_S, fecha);
            break;
        case 10:
            printf("Confirma salida del submenu de informes? [s] [n]");
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



int menuInformes()
{
    int opcion;
    system("cls");
    printf("    -----------------------------------------\n");
    printf("            MENU DE INFORMES                 \n");
    printf("    ------------------------------------------\n");
    printf(" 1. Bicicletas segun color\n");
    printf(" 2. Bicicletas segun tipo\n");
    printf(" 3. Bicicleta/s de menor rodado\n");
    printf(" 4. Bicicletas separadas segun tipo\n");
    printf(" 5. Informar cuantas bicicletas hay, del color y tipo que elige el usuario \n");
    printf(" 6. Colores mas elegidos por los clientes\n");
    printf(" 7. Trabajos realizados a una bicicleta\n");
    printf(" 8. Monto total de los servicios realizados a una bicicleta\n");
    printf(" 9. Servicios realizados por fecha\n");
    printf(" 10. Salir\n");
    printf("   Ingrese opcion: ");
    scanf("%d",&opcion);
    return opcion;
}




int informarBicicletasxColor(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl)
{
    int idColor;
    int flag=0;
    char color[20];
    int error=1;
    system("cls");
    if (bicicletas!=NULL && colores!=NULL && tam_b>0 && tam_c>0)
    {
        printf("    --------------------------------------\n");
        printf("      INFORME DE BICICLETAS SEGUN COLOR   \n");
        printf("    --------------------------------------\n");
        mostrarColores(colores,tam_c);
        printf("\n\n");
        printf("Seleccione el id del color: \n");
        scanf("%d",&idColor);
        printf("\n\n");
        descripcionColor(colores,tam_c,idColor,color);
        printf("Bicicletas de color %s\n",color);
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n\n");
        printf("    ID BICICLETA   RODADO     COLOR    TIPO     MARCA      ID CLIENTE   NOMBRE CLIENTE          \n");
        printf("------------------------------------------------------------------------------------------------\n\n");

        for (int i=0; i<tam_b; i++)
        {

            if (bicicletas[i].isEmpty==0 && bicicletas[i].idColor == idColor)
            {
                printf("\n\n");
                mostrarBicicleta(bicicletas[i],tipos,tam_t,colores,tam_c,clientes,tam_cl);
                flag=1;
            }

        }
        if (flag==0)
        {
            printf("No hay bicicletas de ese color.\n");
        }
        error=0;
    }
    return error;
}



int informarBicicletasxTipo(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl)
{
    int idTipo;
    int flag=0;
    char tipo[20];
    int error=1;
    system("cls");
    if (bicicletas!=NULL && tipo!=NULL && tam_b>0 && tam_t>0)
    {
        printf("    --------------------------------------\n");
        printf("      INFORME DE BICICLETAS SEGUN TIPO    \n");
        printf("    --------------------------------------\n");
        mostrarTipos(tipos,tam_t);
        printf("\n\n");
        printf("Seleccione el id del tipo: \n");
        scanf("%d",&idTipo);
        printf("\n\n");
        descripcionTipos(idTipo,tipos,tam_t,tipo);
        printf("Bicicletas de tipo %s\n",tipo);
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n\n");
        printf("    ID BICICLETA   RODADO     COLOR    TIPO     MARCA      ID CLIENTE   NOMBRE CLIENTE          \n");
        printf("------------------------------------------------------------------------------------------------\n\n");

        for (int i=0; i<tam_b; i++)
        {

            if (bicicletas[i].isEmpty==0 && bicicletas[i].idTipo == idTipo)
            {
                printf("\n\n");
                mostrarBicicleta(bicicletas[i],tipos,tam_t,colores,tam_c,clientes,tam_cl);
                flag=1;
            }
        }
        if (flag==0)
        {
            printf("No hay bicicletas de ese tipo.\n");
        }
        error=0;
    }
    return error;
}

int informarBicicletasDeMenorRodado(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t)
{
    int error=1;
    int flag=0;
    float menorRodado=0;
    int contadorBici=0;

    for (int i=0; i<tam_b; i++)
    {
        if (bicicletas[i].isEmpty==0 && flag==0)
        {
            menorRodado=bicicletas[i].rodado;
            flag=1;

        }
        else if (bicicletas[i].isEmpty==0 && flag==1)
        {
            if(bicicletas[i].rodado<menorRodado)
            {
                menorRodado=bicicletas[i].rodado;
            }
        }
    }
    for (int i=0; i<tam_b; i++)
    {
        if(menorRodado==bicicletas[i].rodado)
        {

            contadorBici++;
        }
    }

    printf("\n\n");
    printf("\n\n");
    printf("La/s bicicleta/s de menor rodado : %.2f ,y son: %d bicicletas\n", menorRodado,contadorBici);
    printf("\n\n");

    return error;
}



int informarBicicletasSeparadasSegunTipo(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl)
{
    system("cls");
    int error=1;
    for(int i = 0; i < tam_b; i++)
    {
        printf("\n         TIPO %s           \n", tipos[i].descripcion);
        printf("--------\n");
        printf ("         ID         RODADO    COLOR   TIPO      MARCA    ID CLIENTE     NOMBRE    \n");
        for (int j = 0; j < tam_b; j++)
        {
            if (bicicletas[j].idTipo == tipos[i].id && bicicletas[j].isEmpty == 0)
            {
                mostrarBicicleta(bicicletas[j],tipos,tam_t,colores,tam_c,clientes,tam_cl);
                error = 0;
            }
        }
    }

    return error;
}



int informarBicicletasColoryTipoxUsuario(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl)
{
    int error=1;
    int auxColor;
    int auxTipo;
    int contadorBicis=0;
    mostrarColores(colores,tam_c);
    printf ("Seleccione id del color de bicicleta: \n");
    scanf("%d",&auxColor);
    mostrarTipos(tipos,tam_t);
    printf ("Seleccione id del tipo de bicicleta: \n");
    scanf("%d",&auxTipo);

    for (int i=0; i<tam_b; i++)
    {
        if (colores[i].id==auxColor && tipos[i].id==auxTipo)
        {
            contadorBicis++;
            error=0;
        }
    }
    printf("\n\n");
    printf("        Cantidad de bicicletas: %d\n", contadorBicis);
    return error;
}


void colorMasElegidoPorLosClientes(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c)
{
    int cantidadColor[tam_c];
    int colorMasElegido;
    int flag = 0;
    system("cls");
    printf("----------------------------------------------------------\n");
    printf("       COLOR MAS ELEGIDO POR LOS CLIENTES                 \n");
    printf("----------------------------------------------------------\n");
    printf("\n\n");
    for (int i = 0; i < tam_c; i++)
    {
        cantidadColor[i] = 0;
    }
    for (int i = 0; i < tam_c; i++)
    {
        for (int j = 0; j < tam_b; j++)
        {
            if (bicicletas[j].isEmpty == 0 && bicicletas[j].idColor == colores[i].id)
            {
                cantidadColor[i]++;
            }
        }
    }
    for (int i = 0; i < tam_c; i++)
    {
        if (cantidadColor[i] > colorMasElegido || flag == 0)
        {
            colorMasElegido= cantidadColor[i];
            flag = 1;
        }
    }

    for (int i = 0; i < tam_c; i++)
    {
        if (cantidadColor[i] == colorMasElegido)
        {
            printf("     =====     %s    =====\n", colores[i].nombreColor);
        }
    }
    printf("\n");
}

/*
int informeTotalaPAgarPorServUnaBicicleta(bBicicleta bicicletas[], int tam_b,bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_s)
{
    int error=1;
    float acumuladorMontoTotal = 0;
    int auxIdBici;
    system("cls");
    printf("\n\n");
    printf("       Ingrese id de la bicicleta: \n");
    scanf("%d",&auxIdBici);
    printf("--------------------------------------------------------------\n");
    printf("   TOTAL A PAGAR POR LOS SERVICIOS REALIZADOS A LA BICICLETA  \n");
    printf("--------------------------------------------------------------\n");
for (int i=0;i<tam_b;i++){

    for (int i=0; i<tam_tr; i++)
    {
        for (int j=0; j<tam_s; j++)
        {
            if (trabajos[i].idServicio && bicicletas[i].id==auxIdBici)
            {

                acumuladorMontoTotal=acumuladorMontoTotal+servicios[j].precio;
            }
        }

printf("\n\n");
printf("TOTAL :$ %.2f",acumuladorMontoTotal);
return error;
}
*/


int trabajosRealizadosAunaBicicleta(bBicicleta bicicleta[],int tam_b,bColores colores[], int tam_c, bTrabajos trabajos[],int tam_tr, bServicios servicios[],int tam_s, bTipos tipos[],int tam_t, bClientes clientes[], int tam_cl)
{
    int auxBici;
    int error=1;
    mostrarBicicletas(bicicleta,tam_b,colores,tam_c,tipos,tam_t,clientes,tam_cl);

    printf("Ingrese ID de la bicicleta: \n");
    scanf("%d",&auxBici);
    printf("   -------------------------------------------------------\n");
    printf("               TRABAJOS REALIZADOS A LA BICICLETA          \n");
    printf("   --------------------------------------------------------\n");
    printf("    ID BICICLETA         TRABAJO       FECHA DE TRABAJO\n");
    for (int i = 0; i < tam_tr; i++)
    {
        for (int j = 0; j < tam_b; j++)
        {
            if (bicicleta[j].id == trabajos[i].idBicicleta && bicicleta[j].isEmpty == 0 && bicicleta[j].id == auxBici)
            {
                listarTrabajo(trabajos[i],servicios,tam_s);
                error=0;
            }
        }
    }
    return error;
}


int serviciosRealizadosXfecha(bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_s, eFecha fechas)
{


    int error = 0;
    eFecha auxFecha;

    printf("Ingrese la fecha que desea ver los trabajos realizados : \n");
    scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
    printf("   -------------------------------------------------------\n");
    printf("                   SERVICIOS REALIZADOS                           \n");
    printf("   -------------------------------------------------------\n");
    printf(" FECHA DEL SERVICIO           SERVICIO\n");
    for (int i = 0; i < tam_tr; i++)
    {
        for (int j = 0; j < tam_s; j++)
        {
            if (auxFecha.dia == trabajos[i].fecha.dia && auxFecha.mes == trabajos[i].fecha.mes && auxFecha.anio == trabajos[i].fecha.anio && trabajos[i].idServicio == servicios[j].id)
            {
                printf("    %d/%d/%d   %20s\n", trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio, servicios[j].descripcion);
                error=1;
            }
        }
    }
    return error;
}
