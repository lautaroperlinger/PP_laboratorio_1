/*
 * Informes.h
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Cliente.h"
#include "Pedido.h"
/// \fn void Menu(int*, char[], char[], int, int)
/// \brief menu donde se imprime las opciones y devuelve la opcion que se ingreso
///
/// \pre
/// \post
/// \param devuelve a la direccion de memoria la opcion elegida
/// \param mensaje que se imprime en el menu
/// \param mensaje que se imprime si se ingreso una opcion valida
/// \param maximo de la opcion a ingresar
/// \param minimo de la opcion a ingresar
void Menu(int* opcion,char mensaje[],char mensajeError[],int maximo,int minimo);
/// \fn void InformarCliente(Cliente[], int, int, int)
/// \brief informa solo un cliente en expecifico
///
/// \pre
/// \post
/// \param lista que va a informar los clientes
/// \param tamanio de la lista
/// \param index del cliente
/// \param totalOrdenes cantidad de ordenes que tiene el cliente
void InformarCliente(Cliente lista[],int tamanio,int index,int totalOrdenes);
/// \fn void InformarClienteS(Cliente[], int)
/// \brief imprime varios clientes en forma de lista
///
/// \pre
/// \post
/// \param lista la lista donde se encuentras los clientes
/// \param tamanio cantidad de indices que tiene el array
void InformarClienteS(Cliente lista[],int tamanio);
/// \fn void InformarPedidoPendiente(Pedido[], Cliente[], int)
/// \brief imprime un pedido pendiente en especifico
///
/// \pre
/// \post
/// \param listapedido lista en donde se encuentra los pedidos
/// \param listacliente lista donde se encuentra los clientes
/// \param tamanio de la lista de pedidos
void InformarPedidoPendiente(Pedido listapedido[],Cliente listacliente[],int tamanio);
/// \fn void InformarPedidoProcesados(Pedido[], Cliente[], int)
/// \brief prime un pedido procesado en especifico
///
/// \pre
/// \post
/// \param listapedido lista en donde se encuentra los pedidos
/// \param listacliente lista donde se encuentra los clientes
/// \param tamanio de la lista de pedidos
void InformarPedidoProcesados(Pedido listapedido[],Cliente listacliente[],int tamanio);
/// \fn void InformarPedidoS(Cliente[], Pedido[], int, int)
/// \brief Informa varios pedidos que pueden ser pendientes o completos
///
/// \pre
/// \post
/// \param listacliente la lista de los clientes
/// \param listapedido lista de los pedidos que se informan
/// \param tamanio tamanio de la lista de los pedidos
/// \param estado si estado es 1 imprime los pendientes, si estado es -1 imprime los completados
void InformarPedidoS(Cliente listacliente[],Pedido listapedido[],int tamanio,int estado);
/// \fn void InformarPendientesporLocalidad(Cliente[], int, char[])
/// \brief Informa la cantidad de pedidos que se encuentran en la localidad que pide el usuario
///
/// \pre
/// \post
/// \param listacliente la lista de los clientes donde se analiza los datos
/// \param tamanio tamanio de la lista de clientes
/// \param localidad nombre de la localidad que pide el usuario
void InformarPendientesporLocalidad(Cliente listacliente[],int tamanio,char localidad[]);
/// \fn void InformarPromedioPP(Cliente[], int, Pedido[], int)
/// \brief Imprime el promedio de poli
///
/// \pre
/// \post
/// \param listacliente la lista de los clientes
/// \param tamanio tamanio de la lista de los clientes
/// \param listapedido lista de los pedidos
/// \param tamaniopedido tamanio de la lista de los pedidos
void InformarPromedioPP(Cliente listacliente[],int tamanio,Pedido listapedido[],int tamaniopedido);
#endif /* INFORMES_H_ */
