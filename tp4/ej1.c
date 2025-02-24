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
	double **segundo_puntero_a = &puntero_a;
	int **segundo_puntero_b = &puntero_b;
	char **segundo_puntero_c = &puntero_c;
	printf("La direccion del double\ta es %p\n", puntero_a);
	printf("La direccion del int\tb es %p\n", puntero_b);
	printf("La direccion del char\tc es %p\n", puntero_c);
	printf("La direccion del double*\tpuntero_a es %p\n", segundo_puntero_a);
	printf("La direccion del int*\tpuntero_b es %p\n", segundo_puntero_b);
	printf("La direccion del char*\tpuntero_c es %p\n", segundo_puntero_c);
	printf("\n");
	printf("El valor del double\ta es %f\n", a);
	printf("El valor del int\tb es %d\n", b);
	printf("El valor del char\tc es %c\n", c);
	printf("El valor del double*\tpuntero_a es %p\n", puntero_a);
	printf("El valor del int*\tpuntero_b es %p\n", puntero_b);
	printf("El valor del char*\tpuntero_c es %p\n", puntero_c);
	printf("\n");
	printf("El tamaño del double\ta es %ld bytes\n", sizeof(a));
	printf("El tamaño del int\tb es %ld bytes\n", sizeof(b));
	printf("El tamaño del char\ta es %ld bytes\n", sizeof(c));
	printf("El tamaño del double*\tpuntero_a es %ld bytes\n", sizeof(puntero_a));
	printf("El tamaño del int*\tpuntero_b es %ld bytes\n", sizeof(puntero_b));
	printf("El tamaño del char*\tpuntero_c es %ld bytes\n", sizeof(puntero_c));
	return 0;
}
