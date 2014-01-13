#ifndef QC
#define QC

#include <stdlib.h>
#include <stdbool.h>

void qc_init(void);

#define qc_return(type, value) ((* (type*) data) = value)
#define qc_args(type, n, max_class) ((* (type*) (data + n * sizeof(max_class))))

typedef void* blob;

typedef void (*gen)(blob);
typedef void (*print)(blob);
typedef bool (*prop)(blob);

void gen_bool(/*@out@*/ blob const data);
void gen_int(/*@out@*/ blob const data);
void gen_char(/*@out@*/ blob const data);

void _gen_array(/*@out@*/ blob const data, gen const g, size_t const size);

#define gen_array(data, g, class) (_gen_array(data, (gen) g, sizeof(class)))

void gen_string(/*@out@*/ blob const data);

void print_bool(blob const data);
void print_int(blob const data);
void print_char(blob const data);
void print_string(blob const data);

void _for_all(prop const property, size_t const arglen, gen const gs[], print const ps[], size_t const max_size);

#define for_all(property, arglen, gs, ps, max_class) (_for_all((prop) property, arglen, gs, ps, sizeof(max_class)))

#endif
