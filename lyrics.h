#ifndef _STDBOOL_H_
#include <stdbool.h>
#endif

#ifndef __CURL_CURL_H
#include <curl/curl.h>
#endif

bool verbose = false;

char *format = "xml";

CURL *curl;
CURLcode res;