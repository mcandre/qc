#ifndef QC
#define QC

typedef int bool;

#ifndef true
	#define true 1
#endif

#ifndef false
	#define false 0
#endif

typedef void (*fp)(void);

void qc_init();

bool gen_bool();
int gen_int();
char gen_char();
void* gen_array(fp gen, size_t size);
char* gen_string();

// void for_all(fp property, ...);

#endif