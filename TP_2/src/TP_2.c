/*
 ============================================================================
 Name        : TP_2.c
 Author      : Mauricio Luque
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecas.h"
#include "ArrayEmployees.h"

#define CANT_EMPLEADOS 4
#define NOMBRE_LEN 31
#define ACTIVO 1
#define INACTIVO 0

int ingresarMenu(int* pResultado, char * mensaje, char * msjError, int min, int max, int reintentos);

int main(void) {

	setbuf(stdout, NULL);

	int respuestaMenu;
	int opcion;
	int idInicial = 1;
	//char auxRespuesta[10];

	eEmployee empleados[CANT_EMPLEADOS]= 	{{ 01, "Cas" , "Storgumon" , 1000 , 9, ACTIVO },
											{ 02, "Adnama" , "Alossonn" , 1010.5 , 8, ACTIVO },
											{ 03, "Rag" , "Bronzarem" , 1050 , 9, ACTIVO },
											{ 04, "Hos" , "Travos" , 900.3 , 7, ACTIVO }};

	do{
		printf ("[MENU] \n(1) ALTAS: \n(2) MODIFICAR: \n(3) BAJA: \n(4) INFORMAR: \n");
		respuestaMenu = ingresarMenu(&opcion, "\nElija una opcion: ", "Error, reingrese nuevamente una opcion correcta.\n", 1, 4, 2);
		if (respuestaMenu == 0){
			switch (opcion){
			case 1:
				addEmployees(empleados, CANT_EMPLEADOS, &idInicial, empleados->nombre, empleados->apellido, empleados->sueldo, empleados->sector);
				break;
			case 2:
				//printf("Estamos en la opcion 2\n");

				break;
			case 3:
				printf("Estamos en la opcion 3\n");
				break;
			case 4:
				printEmployees(empleados, CANT_EMPLEADOS);
				break;
			}
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}
