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

bool gen_bool() {
	bool b = rand() % 2 == 0;

	return b;
}

int gen_int() {
	int i = rand();

	return i;
}

char gen_char() {
	char c = (char) (rand() % 128);

	return c;
}

blob* _gen_array(gen g, size_t size) {
	int len = rand() % 100;

	blob* arr = GC_MALLOC(len * size);

	int i;
	for (i = 0; i < len; i++) {
		*(arr + i * size) = g();
	}

	return arr;
}

char* gen_string() {
	char* s = (char*) gen_array(gen_char, char);

	return s;
}

void print_bool(blob data) {
	bool b = qc_args(bool, 0, bool);

	if (b) {
		printf("true");
	}
	else {
		printf("false");
	}
}

void print_int(blob data) {
	int i = qc_args(int, 0, int);

	printf("%d", i);
}

void print_char(blob data) {
	char c = qc_args(char, 0, char);

	printf("\'%c\'", c);
}

void print_string(blob data) {
	char* s = qc_args(char*, 0, char*);

	printf("%s", s);
}

void _for_all(prop property, int arglen, gen gs[], print ps[], size_t max_size) {
	int i, j, k;

	// Because GC_MALLOC will segfault if GC_INIT() is not called beforehand.
	if (!QC_INITIALIZED) {
		printf("*** Error: Run qc_init() before calling for_all().\n");
		return;
	}

	blob* test_case = GC_MALLOC(arglen * max_size);

	for (i = 0; i < 1/*00*/; i++) {
		for (j = 0; j < arglen; j++) {
			*(test_case + j * max_size) = gs[j]();
		}

		bool holds = property(test_case);

		// if (!holds) {
			printf("*** Failed!\n");
		
			for (k = 0; k < arglen; k++) {
				ps[k](test_case + k * max_size);
				printf("\n");
			}

			return;
		// }
	}

	printf("+++ OK, passed 100 tests.\n");
}