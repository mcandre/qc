#include "qc.h"
#include <gc.h>
#include <stdlib.h>
#include <stdio.h>

void gen_odd(void *data) {
	int i;
	gen_int(&i);

	if (i % 2 == 0) {
		i++;
	}

	(* (int*) data) = i;
}

bool is_odd(void *args) {
	int n = (* (int*) args);

	return n % 2 == 1;
}

int main() {
	qc_init();

	fp gs[] = { gen_odd };

	fp ps[] = { print_int };

	// Are all odd numbers odd?
	for_all((prop) is_odd, 1, gs, ps, sizeof(int));

	fp gs2[] = { gen_int };
	fp ps2[] = { print_int };

	// Are all integers odd?
	for_all((prop) is_odd, 1, gs2, ps2, sizeof(int));

	return 0;
}