#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/wait.h>

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
 * tokenize_command - Tokenize a command into arguments
 * @command: The command to tokenize
 * @argv: An array to store the tokenized arguments
 *
 * Return: The number of arguments.
 */
int tokenize_command(char *command, char **argv)
{
char *del;
char *token;
int argc;
del = " ";
token = strtok(command, del);
argc = 0;
while (token != NULL && argc < 10)
{
argv[argc++] = token;
token = strtok(NULL, del);
}
argv[argc] = NULL;
return (argc);
}
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
