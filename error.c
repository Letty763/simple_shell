#include "shell.h"

/**
 * error2 - this prints error messages
 * @args: this will be the argument array
 * @path: this will be the path taken
 * @n: this will be the error pointer
 */
void error2(char **args, char *path, int n)
{
	char semi = ';';

	if (n == 5)
		print_string(2, "unsetenv to VARIABLE VALUE");
	else if (n == 6)
	{
		print_string(2, "this is environment variable ");
		print_string(2, args[1]);
		print_string(2, " unable to find");
	}
	else if (n == 7)
		print_string(2, "Syntax error: \"&\" ");
	else if (n == 8)
		print_string(2, "Syntax error: \"|\" ");
	else if (n == 9)
	{
		print_string(2, "Syntax error: \"");
		write(STDERR_FILENO, &semi, 1);
		write(STDERR_FILENO, &semi, 1);
		print_string(2, "\" not expected");
	}
	else if (n == 10)
	{
		print_string(2, "the alias: ");
		print_string(2, path);
		print_string(2, " unable to find");
	}
}

/**
 * error - this will print error messages
 * @name: the filename for the program
 * @args: this will be the argument array
 * @path: this will be the path taken
 * @n: this will be the error pointer
 * Return: associated value
 */
int error(char *name, char **args, char *path, int n)
{
	static unsigned int i;

	if (!n)
	{
		i++;
		return (0);
	}
	if (n == 11)
	{
		print_string(2, name);
		print_string(2, " 0: unable to open ");
		print_string(2, args[1]);
		write(STDERR_FILENO, "\n", 1);
		return (EXIT_FAILURE);
	}
	print_string(2, name);
	print_string(2, ": ");
	to_string(2, i);
	print_string(2, ": ");
	if (n == 1)
	{
		print_string(2, args[0]);
		print_string(2, ": unable to find");
	}
	else if (n == 2)
	{
		print_string(2, "exit: not a legitimate number: ");
		print_string(2, args[1]);
	}
	else if (n == 3)
	{
		print_string(2, "cd: unable to change directory to ");
		print_string(2, path);
	}
	else if (n == 4)
		print_string(2, "setenv to VARIABLE VALUE");
	else
		error2(args, path, n);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
