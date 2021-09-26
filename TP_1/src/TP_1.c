/*
 ============================================================================
 Name        : tp1.c
 Author      : Mauricio Luque
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"

int main(void) {

	setbuf (stdout, NULL);

	int numeroA;
	int numeroB;
	int opcion;
	int respuestaMenu;
	int flagOperaciones;
	int contadorA;
	int contadorB;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialA;
	int resultadoFactorialB;

	numeroA = 0;
	numeroB = 0;
	contadorA = 0;
	contadorB = 0;


	do
	{
		printf ("[Menu]: \n(1) 1er operando = %d \n(2) 2do operando = %d \n(3) Calcular todas las operaciones: \n(4) Informar resultados: \n(5) Salir.", numeroA, numeroB);
		respuestaMenu = ingresarMenu(&opcion, "\nElija una opcion: ", "Error, reingrese nuevamente una opcion correcta.\n", 1, 5, 2);
		if (respuestaMenu == 0){
			switch (opcion){
			case 1:
				if (ingresarEntero(&numeroA, "Ingrese 1er operando. ", "Error, ingreso no valido. ", -1000, 1000, 2) == 0){
					contadorA++;
					break;
				}
				else{
					printf("Se requiere un numero valido para continuar.\n");
					break;
				}
				break;
			case 2:
				if (ingresarEntero(&numeroB, "Ingrese 2do operando. ", "Error, ingreso no valido: ", -1000, 1000, 2) == 0){
					contadorB++;
					if (contadorA == 1 && contadorB == 1){
						flagOperaciones = 1;
					}
					break;
				}
				else{
					printf("Se requiere un numero valido para continuar.\n");
					break;
				}
				break;
			case 3:
				if (flagOperaciones == 1){
					resultadoSuma = Sumar(numeroA, numeroB);
					resultadoResta = Restar(numeroA, numeroB);
					resultadoMultiplicacion = Multiplicar(numeroA, numeroB);
					resultadoDivision = Dividir(numeroA, numeroB);
					resultadoFactorialA = Factoriar(numeroA, numeroB, &resultadoFactorialB);
					printf ("Operaciones realizadas.\n\n");
					break;
				}
				else{
					printf ("Queda pendiente por ingresar correctamente los numeros para operar\n\n");
					break;
				}

			case 4:
				if (flagOperaciones == 1){
					if (numeroB == 0){
						printf ("a) El resultado de A+B es %d \nb) El resultado de A-B es %d \nc) El resultado de A*B es %d \nd) No es posible dividir por 0 \ne) El factorial del numeroA es %d y el factorial del numeroB es %d\n\n", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB);
						break;
					}
					else{
						printf ("a) El resultado de A+B es %d \nb) El resultado de A-B es %d \nc) El resultado de A*B es %d \nd) El resultado de A/B es %.2f \ne) El factorial del numeroA es %d y el factorial del numeroB es %d\n\n", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialA, resultadoFactorialB);
						break;
					}
				}
				else{
					printf ("Queda pendiente por ingresar correctamente los numeros para operar\n");
					break;
				}
			case 5:
				break;
			}
		}
		else{
			printf ("Error al intentar ingresar al Menu.");
			break;
		}
	}while (opcion != 5);

	if (opcion == 5){
		printf ("Nos vemos en la proxima iteracion.");
	}

	return EXIT_SUCCESS;
}
