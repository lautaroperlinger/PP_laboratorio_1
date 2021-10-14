/*
 * Cliente.c
 *
 *  Created on: 12 oct. 2021
 *      Author: lauta
 */
#include "Cliente.h"
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void HardcodearClientes(Cliente lista[], int tamanio)
{
    int i;
    int id[]= {0,1,2,3,4};
    char nombres[][51]= {"Carlos","Maria","carlitos","Pedro","Juan"};
    int cuit[]={40404040,50505050,60606060,70707070,80808080};
    char direccion[][51]={"pedraza","manuela","balbin","talcahuano","boqueron"};
    int numeracion[]={2760,7243,4545,1212,4040,};
    char localidades[][51]={"Lanus","Lomas","Lanus","Banfield","Lanus"};
    int idpedido[]={500,501,502,503,504,505};
    int estado[]={1,0,0,1,-1,1};

    for(i=0; i<tamanio; i++)
    {
        lista[i].ID = id[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].cuit=cuit[i];
        strcpy(lista[i].direccion.Calle, direccion[i]);
        lista[i].direccion.numeracion= numeracion[i];
        strcpy(lista[i].localidad, localidades[i]);
        lista[i].IDpedido[i]=idpedido[i];
        lista[i].estado[i]=estado[i];
        lista[i].IsEmpty=1;
    }
}
void InicializarClientes(Cliente lista[],int tamanio)
{
	int i;
	if(lista!=0&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			lista[i].IsEmpty=0;
		}
	}
}
int BuscarEspacioCliente(Cliente lista[],int tamanio,int* index)
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
int BuscarEspacioPedidoCliente(Cliente lista[],int tamanio,int index,int* indexEstado)
{
	int retorno;
	int j;
	retorno=1;
	if(lista!=0&&tamanio>0&&index>=0)
	{
		for(j=0;j<tamanio;j++)
		{
			if(lista[index].estado[j]!=1&&lista[index].estado[j]!=-1)
			{
				*indexEstado=j;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int AgregarCliente(Cliente lista[],int tamanio,int id,char nombre[],long long int cuit,char calle[],int numeracion,char localidad[],int index)
{
	int retorno;
	retorno=0;
	if(lista!=0&&tamanio>0&&id>0&&nombre!=0&&calle!=0&&numeracion>0&&localidad!=0&&index>=0)
	{
		lista[index].ID=id;
		strcpy(lista[index].nombre,nombre);
		lista[index].cuit=cuit;
		strcpy(lista[index].direccion.Calle,calle);
		lista[index].direccion.numeracion=numeracion;
		strcpy(lista[index].localidad,localidad);
		lista[index].IsEmpty=1;
		retorno=1;
	}
	return retorno;
}
int ModificarCliente(Cliente lista[],int tamanio,int id,int tamanioCadena,int respuesta)
{
	int retorno;
	int index;
	retorno=0;
	if(lista!=0&&tamanio>0&&id>0&&tamanioCadena>0)
	{
			BuscarCliente(lista, tamanio, &index,id);
			switch(respuesta)
			{
			case 1:
			PedirCadena(lista[index].direccion.Calle, "Ingrese la nueva calle", tamanioCadena);
			PedirEntero(&lista[index].direccion.numeracion, "Ingrese la nueva numeracion", 0,10000);
			retorno=1;
				break;
			case 2:
			PedirCadena(lista[index].localidad, "Ingrese la nueva localidad", tamanioCadena);
			retorno=1;
				break;
			}
	}
	return retorno;
}
int DarBajaCliente(Cliente lista[],int tamanio,int id)
 {
	 int retorno;
	 int i;
	 retorno=0;
	 if(lista!=0&&tamanio>0&&id>=500)
	 {
		for(i=0;i<tamanio;i++)
		{
			if(lista[i].IsEmpty!=0&&lista[i].ID==id)
			{
				lista[i].IsEmpty=0;
				retorno=1;
				break;
			}
		}
	 }
	 return retorno;
 }
int ContadorPedidos(Cliente lista[],int tamanio,int index,int estado)
{
	int cantidad;
	int j;
	cantidad=0;
	if(lista!=0&&tamanio>0)
	{
		for(j=0;j<=10;j++)
		{
			if(estado==1)
			{
				if(lista[index].IsEmpty==1&&lista[index].estado[j]==1)
				{
				cantidad++;
				}
			}
			else
			{
				if(estado==-1)
				{
					if(lista[index].IsEmpty==1&&lista[index].estado[j]==-1)
					{
						cantidad++;
					}
				}
				else
				{
					if(estado==0)
					{
						if(lista[index].IsEmpty==1&&lista[index].estado[j]!=0)
						{
							cantidad++;
						}
					}
				}
			}

		}
	}
	return cantidad;
}
void BuscarCliente(Cliente lista[],int tamanio,int *index,int id)
{
	int i;
	if(lista!=0&&tamanio>0&&id>=0)
	{
		for(i=0;i<tamanio-1;i++)
		{
				if(lista[i].IsEmpty==1&&lista[i].ID==id)
				{
					*index=i;
					break;
				}
		}
	}

}
void AgregarPedido(Cliente lista[],int tamanio,int indexcliente,int idpedido,int indexestado)
{
	if(lista!=0&&tamanio>0&&idpedido>0&&indexestado>=0&&indexcliente>=0)
	{
		lista[indexcliente].IDpedido[indexestado]=idpedido;
		lista[indexcliente].estado[indexestado]=1;
	}
}
int FinalizarPedidoCliente(Cliente lista[],int tamanio,int idpedido)
{
	int retorno;
	int i;
	int j;
	int flag;
	flag=0;
	retorno=0;
	if(lista!=0&&tamanio>0&&idpedido>0)
	{
		for(i=0;i<tamanio;i++)
		{
			for(j=0;j<10;j++)
			{
				if(lista[i].IDpedido[j]==idpedido&&lista[i].estado[j]==1)
				{
					lista[i].estado[j]=-1;
					flag=1;
					retorno=1;
					break;
				}
				if(flag==1)
				{
					break;
				}
			}
		}
	}
	return retorno;
}
void PedidosporLocalidad(Cliente listacliente[],int tamanio,char localidad[],int* cantidadtotal)
{
	int contador;
	int i;
	int j;
	contador=0;
	if(listacliente!=0&&tamanio>0&&localidad!=0)
	{
		for(i=0;i<tamanio;i++)
		{
			for(j=0;j<tamanio;j++)
			{
				if(listacliente[i].IsEmpty==1&&strcmp(listacliente[i].localidad,localidad)==0&&listacliente[i].estado[j]==1)
				{
					contador++;
				}
			}
		}
		*cantidadtotal=contador;
	}
}
int CantidadClientes(Cliente lista[],int tamanio)
{
	int total;
	int i;
	total=0;
	if(lista!=0&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(lista[i].IsEmpty==1)
			{
				total++;
			}
		}
	}
	return total;
}
int ClienteconMasPedidos(Cliente lista[],int tamanio,int estado)
{
	int maximo;
	int indicemaximo;
	int contador;
	int i;
	maximo=0;
	contador=0;
	if(lista!=0&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			contador=ContadorPedidos(lista, tamanio,i,estado);
			if(maximo==0||contador>maximo)
			{
				maximo=contador;
				indicemaximo=i;
			}
		}
	}
	printf("%d\n",indicemaximo);
	return indicemaximo;
}
