#include "qc.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	qc_init();

	printf("String: %s\n", gen_string());

	return 0;
}