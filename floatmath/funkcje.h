#pragma once

#include <string.h>

int main() {
	char str[20] = "3,40";
	char * pch;
	char * pch2;
	pch = strtok(str, ",");
	pch2 = strtok(NULL, ",");
	printf("%s", pch);
	printf("%s", pch2);
}