#include "shell.h"

/**
 * _Command_right - checks if command exists
 * @cmd_path: argument
 * Return: 1 if command exists, else 0
 */
int _Command_right(char *cmd_path)
{
struct stat st;

if (!cmd_path || (stat(cmd_path, &st) != 0))
return (0);

/*if (st.st_mode & S_IFREG)*/
/*return (1);*/

return (0);
}

/**
* _find_Path - finds the correct path
* @path_par: string array of all paths
* @cmd: keyword
* Return: path of the command, else null
*/
char *_find_Path(char *path_par, char *cmd)
{
char *path;
char *result = NULL, *temp;

if (cmd == NULL)
return (NULL);
if ((_strlen(cmd) > 1) &&
(_startsWith(cmd, "/") || _startsWith(cmd, "./")))
{
_free_pointer(path_par);
return (_Command_right(cmd) ? cmd : NULL);
}
path = _strtok(path_par, ":");
while (path != NULL)
{
temp = _strdup(path);
temp = _strcat(temp, "/");
temp = _strcat(temp, cmd);
if (_Command_right(temp))
{
result = temp;
break;
}
_free_pointer(temp);
path = _strtok(NULL, ":");
}
_free_pointer(path_par);
return (result);
}

/**
* _execute - executes command if possible
* @argv: string args
* @arg0: command
* Return: status
*/
int _execute_command(char *arg0, char **argv)
{
int pid, status;

pid = fork();
if (pid < 0)
{
perror("Fork error");
return (errno);
}
else if (pid == 0)
{
execve(arg0, argv, environ);
perror(arg0);
status = errno;
exit(1);
}
else
{
wait(&status);
if (WIFEXITED(status))
status = WEXITSTATUS(status);
return (status);
}
}
