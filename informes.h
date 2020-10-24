#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#endif // INFORMES_H_INCLUDED
int mostrarMenuInformesPrincipal(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c,bTipos tipos[],int tam_t,bClientes clientes[],int tam_cl,bTrabajos trabajos[], int tam_tr, bServicios servicios[],int tam_serv);
/** \brief muestra el menu principal de informes
 * \param bicicletas[] bBicicleta campo array de estructura bicicletas
 * \param tam_b int tamaño del array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño del array colores
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño del array tipos
 * \param clientes[] bClientes campo de estructura clientes
 * \param tam_cl inttamaño del array clientes
 * \param trabajos[] bTrabajos campo de estructura trabajos
 * \param tam_tr int tamaño del array trabajos
 * \param servicios[] bServicios campo de estructura servicios
 * \param tam_serv int tamaño del array servicios
 * \return int si esta ok.
 */
int menuInformes();
/** \brief menu de informes
 * \return int retorna entero,opcion selecc por el usuario
 */
int informarBicicletasxColor(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl);
/** \brief informa las bicicletas segun el color que desee el usuario
 * \param bicicletas[] bBicicleta campo de estructura bicicletas
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param clientes[] bClientes campo de estructura clientes
 * \param tam_cl int tamaño array clientes
 * \return int retorna si esta ok.
 */

int informarBicicletasxTipo(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl);
/** \brief  informa bicicletas por el tipo seleccionado x el usuario
 * \param bicicletas[] bBicicleta campo de estructura bicicleta
 * \param tam_b inttamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param clientes[] bClientes campo de estructura clientes
 * \param tam_cl int tamaño array clientes
 * \return int  retorna si esta ok.
 */
int informarBicicletasDeMenorRodado(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t);
/** \brief informa cuantas bicicletas son y cual es el menor rodado ingresado
 * \param bicicletas[] bBicicleta campo de estructura bicicletas
 * \param tam_b int tamañ0 estructura bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño array  tipos
 * \return int  retorna si esta ok.
 */
int informarBicicletasSeparadasSegunTipo(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl);
/** \brief informa las bicicletas segun su tipo
 * \param bicicletas[] bBicicleta campo de estructura bicicletas
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTipos  campo de estructura  tipos
 * \param tam_t int  tamaño array tipos
 * \param clientes[] bClientes  campo de estructura  clientes
 * \param tam_cl int tamaño array clientes
 * \return int  retorna si esta ok.
 */
int informarBicicletasColoryTipoxUsuario(bBicicleta bicicletas[], int tam_b,bColores colores[], int tam_c, bTipos tipos[], int tam_t,bClientes clientes[], int tam_cl);
/** \brief informa las bicicletas x su tipo y color segun seleccione el usuario
 * \param bicicletas[] bBicicleta campo de estructura  bicicleta
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTipos campo de estructura  tipos
 * \param tam_t int tamaño array tipos
 * \param clientes[] bClientes campo de estructura  clientes
 * \param tam_cl int tamaño array clientes
 * \return int  retorna si esta ok.
 */

int informeTotalaPAgarPorServUnaBicicleta(bBicicleta bicicletas[], int tam_b,bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_serv);
/** \brief informa el total a pagar de los servicios realizados a una bicicleta
 * \param bicicletas[] bBicicleta campo de estructura  bicicletas
 * \param tam_b int tamaño array bicicletas
 * \param trabajos[] bTrabajos campo de estructura   trabajos
 * \param tam_tr int tamaño array trabajos
 * \param servicios[] bServicios campo de estructura servicios,array
 * \param tam_serv int tamaño arrayservicios
 * \return int  retorna si esta ok.
 */


void colorMasElegidoPorLosClientes(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c);
/** \brief muestra color mas elegido por los clientes
 * \param bicicletas[] bBicicleta campo de estructura  bicicleta
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \return void
 */


int trabajosRealizadosAunaBicicleta(bBicicleta bicicleta[],int tam_b,bColores colores[], int tam_c, bTrabajos trabajos[],int tam_tr, bServicios servicios[],int tam_s, bTipos tipos[],int tam_t, bClientes clientes[], int tam_cl);

/** \brief muestra los trabajos realizados a una bicicleta mediante su id
 * \param bicicleta[] bBicicleta  campo de estructura bicicletas
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param trabajos[] bTrabajos campo de estructura trabajos
 * \param tam_tr int tamaño array  trabajos
 * \param servicios[] bServicios campo de estructura servicios
 * \param tam_s int tamaño array  servicios
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param clientes[] bClientes campo de estructura clientes
 * \param tam_cl int tamañ o array clientes
 * \return int  retorna si esta ok.
 */

 int serviciosRealizadosXfecha(bTrabajos trabajos[], int tam_tr, bServicios servicios[], int tam_s, eFecha fechas);
