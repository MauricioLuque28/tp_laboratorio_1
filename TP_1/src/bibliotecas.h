/*
 * bibliotecas.h
 *
 *  Created on: 21 sep. 2021
 *      Author: Lenovo
 */

#ifndef BIBLIOTECAS_H_
#define BIBLIOTECAS_H_

#include <stdio.h>
#include <stdlib.h>

int ingresarEntero (int* pResultado, char* pMensaje, char* msjError, int min, int max, int reintentos);
int ingresarMenu(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);
int Sumar(int numeroA, int numeroB);
int Restar(int numeroA, int numeroB);
int Multiplicar(int numeroA, int numeroB);
float Dividir(int numeroA, int numeroB);
int Factoriar(int numeroA, int numeroB, int* pResultadoFactorialB);

#endif /* BIBLIOTECAS_H_ */
