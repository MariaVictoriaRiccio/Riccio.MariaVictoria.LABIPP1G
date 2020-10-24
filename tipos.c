#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "tipos.h"

void mostrarTipo (bTipos tipo)
{
    printf("   %8d   %15s\n",tipo.id, tipo.descripcion);
}


int mostrarTipos(bTipos tipos[],int tam_t)
{
    int error =1;
    if (tipos!=NULL && tam_t>0)
    {
        printf("\n");
        printf("        ID              TIPOS   \n");
        printf("    -------------------------------\n");
        for (int i=0; i<tam_t; i++)
        {
            mostrarTipo(tipos[i]);
        }
        error =0;

    }
    return error;
}
int descripcionTipos(int id,bTipos tipos[],int tam_t,char desc[])

{
    int error=1;
    for (int i=0; i<tam_t; i++)
    {
        if (id==tipos[i].id)
        {
            strcpy(desc,tipos[i].descripcion);
            error=0;
            break;
        }

    }

    return error;

}
