
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
typedef struct{
int id;
char nombreColor[20];
}bColores;


#endif // COLOR_H_INCLUDED

void mostrarColores (bColores colores[],int tam_c);
/** \brief muestra los colores
 * \param colores[] bColores
 * \param tam_c int
 * \return void no retorna.
 */
int descripcionColor(bColores color[],int tam_c,int idColor,char nombreColor[]);
/** \brief muestra los colores
 * \param color[] bColores vector de la estructura bcolores
 * \param tam_c int tamanio del vector
 * \param idColor int id del color
 * \param nombreColor[] char nombre del color
 * \return int retorna dato entero si esta ok.
 */
void mostrarColor(bColores color);
/** \brief muestra un color
 * \param bColores color , var de la estructura colores
 * \return void no retorna.
 */
