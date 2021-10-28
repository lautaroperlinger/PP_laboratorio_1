/*
 * Pedido.h
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>
#include <string.h>
typedef struct
{
	int idPedido;
	float kilosTotales;
	float HDPE;
	float LDPE;
	float PP;
	int idCliente;
	int estado;//1 pendiente,-1 completado
	int isEmpty;
}Pedido;
/// \fn void HardcodearPedidos(Pedido[], int)
/// \brief Agrega datos al array de pedidos
///
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedidos
void HardcodearPedidos(Pedido listapedidos[], int tamaniopedidos);
/// \fn void InicializarPedidos(Pedido[], int)
/// \brief Inicializa los pedidos para poder ingresar los datos
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedidos
void InicializarPedidos(Pedido listapedidos[],int tamaniopedidos);
/// \fn int BuscarEspacioPedido(Pedido[], int, int*)
/// \brief Busca un espacio libre en el array y devuelve su indice
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedido
/// \param index
/// \return
int BuscarEspacioPedido(Pedido listapedidos[],int tamaniopedido,int* index);
/// \fn int CrearPedido(Pedido[], int, int, int, float, int)
/// \brief Se agregas los datos solicitados al usuario y los agrega al array de pedidos
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedidos
/// \param idpedido
/// \param idcliente
/// \param totalBasura
/// \param index
/// \return
int CrearPedido(Pedido listapedidos[],int tamaniopedidos,int idpedido,int idcliente,float totalBasura,int index);
/// \fn int ProcesarPedido(Pedido[], int, int)
/// \brief Termina de procesar el pedido pendiente
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedido
/// \param idpedido
/// \return
int ProcesarPedido(Pedido listapedidos[],int tamaniopedido,int idpedido);
/// \fn int ContadorPedidos(Pedido[], int, int, int)
/// \brief Cuenta los pedidos que hay en total
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedidos
/// \param idcliente
/// \param estado
/// \return
int ContadorPedidos(Pedido listapedidos[],int tamaniopedidos,int idcliente,int estado);
/// \fn float CalcularTotalPP(Pedido[], int)
/// \brief Calcula el total de PP que hay por pedido
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedido
/// \return
float CalcularTotalPP(Pedido listapedidos[],int tamaniopedido);
#endif /* PEDIDO_H_ */
