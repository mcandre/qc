#include "qc.h"
#include <stdlib.h>
#include <stdio.h>

void qc_init() {
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
	char* s;

	// ...

	return s;
}

void for_all() {
	// ...
}