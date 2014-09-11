#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#include "lyrics.h"

void 
arguments() 
{
	printf("Usage: lyrics [options] <song> <artist>\n    -v, --verbose   Print verbosely\n");
	exit(1);
}

int 
main (int argc, char** argv) 
{
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
			verbose = true;
		}
	}

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
    
	curl_easy_setopt(curl, CURLOPT_URL, "http://lyrics.wikia.com/api.php?artist=Cake&song=Dime&fmt=xml");
	
	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	arguments();
	return 0;
}