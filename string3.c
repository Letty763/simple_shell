#include "shell.h"


/**

 * _strlen - An expression that returns the string's length

 * @s: the string that needs their length inspected

 *

 * Return: length of string

 */

int _strlen(char *s)

{

        int i = 0;


        if (!s)

                return (0);


        while (*s++)

                i++;

        return (i);

}


/**

 * _strcmp - Compares two strings phonetically

 * @s1: this will be the initial string

 * @s2: this will be the second string

 *

 * Return: negative if s1 is less than s2,

 * positive if s1 greater than s2,

 * zero if s1 is equal to s2

 */

int _strcmp(char *s1, char *s2)

{

        while (*s1 && *s2)

        {

                if (*s1 != *s2)

                        return (*s1 - *s2);

                s1++;

                s2++;

        }

        if (*s1 == *s2)

                return (0);

        else

                return (*s1 < *s2 ? -1 : 1);

}


/**

 * starts_with - will inspect if the needle,

 * indeed starts with the haystack

 * @haystack: this will be the string that needs to be found

 * @needle: this will be the substring which needs to be found

 *

 * Return: Haystack's following character address or NULL

 */

char *starts_with(const char *haystack, const char *needle)

{

        while (*needle)

                if (*needle++ != *haystack++)

                        return (NULL);

        return ((char *)haystack);

}


/**

 * _strcat - this will concatenate 2 strings

 * @dest: this will be the target buffer

 * @src: this will be where the buffer originates from

 *

 * Return: variable for the target buffer

 */

char *_strcat(char *dest, char *src)

{

        char *ret = dest;


        while (*dest)

                dest++;

        while (*src)

                *dest++ = *src++;

        *dest = *src;

        return (ret);

}
