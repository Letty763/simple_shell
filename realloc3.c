#include "shell.h"


/**

 * _memset - Ensures that a constant byte is filled in memory

 * @s: this is the variable for the memory

 * @b: the byte which will be filled

 * @n: the number of bytes which needs to be filled

 * Return: the variable for the memory

 */

char *_memset(char *s, char b, unsigned int n)

{

        unsigned int i;


        for (i = 0; i < n; i++)

                s[i] = b;

        return (s);

}


/**

 * ffree - will release a string of strings

 * @pp: this will be string of strings to be relesed

 */

void ffree(char **pp)

{

        char **a = pp;


        if (!pp)

                return;

        while (*pp)

                free(*pp++);

        free(a);

}


/**

 * _realloc - will redistribute a section of memory

 * @ptr: variable for former malloc'ated section

 * @old_size: this will be the dimensions,

 * of the bytes former section

 * @new_size: this will be the bytes,

 * dimensions for a fresh section

 *

 * Return: variable for the former section

 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{

        char *p;


        if (!ptr)

                return (malloc(new_size));

        if (!new_size)

                return (free(ptr), NULL);

        if (new_size == old_size)

                return (ptr);


        p = malloc(new_size);

        if (!p)

                return (NULL);


        old_size = old_size < new_size ? old_size : new_size;

        while (old_size--)

                p[old_size] = ((char *)ptr)[old_size];

        free(ptr);

        return (p);

}
