#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* 
    Description             The C library function void *malloc(size_t size) allocates the requested memory and returns a pointer to it.

    Prototype               void *malloc(size_t size)

    Parameters              size − This is the size of the memory block, in bytes.

    Return Value            This function returns a pointer to the allocated memory, or NULL if the request fails.
 */

int main()
{
    char *s;
    s = (char *)malloc(10);

    s = strcpy(s, "Hello!");
    printf("string -> %s\nAddress -> %u", s, s);
    return (0);
}