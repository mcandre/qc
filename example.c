#include "qc.h"
#include <gc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void gen_odd(void *data) {
	int i;
	gen_int(&i);

	if (i % 2 == 0) {
		i++;
	}

	qc_return(int, i);
}

bool is_odd(void *data) {
	int n = qc_args(int, 0, sizeof(int));

	return n % 2 == 1;
}

bool both_less_than(void *data) {
	int a = qc_args(int, 0, sizeof(int));
	int b = qc_args(int, 1, sizeof(int));
	int c = qc_args(int, 2, sizeof(int));

	return a < c && b < c;
}

void gen_digit_char(void *data) {
	int i;
	gen_int(&i);

	i %= 10;

	char c = '0' + (char) i;

	qc_return(char, c);
}

void gen_digit(void *data) {
	int i;
	gen_int(&i);

	i %= 10;

	qc_return(int, i);
}

bool does_not_parse_to(void *data) {
	char c = qc_args(char, 0, sizeof(int));
	int i = qc_args(int, 1, sizeof(int));

	return (c - '0') != i;
}

bool does_not_have_an_h(void *data) {
	char* s = qc_args(char*, 0, sizeof(char*));

	return strchr(s, 'h') == NULL;
}

int main() {
	qc_init();

	gen gs[] = { gen_odd };

	print ps[] = { print_int };

	// Are all odd numbers odd?
	for_all(is_odd, 1, gs, ps, sizeof(int));

	gen gs2[] = { gen_int };
	print ps2[] = { print_int };

	// Are all integers odd?
	for_all(is_odd, 1, gs2, ps2, sizeof(int));

	gen gs3[] = { gen_int, gen_int, gen_int };
	print ps3[] = { print_int, print_int, print_int };

	// Are any two integers less than a third integer?
	for_all(both_less_than, 3, gs3, ps3, sizeof(int));

	gen gs4[] = { gen_digit_char, gen_digit };
	print ps4[] = { print_char, print_int };

	// Do any characters parse to a matching integer?
	for_all(does_not_parse_to, 2, gs4, ps4, sizeof(int));

	gen gs5[] = { gen_string };
	print ps5[] = { print_string };

	// Do any string pairs match?
	for_all(does_not_have_an_h, 1, gs5, ps5, sizeof(char*));

	return 0;
}