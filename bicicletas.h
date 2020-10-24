#include "tipos.h"
#include "color.h"
#include "clientes.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;
    int isEmpty;
    bClientes clientes;

}bBicicleta;
#endif // BICICLETAS_H_INCLUDED
char menu();
/** \brief menu de opciones de gestion de bicicletas
 */
int altaBicicleta(bBicicleta bicicletas[], int tam_b, bTipos tipos[], int tam_t, bColores colores[], int tam_c, int idBici, int idCliente);
 /** \brief permite al usuario ingresar datos y dar de alta bicicleta
 * \param bicicletas[] bBicicleta estructura, array  bicicleta
 * \param tam_b int  tamaño del array bicicletas
 * \param colores[] bColores estructura, vector colores
 * \param tam_c int  tamaño del array colores
 * \param rodado[] bBicicleta array rodado de bicicleta
 * \param tipos[] bTipos estructura, array  tipos
 * \param tam_t int  tamaño del array tipos
 * \param clientes[] bClientes array clientes
 * \param tam_cl int  tamaño del array clientes
 * \return int devuelve si esta ok
 */
int initBicicletas(bBicicleta bicicletas[], int tam_b);
/** \brief inicializa el array de la estructura en 0
 * \param bicicletas[] bBicicleta estructura, array  bicicleta
 * \param tam_b int tamaño del array bicicletas
 * \return int  devuelve si esta ok
 */
int modificarBicicleta(bBicicleta bicicletas[],int tam_b,bColores colores[],int tam_c, bBicicleta rodado[], bTipos tipos[],int tam_t, bClientes clientes[], int tam_cl);
/** \brief permite modificar una bicicleta ingresada
 * \param bicicletas[] bBicicleta campo array de estructura bicicleta
 * \param tam_b int tamaño array bicicletas
 * \param colores[] bColores campo array de estructura colores
 * \param tam_c int tamaño de array colores
 * \param rodado[] bBicicleta rodados
 * \param tipos[] bTipos estructura,array tipos
  * \param tam_t int tamañ0 de array tipos
 * \param clientes[] bClientes  campo array de estructura clientes
 * \param tam_cl int tamaño del array clientes
 * \return int devuelve si esta ok
 */
int buscarBicicleta(bBicicleta bicicletas[],int tam_b,int idBici);
/** \brief busca lugar bicicleta
 * \param bicicletas[] bBicicleta estructura, campo bicicleta
 * \param tam_b int tamanio del vector bicicleta
 * \param idBici int id de la bicicleta
 * \return int retorna si esta ok
 */

void mostrarBicicleta(bBicicleta bicicletas, bTipos tipos[],int tam_t,bColores colores[], int tam_c, bClientes clientes[], int tam_cl);
/** \brief muestra una bicicleta
 * \param bicicletas bBicicleta estructura, campo bicicleta
 * \param tipos[] bTipos campo array de estructura tipos
 * \param tam_t int tamaño del array
 * \param colores[] bColores campo array de estructura colores
 * \param tam_c int tamaño array colores
 * \param clientes[] bClientes campo array de estructura clientes
 * \param tam_cl int tamño de array clientes
 * \return void no retorna nada
 */
int mostrarBicicletas(bBicicleta bicicletas[], int tam_b, bColores colores[], int tam_c, bTipos tipos[], int tam_t, bClientes clientes[], int tam_cl);
/** \brief  muestra todas las bicicletas ingresadas por el usuario
 * \param bicicletas[] bBicicleta campo array de estructura bicicleta
 * \param tam_b int tamaño de array bicicletas
 * \param colores[] bColores campo array de estructura colores
 * \param tam_c int tamaño array colores
 * \param tipos[] bTiposcampo array de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param clientes[] bClientes campo array de estructura clientes
 * \param tam_cl int tamaño array clientes
 * \return int retorna si esta ok
 */
int bajaBicicleta(bBicicleta bicicletas[],int tam_b,bTipos tipos[], int tam_t, bColores colores[],int tam_c, bClientes clientes[],int tam_cl);
/** \brief le permite al usuario dar de baja una bicicleta ingresada
 * \param bicicletas[] bBicicleta campo array de estructura bicicleta
 * \param tam_b int tamaño array bicicletas
 * \param tipos[] bTipos campo array de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param colores[] bColores campo array de estructura colores
 * \param tam_c int tamaño array colores
 * \param clientes[] bClientes campo array de estructura clientes
 * \param tam_cl inttamaño array clientes
 * \return int retorna si esta ok
 */
void ordenarBicicletas(bBicicleta bicicletas[], int tam_b, bTipos tipos[], int tam_t, bColores colores[], int tam_c);
/** \brief  ordena las bicicletas
 * \param bicicletas[] bBicicleta
 * \param tam_b int tamaño array bicicletas
 * \param tipos[] bTipos campo array de estructura tipos
 * \param tam_t int tamaño array tipos
 * \param colores[] bColores campo array de estructura colores
 * \param tam_c inttamaño array colores
 * \return void no retorna
 */
