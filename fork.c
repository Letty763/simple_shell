#include "shell.h"

/**
 * _fork - this will fork the procedure
 * @name: the filename for the program
 * @arr: this will be the argument array
 * Return: success if successful
 */
int _fork(char *name, char **arr)
{
  pid_t pid;
  int status, success = 1;
  char *path = NULL;

  path = is_valid(arr[0], name, arr);
  if (path != NULL)
    {
      pid = fork();
      if (pid == 0)
	{
	  success = executer(arr, name, path);
	  exit(0);
	}
      else
	waitpid(pid, &status, 0);
      free(path);
    }
  else
    {
      error(name, arr, NULL, 1);
      success = 0;
    }
  return (success);
}
