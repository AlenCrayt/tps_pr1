//Ejercicio 11: Invertir el orden de los elementos presentes en un arreglo
#include <stdio.h>

#define TODO_OK 0
#define PUNTERO_NULO -1
#define CAPACIDAD_INCORRECTA -2

int verificacion_arreglo(int arreglo[], int capacidad)
{
	int codigo;
	if (arreglo == NULL)
	{
		codigo = PUNTERO_NULO;
	}
	else if (capacidad < 1)
	{
		codigo = CAPACIDAD_INCORRECTA;
	}
	else
	{
		codigo = TODO_OK;
	}
	return codigo;
}


void mostrar_arreglo(int arreglo[], int capacidad)
{
	int valido = verificacion_arreglo(arreglo, capacidad);
	if (valido == TODO_OK)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (i == (capacidad - 1))
			{
				printf("%d\n", arreglo[i]);
			}
			else
			{
				printf("%d ", arreglo[i]);
			}
		}
	}
}

void codigos_error_arreglos_enteros(int codigo)
{
	switch (codigo)
	{
		case PUNTERO_NULO:
			printf("Error: el puntero dado es nulo\n");
			break;
		case CAPACIDAD_INCORRECTA:
			printf("Error: la capacidad indicada es incorrecta\n");
			break;
	}
}

int invertir(int arreglo[], int tamanio)
{
	int codigo = verificacion_arreglo(arreglo, tamanio);
	int i = 0;	
	int x = (tamanio - 1);
	if (codigo == TODO_OK)
	{
		while (i < (tamanio / 2))
		{
			int temp = arreglo[i];
			arreglo[i] = arreglo[x];
			arreglo[x] = temp;
			i++;
			x--;
		}
	}
	return codigo;
}

int main()
{
	int arr[] = {60, 734, 19, 59, 3, 99, 6000, 32, 71, 58, 23, 555};
	int longitud = sizeof(arr) / sizeof(arr[0]);
	printf("Antes:\n");
	mostrar_arreglo(arr, longitud);
	int retorno = invertir(arr, longitud);
	if (retorno == TODO_OK)
	{
		printf("Despues de invertirlo:\n");
		mostrar_arreglo(arr, longitud);
	}
	else
	{
		codigos_error_arreglos_enteros(retorno);
	}
	return 0;
}
