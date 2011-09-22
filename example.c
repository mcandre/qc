#include "qc.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	qc_init();

	printf("Bool: %d\n", gen_bool());

	return 0;
}