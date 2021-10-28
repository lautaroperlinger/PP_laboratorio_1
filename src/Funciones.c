/*
 * Funciones.c
 *
 *  Created on: 24 oct. 2021
 *      Author: lauta
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"


int ValidarCadena(char cadena[])
{
	int retorno;
	int i;
	int total;
	total=0;
	char buffer[4096];
	scanf("%s",buffer);
	retorno=0;
	if(cadena!=0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			total=total+isdigit(buffer[i]);
		}
		if(total==0)
		{
			retorno=1;
			strcpy(cadena,buffer);
		}
	}
	return retorno;
}
void PedirCadena(char cadena[],char mensaje[],int tamanio)
{
	int retorno;
	char buffer[tamanio];
	do
		{
			printf("%s",mensaje);
			retorno=ValidarCadena(buffer);
		}while(strlen(buffer)>tamanio||retorno!=1);
	strcpy(cadena,buffer);
}
int ValidarEntero(int* entero)
{
	int retorno;
	int i;
	int total;
	total=0;
	char buffer[4096];
	scanf("%s",buffer);
	retorno=0;
	if(entero!=0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			total=total+isdigit(buffer[i]);
		}
		if(total!=0)
		{
			retorno=1;
			*entero=atoi(buffer);
		}
	}
	return retorno;
}
void PedirEntero(int* entero,char mensaje[],char mensajeError[],int minimo,int maximo)
{
	int auxiliarEntero;
	do
	{
		printf("%s",mensaje);
		if(ValidarEntero(&auxiliarEntero)!=0)
		{
			*entero=auxiliarEntero;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}while(auxiliarEntero<minimo||auxiliarEntero>maximo);
}

void PedirFlotante(float* flotante,char mensaje[],float minimo)
{
	float numero;
	do
	{
		printf("%s",mensaje);
		scanf("%f",&numero);
	}while(numero<minimo);
	*flotante=numero;
}
void PedirEnteroLargo(long long int* entero,char mensaje[],long long int minimo)
{
	long long int auxiliarEntero;
	do
	{
		printf("%s",mensaje);
		scanf("%11I64d",&auxiliarEntero);
	}while(auxiliarEntero<=minimo);
	*entero=auxiliarEntero;
}

