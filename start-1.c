	/*
	* meteo.c: Muestra la prevision de los 4 proximos dias de la ciudad deseada
	* 	librerias usadas:
	* 		cURL: 		Devuelve en XML la prevision del tiempo por medio de la API de google
	* 		libxml2: 	Obtiene los datos del XML preparados para su uso
	* 
	* 
	* Se mostrara el resultado en pantalla
	* Habra dos formas de obtenerlo, por medio de la linea de comandos o desde el propio programa
	* 
	* 
	* SSOO STI 2012
	*/



#include "curl-7.25.0/include/curl/curl.h"
#include "curl-7.25.0/include/curl/easy.h"
#include <stdio.h>
#include <string.h>

size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, void *userp);

void main(int argc, char const *argv[]) // Para permitir comandos en el ejecutable
{
	CURL *curl_handle = NULL;
	char *content = NULL;
	curl_handle = curl_easy_init();
	curl_easy_perform(curl_handle);
	char *url;
	char direccion[100];
	char ciudad[50];

	if (argc == 1) // Si se abre el archivo sin comandos
	{
		printf("Dime el nombre de una ciudad\n");
		fgets(ciudad,50,stdin);
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", ciudad);
		url = direccion;
																						printf("%s\n",direccion);
	}
	else // Si se escribe la direccion desde la linea de comandos ( sin terminar )
	{
		//url = "http://www.google.es/ig/api?weather=Fuenlabrada";
		sprintf(direccion, "http://www.google.es/ig/api?weather=%s", argv);
		url = direccion;
																						printf("%s\n",direccion);
	}

	if (curl_handle) // Si curl consigue funcionar
	{
		// Abre la conexion y recibe la respuesta desde la url
		curl_handle = curl_easy_init();
		curl_easy_setopt(curl_handle,CURLOPT_URL, url);
		curl_easy_setopt(curl_handle, CURLOPT_HTTPGET, 1);
		curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
		curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback_func);
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);
		curl_easy_perform(curl_handle);
		curl_easy_cleanup(curl_handle);

		if (content==NULL)
		{
			printf("Ha habido un error comprueba que estas conectado a internet.\n");
			return 1;
		}

			// Se escribe el contenido en tiempo.txt
		FILE* f;
		//char c[1000];
		f=fopen("tiempo.xml","w");
		if (f == NULL){
		printf ("Error al abrir el fichero");
		}
		else{	//si se abrió correctamente escribimos el texto al fichero

			fprintf(f, "%s", content);




			/*
			do{
				content;
				putc(content,f);
			}while (c != '\0');	//mientras no encontremos el carácter de nueva línea
			*/



		}
		fflush(f);
		fclose(f);


																	printf("%s", content);
	}
	else
	{
		puts("Ha habido un error.(libcurl)");
	}
}

size_t static write_callback_func(void *buffer,
						size_t size,
						size_t nmemb,
						void *userp)
{
	char **response_ptr =  (char**)userp;

	/* assuming the response is a string */
	*response_ptr = strndup(buffer, (size_t)(size *nmemb));
	return 0;
}