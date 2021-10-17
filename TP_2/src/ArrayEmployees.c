/*
 * ArrayEmployees.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Lenovo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecas.h"
#include "ArrayEmployees.h"

int initEmployee (eEmployee* pEmpleado, int limite)
{
	int retorno = -1;
	int i;

	if (pEmpleado != NULL && limite > 0){
		for (i=0; i<limite; i++){
			if (pEmpleado[i].isEmpty != 1){
				pEmpleado[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int printEmployees (eEmployee* pEmpleado, int LEN)
{
	int retorno = -1;
	int i;

	if (pEmpleado != NULL && LEN > 0){
		for (i=0; i<LEN; i++){
			printf ("El id %d tiene estado en %d \n", i+1, pEmpleado[i].isEmpty);
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/

int addEmployees (eEmployee* pEmpleado, int limite, int id, eEmployee* pNombre, eEmployee* pApellido, eEmployee* pSalario, eEmployee* pSector)
{
	int retorno = -1;
	int i;
	eEmployee auxEmpleado;

	if(pEmpleado != NULL && limite > 0 && id != NULL && pNombre != NULL && pApellido != NULL && pSalario != NULL && pSector != NULL){
		retorno = 0;
		for (i=0; i<limite; i++){
			if (pEmpleado[i].isEmpty == 1){
				pEmpleado[i].nombre = getNombre(&pEmpleado, limite);
				pEmpleado[i].apellido = getNombre(&pEmpleado, limite);
				pEmpleado[i].sueldo = getFloat(&pSalario);
				pEmpleado[i].sector = getInt(&pSector);
			}
		}
	}

	return retorno;
}
