//Implementar una función que retorne el puntero relativo a una cadena segura, en donde se encuentre la primera ocurrencia de una segunda.
//Retornen NULL si no se encuentra.
#include <stdio.h>

char* busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda)
{
	char *primera_ocurrencia;
	int i = 0;
	int x = 0;
	while (i < capacidad_cadena)
	{
		if (cadena[i] == busqueda[0])
		{
			primera_ocurrencia = &cadena[i];
			while(busqueda[x] != '\0')
			{
				if (cadena[i] == busqueda[x])
				{
					x++;
					i++;
				}
			}
			if (x != (capacidad_busqueda - 1))
			{
				primera_ocurrencia = NULL;
				x = 0;
			}
		}
		i++;
	}
	return primera_ocurrencia;
}

int main()
{
	char cad1[] = "hola mundo";
	char cad2[] = "do";
	int cap1 = 11;
	int cap2 = 3;
	char *retorno = busqueda(cad1, cap1, cad2, cap2);
	if (retorno == NULL)
	{
		printf("No se podido encontra una ocurrencia de la subcadena dada en la cadena principal\n");
	}
	else
	{
		printf("Se ha encontrado una subcadena en la cadena principal empezado en el indice %ld de esta\n", (retorno - cad1));
	}
	return 0;
}
