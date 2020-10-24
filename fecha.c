#include "fecha.h"

#include <stdio.h>

void mostrarFecha(eFecha unaFecha)
{
    printf("%02d/%02d/%d\n", unaFecha.dia, unaFecha.mes,unaFecha.anio);
}

