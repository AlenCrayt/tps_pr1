//duplica el valor de una variable usando punteros

#include <stdio.h>

#define TODO_OK 0
#define PUNTERO_NULO 1

int duplicacion(int *puntero_numero)
{
	int codigo = TODO_OK;
	if (puntero_numero == NULL)
	{
		codigo = PUNTERO_NULO;
	}
	else
	{
		*puntero_numero *= 2;//se multiplica por 2 el valor dereferenciado de la direccion de memoria
	}
	return codigo;
}


int main()
{
	int num = 6;
	printf("num es equivalente a: %d\n", num);
	int retorno = duplicacion(&num);
	if (retorno == TODO_OK)
	{
		printf("num duplicado es equivalente a: %d\n", num);
	}
	else
	{
		printf("Error: el puntero no es valido\n");
	}
	return 0;
}
