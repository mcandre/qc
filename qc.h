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

void qc_init();

void gen_bool(void* data);
void gen_int(void* data);
void gen_char(void* data);
void gen_array(void* data, fp gen, int len, size_t size);
void gen_string(void* data);

void print_int(void* data);

void for_all(prop property, int arglen, fp generators[], fp printers[], size_t max_size);

#endif