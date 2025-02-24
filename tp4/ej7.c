//Ejercicio 7: Encontrar la longitud de una cadena segura empleando aritmética de punteros y sin usar el operador de arreglos [].
#include <stdio.h>

#define CADENA_NULA -1
#define CADENA_SIN_TERMINADOR -2

int largo_seguro(char *str, int capacidad_cadena)
{
	int largo = 0;
	if (str == NULL)
	{
		largo = CADENA_NULA;
	}
	str += (capacidad_cadena - 1);
	if (*str != '\0')
	{
		largo = CADENA_SIN_TERMINADOR;
	}
	str -= (capacidad_cadena - 1);
	if (largo == 0)
	{
		while (*str != '\0')
		{
			str++;
			largo++;
		}
	}
	return largo;
}

int main()
{
	char cadena[] = "Tener dos monitores suele aumentar la productividad";
	int capacidad = sizeof(cadena) / sizeof(cadena[0]);
	int retorno = largo_seguro(cadena, capacidad);
	if (retorno >= 0)
	{
		printf("La longitud de la cadena segura es de %d caracteres\n", retorno);
	}
	else if(retorno == CADENA_NULA)
	{
		printf("Error: el puntero pasado a la funcion es nulo\n");
	}
	else if(retorno == CADENA_SIN_TERMINADOR)
	{
		printf("Error: la cadena no tiene un terminador en el indice indicado\n");
	}
	return 0;
}
