/*
 * Cliente.h
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Pedido.h"
struct
{
	char Calle[51];
	int numeracion;

}typedef Direccion;
struct
{
	int ID;
	char nombre[51];
	long long int cuit;
	Direccion direccion;
	char localidad[51];
	int IsEmpty;
	int IDpedido[10];
	int estado[10];
}typedef Cliente;
/// \fn void HardcodearClientes(Cliente[], int)
/// \brief  Ingresa una serie de datos falsos a la lista de los clientes
///
/// \pre
/// \post
/// \param lista la lista donde se ingresan
/// \param tamanio tamanio de la lista
void HardcodearClientes(Cliente lista[], int tamanio);
/// \fn void InicializarClientes(Cliente[], int)
/// \brief Valida todos los indices de la lista donde se van a ingresar los pedidos para poder ingresarlos
///
/// \pre
/// \post
/// \param lista lista de los clientes donde inicializan
/// \param tamanio tamanio de la lista
void InicializarClientes(Cliente lista[],int tamanio);
/// \fn int ContadorPedidos(Cliente[], int, int)
/// \brief Cuenta la cantidad de los pedidos pendientes que tiene los clientes
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista de los clientes
/// \param index indice de la lista de los clientes donde se van a verificar que tenga pedido
/// \param estado 1 si es pendiente, -1 si es procesado y 0 si es total
/// \return retorna la cantidad de pedidos que tiene el cliente
int ContadorPedidos(Cliente lista[],int tamanio,int index,int estado);
/// \fn void BuscarCliente(Cliente[], int, int*, int)
/// \brief Busca un cliente en especifico a traves de su ID y devuelve el indice donde se encuentra
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param index indice que devuelve la funcion
/// \param id el id a verificar en la lista
void BuscarCliente(Cliente lista[],int tamanio,int *index,int id);
/// \fn int AgregarCliente(Cliente[], int, int, char[], long long int, char[], int, char[], int)
/// \brief Agrega un cliente a la lista
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param id id del nuevo clientes
/// \param nombre nombre de la empresa
/// \param cuit cuit de la empresa
/// \param calle calle donde se ubica
/// \param numeracion la numeracion de la calle
/// \param localidad localidad donde se encuentra
/// \param index indice donde hay un espacio libre para ese clientes
/// \return retorna 1 si se pudo ingresar el cliente y 0 si no se pudo
int AgregarCliente(Cliente lista[],int tamanio,int id,char nombre[],long long int cuit,char calle[],int numeracion,char localidad[],int index);
/// \fn int BuscarEspacioCliente(Cliente[], int, int*)
/// \brief verifica el indice en la lista que haya un espacio libre y lo devuelve para agregar a un cliente nuevo
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param index indice que se analiza
/// \return retorna 1 si hay espacio y 0 si no hay
int BuscarEspacioCliente(Cliente lista[],int tamanio,int* index);
/// \fn int ModificarCliente(Cliente[], int, int, int, int)
/// \brief Modifica la direccion o la localidad de un cliente
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param id ID del cliente a modificas
/// \param tamanioCadena tamanio general de las cadenas de caracteres
/// \param respuesta del usuario, si ingresa 1 modifica la direccion si ingresa 2 modifica la localidad
/// \return retorna 1 si es pudo modificar y 0 si no se pudo
int ModificarCliente(Cliente lista[],int tamanio,int id,int tamanioCadena,int respuesta);
/// \fn int DarBajaCliente(Cliente[], int, int)
/// \brief Da de baja logica al cliente
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param id ID del cliente a dar de baja
/// \return
int DarBajaCliente(Cliente lista[],int tamanio,int id);
/// \fn int BuscarEspacioPedidoCliente(Cliente[], int, int, int*)
/// \brief Busca un espacio libre el la lista de los pedidos que puede tener el cliente
///
/// \pre
/// \post
/// \param lista lista de los clients
/// \param tamanio tamanio de la lista
/// \param index indice del cliente
/// \param indexEstado indice que devuelve donde esta el espacio libre
/// \return retorna 1 si hay espacio o 0 si no hay
int BuscarEspacioPedidoCliente(Cliente lista[],int tamanio,int index,int* indexEstado);
/// \fn void AgregarPedido(Cliente[], int, int, int, int)
/// \brief Agrega un pedido nuevo al cliente
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param indexcliente index del cliente a agregar el pedido
/// \param idpedido ID  del nuevo pedido
/// \param indexestado indice del espacio donde se ingresa el nuevo pedido
void AgregarPedido(Cliente lista[],int tamanio,int indexcliente,int idpedido,int indexestado);
/// \fn int FinalizarPedidoCliente(Cliente[], int, int)
/// \brief Da por completo el pedido de recoleccion
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \param idpedido ID del pedido a procesar
/// \return retorna 1 si se pudo completar y 0 si no se pudo
int FinalizarPedidoCliente(Cliente lista[],int tamanio,int idpedido);
/// \fn void PedidosporLocalidad(Cliente[], int, char[], int*)
/// \brief Calcula la cantidad de pedidos que hay por localidad
///
/// \pre
/// \post
/// \param listacliente lista de los clientes
/// \param tamanio tamanio de la lista
/// \param localidad la localidad donde se quiere saber la cantidad de pedidos pendientes
/// \param cantidadtotal la cantidad que devuelve
void PedidosporLocalidad(Cliente listacliente[],int tamanio,char localidad[],int* cantidadtotal);
/// \fn int CantidadClientes(Cliente[], int)
/// \brief Calcula cuantos clientes tenemos en total registrados
///
/// \pre
/// \post
/// \param lista lista de los clientes
/// \param tamanio tamanio de la lista
/// \return devuelve la cantidad de clientes
int CantidadClientes(Cliente lista[],int tamanio);
int ClienteconMasPedidos(Cliente lista[],int tamanio,int estado);

#endif /* CLIENTE_H_ */
