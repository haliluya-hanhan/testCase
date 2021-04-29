//check type:c/cpp 
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
typedef enum { FALSE, TRUE}boolean;
typedef struct sVString {
	size_t  length;  /* size of buffer used */
	size_t  size;    /* allocated size of buffer */
	char   *buffer;  /* location of buffer */
} vString;
void *eMalloc (const size_t size) { return malloc(size); }
extern void *eRealloc (void *const ptr, const size_t size)
{
	void *buffer;
	if (ptr == NULL)
		buffer = eMalloc (size);
	else
	{
		buffer = realloc (ptr, size);
		
	}
	return buffer;
}

#define xRealloc(p,n,Type) (Type *)eRealloc((p), (n) * sizeof (Type))
static void vStringResize (vString *const string, const size_t newSize)
{
	char *const newBuffer = xRealloc (string->buffer, newSize, char);

	string->size = newSize;
	string->buffer = newBuffer;
}
 boolean vStringAutoResize (vString *const string)
{
	boolean ok = TRUE;

	if (string->size <= INT_MAX / 2)
	{
		const size_t newSize = string->size * 2;

		vStringResize (string, newSize);
	}
	return ok;
}

#define vStringPut(s,c) \
	(void)(((s)->length + 1 == (s)->size ? vStringAutoResize (s) : 0),\
	((s)->buffer [(s)->length] = (c)),\
	((c) == '\0' ? 0 : ((s)->buffer [++(s)->length] = '\0')))
int main()
{
    FILE*  fp;
    int c;
    vString* vs;
    do
			{
				vStringPut (vs, c);  //误报-vs->buffer应该不会越界
				c = fgetc (fp);
			} while (c != EOF  &&  ! isspace (c)); 
}