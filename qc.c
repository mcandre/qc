#include "qc.h"
#include <gc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void qc_init() {
	GC_INIT();
	srand((unsigned int) time(NULL));

	QC_INITIALIZED = true;
}

void gen_bool(void* data) {
	bool b = rand() % 2 == 0;

	qc_return(bool, b);
}

void gen_int(void* data) {
	int i = rand();

	qc_return(int, i);
}

void gen_char(void* data) {
	char c = (char) (rand() % 128);

	qc_return(char, c);
}

void _gen_array(void* data, fp gen, int len, size_t size) {
	int i;
	for (i = 0; i < len; i++) {
		gen(data + i * size);
	}
}

void gen_string(void* data) {
	int len = rand() % 100;

	size_t size = sizeof(char);

	char* s = (char*) GC_MALLOC(len * size);

	gen_array(s, gen_char, len, size);

	qc_return(char*, s);
}

void print_bool(void* data) {
	bool b = (* (bool*) data);

	if (b) {
		printf("true");
	}
	else {
		printf("false");
	}
}

void print_int(void* data) {
	int i = qc_args(int, 0, sizeof(int));

	printf("%d", i);
}

void print_char(void* data) {
	char c = qc_args(char, 0, sizeof(char));

	printf("\'%c\'", c);
}

void print_string(void* data) {
	char* s = qc_args(char*, 0, sizeof(char*));

	printf("%s", s);
}

void _for_all(prop property, int arglen, fp generators[], fp printers[], size_t max_size) {
	int i, j;

	// Because GC_MALLOC will segfault if GC_INIT() is not called beforehand.
	if (!QC_INITIALIZED) {
		printf("*** Error: Run qc_init() before calling for_all().\n");
		return;
	}

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