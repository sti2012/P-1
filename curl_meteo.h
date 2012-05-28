// http://curl.haxx.se/libcurl/c/getinmemory.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <curl/curl.h>
 
struct MemoryStruct {
	char *memory;
	size_t size;
};
 
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
	mem->memory = realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
	/* out of memory! */ 
	printf("not enough memory (realloc returned NULL)\n");
	exit(EXIT_FAILURE);
	}
 
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
 
	return realsize;
}
 
//int main(void)
char *descarga(char const *url)
{
	CURL *curl_handle;
 
	struct MemoryStruct chunk;
 
	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */ 
	chunk.size = 0;    /* no data at this point */ 
 
	curl_global_init(CURL_GLOBAL_ALL);
 
	/* init the curl session */ 
	curl_handle = curl_easy_init();
 
	/* specify URL to get */ 
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
 
	/* send all data to this function  */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
 
	/* we pass our 'chunk' struct to the callback function */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
 
	/* some servers don't like requests that are made without a user-agent
	 field, so we provide one */ 
	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
 
	/* get it! */ 
	curl_easy_perform(curl_handle);
 
	/* cleanup curl stuff */ 
	curl_easy_cleanup(curl_handle);
 
	/*
	 * Now, our chunk.memory points to a memory block that is chunk.size
	 * bytes big and contains the remote file.
	 *
	 * Do something nice with it!
	 *
	 * You should be aware of the fact that at this point we might have an
	 * allocated data block, and nothing has yet deallocated that data. So when
	 * you're done with it, you should free() it as a nice application.
	 */ 
 
	printf("%lu bytes retrieved\n", (long)chunk.size);
 
	if(chunk.memory)
	{
		printf("Received:\n%s\n", chunk.memory);
//		free(chunk.memory);
	}

	/* we're done with libcurl, so clean it up */ 
	curl_global_cleanup();
 
	return chunk.memory;
}