#include "shell.h"

/**
 * _getline - scans the input from the standard input
 * @line: this is the string which needs to be scanned
 * Return: length of string
 */
int _getline(char **line)
{
	int i;

	*line = _calloc(10240, sizeof(char));
	i = read(STDIN_FILENO, *line, 10240);
	(*line)[i] = '\0';
	return (i);
}

/**
 * _read - scan the input from a file
 * @line: this is the string which needs to be scanned
 * @args: this will be the argument count
 * Return: an integer
 */
int _read(char **line, char **args)
{
	ssize_t i;
	int ret;

	ret = open(args[1], O_RDONLY);
	if (ret == -1)
	{
		error(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*line = _calloc(10240, sizeof(char));
	i = read(ret, *line, 10240);
	close(ret);
	while (**line == ' ' || **line == '\t')
		(*line)++, i--;
	(*line)[i] = '\0';
	return (i);
}
