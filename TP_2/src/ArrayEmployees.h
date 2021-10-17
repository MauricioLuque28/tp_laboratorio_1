/*
 * ArrayEmployees.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Lenovo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;
} eEmployee;

int initEmployee (eEmployee* pEmpleado, int LEN);
int printEmployees (eEmployee* pEmpleado, int LEN);


#endif /* ARRAYEMPLOYEES_H_ */
