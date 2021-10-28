/*
 ============================================================================
 Name        : PP_labo_recu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Localidad.h"
#include "Funciones.h"
#define TC 10
#define TP 20
#define TL 2
int main(void)
{
	setbuf(stdout,NULL);
	//Array de estructuras
	Cliente listaclientes[TC];
	Pedido listapedidos[TP];
	Localidad listalocalidades[TL];
	//ID
	int idcliente;
	int idpedido;
	int idlocalidad;
	int idauxiliar;
	int respuesta;
	//flags
	int flagcliente;
	int flagpedido;
	//index
	int indexcliente;
	int indexpedido;
	//auxiliares de cliente
	long long int auxiliarcuit;
	char auxiliarnombre[50];
	char auxiliarcalle[50];
	int auxiliarnumeracion;
	//auxiliares de pedidos
	float auxiliarKilo;
	//
	idcliente=100;
	idpedido=500;
	idlocalidad=0;
	flagcliente=0;
	flagpedido=0;
	InicializarClientes(listaclientes, TC);
	HarcodearLocalidades(listalocalidades, TL);
	InicializarPedidos(listapedidos, TP);
	do
	{
		puts("---------MENU DE OPCIONES-----------\t");
		PedirEntero(&respuesta, "1-Agregar cliente\n2-Modificar datos del cliente\n3-Baja cliente\n4-Crear pedido de recoleccion\n5-Procesar residuos\n6-Imprimir clientes\n7-Imprimir pedidos pendientes\n8-Imprimir pedidos procesados\n9-Pedidos por localidad\n10-PP promedio\n11-Cliente con mas pedidos pendientes\n12-Cliente con mas pedidos procesados\n13-Cliente con mas pedidos en total\n14-Salir\n","Ingrese una opcion valida\n",1, 14);
		switch(respuesta)
		{
			case 1://alta cliente
					if(BuscarEspacioCliente(listaclientes, TC,&indexcliente)==1)//busca el espacio libre en el array de clientes
					{
						PedirCadena(auxiliarnombre, "Ingrese nombre del cliente:", 50);
						PedirEnteroLargo(&auxiliarcuit, "Ingrese el CUIT del cliente:", 20000000000);
						PedirCadena(auxiliarcalle, "Ingrese la calle donde se ubica:", 50);
						PedirEntero(&auxiliarnumeracion, "Ingrese la numeracion de la calle:", "Ingrese una opcion valida\n", 0,9000);
						InformarLocalidades(listalocalidades, TL);
						PedirEntero(&idauxiliar, "Ingrese el ID de la localidad:", "Ingrese opcion valida", 0, TL-1);
						if(AgregarCliente(listaclientes, TC, idcliente, auxiliarnombre, auxiliarcuit, auxiliarcalle, auxiliarnumeracion, idauxiliar, indexcliente)==1)
						{
							idcliente++;
							flagcliente=1;
							puts("El cliente que agrego con exito.\n");
							system("pause");
						}
						else
						{
							puts("no se pudo ingresar el cliente\n");
							system("pause");
						}
					 }
					 else
					 {
					 	puts("no hay mas memoria.\n");
					 	system("pause");
					 }
						break;
			case 2://modificar datos del cliente
				if(flagcliente==1)
				{
					InformarClientes(listaclientes, TC, listapedidos, TP, listalocalidades, TL);
					PedirEntero(&idauxiliar, "Ingrese el ID del cliente a modificar:", "ID NO VALIDO", 100, idcliente);
					PedirEntero(&respuesta, "1-modificar direccion\n2-modificar localidad\n", "opcion no valida", 1, 2);
					InformarLocalidades(listalocalidades, TL);
					if(ModificarCliente(listaclientes, TC, idauxiliar, 50, respuesta)==1)
					{
						puts("Se pudo modificar con exito!\n");
						system("pause");
					}
					else
					{
						puts("No se pudo modificar.\n");
						system("pause");
					}
				}
				else
				{
					puts("Ingrese primero un cliente.\n");
					system("pause");
				}
						break;
			case 3://baja cliente
				if(flagcliente==1)
				{
					InformarClientes(listaclientes, TC, listapedidos, TP, listalocalidades, TL);
					PedirEntero(&idauxiliar, "Ingrese el ID del cliente a eliminar", "ID no valida", 100, idcliente);
					switch(BajaCliente(listaclientes, TC, idauxiliar))
					{
						case 1:
							puts("Se pudo dar de baja el cliente.\n");
							system("pause");
							break;
						case -1:
							puts("BAJA CANCELADA.\n");
							system("pause");
							break;
						case 0:
							puts("No se pudo dar de baja el cliente.\n");
							system("pause");
							break;
					}
				}
				else
				{
					puts("Primero ingrese un cliente.\n");
					system("pause");
				}
						break;
			case 4://crear pedido de recoleccion
				if(flagcliente==1)
				{
					if(BuscarEspacioPedido(listapedidos, TP, &indexpedido)==1)
					{
						InformarClientes(listaclientes, TC, listapedidos, TP, listalocalidades, TL);
						PedirEntero(&idauxiliar, "Ingrese el ID del cliente", "ID no valido", 100, idcliente);
						PedirFlotante(&auxiliarKilo, "Ingrese el total de kilos a recolectar", 0);
						if(CrearPedido(listapedidos, TP, idpedido, idauxiliar, auxiliarKilo, indexpedido)==1)
						{
							idpedido++;
							flagpedido=1;
							puts("Se creo el pedido exitosamente.\n");
							system("pause");
						}
						else
						{
							puts("No se pudo crear el pedido.\n");
							system("pause");
						}

					}
					else
					{
						puts("No hay mas espacio.\n");
						system("pause");
					}
				}
				else
				{
					puts("Primero tiene que agregar un cliente.\n");
					system("pause");
				}
						break;
			case 5://procesar residuos
				if(flagpedido==1)
				{
					InformarPedidos(listapedidos, TP, listaclientes, TC, 1);
					PedirEntero(&idauxiliar, "Ingrese ID del pedido a procesar", "ID no valido", 500, idpedido);
					if(ProcesarPedido(listapedidos, TP, idauxiliar)==1)
					{
						puts("Se pudo procesar correctamente el pedido.\n");
						system("pause");
					}
					else
					{
						puts("No se pudo procesar el pedido.\n");
						system("pause");
					}
				}
				else
				{
					puts("Primero tenes que crear un pedido.\n");
					system("pause");
				}
						break;
			case 6://Imprimir clientes
				if(flagcliente==1)
				{
					InformarClientes(listaclientes, TC, listapedidos, TP,listalocalidades,TL);
				}
						break;
			case 7://Imprimir pedidos pendientes
				if(flagpedido==1)
				{
					InformarPedidos(listapedidos, TP, listaclientes, TC, 1);
				}
				else
				{
					puts("Primero se tiene que ingresar un pedido.");
				}
						break;
			case 8://Imprimir pedidos procesados
				if(flagpedido==1)
				{
					InformarPedidos(listapedidos, TP, listaclientes, TC, -1);
				}
				else
				{
					puts("Primero se tiene que ingresar un pedido.");
				}
						break;
			case 9://Cantidad de pedidos por localidad
				if(flagpedido==1)
				{
					InformarLocalidades(listalocalidades, TL);
					PedirEntero(&idauxiliar, "Ingrese ID a informar", "ID no valido", 0, idlocalidad);
					InformarPedidosPendientesxLocalidad(listaclientes, TC, listapedidos, TP, idauxiliar);

				}
				else
				{
					puts("Primero tiene que ingresar un pedido.\n");
					system("pause");
				}
						break;
			case 10://Cantidad de PP promedio
				if(flagpedido==1)
				{
					InformarPromedioPP(listaclientes, TC, listapedidos, TP);
				}
				else
				{
					puts("Primero tiene que ingresar un pedido.\n");
					system("pause");
				}
						break;
			case 11://Cliente con mas pedidos pendientes
				if(flagpedido==1)
				{
					InformarClientexPedidos(listaclientes, TC, listapedidos, TP, 1);
				}
				else
				{
					puts("Primero tiene que ingresar un pedido.\n");
					system("pause");
				}
						break;
			case 12://Cliente con mas pedidos procesados
				if(flagpedido==1)
				{
					InformarClientexPedidos(listaclientes, TC, listapedidos, TP, -1);
				}
				else
				{
					puts("Primero tiene que ingresar un pedido.\n");
					system("pause");
				}
						break;
			case 13://Cliente con mas pedidos en total
				if(flagpedido==1)
				{
					InformarClientexPedidos(listaclientes, TC, listapedidos, TP, 0);
				}
				else
				{
					puts("Primero tiene que ingresar un pedido.\n");
					system("pause");
				}
						break;
		}
	}while(respuesta!=14);

	return EXIT_SUCCESS;
}
