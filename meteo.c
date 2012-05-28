/*
	* -------------------------------------------------------------------------
	* meteo.c: Muestra la prevision de los 4 proximos dias de la ciudad deseada
	* 	librerias usadas:
	* 		libcurl: 		Descarga una URL de internet.
	* 		libxml2: 		Obtiene los datos del XML.
	* 		libgraph:		graphics.h de Turbo C en Linux.
	*
	* cURL descargara la prevision del tiempo de la API de google
	* libxml2 obtendra los datos del archivo en formato XML
	* libgraph mostrara los datos dibujados en la pantalla
	*
	* Dos formas de uso:
	*		Por medio de la linea de comandos.
	*		Desde el propio programa.
	* 
	* 
	* SSOO STI 2012. grupo 5 									28-Mayo-2012
	* -------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

#include "curl_meteo.h"
#include "file_meteo.h"
#include "xml_meteo.h"
#include "replace_meteo.h"
#include "graph_meteo.h"

void main(int argc, char const *argv[]) // Para permitir linea de comandos
{
	char *url;
	char direccion[100];
	char ciudad[50];

	if (argc == 1) // Si se abre el programa sin argumentos
	{
		printf("Dime el nombre de una ciudad\n");
		fgets(ciudad,50,stdin);
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", ciudad);
	}
	else // Si se abre el programa con argumentos
	{
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", *argv);
	}

	replaza(direccion);									// Funcion descarga en replace_meteo.h
	url = direccion;
	
	char *contenido = descarga(url);					// Funcion descarga en curl_meteo.h
	guarda(contenido);									// Funcion guarda en file_meteo.h

	char *nombrearchivo = "tiempo.xml";
	parsea(nombrearchivo);								// Funcion parsea en xml_meteo.h

	dibuja();											// Funcion dibuja en graph_meteo.h

	// return 0;
}