/*
 * utn.c
 *
 *  Created on: 12 abr. 2021
 *      Author: Lenovo
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Solicita un n?mero al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aqu? se guarda el n?mero ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor m?nimo para el ingreso de n?meros
 * \param int maximo Valor m?ximo para el ingreso de n?meros
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s", pMensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}


/**
 * \brief A partir de 2 n?meros, realiza una suma
 * \param int operandoA Primer n?mero que ingres? el usuario previamente
 * \param int operandoB Segundo n?mero que ingres? el usuario previamente
 * \param int* pResultado Puntero donde se guardar? la suma
 * \return 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getSuma(int numeroA, int numeroB, int* pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = numeroA + numeroB;
		retorno=0;
	}
	return retorno;
}


/**
 * \brief A partir de 2 n?meros, realiza una resta
 * \param int operandoA Primer n?mero que ingres? el usuario previamente
 * \param int operandoB Segundo n?mero que ingres? el usuario previamente
 * \param int* pResultado Puntero donde se guardar? la resta
 * \return 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getResta(int numeroA, int numeroB, int* pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = numeroA - numeroB;
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 n?meros, realiza una multiplicaci?n
 * \param operandoA Primer n?mero que ingres? el usuario previamente
 * \param operandoB Segundo n?mero que ingres? el usuario previamente
 * \param pResultado Puntero donde se guardar? la multiplicaci?n
 * \return 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getMultiplicacion(int numeroA, int numeroB, int* pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = numeroA * numeroB;
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 n?meros, realiza una divisi?n. Valida si el divisor es 0
 * \param int operandoA Primer n?mero que ingres? el usuario previamente
 * \param int operandoB Segundo n?mero que ingres? el usuario previamente
 * \param float* pResultado Puntero donde se guardar? la divisi?n
 * \param char* pMensajeError  Puntero al mensaje a ser mostrado en caso de error
 * \return 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getDivision(int numeroA, int numeroB, float* pResultado, char* pMensajeError){
	int retorno;

	if(pResultado != NULL && pMensajeError != NULL && numeroB != 0){
		*pResultado = (float) numeroA / numeroB;
		retorno = 0;
	}else{
		printf("%s", pMensajeError);
		retorno = -1;
	}
	return retorno;
}


/**
 * \brief A partir de 1 n?mero, realiza el factorial.
 * \param int operandoA Primer n?mero que ingres? el usuario previamente
 * \param int* pResultadoA Puntero donde se guardar? el factorial
 * \return Devuelve 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getFactorial(int numeroA, int* pResultadoA){
	int retorno = -1;
	int i;
	int acumulador = 1;

	if(numeroA >= 0 && pResultadoA != NULL){
		for(i = 1; i <= numeroA; i++){
			acumulador*=i;
		}
		*pResultadoA = acumulador;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Muestra un menu de 5 opciones para calcular operaciones matem?ticas de 2 n?meros:
 * 			1 y 2-para pedir n?meros (contiene los valores de los mismos actualizados), 3-calcular operaciones,
 * 			4-informar resultados, 5-salir del menu
 * \param int* pResultado Puntero al resultado. Aqu? se guarda el n?mero ingresado por el usuario
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor m?nimo para el ingreso de n?meros
 * \param int maximo Valor m?ximo para el ingreso de n?meros
 * \param int reintentos Cantidad de reintentos en caso de error
 * \param int operandoA Primer n?mero que ingres? el usuario
 * \param int operandoB Segundo n?mero que ingres? el usuario
 * \return Devuelve 0 si la funci?n fue exitosa, -1 si da error
 */

int utn_getMenu(int* pResultado, char* pMensajeError, int minimo, int maximo, int reintentos, int numeroA, int numeroB){
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("Menu: \n1-Ingresar 1er operando A=%d \n2-Ingresar 2do operando B=%d \n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir\n",
					numeroA, numeroB);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;

			if(reintentos == 0){
				break;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
