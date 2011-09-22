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

char* gen_string() {
	int i, len = gen_int() % 100;

	char* s = (char*) GC_MALLOC(len * sizeof(char));

	for (i = 0; i < len; i++) {
		s[i] = gen_char();
	}

	return s;
}

void for_all() {
	// ...
}