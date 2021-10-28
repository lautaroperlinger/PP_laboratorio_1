/*
 * Localidad.h
 *
 *  Created on: 20 oct. 2021
 *      Author: lauta
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <string.h>
typedef struct
{
	int idLocalidad;
	char nombre[50];
	int isEmpty;
}Localidad;
/// \fn void HarcodearLocalidades(Localidad[], int)
/// \brief Agrega datos de las localidades a un array
///
/// \pre
/// \post
/// \param listalocalidades
/// \param tamaniolocalidades
void HarcodearLocalidades(Localidad listalocalidades[],int tamaniolocalidades);
/// \fn void BuscarLocalidad(Localidad[], int, int, int*)
/// \brief Busca el index de una localidad a traves del ID que se solicita
///
/// \pre
/// \post
/// \param listalocalidades
/// \param tamaniolocalidades
/// \param id
/// \param indexlocalidad
void BuscarLocalidad(Localidad listalocalidades[],int tamaniolocalidades,int id,int* indexlocalidad);

#endif /* LOCALIDAD_H_ */
