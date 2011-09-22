#ifndef QC
#define QC

typedef int bool;

#ifndef true
	#define true 1
#endif

#ifndef false
	#define false 0
#endif

void qc_init();

bool gen_bool();
int gen_int();
char gen_char();
char* gen_string();

void for_all();

#endif