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

#define CADENA_SIN_TERMINADOR -1

int largo_seguro(char cadena[], int capacidad)
{
	int largo_cadena = 0;
	for (int i = 0; i < capacidad; i++)
	{
		if (cadena[i] != '\0')
		{
			largo_cadena += 1;
		} else if (cadena[i] == '\0') {
			return largo_cadena;
		}
	}
	if (largo_cadena <= capacidad)
	{
		return CADENA_SIN_TERMINADOR;
	}
}

int copia_segura(char cad_origen[], char cad_destino[], int cap_origen, int cap_destino)
{
	int inicio = 0;
	int espacio_vacio = 0;
	if (cad_origen == NULL || cad_destino == NULL)
	{
		return -2;
	}
	if (cad_destino[cap_destino - 1] != '\0' || cad_origen[cap_origen - 1] != '\0')
	{
		return CADENA_SIN_TERMINADOR;
	}
	for (int i = 0; i < cap_destino; i++)
	{
		if (cad_destino[i] == ' ')
		{
			espacio_vacio += 1;
			if (inicio == 0)
			{
				inicio = i;
			}
		}
	}
	if (espacio_vacio < cap_origen)
	{
		return -2;
	} else {
		int contador_origen = 0;
		for (int i = inicio; i < cap_destino; i++)
		{
			cad_destino[i] = cad_origen[contador_origen];
			contador_origen++;
		}
		return 0;
	}
}

int main()
{
	char cad1[] = "holajuan";
	char cad2[] = "paracuando         ";
	int retorno = largo_seguro(cad1, 9);
	if (retorno >= 0)
	{
		printf("La cadena es segura y su largo es: %d\n", retorno);
	}
	else if (retorno == CADENA_SIN_TERMINADOR)
	{
		printf("Error: cadena insegura\n");
	}
	retorno = copia_segura(cad1, cad2, 9, 20);
	switch(retorno)
	{
		case -2:
		printf("Error: una de las cadenas ingresadas es nula\n");
		break;
		case CADENA_SIN_TERMINADOR:
		printf("Error: Una de las cadenas no tiene terminador\n");
		break;
		case 0:
		printf("La cadena combinada es %s\n", cad2);
	}
}
