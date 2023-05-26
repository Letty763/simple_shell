#include "shell.h"


/**

 * is_cmd - An executable command can be,

 * determined by determining if a file is executable

 * @info: this will be the info structure

 * @path: this will be the path to the specific file

 *

 * Return: 1 if it is true, and 0 if it is false

 */

int is_cmd(info_t *info, char *path)

{

        struct stat st;


        (void)info;

        if (!path || stat(path, &st))

                return (0);


        if (st.st_mode & S_IFREG)

        {

                return (1);

        }

        return (0);

}


/**

 * dup_chars - this will copy the characters

 * @pathstr: this will be the path string

 * @start: this will be the initial index

 * @stop: this will be the ending index

 *

 * Return: variable for a fresh buffer

 */

char *dup_chars(char *pathstr, int start, int stop)

{

        static char buf[1024];

        int i = 0, k = 0;


        for (k = 0, i = start; i < stop; i++)

                if (pathstr[i] != ':')

                        buf[k++] = pathstr[i];

        buf[k] = 0;

        return (buf);

}


/**

 * find_path - A path to this command,

 * can be found in the path string

 * @info: this will be the structure of the index

 * @pathstr: this will be the path string

 * @cmd: this will be the command to be located

 *

 * Return: will return full path of the command,

 * if it is found or NULL if not found

 */

char *find_path(info_t *info, char *pathstr, char *cmd)

{

        int i = 0, curr_pos = 0;

        char *path;


        if (!pathstr)

                return (NULL);

        if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))

        {

                if (is_cmd(info, cmd))

                        return (cmd);

        }

        while (1)

        {

                if (!pathstr[i] || pathstr[i] == ':')

                {

                        path = dup_chars(pathstr, curr_pos, i);

                        if (!*path)

                                _strcat(path, cmd);

                        else

                        {

                                _strcat(path, "/");

                                _strcat(path, cmd);

                        }

                        if (is_cmd(info, path))

                                return (path);

                        if (!pathstr[i])

                                break;

                        curr_pos = i;

                }

                i++;

        }

        return (NULL);

}
