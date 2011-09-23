#include "qc.h"
#include <gc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

	gen_array(str, (fp) gen_char, len, size);

	(* (char**) data) = str;
}

void print_int(void* data) {
	int i = (* (int*) data);

	printf("%d", i);
}

void for_all(prop property, int arglen, fp generators[], fp printers[], size_t max_size) {
	int i, j;

	void* values = GC_MALLOC(arglen * max_size);

	for (i = 0; i < 100; i++) {
		for (j = 0; j < arglen; j++) {
			generators[j](values + j * max_size);
		}

		bool holds = property(values);

		if (!holds) {
			printf("*** Failed!\n");
		
			for (j = 0; j < arglen; j++) {
				printers[j](values + j * max_size);
				printf("\n");
			}

			return;
		}
	}

	printf("+++ OK, passed 100 tests.\n");
}