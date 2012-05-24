#include "curl-7.25.0/include/curl/curl.h"
#include "curl-7.25.0/include/curl/easy.h"

void main() {
	long http_code = 0;
	CURL *curl;
  	CURLcode res;
 
	//Initializing the CURL module
	curl = curl_easy_init();
 
	if(curl) {
 
		// Tell libcurl the URL
		curl_easy_setopt(curl,CURLOPT_URL, "http://www.google.com");
		//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "data=114");
 
		res = curl_easy_perform(curl);
 
		if(CURLE_OK == res) {
		    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
 
		    if(http_code == 200) {
		        puts("Received 200 status code");
		    } else {
		        puts("Did not receive 200 status code");
		    }
		}
	} else {
	    puts("Could not initialize curl");
	}
}