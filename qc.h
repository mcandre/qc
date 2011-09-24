#ifndef QC
#define QC

#include <stdlib.h>

typedef int bool;

#ifndef true
	#define true 1
#endif

#ifndef false
	#define false 0
#endif

typedef void (*fp)(void*);
typedef bool (*prop)(void*);

bool QC_INITIALIZED;

void qc_init();

#define qc_return(type, value) ((* (type*) data) = value)
#define qc_args(type, n, max_size) ((* (type*) (data + n * max_size)))

void gen_bool(void* data);
void gen_int(void* data);
void gen_char(void* data);

void _gen_array(void* data, fp gen, int len, size_t size);

#define gen_array(data, gen, len, size) (_gen_array(data, (fp) gen, len, size))

void gen_string(void* data);

void print_bool(void* data);
void print_int(void* data);
void print_char(void* data);
void print_string(void* data);

void _for_all(prop property, int arglen, fp generators[], fp printers[], size_t max_size);

#define for_all(property, arglen, generators, printers, max_size) (_for_all((prop) property, arglen, generators, printers, max_size))

#endif