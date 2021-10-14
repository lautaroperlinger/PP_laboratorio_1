/*
 * Funciones.h
 *
 *  Created on: 13 oct. 2021
 *      Author: lauta
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// \fn void PedirEntero(int*, char[], int, int)
/// \brief Pide un entero
///
/// \pre
/// \post
/// \param entero donde se pasa el dato
/// \param mensaje mensaje que se imprime
/// \param minimo minimo que se pide del entero
/// \param maximo maximo que se pide del entero
void PedirEntero(int* entero,char mensaje[],int minimo,int maximo);
/// \fn void PedirCadena(char[], char[], int)
/// \brief Pide una cadena
///
/// \pre
/// \post
/// \param cadena donde se pasa el datp
/// \param mensaje mensaje que se muestra
/// \param tamanio tamanio de la cadena
void PedirCadena(char cadena[],char mensaje[],int tamanio);
/// \fn int ValidarCadena(char[])
/// \brief Valida la cadena
///
/// \pre
/// \post
/// \param cadena cadena que se verifica
/// \return 1 si se es una cadena y 0 si no es cadena
int ValidarCadena(char cadena[]);
/// \fn int ValidarEntero(int*)
/// \brief Valida el entero
///
/// \pre
/// \post
/// \param entero entero a verificar
/// \return 1 si es entero o 0 si no es cadena
int ValidarEntero(int* entero);
/// \fn void PedirFlotante(float*, char[], float)
/// \brief pide un flotante
///
/// \pre
/// \post
/// \param flotante flotante donde se ingresa
/// \param mensaje mensaje que se muestra
/// \param minimo minimo que se pide
void PedirFlotante(float* flotante,char mensaje[],float minimo);
/// \fn void PedirEnteroLargo(long long int*, char[], long long int)
/// \brief pide un numero entero largo
///
/// \pre
/// \post
/// \param entero entero donde se pasa el dato
/// \param mensaje mensaje que imprime
/// \param minimo minimo que pide
void PedirEnteroLargo(long long int* entero,char mensaje[],long long int minimo);

#endif /* FUNCIONES_H_ */
