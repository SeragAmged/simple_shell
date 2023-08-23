#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * penvironment - Print the current environment variables
 */
void penvironment(void)
{
char **env = environ;
while (*env)
{
_printf("%s\n", *env);
env++;
}
}
/**
 * get_argc - count args
 * @argv: argv to count
 * Return: The number of arguments.
 */
int get_argc(char **argv)
{
int argc = 0;
while (argv[argc] != NULL)
{
argc++;
}
return (argc);
}
/**
 * tokenize_command - Tokenize a command into arguments
 * @command: The command to tokenize
 * Return: The number of arguments.
 */
char **tokenize_command(char *command)
{
char *del = " ";
char *token;
int argc = 0;
char **argv = NULL;
token = strtok(command, del);
while (token != NULL)
{
argv = realloc(argv, (argc + 1) * sizeof(char *));
if (!argv)
{
perror("realloc error");
exit(EXIT_FAILURE);
}
argv[argc++] = token;
token = strtok(NULL, del);
}
argv = realloc(argv, (argc + 1) * sizeof(char *));
if (!argv)
{
perror("realloc error");
exit(EXIT_FAILURE);
}
argv[argc] = NULL;

return (argv);
}
/**
 * _getenv - Get value of an environment variable
 * @name: Name of the variable
 * Return: Value of the variable, or NULL if not found/invalid input
 */
char *_getenv(const char *name)
{
size_t name_len;
size_t i, j;
if (name == NULL || environ == NULL)
return (NULL);
name_len = 0;
while (name[name_len] != '\0')
name_len++;
i = 0;
while (environ[i] != NULL)
{
j = 0;
while (environ[i][j] != '\0' && environ[i][j] == name[j])
{
j++;
}
if (j == name_len && environ[i][j] == '=')
{
return (&environ[i][j + 1]);
}
i++;
}
return (NULL);
}
/**
 * execute_child - Execute a command in the child process
 * @argv: Array of arguments for the command
 * @path: Path for command execution
 */
void execute_child(char **argv, const char *path)
{
if (_strrchr(argv[0], '/') != NULL)
{
execve(argv[0], argv, NULL);
}
else
{
char *path_copy, *del, *token;
path_copy = _strdup(path);
del = ":";
token = strtok(path_copy, del);
while (token != NULL)
{
size_t full_path_size = strlen(token) + strlen(argv[0]) + 2;
char *full_path = (char *)malloc(full_path_size);
if (!full_path)
{
perror("malloc error");
exit(EXIT_FAILURE);
}
snprintf(full_path, full_path_size, "%s/%s", token, argv[0]);
if (access(full_path, X_OK) == 0)
{
execve(full_path, argv, NULL);
}
free(full_path);
token = strtok(NULL, del);
}
perror("Command not found");
exit(EXIT_FAILURE);
}
perror("execve Error");
exit(EXIT_FAILURE);
}
