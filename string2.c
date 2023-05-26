#include "shell.h"


/**

 * _strcpy - this will duplicate the string

 * @dest: this will be the target

 * @src: this will be the origin

 *

 * Return: variable for the target

 */

char *_strcpy(char *dest, char *src)

{

        int i = 0;


        if (dest == src || src == 0)

                return (dest);

        while (src[i])

        {

                dest[i] = src[i];

                i++;

        }

        dest[i] = 0;

        return (dest);

}


/**

 * _strdup - this will copy the string

 * @str: this will be the string which needs to be copied

 *

 * Return: variable for the copied string

 */

char *_strdup(const char *str)

{

        int length = 0;

        char *ret;


        if (str == NULL)

                return (NULL);

        while (*str++)

                length++;

        ret = malloc(sizeof(char) * (length + 1));

        if (!ret)

                return (NULL);

        for (length++; length--;)

                ret[length] = *--str;

        return (ret);

}


/**

 * _puts - An input string will be printed

 * @str: this will be the string which needs to be printed

 *

 * Return: NULL

 */

void _puts(char *str)

{

        int i = 0;


        if (!str)

                return;

        while (str[i] != '\0')

        {

                _putchar(str[i]);

                i++;

        }

}


/**

 * _putchar - This function prints the character,

 * c to the standard output

 * @c: this will be the character which needs to be printed

 *

 * Return: 1 if successful, and -1 if failed

 */

int _putchar(char c)

{

        static int i;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)

        {

                write(1, buf, i);

                i = 0;

        }

        if (c != BUF_FLUSH)

                buf[i++] = c;

        return (1);

}
