/*
 * Informes.c
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */
#include "Cliente.h"
#include "Funciones.h"
#include "Pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(int* opcion,char mensaje[],char mensajeError[],int maximo,int minimo)
{
	int auxiliar;
	int flag;
	flag=0;
	if(opcion!=0&&mensaje!=0&&mensajeError!=0&&maximo>minimo)
	{
		printf("%s",mensaje);
		scanf("%d",&auxiliar);
		do
		{

			if(auxiliar>=minimo&&auxiliar<=maximo)
			{
				*opcion=auxiliar;
				flag=1;
				break;
			}
			else
			{
					printf("%s",mensajeError);
					scanf("%d",&auxiliar);
			}
		}while(flag==0);
	}
}
void InformarCliente(Cliente lista[],int tamanio,int index,int totalOrdenes)
{
	int j;
	if(lista!=0&&tamanio>0&&index>=0)
	{
		for(j=0;j<=10;j++)
		{
			if(lista[index].IsEmpty==1)
			{
				printf("%d         %s        %I64d           %s%d         %s                     %d\n",lista[index].ID,lista[index].nombre,lista[index].cuit,lista[index].direccion.Calle,lista[index].direccion.numeracion,lista[index].localidad,totalOrdenes);
				break;
			}
		}
	}
}
void InformarClienteS(Cliente lista[],int tamanio)
{
	int i;
	int cantidad;
	printf("ID           NOMBRE            CUIT               DIRECCION           LOCALIDAD            CANTIDAD DE PEDIDOS PENDIENTES\n");
	for(i=0;i<tamanio;i++)
	{
		cantidad=ContadorPedidos(lista, tamanio, i);
		InformarCliente(lista, tamanio, i,cantidad);
	}
}
void InformarPedidoPendiente(Pedido listapedido[],Cliente listacliente[],int tamanio)
{
	int j;
	int i;
	int indexpedido;
	if(listapedido!=0&&listacliente!=0&&tamanio>0)
	{
		for(i=0;i<=tamanio;i++)
		{
			for(j=0;j<=10;j++)
			{
				BuscarPedidosPendientes(listapedido,tamanio,i,&indexpedido);
				if(listapedido[indexpedido].IdPedido==listacliente[i].IDpedido[j]&&listacliente[i].estado[j]==1)
				{
					printf("%d       %I64d     %s%d      %.2f\n",listapedido[indexpedido].IdPedido,listacliente[i].cuit,listacliente[i].direccion.Calle,listacliente[i].direccion.numeracion,listapedido[indexpedido].kilosTotales);
				}
			}
		}
	}

}
void InformarPedidoProcesados(Pedido listapedido[],Cliente listacliente[],int tamanio)
{
	int j;
	int i;
	int indexpedido;
	if(listapedido!=0&&listacliente!=0&&tamanio>0)
	{
		for(i=0;i<=tamanio;i++)
		{
			for(j=0;j<=10;j++)
			{
				BuscarPedidosProcesados(listapedido, tamanio,i, &indexpedido);
				if(listapedido[indexpedido].IdPedido==listacliente[i].IDpedido[j]&&listacliente[i].estado[j]==-1)
				{
					printf("%d       %I64d     %s%d      %.2f              %.2f                %2.f               %2.f\n",listapedido[indexpedido].IdPedido,listacliente[i].cuit,listacliente[i].direccion.Calle,listacliente[i].direccion.numeracion,listapedido[indexpedido].kilosTotales,listapedido[indexpedido].HDPE,listapedido[indexpedido].LDPE,listapedido[indexpedido].PP);
				}
			}
		}
	}

}
void InformarPedidoS(Cliente listacliente[],Pedido listapedido[],int tamanio,int estado)
{
	if(estado==1)
	{
		printf("ID        CUIT         DIRECCION        CANTIDAD TOTAL A RECOLECTAR\n");
		InformarPedidoPendiente(listapedido, listacliente, tamanio);
	}
	else
	{
		if(estado==-1)
		{
			printf("ID        CUIT         DIRECCION        CANTIDAD TOTAL A RECOLECTAR        CANTIDAD DE HDPE     CANTIDAD DE LPDE       CANTIDAD DE PP\n");
			InformarPedidoProcesados(listapedido, listacliente, tamanio);
		}
	}
}
void InformarPendientesporLocalidad(Cliente listacliente[],int tamanio,char localidad[])
{
	int total;
	total=0;
	PedidosporLocalidad(listacliente, tamanio, localidad, &total);
	printf("La cantidad de Pedidos pendientes en %s es:%d\n",localidad,total);
}
void InformarPromedioPP(Cliente listacliente[],int tamanio,Pedido listapedido[],int tamaniopedido)
{
	float promedio;
	int clientes;
	float pptotal;

	clientes=CantidadClientes(listacliente, tamanio);
	pptotal=CalcularTotalPP(listapedido, tamaniopedido);
	promedio=pptotal/clientes;
	printf("El promedio de PP por cliente es:%.2f (%.2f/%d)\n",promedio,pptotal,clientes);
}
