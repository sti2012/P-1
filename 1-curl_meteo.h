#include <curl/curl.h>
#include <curl/easy.h>
#include <stdlib.h> // Para malloc()

size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, void *userp);

char *descarga(char const *url)
{
	// Inicia cURL
	CURL *curl_handle = NULL;

	char *content = NULL;     
	content = malloc(2000);						   // ------------------------------ Arreglado (?)

	curl_handle = curl_easy_init();
	curl_easy_perform(curl_handle);

	// Abre la conexion y recibe la respuesta desde la url
	curl_handle = curl_easy_init();
	curl_easy_setopt(curl_handle,CURLOPT_URL, url);
	curl_easy_setopt(curl_handle, CURLOPT_HTTPGET, 1);
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback_func);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);
	curl_easy_perform(curl_handle);
	curl_easy_cleanup(curl_handle);

	if (content == NULL)
	{
		printf("Ha habido un error comprueba que estas conectado a internet.\n");
	}
	else
	{

	//////////////////////////////		printf("Test curl \n%s\n", content);

	return content; // Devuelve la respuesta de la funcion
	}
}

size_t static write_callback_func(void *buffer,
						size_t size,
						size_t nmemb,
						void *userp)
{
	char **response_ptr =  (char**)userp;
	*response_ptr = strndup(buffer, (size_t)(size *nmemb));
	return 0;
}