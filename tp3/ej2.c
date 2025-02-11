#include <stdio.h>
/*
Manipular un arreglo de manera segura es poder limitar la cantidad de posiciones que serán recorridas en el caso de que la cadena de caracteres no cuente con su carácter de terminación (\0).

    Las funciones a implementar no pueden usar las funciones de la librería.
    Implementar las funciones indicadas a continuación en un único programa.
    Implementar un programa que haga uso de estas funciones con datos ingresados por la consola.

Todas las funciones deben retornar códigos de error como números negativos para las situaciones que se puedan encontrar, como que la cadena de destino es más chica de lo que se necesita. Por ejemplo:

#define CADENA_SIN_TERMINADOR -1

2.1 Largo de cadenas

Implementar una función que cuente el largo de una cadena de texto de manera segura, La función debe retornar el largo de la cadena o el código de error correspondiente.

Este prototipo es un ejemplo para el resto de las funciones a implementar.


  La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
   @param cadena es la direccion de la cadena con la que se contaran los caracteres
   @pre cadena es una cadena valida
   @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
   @pre es un valor numerico entero positivo mayor a uno
   @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
  @post 
 
int largo_seguro(char cadena[], int capacidad);

2.2 Copia de cadenas

Implementar una función que copie una cadena en otra y deje solo un \0 en la cadena destino

La función debe retornar el largo de la cadena destino o el código de error correspondiente.
2.3 Inserción de cadenas

Implementar una función que inserte una cadena en otra luego de la posición indicada de manera segura.

Que hacer cuando la cadena destino no tiene la capacidad necesaria para alojar la cadena a insertar es su decisión, la cual debe quedar registrada en el comentario de la función.

Ejemplo

Insertar "HOLA" en "Mundo" en la posición 2 daría como resultado "MunHOLAdo"

La función debe retornar el largo de la cadena destino o el código de error correspondiente.
2.4 Limpieza

Implementar una función que limpie la cadena de todos los caracteres que no sean los alfanuméricos (AZaz09) menos el \0 en una cadena diferente a la de entrada.

La función debe retornar el largo de la cadena destino o el código de error correspondiente.
2.5 Comparación

Implementar una función que indique el ordenamiento alfabético de dos cadenas (solo minúsculas)

    -1 la primera cadena va antes de que las segunda
    0 ambas cadenas son iguales
    1 la primera cadena va después que la segunda.

2.6 A minúsculas y a mayúsculas

Implementar una función que modifique la cadena dejando todos sus caracteres en minúsculas.
2.7 Palíndromo seguro

Implementar una función que indique con TRUE si la cadena es un palíndromo, con FALSE si no lo es o indicar un error si no posee \0.

Una palabra es palíndromo cuando se puede leer de la misma manera en ambas direcciones.

Ignoren mayúsculas y minúsculas.

Neuquen -> es palíndromo

Opcionalmente, pueden agregar un argumento para las opciones de la función, como ignorar Mayúsculas/minúsculas o símbolos.
*/

#define CADENA_MENOR 1
#define CADENA_IGUAL 2
#define CADENA_MAYOR 3
#define TODO_OK 0
#define CADENA_NULA -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3
#define POSICION_INVALIDA -4
#define CAPACIDAD_INSUFICIENTE -5
#define CADENA_SIN_TERMINADOR -6

void imprimir_codigos_error(int codigo)
{
	switch(codigo)
	{
		case TODO_OK:
		printf("Codigo 0, no hay errores\n");
		break;
		case CADENA_NULA:
		printf("Error: Una de las cadenas es nula\n");
		break;
		case SIN_LUGAR_SUFICIENTE:
		printf("Error: no hay lugar suficiente en la cadena de destino\n");
		break;
		case CAPACIDAD_INCORRECTA:
		printf("Error: la capacidad del arreglo es incorrecta\n");
		break;
		case POSICION_INVALIDA:
		printf("Error: La posicion seleccionada es invalida\n");
		break;
		case CAPACIDAD_INSUFICIENTE:
		printf("Error: La capacidad de la cadena es insuficiente\n");
		break;
		case CADENA_SIN_TERMINADOR:
		printf("Error: La cadena no posee terminador\n");
		break;
	}
}

int largo_seguro(char cadena[], int capacidad)
{
	int largo_cadena = 0;
	while (largo_cadena <= capacidad && cadena[largo_cadena] != '\0')
	{
		largo_cadena++;
	}//hay que arreglar la deteccion de falta de terminador en cadenas de la funcion
	if (largo_cadena == capacidad)
	{
		largo_cadena = CADENA_SIN_TERMINADOR;
	}
	return largo_cadena;
}

int copia(char cad_origen[], char cad_destino[], int cap_origen, int cap_destino)
{
	int codigo;
	if (cad_origen == NULL || cad_destino == NULL)
	{
		codigo = CADENA_NULA; 
	}
	if (cad_destino[cap_destino] != '\0' || cad_origen[cap_origen] != '\0')
	{
		codigo = CADENA_SIN_TERMINADOR;
	}
	for (int i = 0; i < cap_destino && cad_destino[i] != '\0'; i++)
	{
		cad_destino[i] = cad_origen[i];
	}
	if (cad_origen[0] == cad_destino[0] && cad_destino[cap_destino] == '\0')
	{
		codigo = TODO_OK;
	}
	return codigo;
}

int main()
{
	char cad1[] = "holajuan";
	char cad2[] = "-------------------";
	int retorno = largo_seguro(cad1, 9);
	imprimir_codigos_error(retorno);
	if (retorno >= 0)
	{
		printf("La cadena es segura y su largo es: %d\n", retorno);
	}
	retorno = copia(cad1, cad2, 9, 21);
	imprimir_codigos_error(retorno);
	if (retorno == 0)
	{
		printf("La copia a la cadena destino es: %s\n", cad2);
	}
	/*switch(retorno)
	{
		case -2:
		printf("Error: una de las cadenas ingresadas es nula\n");
		break;
		case CADENA_SIN_TERMINADOR:
		printf("Error: Una de las cadenas no tiene terminador\n");
		break;
		case 0:
		printf("La copia a la cadena destino es: %s\n", cad2);
	}*/
}
