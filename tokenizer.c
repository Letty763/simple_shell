#include "shell.h"


/**

 * exists_within - assesses whether character is within a delimiter

 * @c: this will be the character which needs to be checked

 * @s: this will be the delimiter

 * Return: boolean value

 */

int exists_within(char c, char *s)

{

        if (*s == '\0')

                return (c == *s);

        return (c == *s ? 1 : exists_within(c, s + 1));

}


/**

 * _strtok - this will be the string tokenizer

 * @s: this will be the delimiter

 * @delim: this will be the string

 * Return: tokens

 */

char **_strtok(char *s, char *delim)

{

        char **tokens;

        size_t j = 0, i, len = _strlen(s) + 1;

        int found = 1, k = 0;


        tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));

        *tokens = (char *)_calloc(len, sizeof(char));

        if (!*tokens)

                free(tokens);

        for (i = 0; s[i]; i++)

        {

                if (exists_within(s[i], delim))

                {

                        if (!found)

                        {

                                tokens[k++][j] = '\0';

                                tokens[k] = (char *)_calloc(len, sizeof(char));

                                if (!tokens[k])

                                        _free(tokens);

                        }

                        found = 1;

                        j = 0;

                }

                else

                {

                        tokens[k][j++] = s[i];

                        found = 0;

                }

        }

        if (found)

        {

                free(tokens[k]);

                tokens[k] = NULL;

        }

        else

                tokens[k][j] = '\0';

        return (tokens);

}


/**

 * replace_substring - this will exchange the substring

 * @str: this will be the input string

 * @old_substr: this will be the previous substring

 * @new_substr: this will be the renewed substring

 * Return: decomposition

 */

void replace_substring(char *str, char *old_substr, char *new_substr)

{

        char *ptr = NULL;

        size_t old_len = _strlen(old_substr);

        size_t new_len = _strlen(new_substr);

        size_t k = new_len, l = old_len;


        ptr = _strstr(str, old_substr);

        if (!ptr)

                return;

        do {

                ptr[k++] = ptr[l++];

        } while (ptr[l]);

        ptr[k] = '\0';

        _memcpy(ptr, new_substr, new_len);

        replace_substring(ptr + new_len, old_substr, new_substr);

}


/**

 * _atoi - this will change a string into an int

 *@s: this will be the string

 * Return: an int

 */


int _atoi(char *s)

{

        int i;

        int n = 0;


        for (i = 0; s[i] != '\0'; i++)

        {

                n *= 10;

                n += (s[i] - '0');

        }

        return (n);

}


