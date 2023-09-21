#include "shell.h"

/**
 * main - shell manager
 * Return: Always 0
 */
int main(void)
{
size_t n = 0, argc = 0, iter_man = 0;
ssize_t line_size;
char *buffer = NULL, **argv = NULL;
void *temp = NULL;
int status = 0, temp2;

signal(SIGINT, signal_helper);
while (++iter_man)
{
buffer = NULL;
argv = NULL;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, PROMPT, 2);
fflush(stdout);
line_size = getline(&buffer, &n, stdin);
_end_of_file(line_size, NULL, buffer, status);
if (line_size == 1)
continue;
argv = _args_builder(buffer, &argc, LINE_DELIMITER);
if (argv == NULL)
continue;
if (_env(argv[0], buffer, argv))
continue;
temp2 = _my_exit(argv[0], (argv[1] ? argv[1] : 0), &status, iter_man);
if (temp2 == -1)
continue;
if (temp2 == 1)
_end_of_file(0, argv, buffer, status);
temp = _find_Path(_strdup(_getenv("PATH", 4)), argv[0]);
if (!_command_exist(temp, argv[0], iter_man, &status))
status = _execute_command(temp, argv);
if (temp != argv[0])
_free_pointer(temp);
freeBuffs(buffer, argv);
}
return (0);
}

/**
 * getPWD - get path of current directory
 * Return: string of the path
 */
char *getPWD(void)
{
return (_getenv("_", 1));
}

/**
 * signal_helper - handles an int signal
 * @signum: signal identifier
 *
 * Return: void
 */
void signal_helper(int signum)
{
if (signum == SIGINT)
{
_print("\n");
_print(PROMPT);
}
else if (signum == SIGHUP)
_print("\n");
}

/**
 * _end_of_file - handles end of file
 * @line_size: line size
 * @argv: argv pointer
 * @buffer: buffer pointer
 * @status: last status
 */
void _end_of_file(ssize_t line_size, char **argv, char *buffer, int status)
{
if (line_size == 1)
{
free(buffer);
return;
}
if (line_size < 1)
{
if (line_size == -1 && isatty(STDIN_FILENO))
{
_print("\n");
}
freeBuffs(buffer, argv);
exit(status);
}
}
/**
 * _env - Execute the "env" command.
 *
 * @arg: The first argument (command name).
 * @buffer: A buffer for storing output.
 * @argv: An array of arguments (unused in this function).
 *
 * This function checks if the provided argument is "env" and if so,
 * it calls the _printEnv function to display the environment variables.
 * It then frees memory allocated for the buffer and argv.
 *
 * Return: 1 if the argument is "env," 0 otherwise.
 */
int _env(char *arg, char *buffer, char **argv)
{
if (!_strcmp(arg, "env"))
{
_printEnv();
freeBuffs(buffer, argv);
return (1);
}
return (0);
}
