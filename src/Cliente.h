/*
 * Cliente.h
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <string.h>
typedef struct
{
	char Calle[50];
	int numeracion;
}Direccion;
typedef struct
{
	int idCliente;
	char nombre[50];
	long long int cuit;
	Direccion direccion;
	int idLocalidad;
	int isEmpty;

}Cliente;
/// \fn void HardcodearClientes(Cliente[], int)
/// \brief Agrega datos falsos al array de cliente
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
void HardcodearClientes(Cliente listaclientes[], int tamanioclientes);
/// \fn void InicializarClientes(Cliente[], int)
/// \brief Inicializa el array de cliente para poder ingresar datos
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
void InicializarClientes(Cliente listaclientes[],int tamanioclientes);
/// \fn int BuscarEspacioCliente(Cliente[], int, int*)
/// \brief Busca en el array un espacio libre que tenga y devuelve el indice
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param index
/// \return 1 si hay espacio y 0 si no hay
int BuscarEspacioCliente(Cliente listaclientes[],int tamanioclientes,int* index);
/// \fn int AgregarCliente(Cliente[], int, int, char[], long long int, char[], int, int, int)
/// \brief Agrega los datos que se le solicitaron al cliente y los agrega al indice en el array
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param idcliente
/// \param nombre
/// \param cuit
/// \param calle
/// \param numeracion
/// \param idlocalidad
/// \param indexlibre
/// \return
int AgregarCliente(Cliente listaclientes[],int tamanioclientes,int idcliente,char nombre[],long long int cuit,char calle[],int numeracion,int idlocalidad,int indexlibre);
/// \fn int ModificarCliente(Cliente[], int, int, int, int)
/// \brief Modifica los datos del cliente que se solicitan
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamaniocliente
/// \param idcliente
/// \param tamanioCadena
/// \param respuesta
/// \return
int ModificarCliente(Cliente listaclientes[],int tamaniocliente,int idcliente,int tamanioCadena,int respuesta);
/// \fn int BajaCliente(Cliente[], int, int)
/// \brief  Baja logicamente al cliente
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param idcliente
/// \return
int BajaCliente(Cliente listaclientes[],int tamanioclientes,int idcliente);
/// \fn void BuscarCliente(Cliente[], int, int, int*)
/// \brief Busca en el array un cliente en especifico a traves del ID y devuelve el indice donde se encuentra
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param id
/// \param indexcliente
void BuscarCliente(Cliente listaclientes[],int tamanioclientes,int id,int* indexcliente);
/// \fn int CantidadClientes(Cliente[], int)
/// \brief Cuenta el total de clientes que hay en el array
///
/// \pre
/// \post
/// \param lista
/// \param tamanio
/// \return
int CantidadClientes(Cliente lista[],int tamanio);
#endif /* CLIENTE_H_ */
