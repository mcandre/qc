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

bool QC_INITIALIZED;

void qc_init();

// #define qc_return(type, value) ((* (type*) data) = value)
#define qc_args(type, n, max_class) ((* (type*) (data + n * sizeof(max_class))))

typedef void* blob;

typedef blob (*gen)();
typedef void (*print)(blob);
typedef bool (*prop)(blob);

bool gen_bool();
int gen_int();
char gen_char();

blob* _gen_array(gen g, size_t size);

#define gen_array(g, class) (_gen_array((gen) g, sizeof(class)))

char* gen_string();

void print_bool(blob data);
void print_int(blob data);
void print_char(blob data);
void print_string(blob data);

void _for_all(prop property, int arglen, gen gs[], print ps[], size_t max_size);

#define for_all(property, arglen, gs, ps, max_class) (_for_all((prop) property, arglen, gs, ps, sizeof(max_class)))

#endif