#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bicicletas.h"
#include "tipos.h"
#include "color.h"
#include "fecha.h"
#include "trabajos.h"
#include "servicios.h"
#include "clientes.h"
#include "validaciones.h"
#include "informes.h"

char menu()
{

    char opcion;

    printf("\n\n");
    printf("    ------------------------------------------------------\n");
    printf("                 GESTION DE BICICLETERIA              \n");
    printf("    ------------------------------------------------------\n");
    printf("\n\n");
    printf("      A. Alta Bicicleta\n");
    printf("      B. Modificar Bicicleta\n");
    printf("      C. Baja Bicicleta\n");
    printf("      D. Listar Bicicletas\n");
    printf("      E. Listar Tipos\n");
    printf("      F. Listar Colores\n");
    printf("      G. Listar Servicios\n");
    printf("      H. Alta Trabajo\n");
    printf("      I. Listar Trabajos\n");
    printf("      J. Informes\n");
    printf("      K. Salir\n\n");
    printf("    Ingrese opcion: ");

    fflush(stdin);
    opcion = toupper(getchar());

    return opcion;

}


int initBicicletas(bBicicleta bicicletas[], int TAMB)
{

    int error=1;

    if (bicicletas!= NULL && TAMB>0)
    {
        for (int i=0; i<TAMB; i++)
        {
            bicicletas[i].isEmpty=1;
        }
        error=0;
    }
    return error;

}

