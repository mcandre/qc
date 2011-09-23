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

void qc_init();

void gen_bool(void* d);
void gen_int(void* d);
void gen_char(void* d);
void* gen_array(fp gen, size_t size);
void gen_string(void* d);

// void for_all(fp property, ...);

#endif