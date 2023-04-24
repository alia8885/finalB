#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"libcurl.lib")
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<curl/curl.h>
#include "appdev.h"

int main(void) {
	rock r;
	printf("Application Developers rock!\n"); 
	printf("Enter your name: ");
	scanf_s("%s", r.rname, (unsigned)_countof(r.rname));
	r.max = rand() % 50 + 51;
	r.min = rand() % 50 + 1;
	send_data(r);
	printf("Rockin 'Roll\n");
	return 0;
}

void send_data(rock r) {
	CURL* curl;
	CURLcode res;
	char poststr[100];
	sprintf(poststr, "min=%d&max=%d&user=%s", r.min, r.max, r.rname);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.cc.puv.fi/~e2203754/appdevv.php");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			printf("Post to server is failed\n"); return 1;
		}
		curl_easy_cleanup(curl);

	}
	return;
}