#include "shell.h"


/**

 * _strpbrk - scans string for bytes

 * @s: this will be the string used

 * @accept: characters that can be accepted

 * Return: amount or 0

 */

char *_strpbrk(char *s, char *accept)

{

        int i, j;


        if (*s == '\0' && *accept == '\0')

                return (0);

        for (i = 0; s[i] != '\0'; i++)

        {

                for (j = 0; accept[j] != '\0'; j++)

                {

                        if (s[i] == accept[j])

                                break;

                }

                if (accept[j] != '\0')

                        break;

        }

        if (s[i] != '\0')

                return (&s[i]);

        return (0);

}


/**

 * _strcpy - duplicates a string by source to destination

 *@src: this will be the string used

 *@dest: this will be the buffer

 * Return: destination string

 */

char *_strcpy(char *dest, char *src)

{

        int i;


        for (i = 0; src[i] != '\0'; i++)

                dest[i] = src[i];

        dest[i] = '\0';

        return (dest);

}


/**

 * _strcat - concatenates two strings together

 *@src: this will be the initial string

 *@dest: this will be the following string

 *Return: destination string

 */

char *_strcat(char *dest, char *src)

{

        int i, j;


        for (i = 0; dest[i] != '\0'; i++)

                ;

        dest[i] = ' ';

        for (j = 0; src[j] != '\0'; i++, j++)

                dest[i] = src[j];

        dest[i] = '\0';

        return (dest);

}


/**

 * del - thai will erase the initial character of a string

 * @s: this will be the string used

 */

void del(char **s)

{

        int i;


        for (i = 0; (*s)[i]; i++)

                (*s)[i] = (*s)[i + 1];

}
