#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[11];
    int isEmpty;
}Cliente;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Cliente* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cliente_inicializar(Cliente* arrayClientes, int limite);

int cliente_buscarPorId(Cliente* arrayClientes,int limite, int id);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok

*/
int cliente_altaForzada(Cliente* arrayClientes, int limite, char nombre[],char apellido[],char cuit[]);

int cliente_alta(Cliente* arrayClientes,int limite);

int cliente_mostrar(Cliente* arrayClientes,int limite);

int cliente_modificar(Cliente* arrayClientes, int limite,int index);

int cliente_baja(Cliente* arrayClientes,int limite, int id);
