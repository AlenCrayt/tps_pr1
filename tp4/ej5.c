//Implementar una única función que obtenga el mínimo, máximo, suma y promedio de un arreglo.
#include <stdio.h>

#define TODO_OK 0
#define ARREGLO_NULO -1

int estadisticas_arreglo(int arreglo[], int capacidad, int *minimo, int *maximo, int *suma, int *promedio)
{
	int codigo;
	if (arreglo == NULL)
	{
		codigo = ARREGLO_NULO;
	}
	else
	{
		*minimo = arreglo[0];
		*maximo = 0;
		*suma = 0;
		*promedio = 0;
		for (int i = 0; i < capacidad; i++)
		{
			*suma += arreglo[i];
			if (arreglo[i] > *maximo)
			{
				*maximo = arreglo[i];
			}
			if (arreglo[i] < *minimo)
			{
				*minimo = arreglo[i];
			}
		}
		*promedio = *suma / capacidad;
		codigo = TODO_OK;
	}

	return codigo;
}

int main()
{
	int arr1[] = {45, 293, 90, 3, 555, 90, 123, 5090, 867, 54};
	int largo_arreglo = sizeof(arr1) / sizeof(arr1[0]);
	int suma_arreglo, minimo_arreglo, maximo_arreglo, promedio_arreglo;
	int retorno = estadisticas_arreglo(arr1, largo_arreglo, &minimo_arreglo, &maximo_arreglo, &suma_arreglo, &promedio_arreglo);
	switch (retorno) 
	{
	case TODO_OK:
	printf("El arreglo tiene un valor minimo de %d, un valor maximo de %d, la suma de los valores del arreglo es %d y su promedio es %d\n", minimo_arreglo, maximo_arreglo, suma_arreglo, promedio_arreglo);
	break;
	case ARREGLO_NULO:
	printf("Error: el arreglo pasado a la funcion es nulo\n");
	break;
	}
	return 0;
}
