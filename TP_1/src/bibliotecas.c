/*
 * bibliotecas.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Lenovo
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"
//**
/// @brief Solicita un numero al usuario, valida el numero, lo verifica y devuelve el resultado
/// @param pResultado Puntero al resultado. Se guarda el valor que ingresa el usuario
/// @param pMensaje Puntero al mensaje
/// @param msjError Puntero al mensaje de error
/// @param min Valor minimo para validar el ingreso de un numero
/// @param max Valor maximo para validar el ingreso de un numero
/// @param reintentos Valor que permite una cantidad de reintentos
/// @return retorna 0 si la funcion es correcta, -1 si da error
/// */
int ingresarEntero (int* pResultado, char* pMensaje, char* msjError, int min, int max, int reintentos)
{
	int retorno = -1;
	int aux;

	aux = 1001;

	if (pResultado != NULL && pMensaje != NULL && msjError != NULL && min <= max && reintentos >= 0){
			do{
			printf ("%sTenes %d reintento/s: ", pMensaje, reintentos);
			fflush(stdin);
			scanf ("%d", &aux);

				if (aux >= min && aux <= max){
					*pResultado = aux;
					retorno = 0;
					break;
				}
				else{
					reintentos--;
					printf (msjError);
				}
			} while (reintentos >= 0);
	}
	return retorno;
}


//**
/// @brief Solicita un numero al usuario, valida el numero, lo verifica y lo devuelve como resultado
/// @param pResultado Puntero al resultado. Se guarda el valor que ingresa el usuario
/// @param mensaje Puntero al mensaje
/// @param msjError Puntero al mensaje de error
/// @param min Valor minimo para validar el ingreso de un numero
/// @param max Valor maximo para validar el ingreso de un numero
/// @param reintentos Valor que permite una cantidad de reintentos
/// @return retorna 0 si la funcion es correcta, -1 si da error
/// */
int ingresarMenu(int* pResultado, char * mensaje, char * msjError, int min, int max, int reintentos)
{
	int retorno;
	int aux;

	do{
		if (pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max && reintentos >= 0){
			printf (mensaje);
			fflush(stdin);
			scanf ("%d", &aux);
			if (aux >= min && aux <= max){
				*pResultado = aux;
				retorno = 0;
				break;
			}

			else{
				reintentos--;
				printf (msjError);
			}
		}
	} while (reintentos >= 0);

	return retorno;
}

//**
/// @brief Recibe dos numeros como parametros, realiza la suma y devuelve el resultado
/// @param numeroA Primer valor que ingreso previamente el usuario
/// @param numeroB Segundo valor que ingreso previamente el usuario
/// @return retorna el resultado de la operacion
/// */
int Sumar(int numeroA, int numeroB)
{
	int resultadoSuma;

	resultadoSuma = numeroA + numeroB;

	return resultadoSuma;
}

//**
/// @brief Recibe dos numeros como parametros, realiza la resta y devuelve el resultado
/// @param numeroA Primer valor que ingreso previamente el usuario
/// @param numeroB Segundo valor que ingreso previamente el usuario
/// @return retorna el resultado de la operacion
/// */
int Restar(int numeroA, int numeroB)
{
	int resultadoResta;

	resultadoResta = numeroA - numeroB;

	return resultadoResta;
}

//**
/// @brief Recibe dos numeros como parametro, realiza la multiplicacion y devuelve el resultado
/// @param numeroA Primer valor que ingreso previamente el usuario
/// @param numeroB Segundo valor que ingreso previamente el usuario
/// @return retorna el resultado de la operacion
/// */
int Multiplicar(int numeroA, int numeroB)
{
	int resultadoMultiplicacion;

	resultadoMultiplicacion = numeroA * numeroB;

	return resultadoMultiplicacion;
}

//**
/// @brief Recibe dos numeros como parametros, verfica y si es posible, realiza la division y devuelve el resultado
/// @param numeroA Primer valor que ingreso previamente el usuario
/// @param numeroB Segundo valor que ingreso previamente el usuario
/// @return retorna el resultado de la operacion
/// */

float Dividir(int numeroA, int numeroB)
{
	float resultadoDivision;
	int retorno;

	if (numeroB == 0){
		retorno = -1;
	}
	else {
		resultadoDivision = (float) numeroA / numeroB;
		retorno = resultadoDivision;
	}

	return retorno;
}

//**
/// @brief Recibe dos numeros, verifica y realiza la operacion, y devuelve el resultado
/// @param numeroA Primer numero que ingreso previamente el usuario
/// @param numeroB Segundo numero que ingreso previamente el usuario
/// @param pResultadoFactorialB Puntero al resultado de la operacion de la variable "numeroB"
/// @return retorna el resultado de la operacion de la variable "numeroA"
/// */
int Factoriar(int numeroA, int numeroB, int* pResultadoFactorialB)
{
	int factorialA;
	int resultadoFactorialA;
	int factorialB;
	int resultadoFactorialB;

	resultadoFactorialA = 1;
	resultadoFactorialB = 1;

	if (numeroA == 0){
		resultadoFactorialA = 1;
	}
	else {
		for (factorialA = 1; factorialA <= numeroA; factorialA++){
			resultadoFactorialA = resultadoFactorialA * factorialA;
		}
	}

	if (numeroB == 0){
		*pResultadoFactorialB = 1;
	}
	else{
		for (factorialB = 1; factorialB <= numeroB; factorialB++){
			resultadoFactorialB = resultadoFactorialB * factorialB;
			*pResultadoFactorialB = resultadoFactorialB;
		}
	}

	return resultadoFactorialA;
}
