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

	if (argc == 1) {
		arguments();
	}

	for (int i = 0; i < argc; i++) {

		// If verbose
		if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
			verbose = true;
		}

		// If returned data format is specified
		if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--format") == 0) {

			// If there aren't any arguments to -f or --format
			if (argc - i == 1) {
				arguments();
			}

			// If format is XML
			if (strcmp(argv[i+1], "xml") == 0) {
				format = "xml";
			}

			// If format is json
			if (strcmp(argv[i+1], "json") == 0) {
				format = "json";
			}

			// If format is HTML
			if (strcmp(argv[i+1], "html") == 0) {
				format = "html";
			}

			// If format is text
			if (strcmp(argv[i+1], "text") == 0) {
				format = "text";
			}
		}
	}

	// Allocate memory for the base url. The 39 is the amount of chars in the base. 1 is for the null char.
	char *baseurl = malloc(1);

	char *url = "http://api.chartlyrics.com/apiv1.asmx/GetLyric?lyricId=1710&lyricCheckSum=b6d42dee5adafc97b7c0247a5740c57f";

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
    
	curl_easy_setopt(curl, CURLOPT_URL, url);
	
	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);

	return 0;
}