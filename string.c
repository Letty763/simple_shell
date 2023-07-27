#include "shell.h"


/**

 * _strlen - the length of the string

 *@s: this will be the string used

 * Return: strings length

 */


size_t _strlen(char *s)

{

        if (!s || *s == '\0')

                return (0);

        return (1 + _strlen(s + 1));

}


/**

 * _strcmp - this will contrast

 *@s1: this will be the initial string

 *@s2: this will be the following string

 *Return: an int

 */

int _strcmp(const char *s1, char *s2)

{

        for (; *s1 == *s2; s1++, s2++)

        {

                if (*s1 == '\0')

                        return (0);

        }

        return (*s1 - *s2);

}

/**

 * _strncmp - contrasts n amount of characters

 * @s1: this will be the initial string

 * @s2: this will be the subsequent string

 * @n: this will be the amount

 * Return: an int or 0

 */

int _strncmp(const char *s1, char *s2, int n)

{

        for (; n && *s1 == *s2; n--, s1++, s2++)

                ;

        if (n)

                return (*s1 - *s2);

        return (0);

}

/**

 * _strstr - this will find a substring

 * @haystack: this will be the string

 * @needle: thai will be the string which is being looked for

 * Return: location of string or NULL

 */


char *_strstr(char *haystack, char *needle)

{

        int i, j;


        if (*haystack == '\0' && *needle == '\0')

                return (NULL);

        for (i = 0; haystack[i] != '\0'; i++)

        {

                for (j = 0; needle[j] != '\0'; j++)

                {

                        if (needle[j] != haystack[i + j])

                                break;

                }

                if (needle[j] == '\0')

                        return (&haystack[i]);

        }

        return (NULL);

}

/**

 * _memcpy - this will duplicate the memory region

 * @dest: this will be the destination of the memory region

 * @src: this will be the source of the memory region

 * @n: this will be the bytes of the memory

 * Return: the destinantion

 */

char *_memcpy(char *dest, char *src, unsigned int n)

{

        unsigned int i;


        for (i = 0; i < n; i++)

        {

                dest[i] = src[i];

        }

        return (dest);

}
