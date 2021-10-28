/*
 * Cliente.c
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */
#include "Cliente.h"
#include "Funciones.h"
void HardcodearClientes(Cliente listaclientes[], int tamanioclientes)
{
    int i;
    int id[]= {100,101,102,103,104};
    char nombres[][50]= {"Carlos","Maria","carlitos","Pedro","Juan"};
    long long int cuit[]={40404040,50505050,60606060,70707070,80808080};
    char calle[][50]={"pedraza","manuela","balbin","talcahuano","boqueron"};
    int numeracion[]={2760,7243,4545,1212,4040,};
    int idLocalidad[]={1,2,3,2,1};
    for(i=0; i<=tamanioclientes; i++)
    {
    	listaclientes[i].idCliente = id[i];
    	strcpy(listaclientes[i].nombre, nombres[i]);
        listaclientes[i].cuit=cuit[i];
        strcpy(listaclientes[i].direccion.Calle, calle[i]);
        listaclientes[i].direccion.numeracion= numeracion[i];
        listaclientes[i].idLocalidad=idLocalidad[i];
        listaclientes[i].isEmpty=1;
    }
}
void InicializarClientes(Cliente listaclientes[],int tamanioclientes)
{
	int i;
	if(listaclientes!=0&&listaclientes>0)
	{
		for(i=0;i<=tamanioclientes;i++)
		{
			listaclientes[i].isEmpty=0;
		}
	}
}
int BuscarEspacioCliente(Cliente listaclientes[],int tamanioclientes,int* index)
{
	int retorno;
	int i;
	retorno=0;
	if(listaclientes!=0&&tamanioclientes>0&&index>=0)
	{
		for(i=0;i<=tamanioclientes;i++)
		{
			if(listaclientes[i].isEmpty==0)
			{
				*index=i;
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
int AgregarCliente(Cliente listaclientes[],int tamanioclientes,int idcliente,char nombre[],long long int cuit,char calle[],int numeracion,int idlocalidad,int indexlibre)
{
	int retorno;
	retorno=0;
	if(listaclientes!=0&&tamanioclientes>0&&idcliente>0&&nombre!=0&&calle!=0&&numeracion>0&&idlocalidad>=0&&indexlibre>=0)
	{
		listaclientes[indexlibre].idCliente=idcliente;
		strcpy(listaclientes[indexlibre].nombre,nombre);
		listaclientes[indexlibre].cuit=cuit;
		strcpy(listaclientes[indexlibre].direccion.Calle,calle);
		listaclientes[indexlibre].direccion.numeracion=numeracion;
		listaclientes[indexlibre].idLocalidad=idlocalidad;
		listaclientes[indexlibre].isEmpty=1;
		retorno=1;
	}
	return retorno;
}
int ModificarCliente(Cliente listaclientes[],int tamaniocliente,int idcliente,int tamanioCadena,int respuesta)
{
	int retorno;
	int index;
	retorno=0;
	if(listaclientes!=0&&tamaniocliente>0&&idcliente>0&&tamanioCadena>0)
	{
			BuscarCliente(listaclientes, tamaniocliente, idcliente,&index);
			switch(respuesta)
			{
			case 1:
			PedirCadena(listaclientes[index].direccion.Calle, "Ingrese la nueva calle:", tamanioCadena);
			PedirEntero(&listaclientes[index].direccion.numeracion, "Ingrese la nueva numeracion de la calle:", "Ingrese un numero valido", 0, 5000);
			retorno=1;
				break;
			case 2:
			PedirEntero(&listaclientes[index].idLocalidad, "Ingrese el ID de la nueva localidad:", "Opcion no valida", 0, 2);
			retorno=1;
				break;
			}
	}
	return retorno;
}
int BajaCliente(Cliente listaclientes[],int tamanioclientes,int idcliente)
 {
	 int retorno;
	 int respuesta;
	 int i;
	 retorno=0;
	 if(listaclientes!=0&&tamanioclientes>0&&idcliente>=100)
	 {
		for(i=0;i<tamanioclientes;i++)
		{
			if(listaclientes[i].isEmpty==1&&listaclientes[i].idCliente==idcliente)
			{
				PedirEntero(&respuesta, "Seguro quiere eliminar a este cliente?\n 1-Si 2-No\n", "Opcion no valida", 1, 2);
				switch(respuesta)
				{
					case 1:
						listaclientes[i].isEmpty=0;
						retorno=1;
						break;
					case 2:
						retorno=-1;
						break;
						break;
				}
			}
		}
	 }
	 return retorno;
 }
void BuscarCliente(Cliente listaclientes[],int tamanioclientes,int id,int* indexcliente)
{
	int i;
	if(listaclientes!=0&&tamanioclientes>0&&id!=0)
	{
		for(i=0;i<=tamanioclientes;i++)
		{
			if(listaclientes[i].idCliente==id)
			{
				*indexcliente=i;
				break;
			}
		}
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
			if(lista[i].isEmpty==1)
			{
				total++;
			}
		}
	}
	return total;
}
