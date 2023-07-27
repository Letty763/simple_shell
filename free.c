#include "shell.h"
/**
 * _free - this will release an array of strings
 * @arr: this will be the argument array
 */
void _free(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
/**
 * _calloc - this will assign an arrays memory using malloc
 * @nmemb: the amount of members
 * @size: this will be the dimensions
 * Return: a index or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		p[i] = 0;
	return (p);
}
