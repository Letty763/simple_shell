#include "shell.h"


/**

 * bfree - this will release a variable,

 * and it will NULL its address

 * @ptr: address of pointer which needs to be released

 *

 * Return: if it is released 1, else 0 if not.

 */

int bfree(void **ptr)

{

        if (ptr && *ptr)

        {

                free(*ptr);

                *ptr = NULL;

                return (1);

        }

        return (0);

}
