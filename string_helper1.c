#include "shell.h"

/**
 * _args_builder - turns given string to array of strings used as args
 * @str: string given
 * @argc: pointer to its size
 * @delim: delimiter that explodes
 * Return: pointer to arguments made
 */
char **_args_builder(char *str, size_t *argc, char *delim)
{
size_t n = 0;
char **argv, *token;

argv = malloc(sizeof(char *) * 256);
token = strtok(str, delim);
while (token)
{
argv[n++] = token;
token = strtok(NULL, delim);
}
argv[n] = NULL;
*argc = n;
if (n == 0)
{
freeBuffs(str, argv);
argv = NULL;
}
return (argv);
}

/**
 * _strdup - duplicates a string with n characters
 * @str: string given
 * Return: pointer to the new string
 */
char *_strdup(const char *str)
{
size_t length, i;
char *new_str;

if (!str)
return (NULL);
length = _strlen(str);
new_str = malloc((length + 1) * sizeof(char));
_alloc_check(new_str);
for (i = 0; str[i] != '\0'; i++)
new_str[i] = str[i];
new_str[i] = '\0';
return (new_str);
}

/**
 * _strlen - get len of a string
 * @str: given string
 * Return: size_t of str
 */
size_t _strlen(const char *str)
{
size_t i;

if (str == NULL)
return (0);

for (i = 0; str[i] != '\0'; i++)
;

return (i);
}

/**
 * _strcat - concatenates strings
 * @destination: 1st part and the destination
 * @source: 2nd part of the string
 * Return: pointer to the destination
 */
char *_strcat(char *destination, char *source)
{
int i, j;
char *str = malloc(_strlen(destination) + _strlen(source) + 1);

for (i = 0; destination[i] != '\0'; i++)
str[i] = destination[i];
for (j = 0; source[j] != '\0'; j++)
str[i + j] = source[j];
free(destination);
str[i + j] = '\0';
return (str);
}

/**
 * _startsWith - checks if str starts with target
 * @str: string we search into
 * @target: the substring to find
 * Return: pointer excluding the needle
 */
char *_startsWith(char *str, const char *target)
{
int i = 0;

while (target[i] != '\0')
{
if (target[i] != str[i])
return (NULL);
i++;
}
return (str + i);
}
