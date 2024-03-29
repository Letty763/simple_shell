#include "shell.h"

/**
 * main - this is a simple shell program
 * @argc: this will be the argument count
 * @args: this will be the argument count
 * Return: 0 if successful
 */
int main(int argc, char **args)
{
	aliases alias;
	int idx = 0, ret_val = 0;
	char *input = NULL, *name = args[0], *temp = NULL;

	(void) argc;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0) && argc == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (argc == 1 && _getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(ret_val);
		}
		else if (argc != 1 && _read(&input, args) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(ret_val);
		}
		temp = _strstr(input, "#");
		if (temp)
			*temp = '\0';
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			error(name, NULL, NULL, 0);
			ret_val = split_line(input, name, &alias, &idx);
		}
		free(input);
		if (argc != 1)
			return (0);
	}
}
