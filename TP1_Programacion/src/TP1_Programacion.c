/*
 ============================================================================
 Name        : TP1_Programacion.c
 Author      : Mauricio Luque
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int respuestaMenu;
	int numeroA = 0;
	int numeroB = 0;

	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorialA;
	int factorialB;
	int respuestaDivision;
	int flagOperaciones = 0;
	int contadorA = 0;
	int contadorB = 0;

	do{
		respuestaMenu = utn_getMenu(&opcion, "Error, elija una opcion del menu\n", 1, 5, 1, numeroA, numeroB);

		if(respuestaMenu == 0){
			switch(opcion){
			case 1:
				system("cls");
				if(utn_getNumero(&numeroA, "Ingresar 1er operando: \n", "Error. Reingrese 1er operando\n", -10000, 10000, 2)==0){
					contadorA++;
				}
				break;
			case 2:
				system("cls");
				if(utn_getNumero(&numeroB, "Ingresar 2do operando: \n", "Error. Reingrese 2do operando\n", -10000, 10000, 2)==0){
					contadorB++;
				}
				break;
			case 3:
				system("cls");
				if(contadorA > 0 && contadorB > 0){
					flagOperaciones = 1;
				}

				if(flagOperaciones == 1){
					utn_getSuma(numeroA, numeroB, &suma);
					utn_getResta(numeroA, numeroB, &resta);
					utn_getMultiplicacion(numeroA, numeroB, &multiplicacion);
					respuestaDivision = utn_getDivision(numeroA, numeroB, &division, "Error, no se puede dividir por 0. Reingresar el 2do operando\n");

					if(numeroA >= 0 && numeroB >= 0){
						utn_getFactorial(numeroA, &factorialA);
						utn_getFactorial(numeroA, &factorialB);
					}
					else{
						printf("Error, no se puede calcular el factorial\n");
					}
				}
				else{
					printf("Error. Reingrese los numeros\n");
				}
				break;
			case 4:
				system("cls");
				if(flagOperaciones == 1){
					if(respuestaDivision == 0 && numeroA >= 0 && numeroB >= 0){
						printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: %.2f \nFactorial del 1er operando: %d \nFactorial del 2do operando %d \n",
								suma, resta, multiplicacion, division, factorialA, factorialB);
					}
					else{
						printf("Error al realizar las operaciones. Reingrese los numeros\n");
					}
				}
				else{
					printf("Error al cargar los numeros\n");
				}
				break;
			}
		}
	}while(opcion != 5);

	return 0;
}
