#include "shell.h"

/**
 * cmd_selector - assess for any builtin functions
 * @cmd: the name of the command
 * @args: this will be the argument array
 * @name: the filename for the program
 * @alias: alias node
 * @idx: this will be the amount of alias’
 * @split: break of a line
 * @line: this is a line
 * Return: -1 if  successful
 */
int cmd_selector(const char *cmd, char **args,
		char *name, aliases *alias, int *idx, char **split, char *line)
{
	cmd_executer executers[] = {
		{"exit", exit_function},
		{"cd", change_dir},
		{"setenv", export},
		{"unsetenv", unset},
		{"env", env},
		{"alias", _alias},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exe_func != NULL && _strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exe_func != NULL)
		return (executers[j].exe_func(args_count(args), args,
					name, alias, idx, split, line));
	return (-1);
}

/**
 * args_count - calculates the number of arguments
 * @args: this will be the argument array
 * Return: argc if successful
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
