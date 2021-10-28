/*
 * Informes.h
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Pedido.h"
#include "Cliente.h"
#include "Localidad.h"


#endif /* INFORMES_H_ */
/// \fn void InformarCliente(Cliente[], int, Localidad[], int, int, int)
/// \brief Informa un cliente en especifico
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamaniocliente
/// \param listalocalidad
/// \param indexcliente
/// \param indexlocalidad
/// \param totalpedidos
void InformarCliente(Cliente listaclientes[],int tamaniocliente,Localidad listalocalidad[],int indexcliente,int indexlocalidad,int totalpedidos);
/// \fn void InformarClientes(Cliente[], int, Pedido[], int, Localidad[], int)
/// \brief Informa todo un array especifico del tipo cliente
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamaniocliente
/// \param listapedidos
/// \param tamaniopedidos
/// \param listalocalidad
/// \param tamaniolocalidad
void InformarClientes(Cliente listaclientes[],int tamaniocliente,Pedido listapedidos[],int tamaniopedidos,Localidad listalocalidad[],int tamaniolocalidad);
/// \fn void InformarPedidos(Pedido[], int, Cliente[], int, int)
/// \brief Informa todo un array de pedidos.
///
/// \pre
/// \post
/// \param listapedidos
/// \param tamaniopedido
/// \param listaclientes
/// \param tamanioclientes
/// \param estado
void InformarPedidos(Pedido listapedidos[],int tamaniopedido,Cliente listaclientes[],int tamanioclientes, int estado);
/// \fn void InformarLocalidades(Localidad[], int)
/// \brief Informa todo un array de localidades
///
/// \pre
/// \post
/// \param listalocalidades
/// \param tamaniolocalidades
void InformarLocalidades(Localidad listalocalidades[],int tamaniolocalidades);
/// \fn void InformarPedidosPendientesxLocalidad(Cliente[], int, Pedido[], int, int)
/// \brief Informa el total de pedidos que tiene una determinada localidad que se le pide al usuario
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param listapedidos
/// \param tamaniopedidos
/// \param idlocalidad
void InformarPedidosPendientesxLocalidad(Cliente listaclientes[],int tamanioclientes,Pedido listapedidos[],int tamaniopedidos,int idlocalidad);
/// \fn void InformarPromedioPP(Cliente[], int, Pedido[], int)
/// \brief Informa el promedio de PP que hay por cliente
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamaniocliente
/// \param listapedidos
/// \param tamaniopedidos
void InformarPromedioPP(Cliente listaclientes[],int tamaniocliente,Pedido listapedidos[],int tamaniopedidos);
/// \fn void InformarClientexPedidos(Cliente[], int, Pedido[], int, int)
/// \brief Informa un cliente en especifico dependiendo que estado tenga, si tiene 0 informa el cliente
/// con mas pedidos, 1 para el cliente que tenga mas pedidos pendientes y -1 para el cliente con mas pedidos procesados.
///
/// \pre
/// \post
/// \param listaclientes
/// \param tamanioclientes
/// \param listapedidos
/// \param tamaniopedidos
/// \param estado
void InformarClientexPedidos(Cliente listaclientes[],int tamanioclientes,Pedido listapedidos[],int tamaniopedidos,int estado);
