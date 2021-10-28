/*
 * Localidad.c
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */
#include "Localidad.h"
void HarcodearLocalidades(Localidad listalocalidades[],int tamaniolocalidades)
{
	int i;
	int id[]={0,1,2};
	char nombre[][50]={"lanus","constitucion","avellaneda"};
	for(i=0;i<=tamaniolocalidades;i++)
	{
		listalocalidades[i].idLocalidad=id[i];
		strcpy(listalocalidades[i].nombre,nombre[i]);
		listalocalidades[i].isEmpty=1;
	}
}
void BuscarLocalidad(Localidad listalocalidades[],int tamaniolocalidades,int id,int* indexlocalidad)
{
	int i;
	if(listalocalidades!=0&&tamaniolocalidades>0&&id>=0)
	{
		for(i=0;i<=tamaniolocalidades;i++)
		{
			if(listalocalidades[i].idLocalidad==id)
			{
				*indexlocalidad=i;
				break;
			}
		}
	}
}
