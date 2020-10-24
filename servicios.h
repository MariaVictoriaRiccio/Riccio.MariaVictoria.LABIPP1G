#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} bServicios;



#endif // SERVICIOS_H_INCLUDED

void listarServicio(bServicios servicio);

     /** \brief lista un servicio
 * \param servicio bServicios  campo de la estructura, array
 * \return void no retorna
 */

int listarServicios(bServicios servicios[], int tam_s);
/** \brief lista todos los servicios
 * \param servicios[] bServicios campo de la estructura, array
 * \param tam_s int tamaño array servicios
 * \return int  retorna si esta ok.
 */

int mostrarDescServicios(int id, bServicios servicio[], int tam_s,char descripcionServ[]);
/** \brief mostrar descripcion de los servicios
 * \param id int id del servicio
 * \param servicio[] bServicios campo del a estructura,array
 * \param tam_s int tamaño del array
 * \param descripcionServ[] char descripcion.
 * \return int retorna si esta ok.
 */
