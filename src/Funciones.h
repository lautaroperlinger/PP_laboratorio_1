/*
 * Funciones.h
 *
 *  Created on: 24 oct. 2021
 *      Author: lauta
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */
/// \fn int ValidarCadena(char[])
/// \brief Valida una cadena
///
/// \pre
/// \post
/// \param cadena
/// \return
int ValidarCadena(char cadena[]);
/// \fn void PedirCadena(char[], char[], int)
/// \brief Pide al usuario a traves del mensaje una cadena de caracteres
///
/// \pre
/// \post
/// \param cadena
/// \param mensaje
/// \param tamanio
void PedirCadena(char cadena[],char mensaje[],int tamanio);
/// \fn int ValidarEntero(int*)
/// \brief Valida un entero
///
/// \pre
/// \post
/// \param entero
/// \return
int ValidarEntero(int* entero);
/// \fn void PedirEntero(int*, char[], char[], int, int)
/// \brief Pide al usuario un entero a traves del mensaje y lo valida
///
/// \pre
/// \post
/// \param entero
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
void PedirEntero(int* entero,char mensaje[],char mensajeError[],int minimo,int maximo);
/// \fn void PedirFlotante(float*, char[], float)
/// \brief PPido un numero tipo flotante
///
/// \pre
/// \post
/// \param flotante
/// \param mensaje
/// \param minimo
void PedirFlotante(float* flotante,char mensaje[],float minimo);
/// \fn void PedirEnteroLargo(long long int*, char[], long long int)
/// \brief Pide un entero que contiene un monton de numeros
///
/// \pre
/// \post
/// \param entero
/// \param mensaje
/// \param minimo
void PedirEnteroLargo(long long int* entero,char mensaje[],long long int minimo);
