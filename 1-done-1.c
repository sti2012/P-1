/*
	* -------------------------------------------------------------------------
	* meteo.c: Muestra la prevision de los 4 proximos dias de la ciudad deseada
	* 	librerias usadas:
	* 		libcurl: 		Descarga una direccion de internet.
	* 		libxml2: 		Obtiene los datos del XML.
	* 		libgraph:		graphics.h de Turbo C en Linux	
	*
	* cURL descargara la prevision del tiempo de la API de google
	* libxml2 obtendra los datos del archivo en formato XML
	* libgraph mostrara los datos dibujados en la pantalla
	*
	* Dos formas de uso:
	*		Por medio de la linea de comandos.
	*		Desde el propio programa.
	* 
	* Ideas:
	* 		Historial de busquedas recientes.
	* 		Grafica con las temperaturas maximas y minimas.
	* 
	* SSOO STI 2012. grupo 5
	* -------------------------------------------------------------------------
*/

// Uso de librerias, FILE, fgets, printf, sprintf, argc-argv, 
//			punteros, arrays, funciones, estructuras, graficos...

#include <stdio.h>
#include <string.h>

// Editar nombres al terminar
#include "1-curl_meteo.h"
#include "1-file_meteo.h"
#include "4-xml_meteo.h"
#include "1-graph_meteo.h"

void main(int argc, char const *argv[]) // Para permitir linea de comandos
{
	char *url;
	char direccion[100];
	char ciudad[50];

	if (argc == 1) // Si se abre el programa sin argumentos
	{
		// * Arreglar *
		printf("Dime el nombre de una ciudad\n");
		fgets(ciudad,50,stdin);
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", ciudad);
		url = direccion;
	//////////////////////////////		printf("Test url 1: %s\n",direccion);
	}
	else // Si se abre el programa con argumentos
	{
		//url = "http://www.google.es/ig/api?weather=Fuenlabrada";
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", *argv);
		url = direccion;
	//////////////////////////////		printf("Test url 2: %s\n",direccion);
	}


	char *contenido = descarga(url);	// Funcion descarga en curl_meteo.h

	//////////////////////////////		printf("Test contenido\n%s\n", contenido);

	guarda(contenido);					// Funcion guarda en file_meteo.h

	parsea('1-tiempo.xml');				// Funcion parsea en xml_meteo.h

	// dibuja();						// Funcion dibuja en graph_meteo.h

	return 0;
}