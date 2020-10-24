#include "servicios.h"
#include "bicicletas.h"
#include "tipos.h"
#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int isEmpty;
    int idServicio;
eFecha fecha;

}bTrabajos;


#endif // TRABAJOS_H_INCLUDED
int buscarTrabajoLibre(bTrabajos trabajos[], int tam_tr);
/** \brief busca lugar libre
 * \param trabajos[] bTrabajos estructura y su campo trabajos array
 * \param tam_tr int tamaño del array trabajos
 * \return int si esta ok.
 */
int altaTrabajo(bTrabajos trabajo[], int tam_tr, bBicicleta bicicletas[],int tam_b,bServicios servicios[], int tam_s,bTipos tipo[],int tam_t,bColores colores[], int tam_c, int idTrabajo, bClientes clientes[], int tam_cl);
/** \brief permite dar de alta los trabajos
 * \param trabajo[] bTrabajos campo de estructura trabajos
 * \param tam_tr int  tamaño del array trabajos
 * \param bicicletas[] bBicicleta campo de estructura bicicletas
 * \param tam_b int  tamaño del array bicicletas
 * \param servicios[] bServicios campo de  estructura servicios
 * \param tam_s int tamaño del array servicios
 * \param tipo[] bTipos campo de estructura tipos
 * \param tam_t int tamaño del array tipos
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño del array colores
 * \param idTrabajo int id trabajo
 * \param clientes[] bClientes campo de estructura clientes
 * \param tam_cl int tamaño del array clientes
 * \return int retonra ok.
 */
int listarTrabajos(bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_s);
/** \brief muestra los trabajos
 * \param trabajos[] bTrabajos  campo de estructura trabajos
 * \param tam_tr int tamaño del array tranajos
 * \param servicios[] bServicios campo de estructura servicios
 * \param tam_s int  tamaño del array clientes
 * \return int retorna ok
 */
void listarTrabajo(bTrabajos trabajo, bServicios servicios[], int tam_s);
/** \brief muestra un trabajo
 * \param trabajos[] bTrabajos  campo de estructura trabajos
 * \param tam_tr int tamaño del array trabajos
 * \param servicios[] bServicios campo de estructura servicios
 * \param tam_s int  tamaño del array clientes
 * \return void
 */

int initTrabajo(bTrabajos trabajos[], int tam_tr);
/** \brief inicializa trabajos
 * \param trabajos[] bTrabajos campo de estructura trabajos
 * \param tam_tr int tamaño array trabajos
 * \return int retorna ok.
 */
