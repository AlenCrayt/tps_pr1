/*
 Implementar una función que, en el ordenamiento de arreglos de números enteros, haga uso de la función.

void intercambia(int* izquierda, int* derecha);

Para hacer los movimientos de los valores en el arreglo en lugar de hacer las asignaciones entre las posiciones.
*/

#include <stdio.h>

void intercambia(int* izquierda, int* derecha)
{
	int temp;
	temp = *izquierda;
	*izquierda = *derecha;
	*derecha = temp;
}

int ordenamiento(int arreglo_enteros[], int largo)
{
	int codigo;
	for (int x = 0; x < largo; x++)
	{
		for (int i = 0; i < (largo - 1); i++)
		{
			if (arreglo_enteros[i] < arreglo_enteros[i + 1])
			{
				intercambia(&arreglo_enteros[i], &arreglo_enteros[i + 1]);
			}
		}
	}
	codigo = 0;
	return codigo;
}

int main()
{
	int arreglo[] = {230, 72012, 44, 98, 342, 56, 90, 2, 88, 10, 7, 1, 67, 8340, 225};
	int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
	printf("Longitud arreglo: %d\n", longitud);
	int retorno = ordenamiento(arreglo, longitud);
	if (retorno == 0)
	{
		printf("La cadena ordenada es:\n");
		for (int i = 0; i < longitud; i++)
		{
			printf("%d\n", arreglo[i]);
		}
	}
	return 0;
}
