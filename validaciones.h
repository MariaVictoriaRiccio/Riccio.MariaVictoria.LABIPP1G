#include "color.h"
#include "tipos.h"
#include "bicicletas.h"
#include "servicios.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


#endif // VALIDACIONES_H_INCLUDED
int validarColores(bColores colores[], int tam_c, int idC);
/** \brief valida colores
 * \param colores[] bColores campo de estructura colores
 * \param tam_c int tamaño array colores
 * \param idC int id colores
 * \return int retorna ok.
 */
int validarIdTipo(bTipos tipos[], int tam_t, int id);
/** \brief validar id tipo
 * \param tipos[] bTipos campo de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param id int id de tipos
 * \return int retora si esta ok.
 */

int validarMarca(char cadena[]);
/** \brief valida cadena de caracteres
 * \param cadena[] char
 * \return int retorna ok
 */
int validarServId(bServicios servicios[],int tam_s, int id);
/** \brief valida id de los servicios
 * \param servicios[] bServicios campo de estructura servicios
 * \param tam_s int tamaño array servicios
 * \param id int id de servicios
 * \return int retorna si esta ok.
 */
int validarFecha(int dia, int mes, int anio);
/** \brief valida fecha correcta
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int retorna si esta ok.
 */
int validarSexo(char sexo);
/** \brief valida sexo f o m/ F o M
 * \param sexo char
 * \return int retorna si esta ok.
 */

int validarIdBici(bBicicleta bicicletas[], int tam_b, int auxIdBici);
/** \brief valida id de la bicicleta dentro de las ingresadas
 * \param bicicletas[] bBicicleta campo de estructura bicicleta
 * \param tam_b int tamaño de array bicicleta
 * \param auxIdBici int auxiliar del id de la bicicleta
 * \return int retorna si esta ok.
 */
