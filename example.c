#include "qc.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	qc_init();

	printf("Char: %c\n", gen_char());

	return 0;
}