//Implementar una única función que obtenga el cociente y resto de dos números enteros
#include <stdio.h>

#define TODO_OK 0
#define DIVISION_POR_CERO -1
#define PUNTERO_NO_VALIDO -2

int comprobacion_signo(int numero)
{
	int codigo;
	if (numero < 0)
	{
		codigo = -1;
	}
	else if (numero > 0)
	{
		codigo = 1;
	}
	else if (numero == 0)
	{
		codigo = 0;
	}
	return codigo;
}

int division_lenta(int dividendo, int divisor, int *cociente, int *resto)
{
	int codigo;
	int signo_divisor = comprobacion_signo(divisor);
	int signo_dividendo = comprobacion_signo(dividendo);

	*cociente = 0;
	*resto = 0;

	if (divisor == 0)
	{
		codigo = DIVISION_POR_CERO;
	}
	else if (cociente == NULL || resto == NULL)
	{
		codigo = PUNTERO_NO_VALIDO;
	}
	else
	{
		dividendo *= signo_dividendo;
		divisor *= signo_divisor;
		while (dividendo >= divisor)
		{
			dividendo -= divisor;
			*cociente += 1;
		}
		*cociente *= signo_dividendo * signo_divisor;
		*resto = dividendo * signo_divisor;
		codigo = TODO_OK;
	}
	return codigo;
}

int main()
{
	int dividendo = -25;
	int divisor = 7;
	int cociente, resto;
	int retorno = division_lenta(dividendo, divisor, &cociente, &resto);
	if (retorno == TODO_OK)
	{
		printf("La division de %d por %d, tiene un cociente de %d y un resto de %d\n", dividendo, divisor, cociente, resto);
	}
	else if (retorno == DIVISION_POR_CERO)
	{
		printf("La division por cero no es valida\n");
	}
	else if (retorno == PUNTERO_NO_VALIDO)
	{
		printf("Los punteros pasados a la funcion no son validos\n");
	}
	return 0;
}
