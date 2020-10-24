#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"


void mostrarColor(bColores color){
printf("    %d   %10s\n",color.id,color.nombreColor);
}


void mostrarColores (bColores colores[],int tam_c){
 printf("\n\n");
 printf("   ---------------------------\n");
 printf("     ID        COLORES        \n");
 printf("   ---------------------------\n");


 for (int i=0;i<tam_c;i++){
if(colores!=NULL){
mostrarColor(colores[i]);
}
}
}

int descripcionColor(bColores color[],int tam_c,int idColor,char nombreColor[]){

    int error = 1;
    if(color!= NULL && tam_c > 0 && nombreColor != NULL)
    {
        for (int i = 0; i<tam_c ; i++)
        {
            if(color[i].id == idColor)
            {
                strcpy(nombreColor,color[i].nombreColor);
                error = 0;
                break;
            }
        }
    }

    return error;

}
