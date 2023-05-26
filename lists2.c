#include "shell.h"


/**

 * list_len - A link list's length is determined by this parameter

 * @h: the initial nodes variable

 *

 * Return: this will be the dimensions of list

 */

size_t list_len(const list_t *h)

{

        size_t i = 0;


        while (h)

        {

                h = h->next;

                i++;

        }

        return (i);

}


/**

 * list_to_strings - The list's strings are returned as an array

 * @head: the initial nodes variable

 *

 * Return: an array of strings

 */

char **list_to_strings(list_t *head)

{

        list_t *node = head;

        size_t i = list_len(head), j;

        char **strs;

        char *str;


        if (!head || !i)

                return (NULL);

        strs = malloc(sizeof(char *) * (i + 1));

        if (!strs)

                return (NULL);

        for (i = 0; node; node = node->next, i++)

        {

                str = malloc(_strlen(node->str) + 1);

                if (!str)

                {

                        for (j = 0; j < i; j++)

                                free(strs[j]);

                        free(strs);

                        return (NULL);

                }


                str = _strcpy(str, node->str);

                strs[i] = str;

        }

        strs[i] = NULL;

        return (strs);

}



/**

 * print_list - The list_t linked list is printed with all its elements

 * @h: the initial nodes variable

 *

 * Return: the dimensions of the list

 */

size_t print_list(const list_t *h)

{

        size_t i = 0;


        while (h)

        {

                _puts(convert_number(h->num, 10, 0));

                _putchar(':');

                _putchar(' ');

                _puts(h->str ? h->str : "(nil)");

                _puts("\n");

                h = h->next;

                i++;

        }

        return (i);

}


/**

 * node_starts_with - Prefix-starting nodes are returned

 * @node: Variable for the head of the list

 * @prefix: string which needs to be matched

 * @c: following character from the prefix,

 * which needs to be matched

 *

 * Return: node which is matched or NULL

 */

list_t *node_starts_with(list_t *node, char *prefix, char c)

{

        char *p = NULL;


        while (node)

        {

                p = starts_with(node->str, prefix);

                if (p && ((c == -1) || (*p == c)))

                        return (node);

                node = node->next;

        }

        return (NULL);

}


/**

 * get_node_index - index of the node is fetched

 * @head: nodes heads variable

 * @node: the nodes variable

 *

 * Return: the nodes index or -1

 */

ssize_t get_node_index(list_t *head, list_t *node)

{

        size_t i = 0;


        while (head)

        {

                if (head == node)

                        return (i);

                head = head->next;

                i++;

        }

        return (-1);

}


main.c


#include "shell.h"


/**

 * main - this is the access point

 * @ac: this is the arg tally

 * @av: this is the arg angle

 *

 * Return: 0 on success, 1 on error

 */

int main(int ac, char **av)

{

        info_t info[] = { INFO_INIT };

        int fd = 2;


        asm ("mov %1, %0\n\t"

                        "add $3, %0"

                        : "=r" (fd)

                        : "r" (fd));


        if (ac == 2)

        {

                fd = open(av[1], O_RDONLY);

                if (fd == -1)

                {

                        if (errno == EACCES)

                                exit(126);

                        if (errno == ENOENT)

                        {

                                _eputs(av[0]);

                                _eputs(": 0: Can't open ");

                                _eputs(av[1]);

                                _eputchar('\n');

                                _eputchar(BUF_FLUSH);

                                exit(127);

                        }

                        return (EXIT_FAILURE);

                }

                info->readfd = fd;

        }

        populate_env_list(info);

        read_history(info);

        hsh(info, av);

        return (EXIT_SUCCESS);

}
