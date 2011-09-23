#include "qc.h"
#include <gc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include <stdarg.h>

void qc_init() {
	GC_INIT();
	srand((unsigned int) time(NULL));
}

void gen_bool(void* data) {
	bool b = rand() % 2 == 0;

	(* (bool*) data) = b;
}

void gen_int(void* data) {
	int i = rand();

	(* (int*) data) = i;
}

void gen_char(void* data) {
	char c = (char) (rand() % 128);

	(* (char*) data) = c;
}

void gen_array(void* data, fp gen, int len, size_t size) {
	int i;
	for (i = 0; i < len; i++) {
		gen(data + i * size);
	}
}

void gen_string(void* data) {
	int len = rand() % 100;

	size_t size = sizeof(char);

	char* str = (char*) GC_MALLOC(len * size);

	gen_array(str, (fp) gen_char, len, sizeof(char));

	(* (char**) data) = str;
}

// Syntax:
//
// for_all(property, gen1, print1, gen2, print2, ...);

// void for_all(fp property, ...) {
// 	va_list ap1, ap2;
// 	int i;
// 
// 	va_copy(ap2, ap1);
// 
// 	if (property(property, ap2)) {
// 		printf("+++ OK, passed 100 tests.\n");
// 	}
// 	else {
// 		printf("*** Failed!\n");
// 	}
// }