#include "shell.h"

/**
 * _alias - responsible for aliases
 * @argc: this will be the argument count
 * @args: this will be the argument array
 * @name: the filename for the program
 * @alias: alias node
 * @idx: this will be the amount of alias’
 * @split: break of a line
 * @line: this is a line
 * Return: 1 if successful
 */
int _alias(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	char **al;
	int i, j;

	(void) name;
	(void) split;
	(void) line;
	if (argc == 1)
	{
		for (i = 0; *idx && i < *idx; i++)
		{
			print_string(1, alias[i].name), print_string(1, "='");
			print_string(1, alias[i].value), print_string(1, "'\n");
		}
	}
	for (i = 1; i < argc; i++)
	{
		al = _strtok(args[i], "'="), j = _getalias(alias, al[0], *idx);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				print_string(1, alias[j].name), print_string(1, "='");
				print_string(1, alias[j].value), print_string(1, "'\n");
			} else
				error(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, al[1]);
		}
		else
		{
			alias[*idx].name = malloc(_strlen(al[0]) + 1);
			alias[*idx].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[*idx].name, al[0]);
			_strcpy(alias[*idx].value, al[1]), (*idx)++;
		}
	}
	return (1);
}
