#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * shell_loop - Main shell loop to read and execute commands
 */
void shell_loop(void)
{
char *line = NULL;
ssize_t my_len;
size_t ref = 0;
unsigned long iterman = 0;

while (++iterman)
{
if (isatty(STDIN_FILENO))
{
_printf(PROMPT);
}
fflush(stdout);
my_len = getline(&line, &ref, stdin);
if (my_len <= 0)
{
if (isatty(STDIN_FILENO))
_printf("\n");
exit(EXIT_SUCCESS);
}
if (line[my_len - 1] == '\n')
{
line[my_len - 1] = '\0';
my_len--;
}
execute_command(line, my_len, iterman);
}
free(line);
line = NULL;
}
/**
 * execute_command - Execute a command and its arguments
 * @command: The command to execute.
 * @len: length of command.
 */
void execute_command(char *command, size_t len, unsigned long iterman)
{
char **argv;
int argc, exit_code, status = 0;
size_t i;
char *command_name, *tempiterman;
char *copy = malloc(len);
if (copy == NULL)
{
perror("malloc error");
exit(EXIT_FAILURE);
}
i = 0;
while (command[i] != '\0' && command[i] != '\n')
{
copy[i] = command[i];
i++;
}
copy[i] = '\0';
argv = tokenize_command(copy), argc = get_argc(argv);
if (argc > 0)
{
command_name = get_command_name(argv[0]);
if (_strcmp_trim(argv[0], "exit") == 0)
{
free_argv(argv), free(copy), exit_code = WEXITSTATUS(status), exit(exit_code);
}
else if (_strcmp_trim(argv[0], "env") == 0)
penvironment();
else if (command_name != NULL && command_exists(command_name))
execute_with_fork(argv, &exit_code, &status);
else
{
tempiterman = converter(iterman);
if (!tempiterman)
return;
_printf("%s: %s: %s: not found\n", _getenv("_"), tempiterman, argv[0]);
free(tempiterman);
}
free(command_name);
}
free_argv(argv), free(copy);
}
/**
 * execute_with_fork - Execute a command with fork and wait
 * @argv: An array of arguments for the command
 */
void execute_with_fork(char **argv, int *exit_code, int *status)
{

pid_t pid = fork();
if (pid == -1)
{
perror("Fork error:");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char *path = _getenv("PATH");
if (path == NULL)
{
perror("No PATH in environment");
exit(EXIT_FAILURE);
}
execute_child(argv, path);
}
else
{
wait(status);
if (WIFEXITED(*status))
{
*exit_code = WEXITSTATUS(*status);
}
}
}
/**
 * command_exists - Check if a command exists in the PATH
 * @command: The name of the command to check
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int command_exists(const char *command)
{
char *path_copy, *del, *token, *path;
path = _getenv("PATH");
if (path == NULL)
{
return (0);
}
path_copy = _strdup(path);
del = ":";
token = strtok(path_copy, del);
while (token != NULL)
{
char full_path[1024];
_snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (1);
}
token = strtok(NULL, del);
}
free(path_copy);
return (0);
}
/**
 * get_command_name - Get the name of the command from its full path
 * @command_with_path: The full path of the command
 *
 * Return: The name of the command.
 */
char *get_command_name(const char *command_with_path)
{
char *last_slash = _strrchr(command_with_path, '/');
if (last_slash != NULL)
{
return (_strdup(last_slash + 1)); /*Skip the slash to get the command name*/
}
return (_strdup(command_with_path)); /*No path, return as is*/
}
