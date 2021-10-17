/*
 * bibliotecas.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Lenovo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

