#include "shell.h"

/**
 * _getenv - obtains variables of environment
 * @var: this will be the name of the variable
 * Return: a string or NULL
 */
char *_getenv(char *var)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(var, environ[i], _strlen(var)))
		{
			temp = _strstr(environ[i], "=");
			temp++;
			return (temp);
		}
	}
	return (NULL);
}
/**
 * _getalias - obtains the alias’
 * @alias: alias node
 * @var: this will be the name of the variable
 * @idx: this will be the amount of alias’
 * Return: a string or -1
 */
int _getalias(aliases *alias, char *var, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!_strcmp(var, alias[i].name))
			return (i);
	}
	return (-1);
}
