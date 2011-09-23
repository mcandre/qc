#include "qc.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	qc_init();

	bool random_bool;
	gen_bool(&random_bool);

	printf("Random bool: %d\n", random_bool);

	int random_int;
	gen_int(&random_int);

	printf("Random int: %d\n", random_int);

	char random_char;
	gen_char(&random_char);

	printf("Random char: %c\n", random_char);

	char* random_string;
	gen_string(&random_string);

	printf("Random string: %s\n", random_string);

	return 0;
}