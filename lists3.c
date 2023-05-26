#include "shell.h"

/**
 * add_node - The list is started with a new node
 * @head: The address of the head node
 * @str: this is a str field of a node
 * @num: this is the index of the node that will be used
 *
 * Return: this will be the dimension of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return (NULL);

    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);

    memset((void *)new_head, 0, sizeof(list_t));

    new_head->num = num;

    if (str)
    {
        new_head->str = strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }

    new_head->next = *head;
    *head = new_head;

    return (new_head);
}

/**
 * add_node_end - the end of the lists is ended with a new node
 * @head: The address of the head node
 * @str: this is a str field of a node
 * @num: this is the index of the node that will be used
 *
 * Return: this will be the dimension of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);

    node = *head;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    memset((void *)new_node, 0, sizeof(list_t));

    new_node->num = num;

    if (str)
    {
        new_node->str = strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    if (node)
    {
        while (node->next)
            node = node->next;

        node->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    return (new_node);
}

/**
 * print_list_str - List_t linked lists are printed only,
 * with the str element
 * @h: this will be the pointer for the initial node
 *
 * Return: this will be the dimension of list
 */
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * delete_node_at_index - will discard of a node at given index
 * @head: The address of the head node
 * @index: index of the node which needs to be discarded
 *
 * Return: 1 if successful, 0 if failed
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    if (!index)
    {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1);
    }

    node = *head;

    while (node)
    {
        if (i == index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }

        i++;
        prev_node = node;
        node = node->next;
    }

    return (0);
}

/**
 * free_list - the nodes of the list will be released
 * @head_ptr: The address of the head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
    list_t *node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;

    head = *head_ptr;
    node = head;

    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }

    *head_ptr = NULL;
}
