/*
 * Pedido.h
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

struct
{
	int IdPedido;
	float kilosTotales;
	float HDPE;
	float LDPE;
	float PP;
	int IsEmpty;
}typedef Pedido;
/// \fn void HardcodearPedidos(Pedido[], int)
/// \brief Agrega datos falso a la lista de los pedidos
///
/// \pre
/// \post
/// \param lista de pedidos
/// \param tamanio de la lista
void HardcodearPedidos(Pedido lista[], int tamanio);
/// \fn void InicializarPedidos(Pedido[], int)
/// \brief  Agrega los espacios libres al array de pedidos
///
/// \pre
/// \post
/// \param lista de pedidos
/// \param tamanio de la lista
void InicializarPedidos(Pedido lista[],int tamanio);
/// \fn void BuscarPedidosPendientes(Pedido[], int, int, int*)
/// \brief Busca los pedidos pendientes que haya en la lista
///
/// \pre
/// \post
/// \param lista lista de pedidos
/// \param tamanio de la lista
/// \param index indice donde se va a buscar el pedido pendiente
/// \param indexpedido indice que devuelve del pedido
void BuscarPedidosPendientes(Pedido lista[],int tamanio,int index,int* indexpedido);
/// \fn void BuscarPedidosProcesados(Pedido[], int, int, int*)
/// \brief Busca los pedidos procesados que haya en la lista
///
/// \pre
/// \post
/// \param lista de pedidos
/// \param tamanio de la lista
/// \param index indice donde se va a buscar el pedido procesado
/// \param indexpedido indice del pedido que se encontro procesado
void BuscarPedidosProcesados(Pedido lista[],int tamanio,int index,int* indexpedido);
/// \fn int BuscarLibrePedido(Pedido[], int, int*)
/// \brief Busca un espacio libre en el array de pedidos
///
/// \pre
/// \post
/// \param lista de los pedidos
/// \param tamanio de la lista
/// \param index indice donde se verifica el indice del pedido
/// \return retorna el indice donde se encuentra habilitado
int BuscarLibrePedido(Pedido lista[],int tamanio,int* index);
/// \fn int CrearPedido(Pedido[], int, int, float, int)
/// \brief Crea un pedido y lo ubica en el cliente
///
/// \pre
/// \post
/// \param lista de los pedidos
/// \param tamanio de la lsita
/// \param id del nuevo pedido
/// \param totalBasura el total de basura que se recolecta
/// \param index indice del pedido
/// \return 1 si se pudo crear el pedido o 0 ssi no se pudo
int CrearPedido(Pedido lista[],int tamanio,int id,float totalBasura,int index);
/// \fn int ProcesarPedido(Pedido[], int, int)
/// \brief Finaliza un pedido pendiente e ingresa los datos que trae
///
/// \pre
/// \post
/// \param lista de pedidos
/// \param tamanio tamanio de la lsita
/// \param id ID del pedido a procesar
/// \return retorna 1 si se pudo procesar o 0 si no se pudo
int ProcesarPedido(Pedido lista[],int tamanio,int id);
/// \fn float CalcularTotalPP(Pedido[], int)
/// \brief Calcula la cantidad total de PP en los pedidos procesados
///
/// \pre
/// \post
/// \param lista pedidos
/// \param tamanio de la lista
/// \return retorna el total
float CalcularTotalPP(Pedido lista[],int tamanio);
#endif /* PEDIDO_H_ */
