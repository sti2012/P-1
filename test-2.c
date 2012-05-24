#include "curl-7.25.0/include/curl/curl.h"
//#include "include/curl/types.h"
#include "curl-7.25.0/include/curl/easy.h"
#include <string.h>
#include <stdio.h>

/* function prototypes to define later */
char *do_web_request(char *url);
size_t static write_callback_func(void *buffer,
						size_t size,
						size_t nmemb,
						void *userp);

/* the main function invoking */
int main(int argc, char const *argv[])
{
	char *url = "http://www.google.es/ig/api?weather=Fuenlabrada";
	char *content = NULL;

	content = do_web_request(url);

	printf("%s", content);
}

/* the function to return the content for a url */
char *do_web_request(char *url)
{
	/* keeps the handle to the curl object */
	CURL *curl_handle = NULL;
	/* to keep the response */
	char *response = NULL;

	/* initializing curl and setting the url */
	curl_handle = curl_easy_init();
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	curl_easy_setopt(curl_handle, CURLOPT_HTTPGET, 1);

	/* follow locations specified by the response header */
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);

	/* setting a callback function to return the data */
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback_func);

	/* passing the pointer to the response as the callback parameter */
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &response);

	/* perform the request */
	curl_easy_perform(curl_handle);

	/* cleaning all curl stuff */
	curl_easy_cleanup(curl_handle);

	return response;
}

/* the function to invoke as the data recieved */
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