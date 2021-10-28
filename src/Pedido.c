/*
 * Pedido.c
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */
#include "Pedido.h"
#include "Funciones.h"
void HardcodearPedidos(Pedido listapedidos[], int tamaniopedidos)
{
    int i;
    int id[]= {500,501,502,503,504,505};
    float kilos[]={11,12,13,14,15,16};
    int idClientes[]={100,101,102,103,104,101};
    int estados[]={1,1,1,-1,-1,1};
    for(i=0; i<=tamaniopedidos; i++)
    {
    	listapedidos[i].idPedido=id[i];
    	listapedidos[i].kilosTotales=kilos[i];
    	listapedidos[i].HDPE=0;
    	listapedidos[i].LDPE=0;
    	listapedidos[i].PP=0;
    	listapedidos[i].idCliente=idClientes[i];
    	listapedidos[i].estado=estados[i];
    	listapedidos[i].isEmpty=1;
    }
}
void InicializarPedidos(Pedido listapedidos[],int tamaniopedidos)
{
	int i;
	if(listapedidos!=0&&tamaniopedidos>0)
	{
		for(i=0;i<=tamaniopedidos;i++)
		{
			listapedidos[i].isEmpty=0;
		}
	}
}
int BuscarEspacioPedido(Pedido listapedidos[],int tamaniopedido,int* index)
{
	int retorno;
	int i;
	retorno=0;
	if(listapedidos!=0&&tamaniopedido>0&&index>=0)
	{
		for(i=0;i<=tamaniopedido;i++)
		{
			if(listapedidos[i].isEmpty==0)
			{
				*index=i;
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
int CrearPedido(Pedido listapedidos[],int tamaniopedidos,int idpedido,int idcliente,float totalBasura,int index)
{
	int retorno;
	retorno=0;
	if(listapedidos!=0&&tamaniopedidos>0&&idpedido>=0&&idcliente>=0&&index>=0&&totalBasura>0&&listapedidos[index].isEmpty==0)
	{
		listapedidos[index].idPedido=idpedido;
		listapedidos[index].idCliente=idcliente;
		listapedidos[index].kilosTotales=totalBasura;
		listapedidos[index].isEmpty=1;
		listapedidos[index].estado=1;
		retorno=1;
	}
	return retorno;
}
int ProcesarPedido(Pedido listapedidos[],int tamaniopedido,int idpedido)
{
	int retorno;
	float totalbasura;
	int i;
	int flag;
	flag=0;
	retorno=0;
	totalbasura=0;
	if(listapedidos!=0&&tamaniopedido>0&&idpedido>0)
	{
		for(i=0;i<tamaniopedido;i++)
		{
			if(listapedidos[i].idPedido==idpedido&&listapedidos[i].isEmpty==1)
			{
				do
				{
					if(flag==1)
					{
						printf("Error, te estas pasando del total\n");
						totalbasura=0;
					}
					PedirFlotante(&listapedidos[i].HDPE, "cuanto se ingreso de HDPE:", 0);
					totalbasura=totalbasura+listapedidos[i].HDPE;
					PedirFlotante(&listapedidos[i].LDPE, "cuanto se ingreso de LDPE:", 0);
					totalbasura=totalbasura+listapedidos[i].LDPE;
					PedirFlotante(&listapedidos[i].PP, "cuanto se ingreso de PP:", 0);
					totalbasura=totalbasura+listapedidos[i].PP;
					flag=1;
					printf("%2.f",totalbasura);
				}while(totalbasura>=listapedidos[i].kilosTotales);
				listapedidos[i].estado=-1;
				retorno=1;
			}
		}
	}
	return retorno;
}
float CalcularTotalPP(Pedido listapedidos[],int tamaniopedido)
{
	float cantidadtotal;
	int i;
	cantidadtotal=0;
	if(listapedidos!=0&&tamaniopedido>0)
	{
		for(i=0;i<=tamaniopedido;i++)
		{
			if(listapedidos[i].isEmpty==-1&&listapedidos[i].PP>0)
			{
				cantidadtotal=cantidadtotal+listapedidos[i].PP;
			}
		}
	}
	return cantidadtotal;
}
int ContadorPedidos(Pedido listapedidos[],int tamaniopedidos,int idcliente,int estado)
{
	int i;
	int contador;
	contador=0;
	if(listapedidos!=NULL&&tamaniopedidos>0&&idcliente>=100)
	{
		for(i=0;i<=tamaniopedidos;i++)
		{
			switch(estado)
			{
				case 0:
					if(listapedidos[i].idCliente==idcliente&&listapedidos[i].isEmpty==1)
					{
						contador++;
					}
					break;
				case 1:
					if(listapedidos[i].idCliente==idcliente&&listapedidos[i].isEmpty==1&&listapedidos[i].estado==estado)
					{
						contador++;
					}
					break;
				case -1:
					if(listapedidos[i].idCliente==idcliente&&listapedidos[i].isEmpty==1&&listapedidos[i].estado==estado)
					{
						contador++;
					}
					break;
			}
		}
	}
	return contador;
}

