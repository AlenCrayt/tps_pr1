//Intercambiar dos caracteres en una misma cadena segura.
#include <stdio.h>

#define TODO_OK 0
#define CADENA_NULA -1
#define CADENA_SIN_TERMINADOR -2

int intercambia(char cadena[], int capacidad_cadena, int origen, int destino)
{
	int codigo;
	if (cadena == NULL)
	{
		codigo = CADENA_NULA;
	}
	else if (cadena[(capacidad_cadena - 1)] != '\0')
	{
		codigo = CADENA_SIN_TERMINADOR;
	}
	else
	{
		char temporal = cadena[destino];
		cadena[destino] = cadena[origen];
		cadena[origen] = temporal;
		codigo = TODO_OK;
	}
	return codigo;
}

int main()
{
	char palabra[] = "Hola";
	int capacidad = 5;
	int retorno = intercambia(palabra, capacidad, 1, 3);
	switch (retorno)
	{
		case TODO_OK:
			printf("La cadena con los caracteres intercambiados es: %s\n", palabra);
			break;
		case CADENA_NULA:
			printf("Error: la cadena pasada a la funcion es nula\n");
			break;
		case CADENA_SIN_TERMINADOR:
			printf("Error: la cadena no posee un terminador en el indice esperado\n");
			break;
	}
	return 0;
}
