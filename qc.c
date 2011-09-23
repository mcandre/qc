#include "qc.h"
#include <gc.h>
#include <stdlib.h>
#include <stdio.h>

void qc_init() {
	GC_INIT();
	srand((unsigned int) time(NULL));
}

bool gen_bool() {
	return rand() % 2 == 0;
}

int gen_int() {
	return rand();
}

char gen_char() {
	return (char) (gen_int() % 128);
}

void* gen_array(fp gen, size_t size) {
	int i, len = gen_int() % 100;

	void* arr = (void*) GC_MALLOC(len * size);

	for (i = 0; i < len; i++) {
		arr[i] = gen();
	}

	return arr;
}

char* gen_string() {
	return (char*) gen_array((fp) gen_char, sizeof(char));
}

// // Syntax:
// //
// // for_all(property, gen1, print1, gen2, print2, ...);
// 
// void for_all(void *property, ...) {
// 	// ...
// }