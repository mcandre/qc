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

void gen_bool(void* d) {
	bool b = rand() % 2 == 0;

	(* (bool*) d) = b;
}

void gen_int(void* d) {
	int i = rand();

	(* (int*) d) = i;
}

void gen_char(void* d) {
	char c = (char) (rand() % 128);

	(* (char*) d) = c;
}

void* gen_array(fp gen, size_t size) {
	int i, len = rand() % 100;

	void* arr = GC_MALLOC(len * size);

	for (i = 0; i < len; i++) {
		gen(arr + i * size);
	}

	return arr;
}

void gen_string(void* d) {
	char* str = (char*) gen_array((fp) gen_char, sizeof(char));

	(* (char**) d) = str;
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