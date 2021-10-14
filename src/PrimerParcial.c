/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Pedido.h"
#include "Informes.h"
#include "Funciones.h"
#define TAM 100
#define TAMPE 1000
#define TAMCAD 51
int main(void) {
	setbuf(stdout,NULL);
	Cliente listaClientes[TAM];
	Pedido listaPedidos[TAMPE];
	int respuesta;
	int flagopcion;
	int flagpedido;
	int index;
	int indexpedido;
	int indexestado;
	long long int auxcuit;
	char auxnombre[TAMCAD];
	char auxcalle[TAMCAD];
	int auxnumeracion;
	char auxlocalidad[TAMCAD];
	int auxrespuesta;
	int auxid;
	int idCliente;
	float auxBasura;
	int idPedido;
	idCliente=500;
	idPedido=100;
	flagopcion=0;
	flagpedido=0;
	InicializarClientes(listaClientes, TAM);
	InicializarPedidos(listaPedidos, TAMPE);
	do
	{	printf("MENU DE OPCIONES\n");
		printf("----------------\n");
		Menu(&respuesta, "1-Alta de cliente:\n2-Modificar datos de cliente:\n3-Baja de cliente:\n4-Crear pedido de recolección:\n5-Procesar residuos:\n6-Imprimir Clientes:\n7-Imprimir Pedidos pendientes:\n8-Imprimir Pedidos procesados:\n9-Cantidad de pedidos por localidad\n10-PP promedio por cliente\n11-Cliente con mas pedidos \n12-Cliente con mas pedidos procesados\n13-Cliente con mas pedidos pendientes\n15-Salir\n", "Opcion no valida, ingrese otra", 15, 1);
		switch(respuesta)
		{
			case 1:
				if(BuscarEspacioCliente(listaClientes, TAM,&index)==0)
				{
					PedirCadena(auxnombre, "Ingrese nombre de la empresa:", TAMCAD);
					PedirEnteroLargo(&auxcuit, "Ingrese cuit de la empresa(sin guiones)ejemplo: 20430211952:", 20000000000);
					PedirCadena(auxcalle, "Ingrese la calle:", TAMCAD);
					PedirEntero(&auxnumeracion, "Ingrese la numeracion de la calle", 0,10000);
					PedirCadena(auxlocalidad, "Ingrese localiad donde se encuentra la empresa:", TAMCAD);
					if(AgregarCliente(listaClientes, TAM, idCliente, auxnombre, auxcuit, auxcalle, auxnumeracion, auxlocalidad, index)==1)
					{
						printf("El cliente se agrego exitosamente!\n");
						idCliente++;
					}
					else
					{
						printf("No se pudo agregar al cliente!\n");
					}
				}
				else
				{
					printf("no hay memoria jejox\n");
				}
				//HardcodearClientes(listaClientes, TAM);
				flagopcion=1;
						break;
			case 2:
				if(flagopcion==1)
				{
					InformarClienteS(listaClientes, TAM);
					PedirEntero(&auxid, "Ingrese el ID del cliente a modificar:",500,600);
					Menu(&auxrespuesta, "1-modificar direccion\n2-modificar localidad\n", "opcion no valida", 5, 1);
					if(ModificarCliente(listaClientes, TAM, auxid, TAMCAD,auxrespuesta)==1)
					{
						printf("se pudo modificar con exito!\n");
						system("pause");
					}
					else
					{
						printf("no se pudo modificar!\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 3:
				if(flagopcion==1)
				{
					InformarClienteS(listaClientes, TAM);
					PedirEntero(&auxid, "Ingrese el ID del cliente a dar de baja:",500,600);
					if(DarBajaCliente(listaClientes, TAM, auxid)==1)
					{
						printf("la baja del cliente fue exitosa!\n");
					}
					else
					{
						printf("no se pudo dar de baja el cliente!\n");
					}

				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 4:
				if(flagopcion==1)
				{
					//HardcodearPedidos(listaPedidos, TAMPE);
					InformarClienteS(listaClientes, TAM);
					PedirEntero(&auxid, "Ingrese el ID del cliente para crear el pedido de recoleccion:",500,600);
					BuscarCliente(listaClientes, TAM, &index, auxid);
					PedirFlotante(&auxBasura, "Ingrese el total de basura a recoletar:", 0);
					if(BuscarLibrePedido(listaPedidos, TAMPE, &indexpedido)==0)
					{
						if(CrearPedido(listaPedidos, TAMPE, idPedido, auxBasura, indexpedido)==0)
						{
							if(BuscarEspacioPedidoCliente(listaClientes, TAM, index,&indexestado)==0)
							{
								AgregarPedido(listaClientes, TAM, index, idPedido, indexestado);
								idPedido++;
								auxBasura=0;
							}
							else
							{
								printf("No se le puede agregar pedidos al cliente\n");
								system("pause");
							}

						}
						else
						{
							printf("No se pudo crear el pedido\n");
							system("pause");
						}
					}
					else
					{
						printf("no se puede agregar mas pedidos\n");
						system("pause");
					}
					flagpedido=1;
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 5:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						InformarPedidoS(listaClientes, listaPedidos, TAM, 1);
						PedirEntero(&auxid, "Ingrese el ID del pedido para procesar el pedido de recoleccion:",100,1100);
						auxrespuesta=ProcesarPedido(listaPedidos, TAMPE, auxid);
						if(auxrespuesta==0)
						{
							FinalizarPedidoCliente(listaClientes, TAM, auxid);
						}
						else
						{
							printf("no se pudo procesar el pedido!\n");
						}
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 6:
				if(flagopcion==1)
				{
						InformarClienteS(listaClientes, TAM);
						system("pause");
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 7:
				if(flagopcion==1)
				{
					InformarPedidoS(listaClientes, listaPedidos, TAM, 1);
					system("pause");
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 8:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						InformarPedidoS(listaClientes, listaPedidos, TAM, -1);
						system("pause");
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 9:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						PedirCadena(auxlocalidad, "Ingrese la localidad a buscar", TAMCAD);
						InformarPendientesporLocalidad(listaClientes, TAM, auxlocalidad);
						system("pause");
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 10:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						InformarPromedioPP(listaClientes, TAM, listaPedidos, TAMPE);
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
						break;
			case 11:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						InformarClienteMasPedidoPendientes(listaClientes, TAM);
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
					break;
			case 12:
			if(flagopcion==1)
			{
				if(flagpedido==1)
				{
					InformarClienteMasPedidoProcesados(listaClientes, TAM);
				}
				else
				{
					printf("primero se tiene que agregar un pedido\n");
					system("pause");
				}
			}
			else
			{
				printf("primero tiene que ingresar un cliente!\n");
				system("pause");
			}
					break;
			case 13:
				if(flagopcion==1)
				{
					if(flagpedido==1)
					{
						InformarClienteMasPedidoPendientes(listaClientes, TAM);
					}
					else
					{
						printf("primero se tiene que agregar un pedido\n");
						system("pause");
					}
				}
				else
				{
					printf("primero tiene que ingresar un cliente!\n");
					system("pause");
				}
					break;

		}
	}while(respuesta!=15);
	return EXIT_SUCCESS;
}
