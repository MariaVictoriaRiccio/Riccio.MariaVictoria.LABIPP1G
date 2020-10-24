#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct{
int id;
char nombre[20];
char sexo;
int isEmpty;
}bClientes;

#endif // CLIENTES_H_INCLUDED
int descripcionClientes(int id,bClientes clientes[],int tam_cl,char desc[]);
/** \brief permite obtener la descripcion de los clientes
 * \param id int id del cliente
 * \param clientes[] bClientes estructura,vector clientes
 * \param tam_cl int tamanio del vector clientes
 * \param desc[] char descripcion
 * \return int retorna si esta ok.
 */
