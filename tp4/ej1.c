/*Escriba un programa corto en C (no hace falta que este resuelto con funciones) que declare e inicialice a cualquier valor deseado, sin ser necesario que sea ingresado por el usuario, variables de tipo double, int y char. A continuación, declare e inicialice un puntero a cada una de las tres variables. Su programa debe imprimir la dirección y el valor almacenado y el tamaño de la memoria (en bytes) de cada una de las seis variables.

Utilice el especificador de formato "%p" para imprimir direcciones de punteros (las cuales están en hexadecimal).

Para obtener los tamaños en memoria de las variables, utilice el operador sizeof para determinar el tamaño de memoria asignado para cada variable.

Para armar la salida en columnas, pueden usar tabuladores \t en el string del printf*/

#include <stdio.h>

int main()
{
	double a = 34.6;
	int b = 12;
	char c = 'u';
	double *puntero_a = &a;
	int *puntero_b = &b;
	char *puntero_c = &c;
	printf("La variable a de tipo double esta almacenada en la direccion: %p, tiene el valor %f y su tamaño es de %ld bytes\n", puntero_a, a, sizeof(*puntero_a));
	printf("La variable b de tipo int esta almacenada en la direccion: %p, tiene el valor %d y su tamaño es de %ld bytes\n", puntero_b, b, sizeof(*puntero_b));
	printf("La variable c de tipo char esta almacenada en la direccion: %p, tiene el valor %c y su tamaño es de %ld bytes\n", puntero_c, c, sizeof(*puntero_c));
	return 0;
}
