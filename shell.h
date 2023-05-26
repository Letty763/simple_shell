#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s {
    int num;
    char *str;
    struct list_s *next;
} list_t;

void _puts(const char *str);
char *_strdup(const char *str);
void _memset(void *s, int c, size_t n);

list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

#endif /* SHELL_H */
