#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>

#define DLLEXPORT __declspec(dllexport)

extern "C" DLLEXPORT  int
__stdcall  GetMinRefreshInterval(){
	return 500;
}

int precyzja = 3;

extern "C" DLLEXPORT  char *
__stdcall  function1(char *param1, char *param2) {
	static char outbuf[100];
	double wynik = atof(param1) + atof(param2);
	_gcvt_s(outbuf, wynik, precyzja);
	return outbuf;
}

extern "C" DLLEXPORT  char *
__stdcall  function2(char *param1, char *param2) {
	static char outbuf[100];
	double wynik = atof(param1) - atof(param2);
	_gcvt_s(outbuf, wynik, precyzja);
	return outbuf;
}

extern "C" DLLEXPORT  char *
__stdcall  function3(char *param1, char *param2) {
	static char outbuf[100];
	double wynik = atof(param1) * atof(param2);
	_gcvt_s(outbuf, wynik, precyzja);
	return outbuf;
}

extern "C" DLLEXPORT  char *
__stdcall  function4(char *param1, char *param2) {
	static char outbuf[100];
	double wynik = atof(param1) / atof(param2);
	_gcvt_s(outbuf, wynik, precyzja);
	return outbuf;
}

/* skleja dwa parametry w jeden z kropk¹, np param1 = 3, param2 = 14, outbuf = 3.14 */
extern "C" DLLEXPORT  char *
__stdcall  function5(char *param1, char *param2) {
	static char liczba[20];
	strcpy_s(liczba, param1);
	strcat_s(liczba, ".");
	strcat_s(liczba, param2);
	return liczba;
}

/* zamienia np. 3,14 na 3.14 */
extern "C" DLLEXPORT  char *
__stdcall  function6(char *param1, char *param2) {
	static char outbuf[100];
	char * pch;
	char * pch2;
	pch = strtok(param1, ",");
	pch2 = strtok(NULL, ",");
	strcpy_s(outbuf, pch);
	strcat_s(outbuf, ".");
	strcat_s(outbuf, pch2);
	return outbuf;
}