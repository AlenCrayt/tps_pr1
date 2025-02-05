#include <stdio.h>

/*
Empleen el valor de return como int para indicar potenciales fallos.
1.1 Cargador de arreglos

Desarrollar una función que dado un arreglo de números enteros, y la cantidad de elementos, solicite valores por teclado para llenar las posiciones.

int cargar_arreglo(int capacidad, int arreglo[]);

1.2 Impresora de arreglos

Desarrollar una función que permita mostrar el contenido de un arreglo.

int muestra_arreglo(int capacidad, int arreglo[]);

1.3 Fusionadora de arreglos

Desarrollar una función que permita unir dos arreglos en un tercero que tenga la capacidad suficiente.
1.4 Operaciones con arreglos

Implementar funciones que permitan hacer las siguientes operaciones sobre arreglos de números enteros.

    Promedio
    Obtenga el valor mínimo
    Obtenga la posición del valor máximo
    Ordenar de menor a mayor

*/

int cargar_arreglo(int capacidad, int arreglo[])
{
	printf("Ingrese %d numeros para el arreglo\n", capacidad);
	for (int i = 0; i < capacidad; ++i)
	{
		scanf("%d", &arreglo[i]);
		printf("Se han ingresado %d numeros\n",(i + 1));
	}
	return 0;
}

int muestra_arreglo(int capacidad, int arreglo[])
{
	for (int i = 0; i < capacidad; ++i)
	{
		printf("En la posicion %d del arreglo esta el numero: %d\n", i, arreglo[i]);
	}
	return 0;
}

int fusion_arreglos(int cap_arr1, int cap_arr2, int arr1[], int arr2[])
{
	printf("Fusionando arreglos...\n");
	int cap_combinada = cap_arr1 + cap_arr2;
	int arr3[cap_combinada];
	int i = 0;
	for (int x = 0; x < cap_arr1; ++x)
	{
		//si uso if/else el problema que surge es que la cuenta de i va a hacer que se acceda a posiciones fuera de rango de los arreglos
		//los bucles for actuales se ejecutan demasiadas veces, tengo que hacer que cuando se carge el primer arreglo las posiciones i del arr3 esten ya en el medi
		arr3[x] = arr1[x];
		i = x;
	}
	i += 1;
	//printf("valor de i: %d\n", i);
	for (int z = 0; z < cap_arr2; ++z)
	{
		arr3[i] = arr2[z];
		//printf("valor z: %d\n", z);
		++i;
	}
	//printf("valor de i: %d\n", i);
	muestra_arreglo(cap_combinada, arr3);
	return 0;
}

int promedio_arreglo(int capacidad, int arr[])
{
	int promedio = 0;
	for (int i = 0; i < capacidad; i++)
	{
		promedio += arr[i];
	}
	promedio = promedio / capacidad;
	printf("El promedio del arreglo es: %d\n", promedio);
}

int minimo_valor(int capacidad, int arr[])
{
	int mini = arr[0];
	for (int i = 0; i < capacidad; i++)
	{
		if (arr[i] < mini)
		{
			mini = arr[i];
		}
	}
	printf("El valor minimo del arreglo es %d\n", mini);
	return 0;
}

int pos_val_max(int capacidad, int arr[])
{
	int pos_max = 0;
	int max_val = arr[0];
	for (int i = 0; i < capacidad; i++)
	{
		if (arr[i] > max_val)
		{
			max_val = arr[i];
			pos_max = i;
		}
	}
	printf("La posicion de maximo valor del arreglo esta en el indice %d\n", pos_max);
	return 0;
}
//hay un algoritmo para organizar el arreglo de menor a mayor
int may_men(int capacidad, int arr[])
{
	for (int i = 0; i < capacidad; i++)
	{
		for (int x = 0; x < (capacidad - 1); x++)
		{
			if (arr[x] > arr[x + 1])
			{
				int temp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
			}
		}
	}
	muestra_arreglo(capacidad, arr);
	return 0;
}

int main()
{
	int arr1[] = {0, 2, 4, 6};
	int arr2[] = {743, 4, 9, 2};
	cargar_arreglo(4, arr1);
	muestra_arreglo(4, arr1);
	fusion_arreglos(4, 4, arr1, arr2);
	promedio_arreglo(4, arr1);
	minimo_valor(4, arr1);
	pos_val_max(4, arr1);
	may_men(4, arr1);
}

