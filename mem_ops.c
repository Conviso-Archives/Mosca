#include "mem_ops.h"


int safe_add(int a, int b) 
{
    	if (a > 0 && b > INT_MAX - a) 
	{
    		DEBUG("Integer Overflow here");
		exit(0);
	} else if (a < 0 && b < INT_MIN - a) {
        	DEBUG("Integer Underflow here");
		exit(0);
	}
    
    return a + b;
}

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *xmallocarray (size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		DEBUG("integer overflow block");
		return NULL;
	}

	void *ptr = malloc (nmemb*size);

	if (ptr == NULL) 
		return NULL;

	return ptr;
}

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *xreallocarray (void *ptr, size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		DEBUG("integer overflow block");
		return NULL;
	}

	void *p = realloc (ptr, nmemb*size);

	if (p == NULL) 
		return NULL;

	return p;
}

static void *xmalloc_fatal(size_t size) 
{
	if ( size == 0 ) 
		return NULL;

	DEBUG("\n Memory FAILURE...\n");

	exit(1);
}

void *xmalloc (size_t size) 
{
	void *ptr = malloc (size);

	if (ptr == NULL) 
		return xmalloc_fatal(size);

	return ptr;
}

void *xcalloc (size_t mem, size_t size) 
{
	void *ptr = calloc (mem, size);

	if (ptr == NULL) 
		return xmalloc_fatal(mem*size);

	return ptr;
}

void *xrealloc (void *ptr, size_t size) 
{
	void *p = realloc (ptr, size);

	if (p == NULL) 
		return xmalloc_fatal(size);

	return p;
}

void xfree(void **ptr) 
{
	assert(ptr);
	if( ptr != NULL )
        {
		free(*ptr);
		*ptr=NULL;	
        }
	
}

volatile void *burn_mem(volatile void *dst, int c, size_t len) 
{
	volatile char *buf;
   
	for(buf = (volatile char *)dst;  len;  buf[--len] = c);

	return dst;
}


