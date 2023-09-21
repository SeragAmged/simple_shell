#include "shell.h"

/**
 * _alloc_check - checks if pointer is allocated in memory
 * @ptr: void pointer
 */
void _alloc_check(void *ptr)
{
if (ptr == NULL)
{
perror(getPWD());
}
}

/**
 * _command_exist - checks command existance
 * @ptr: pointer
 * @command: command to be executed
 * @iter_num: current program iteration
 * @status: status pointer
 * Return: 0 if command exist, else -1
 */
int _command_exist(void *ptr, char *command,
size_t iter_num, int *status)
{
char *temp;

if (ptr == NULL)
{
_print(getPWD());
_print(": ");
temp = UnsignedLong_toString(iter_num);
_print(temp);
free(temp);
_print(": ");
_print(command);
_print(": not found");
_print("\n");
*status = 127;
errno = 127;
return (-1);
}
*status = 0;
errno = 0;
return (0);
}
/**
 * _my_exit - Handle the "exit" command.
 *
 * @cmd: Command name ("exit").
 * @arg1: Argument for exit status.
 * @status: Pointer to exit status.
 * @iter_num: Unused iteration number.
 *
 * Return: 2 if @arg1 is invalid, else 0
 */
int _my_exit(char *cmd, char *arg1, int *status, size_t iter_num)
{
char *temp;
int st;

if (!_strcmp(cmd, "exit"))
{
if (arg1 == NULL)
return (1);
st = _isPositive(arg1);
if (!st)
{
_print(getPWD());
_print(": ");
temp = UnsignedLong_toString(iter_num);
_print(temp);
free(temp);
_print(": exit: Illegal number: ");
_print(arg1);
_print("\n");
*status = 2;
return (-1);
}
*status = (int) _str_To_UnsignedInt(arg1);
return (1);
}
return (0);
}