int buscarLibre(bBicicleta bicicletas[], int tam_b)
{
    int indice = -1;

    for(int i = 0; i < tam_b; i++)
    {
        if(bicicletas[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaBicicleta(bBicicleta bicicletas[], int tam_b, bTipos tipos[], int tam_t, bColores colores[], int tam_c, int idBici, int idCliente)
{
    int error = 1;
    int indice;
    int auxIdColor;
    int auxIdTipo;
    float auxRodado;

    char auxMarca[20];

    bBicicleta nuevaBici;


    if(bicicletas!=NULL && tam_b > 0 && idBici>0)
    {
        system("cls");
        printf("\n\n");
        printf("   --------------------------------------------\n");
        printf("              ALTA DE BICICLETA                \n");
        printf("   --------------------------------------------\n");
        printf("\n");
        indice = buscarLibre(bicicletas, tam_b);
        if(indice == -1)
        {
            printf("No se pueden ingresar mas bicicletas, sistema completo\n");
        }
        else
        {

            nuevaBici.clientes.isEmpty=0;

            nuevaBici.clientes.id=idCliente;
            printf("ID CLIENTE: %d: \n",nuevaBici.clientes.id);


            printf("\n\nINGRESE NOMBRE DEL CLIENTE: ");
            fflush(stdin);
            gets(nuevaBici.clientes.nombre);
            while (validarMarca(nuevaBici.clientes.nombre)==0)
            {
                printf("ERROR. REINGRESE NOMBRE UTILIZANDO LETRAS, NO NUMEROS:  \n");
                fflush(stdin);
                scanf("%s", nuevaBici.clientes.nombre);
            }

            printf("\n\nINGRESE SEXO DEL CLIENTE:  [f]  [m]: ");
            fflush(stdin);
            scanf("%c",&nuevaBici.clientes.sexo);
             while (validarSexo(nuevaBici.clientes.sexo)==0){
                printf("ERROR. REINGRESE SEXO:  [f]  [m]\n");
                            fflush(stdin);

                scanf("%c",&nuevaBici.clientes.sexo);
             }

            nuevaBici.isEmpty=0;
            nuevaBici.id=idBici;
            printf("ID BICICLETA: %d\n",nuevaBici.id);

            mostrarTipos(tipos,tam_t);
            printf("\nINGRESE ID DEL TIPO DE BICICLETA: \n");
            scanf("%d", &auxIdTipo);
            while (validarIdTipo(tipos,tam_t,auxIdTipo)==0)
            {
                printf("ERROR. INGRESE ID CORRECTO: \n");
                scanf("%d", &auxIdTipo);
            }
            nuevaBici.idTipo = auxIdTipo;
            printf("\n\n");
            system("cls");
            printf("\n\nINGRESE RODADO [20, 26, 27.5, 29] : ");
            scanf("%f", &auxRodado);
            while (auxRodado!=20 && auxRodado!=26 && auxRodado!=27.5 && auxRodado!=29)
            {
                printf("\n\nERROR EN EL INGRESO DEL RODADO\n");
                printf("    POR FAVOR, INGRESE: [20, 26, 27.5, 29]");
                scanf("%f", &auxRodado);
            }

            nuevaBici.rodado = auxRodado;

            system("cls");


            mostrarColores(colores,tam_c);


            printf("\n\nINGRESE ID COLOR: ");
            scanf("%d", &auxIdColor);
            while(validarColores(colores, tam_c, auxIdColor)==0)
            {
                printf("ERROR. INGRESE ID CORRECTO: \n");
                fflush(stdin);
                scanf("%d", &auxIdColor);
            }
            nuevaBici.idColor = auxIdColor;
            printf("\n\n");

            system("cls");
            printf("\n\nINGRESE MARCA DE LA BICICLETA: ");
            fflush(stdin);
            gets(auxMarca);
            while (validarMarca(auxMarca)==0)
            {
                printf("ERROR. REINGRESE MARCA UTILIZANDO LETRAS, NO NUMEROS:  \n");
                fflush(stdin);
                scanf("%s", auxMarca);
            }
            strcpy(nuevaBici.marca,auxMarca);


            bicicletas[indice]=nuevaBici;
            error = 0;
        }
    }

    return error;
}


int buscarBicicleta(bBicicleta bicicletas[],int tam_b,int idBici)
{
    int indice = -1;
    for(int i = 0; i < tam_b; i++)
    {
        if( bicicletas[i].id == idBici && bicicletas[i].isEmpty == 0 )
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int modificarBicicleta(bBicicleta bicicletas[],int tam_b,bColores colores[],int tam_c, bBicicleta rodado[], bTipos tipos[],int tam_t, bClientes clientes[], int tam_cl)
{
    int error = 1;
    int idBici;
    int nuevoTipo=0;
    float nuevoRodado=0;
    int indice;
    int rta;
    char confirma = 's';
    char auxTipoDescripcion[20];

    if (bicicletas!=NULL && tam_b>0)
    {
        printf("\n\n");
        printf("--------------------------------------------\n");
        printf("        MODIFICAR DE BICICLETA               \n");
        printf("---------------------------------------------\n");

 mostrarBicicletas(bicicletas,tam_b,colores,tam_c,tipos,tam_t,clientes,tam_cl);

        printf ("Ingrese id de la bicicleta a modificar: \n");
        scanf ("%d", &idBici);
        indice = buscarBicicleta(bicicletas,tam_b,idBici);
        if (indice == -1)
        {
            printf ("No existe una bicicleta con ese id\n");
        }
        else
        {
            printf ("Ingrese la opcion a modificar: [1]. TIPO   [2]. RODADO\n");
            scanf("%d",&rta);
            while (rta!=1 && rta!=2)
            {
                printf("Error. Ingrese una opcion valida");
                scanf("%d",&rta);
            }
            if (rta==1)
            {
                mostrarTipos(tipos,tam_t);
                printf("\n      Ingrese el ID del tipo: \n");
                scanf("%d", &nuevoTipo);

                printf("\n   Nuevo tipo:  %s  \n", auxTipoDescripcion);
            }

         else
            {
                printf("\nIngrese el nuevo rodado: ");
                scanf("%f", &nuevoRodado);
                printf("Nuevo Rodado:  %.2f  \n", nuevoRodado);
            }
            printf("Confirma que desea modificar el campo [s] [n]\n?");
            fflush(stdin);
            scanf("%c", &confirma);

            if (confirma == 's')
            {
                if( rta == 1 )
                {
                    bicicletas[indice].idTipo = nuevoTipo;
                }
                else
                {
                    bicicletas[indice].rodado = nuevoRodado;
                }
                error = 0;

            }
            else
            {
                error = 2;
            }

        }

    }

    return error;

}



void mostrarBicicleta(bBicicleta bicicletas, bTipos tipos[],int tam_t,bColores colores[], int tam_c, bClientes clientes[], int tam_cl)
{

    char nombreColor[20];
    char descTipo[20];
    char descC[20];
    descripcionColor(colores,tam_c,bicicletas.idColor,nombreColor);
    descripcionTipos(bicicletas.idTipo,tipos,tam_t,descTipo);
    descripcionClientes(bicicletas.idCliente,clientes,tam_cl,descC);
    printf("      %4d          %.1f  %8s  %8s  %8s     %4d        %8s        \n",
           bicicletas.id,bicicletas.rodado,nombreColor,descTipo,bicicletas.marca,
           bicicletas.clientes.id,bicicletas.clientes.nombre);
}



int mostrarBicicletas(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c, bTipos tipos[], int tam_t, bClientes clientes[], int tam_cl)
{
    int error = 1;
    int flag = 0;

    if( bicicletas!= NULL && tam_b > 0)
    {
        system("cls");
        printf("---------------------------------------------------------------------------------------------------\n\n");
        printf("    ID BICICLETA   RODADO     COLOR    TIPO     MARCA      ID CLIENTE   NOMBRE CLIENTE              \n");
        printf("--------------------------------------------------------------------------------------------------\n\n");


        for(int i=0; i<tam_b; i++)
        {
            if(bicicletas[i].isEmpty == 0)
            {
  mostrarBicicleta(bicicletas[i],tipos,tam_t,colores,tam_c,clientes,tam_cl);
                flag = 1;
                printf("\n\n");

            }
        }

        if( flag == 0)
        {
            printf("No se han ingresado bicicletas");
        }

        error = 0;

    }
    return error;

}

int bajaBicicleta(bBicicleta bicicletas[],int tam_b,bTipos tipos[], int tam_t, bColores colores[],int tam_c, bClientes clientes[],int tam_cl)
{
    int error = 1;
    int indice;
    int confirma;
    int bajaID;
    if(bicicletas!= NULL && tam_b > 0)
    {
        system("cls");
        printf("----------------------------------------\n\n");
        printf("          BAJA DE BICICLETA              \n\n");
        printf("-----------------------------------------\n\n");

        mostrarBicicletas(bicicletas,tam_b,colores,tam_c,tipos,tam_t,clientes,tam_cl);

        printf("INGRESE ID DE LA BICICLETA QUE DESEA DAR DE BAJA: \n");
        scanf("%d", &bajaID);
        indice = buscarBicicleta(bicicletas, tam_b, bajaID);
        if( indice == -1)
        {
            printf("ERROR. ID INVALIDO. POR FAVOR, REINGRESE ID: \n");
            scanf("%d", &bajaID);
        }
        else
        {
            printf("CONFIRMA DAR DE BAJA LA BICICLETA? 1. [SI] 2. [NO]\n\n");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                bicicletas[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    if(error==0)
    {
        system("cls");
        printf("\nSE HA REALIZADO LA BAJA EXITOSAMENTE\n\n");
    }
    else if(error==2)
    {
        printf("\nLA BAJA HA SIDO CANCELADA POR EL USUARIO\n\n");
    }
    else
    {
        printf("\nERROR AL REALIZAR LA BAJA\n");
    }
    return error;

}


void ordenarBicicletas(bBicicleta bicicletas[], int tam_b, bTipos tipos[], int tam_t, bColores colores[], int tam_c)
{
    bBicicleta auxBicicleta;
    for (int i = 0; i < tam_b-1; i++)
    {
        for (int j = i+1; j < tam_b; j++)
        {
            if(bicicletas[i].idTipo> bicicletas[j].idTipo && !bicicletas[i].isEmpty && !bicicletas[i].isEmpty)
            {
                auxBicicleta = bicicletas[i];
                bicicletas[i] = bicicletas[j];
                bicicletas[j] = auxBicicleta;
            }
            if (bicicletas[i].idTipo == bicicletas[j].idTipo && bicicletas[i].rodado > bicicletas[j].rodado && !bicicletas[i].isEmpty && !bicicletas[i].isEmpty)
            {
                auxBicicleta = bicicletas[i];
                bicicletas[i] = bicicletas[j];
                bicicletas[j] = auxBicicleta;
            }
        }
    }
}


