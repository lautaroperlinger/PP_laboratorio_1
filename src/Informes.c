/*
 * Informes.c
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */
#include "Informes.h"
void InformarCliente(Cliente listaclientes[],int tamaniocliente,Localidad listalocalidad[],int indexcliente,int indexlocalidad,int totalpedidos)
{
	if(listaclientes!=0&&tamaniocliente>0&&listalocalidad!=0&&indexcliente>=0&&indexlocalidad>=0&&totalpedidos>=0&&listaclientes[indexcliente].isEmpty==1)
	{
		printf("%d--------%s-----------%s%d---------%I64d---------%s-------%d\n",listaclientes[indexcliente].idCliente,listaclientes[indexcliente].nombre,listaclientes[indexcliente].direccion.Calle,listaclientes[indexcliente].direccion.numeracion,listaclientes[indexcliente].cuit,listalocalidad[indexlocalidad].nombre,totalpedidos);
	}
}
void InformarClientes(Cliente listaclientes[],int tamaniocliente,Pedido listapedidos[],int tamaniopedidos,Localidad listalocalidad[],int tamaniolocalidad)
{
	int i;
	int auxiliartotalpedidos;
	int indexlocalidad;
	if(listaclientes!=0&&tamaniocliente>0)
	{
		puts("----------------------------Lista de clientes-------------------------------\t");
		puts("Id-----Nombre-----Direccion--------CUIT--------Localidad-----TotalPedidos\n");
		for(i=0;i<=tamaniocliente;i++)
		{
			auxiliartotalpedidos=ContadorPedidos(listapedidos, tamaniopedidos, listaclientes[i].idCliente, 1);
			BuscarLocalidad(listalocalidad, tamaniolocalidad, listaclientes[i].idLocalidad, &indexlocalidad);
			InformarCliente(listaclientes, tamaniocliente, listalocalidad,i,indexlocalidad, auxiliartotalpedidos);
		}
	}
}
void InformarPedidos(Pedido listapedidos[],int tamaniopedido,Cliente listaclientes[],int tamanioclientes, int estado)
{
	int i;
	int indexcliente;
	if(listapedidos!=0&&tamaniopedido>0&&estado!=0)
	{
		puts("------------------------Lista de pedidos---------------------------\t");
		puts("Id-------------CUIT----------Direccion-----Total kilos a recolectar\n");
		for(i=0;i<=tamaniopedido;i++)
		{
			if(listapedidos[i].isEmpty==1&&listapedidos[i].estado==estado)
			{
				BuscarCliente(listaclientes, tamanioclientes, listapedidos[i].idCliente, &indexcliente);
				printf("%d        %I64d         %s%d           %.2f\n",listapedidos[i].idPedido,listaclientes[indexcliente].cuit,listaclientes[indexcliente].direccion.Calle,listaclientes[indexcliente].direccion.numeracion,listapedidos[i].kilosTotales);
			}
		}
	}
}
void InformarLocalidades(Localidad listalocalidades[],int tamaniolocalidades)
{
	int i;
	if(listalocalidades!=0&&tamaniolocalidades>0)
	{
		puts("--Lista de localidades--\t");
		puts("Id-------------Localidad\n");
		for(i=0;i<=tamaniolocalidades;i++)
		{
			if(listalocalidades[i].isEmpty==1)
			{
				printf("%d             %s\n",listalocalidades[i].idLocalidad,listalocalidades[i].nombre);
			}
		}
	}
}
void InformarPedidosPendientesxLocalidad(Cliente listaclientes[],int tamanioclientes,Pedido listapedidos[],int tamaniopedidos,int idlocalidad)
{
	int i;
	int j;
	int contadorpedidos;
	contadorpedidos=0;
	if(listaclientes!=0&&tamanioclientes>0&&listapedidos!=0&&tamaniopedidos>0)
	{
		for(i=0;i<=tamaniopedidos;i++)
		{
			for(j=0;j<=tamanioclientes;j++)
			{
				if(listapedidos[i].idCliente==listaclientes[j].idCliente&&listaclientes[j].idLocalidad==idlocalidad&&listapedidos[i].estado==1)
				{
					contadorpedidos++;
				}
			}
		}
		printf("La localidad tiene un total de %d de pedidos pendientes.\n",contadorpedidos);
	}
}
void InformarPromedioPP(Cliente listaclientes[],int tamaniocliente,Pedido listapedidos[],int tamaniopedidos)
{
	float promedio;
	int clientes;
	float pptotal;

	clientes=CantidadClientes(listaclientes, tamaniocliente);
	pptotal=CalcularTotalPP(listapedidos, tamaniopedidos);
	promedio=pptotal/clientes;
	printf("El promedio de PP por cliente es:%.2f (%.2f/%d)\n",promedio,pptotal,clientes);
}
void InformarClientexPedidos(Cliente listaclientes[],int tamanioclientes,Pedido listapedidos[],int tamaniopedidos,int estado)
{
	int indexcliente;
	int totalpedidoscliente;
	int totalpedidos;
	int i;
	totalpedidos=0;
	totalpedidoscliente=0;
	if(listaclientes!=0&&tamanioclientes>0&&listapedidos!=0&&tamaniopedidos>0)
	{
		for(i=0;i<=tamanioclientes;i++)
		{

			totalpedidos=ContadorPedidos(listapedidos, tamaniopedidos, listaclientes[i].idCliente, estado);
			if(totalpedidos>totalpedidoscliente||totalpedidos==0)
			{
				indexcliente=i;
				totalpedidoscliente=totalpedidos;
				break;
			}

		}
		printf("El cliente con mas pedidos con un total de %d es: %s",totalpedidos,listaclientes[indexcliente].nombre);
	}
}
