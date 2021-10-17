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
#include <string.h>

int ingresarEntero (int* pResultado, char* pMensaje, char* msjError, int min, int max, int reintentos);
int ingresarMenu(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);
int Sumar(int numeroA, int numeroB);
int Restar(int numeroA, int numeroB);
int Multiplicar(int numeroA, int numeroB);
float Dividir(int numeroA, int numeroB);
int Factoriar(int numeroA, int numeroB, int* pResultadoFactorialB);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);

#endif /* BIBLIOTECAS_H_ */
