#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

} bTipos;

#endif // TIPOS_H_INCLUDED
void mostrarTipo (bTipos tipo);
/** \brief muestra el tipo de bicicleta
 * \param bTipos tipo estructura con campo array tipo
 * \return
 */

int mostrarTipos(bTipos tipos[],int tam_t);
/** \brief muestra los tipos de bicicleta
 *
 * \param tipos[] bTipos estructura tipos, array campo dentro de estructura
 * \param tam_t int tamaño del array tipos
 * \return int devuelve si ok.
 */

int descripcionTipos(int id,bTipos tipos[],int tam_t,char desc[]);
/** \brief permite l descripcion de los tipos de bicicleta x su id
 * \param bTipos tipos[]  estructura tipos, array campo dentro de estructura
 * \param tam_t tamaño del array tipos
 * \param char desc[]  descripcion tipos
 * \return int retorna si esta ok.
 */
