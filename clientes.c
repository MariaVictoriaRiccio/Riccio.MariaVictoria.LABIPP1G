#include "clientes.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int descripcionClientes(int id,bClientes clientes[],int tam_cl,char desc[]){
    int error = 1;
    if(clientes!= NULL && tam_cl > 0 && desc != NULL)
    {
        for (int i = 0; i<tam_cl ; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(desc,clientes[i].nombre);
                error = 0;
                break;
            }
        }
    }

return error;
}

