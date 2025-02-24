//Ejercicio 10: Implementar una función que reemplace las vocales de una cadena segura reemplazándolas por un carácter indicado.
#include <stdio.h>

#define TODO_OK 0
#define CADENA_NULA -1
#define FALTA_TERMINADOR -2

int verificacion_cadena(char cadena[], int capacidad)
{
	int codigo;
	if (cadena == NULL)
	{
		codigo = CADENA_NULA;
	}
	else if(cadena[(capacidad - 1)] != '\0')
	{
		codigo = FALTA_TERMINADOR;
	}
	else
	{
		codigo = TODO_OK;
	}
	return codigo;
}

void impresion_errores_cadena(int codigo)
{
	switch (codigo)
	{
		case CADENA_NULA:
			printf("Error: la cadena es nula\n");
			break;
		case FALTA_TERMINADOR:
			printf("Error: la cadena no posee un terminador en el indice esperado\n");
			break;
	}
}

int reemplazo_vocales(char cadena[], int capacidad, char indicado)
{
	int codigo = verificacion_cadena(cadena, capacidad);
	if (codigo == TODO_OK)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u')
			{
				cadena[i] = indicado;
			}
		}
	}
	return codigo;
}

int main()
{
	char reemplazador = 'v';
	char frase[] = "river tiene todo hecho para ganar";
	int longitud = sizeof(frase) / sizeof(frase[0]);
	printf("Antes:\n");
	printf("%s\n", frase);
	int retorno = reemplazo_vocales(frase, longitud, reemplazador);
	if (retorno == TODO_OK)
	{
		printf("Despues de remplazar las vocales de la cadena con el caracter: %c\n", reemplazador);
		printf("%s\n", frase);
	}
	else
	{
		impresion_errores_cadena(retorno);
	}
	return 0;
}
