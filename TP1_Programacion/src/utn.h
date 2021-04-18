/*
 * utn.h
 *
 *  Created on: 12 abr. 2021
 *      Author: Lenovo
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getSuma(int numeroA, int numeroB, int* pResultado);
int utn_getResta(int numeroA, int numeroB, int* pResultado);
int utn_getMultiplicacion(int numeroA, int numeroB, int* pResultado);
int utn_getDivision(int numeroA, int numeroB, float* pResultado, char* pMensajeError);
int utn_getFactorial(int numeroA, int* pResultadoA);
int utn_getMenu(int* pResultado, char* pMensajeError, int minimo, int maximo, int reintentos, int numeroA, int numeroB);

#endif /* UTN_H_ */
