#include <stdio.h>	
#include <sys/types.h>
#include <string.h>		
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include <stddef.h>

#define XFREE(x) xfree((void **)&x); 
#define MUL_NO_OVERFLOW	((size_t)1 << (sizeof(size_t)*4))

// set DEBUG ON
#define BUGVIEW 1
#define DEBUG(x, s...) do { \
 if (!BUGVIEW) { break; } \
 time_t t = time(NULL); \
 char *d = ctime(&t); \
 fprintf(stderr, "\n--- DEBUG-START ---\n\n %.*s %s[%d] %s(): \n", \
 (int)strlen(d) - 1, d, __FILE__, \
 __LINE__, __FUNCTION__); \
 fprintf(stderr, x, ## s); \
 fprintf(stderr,"\n\n--- DEBUG-END ---\n"); \
} while (0);
 
int safe_add(int a, int b); 
// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *xmallocarray (size_t nmemb, size_t size); 
// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *xreallocarray (void *ptr, size_t nmemb, size_t size); 
void *xmalloc (size_t size);
void *xcalloc (size_t mem, size_t size);
void *xrealloc (void *ptr, size_t size);
void xfree(void **ptr);
volatile void *burn_mem(volatile void *dst, int c, size_t len); // secure way to erase memory 
