//Ejercicio 9
//Implementar una función que elimine los duplicados de un arreglo, retornando el nuevo tamaño.
#include <stdio.h>

#define CAPACIDAD_MAXIMA 30
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

int eliminar_duplicados(int arreglo[], int capacidad)
{
	int tamanio = verificacion_arreglo(arreglo, capacidad);
	int duplicado = 0;
	int x;
	if (tamanio == TODO_OK)
	{
		tamanio = 1;
		for (int i = 1; i < capacidad; i++)
		{
            duplicado = 0;
            x = 0;
            while (x < tamanio && !duplicado)
            {
                duplicado = (arreglo[i] == arreglo[x]);
                x++;
            }
            if (!duplicado)
            {
                arreglo[tamanio] = arreglo[i];
                tamanio++;
            }
        }
	}
	return tamanio;
}

int main()
{
	int arr[CAPACIDAD_MAXIMA] = {89, 23, 54, 77, 12, 12, 44, 89, 54, 23};
	printf("Arreglo antes de eliminacion de duplicados:\n");
	mostrar_arreglo(arr, 10);
	int retorno = eliminar_duplicados(arr, 10);
	printf("Despues de eliminar duplicados:\n");
	mostrar_arreglo(arr, retorno);
	return 0;
}
