// Copyright (C) YelloSoft

#include "qc.h"
#include <gc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "example.h"

void gen_odd(blob const data) {
  int i;
  gen_int(&i);

  if (i % 2 == 0) {
    i++;
  }

  qc_return(int, i);
}

bool xors_self_to_false(blob const data) {
  bool b = qc_args(bool, 0, bool);

  return (b ^ b) == false;
}

bool is_odd(blob const data) {
  int n = qc_args(int, 0, int);

  return n % 2 == 1;
}

bool both_less_than(blob const data) {
  int a = qc_args(int, 0, int);
  int b = qc_args(int, 1, int);
  int c = qc_args(int, 2, int);

  return a < c && b < c;
}

void gen_digit_char(blob const data) {
  int i;
  char c;

  gen_int(&i);

  i %= 10;

  c = '0' + (char) i;

  qc_return(char, c);
}

void gen_digit(blob const data) {
  int i;
  gen_int(&i);

  i %= 10;

  qc_return(int, i);
}

bool does_not_parse_to(blob const data) {
  char c;
  int i;

  c = qc_args(char, 0, int);
  i = qc_args(int, 1, int);

  return (c - '0') != (char) i;
}

bool does_not_have_an_h(blob const data) {
  char *s = qc_args(char *, 0, char *);

  return strchr(s, 'h') == NULL;
}

int main() {
  gen gs0[] = { gen_bool };
  print ps0[] = { print_bool };

  gen gs[] = { gen_odd };
  print ps[] = { print_int };

  gen gs2[] = { gen_int };
  print ps2[] = { print_int };

  gen gs3[] = { gen_int, gen_int, gen_int };
  print ps3[] = { print_int, print_int, print_int };

  gen gs4[] = { gen_digit_char, gen_digit };
  print ps4[] = { print_char, print_int };

  gen gs5[] = { gen_string };
  print ps5[] = { print_string };

  qc_init();

  // Do all booleans XOR themselves to false?
  for_all(xors_self_to_false, 1, gs0, ps0, bool);

  // Are all odd numbers odd?
  for_all(is_odd, 1, gs, ps, int);

  // Are all integers odd?
  for_all(is_odd, 1, gs2, ps2, int);

  // Are any two integers less than a third integer?
  for_all(both_less_than, 3, gs3, ps3, int);

  // Do any characters parse to a matching integer?
  for_all(does_not_parse_to, 2, gs4, ps4, int);

  // Do any string pairs match?
  for_all(does_not_have_an_h, 1, gs5, ps5, char *);

  return 0;
}
