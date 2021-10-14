/*
 * Pedido.c
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */
#include "Pedido.h"
#include "Cliente.h"
#include "Funciones.h"
#include <stdio.h>

void HardcodearPedidos(Pedido lista[], int tamanio)
{
    int i;
    int id[]= {500,501,502,503,504,505};
    int kilos[]={11,12,13,14,15,16};
    for(i=0; i<tamanio; i++)
    {
    	lista[i].IdPedido=id[i];
    	lista[i].kilosTotales=kilos[i];
    	lista[i].HDPE=0;
    	lista[i].LDPE=0;
    	lista[i].PP=0;
    	lista[i].IsEmpty=1;
    }
}
void InicializarPedidos(Pedido lista[],int tamanio)
{
	int i;
	if(lista!=0&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			lista[i].IsEmpty=0;
			lista[i].HDPE=0;
			lista[i].LDPE=0;
			lista[i].PP=0;
		}
	}
}
void BuscarPedidosPendientes(Pedido lista[],int tamanio,int index,int* indexpedido)
{
	if(lista!=0&&tamanio>0)
	{
			if(lista[index].IsEmpty==1&&lista[index].HDPE==0&&lista[index].LDPE==0&&lista[index].PP==0)
			{
				*indexpedido=index;
			}

	}
}
void BuscarPedidosProcesados(Pedido lista[],int tamanio,int index,int* indexpedido)
{
	if(lista!=0&&tamanio>0)
	{
			if(lista[index].IsEmpty==1&&lista[index].HDPE!=0&&lista[index].LDPE!=0&&lista[index].PP!=0)
			{
				*indexpedido=index;
			}

	}
}
int BuscarLibrePedido(Pedido lista[],int tamanio,int* index)
{
	int retorno;
	int i;
	retorno=1;
	if(lista!=0&&tamanio>0&&index>=0)
	{
		for(i=0;i<=tamanio;i++)
		{
			if(lista[i].IsEmpty==0)
			{
				*index=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int CrearPedido(Pedido lista[],int tamanio,int id,float totalBasura,int index)
{
	int retorno;
	retorno=1;
	if(lista!=0&&tamanio>0&&id>0&&index>=0&&totalBasura>0&&lista[index].IsEmpty==0)
	{
		lista[index].IdPedido=id;
		lista[index].kilosTotales=totalBasura;
		lista[index].IsEmpty=1;
		retorno=0;
	}
	return retorno;
}
int ProcesarPedido(Pedido lista[],int tamanio,int id)
{
	int retorno;
	float totalbasura;
	int i;
	int flag;
	flag=0;
	retorno=1;
	totalbasura=0;
	if(lista!=0&&tamanio>0&&id>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(lista[i].IdPedido==id&&lista[i].IsEmpty==1)
			{
				do
				{
					if(flag==1)
					{
						printf("Error, te estas pasando del total\n");
					}
					PedirFlotante(&lista[i].HDPE, "cuanto se ingreso de HDPE:", 0);
					totalbasura=totalbasura+lista[i].HDPE;
					PedirFlotante(&lista[i].LDPE, "cuanto se ingreso de LDPE:", 0);
					totalbasura=totalbasura+lista[i].LDPE;
					PedirFlotante(&lista[i].PP, "cuanto se ingreso de PP:", 0);
					totalbasura=totalbasura+lista[i].PP;
					flag=1;
				}while(totalbasura>lista[i].kilosTotales);
				lista[i].IsEmpty=-1;
				retorno=0;
			}
		}
	}
	return retorno;
}
float CalcularTotalPP(Pedido lista[],int tamanio)
{
	float cantidadtotal;
	int i;
	cantidadtotal=0;
	if(lista!=0&&tamanio>0)
	{
		for(i=0;i<=tamanio;i++)
		{
			if(lista[i].IsEmpty==-1&&lista[i].PP!=0)
			{
				cantidadtotal=cantidadtotal+lista[i].PP;
			}
		}
	}
	return cantidadtotal;
}
