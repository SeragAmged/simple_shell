#include "string_helper.h"
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 * @...: The list of additional arguments based on the format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
int written;
va_list args;
size_t format_len, i, str_len;
va_start(args, format);
written = 0;
format_len = 0;
while (format[format_len] != '\0')
{
format_len++;
}
i = 0;
while (i < format_len)
{
if (format[i] != '%')
{
write(STDOUT_FILENO, &format[i], 1);
written++;
}
else if (format[i + 1] == 's')
{
char *str = va_arg(args, char *);
str_len = 0;
while (str[str_len] != '\0')
str_len++;
write(STDOUT_FILENO, str, str_len);
written += str_len;
i++; /*Skip the 's'*/
}
else
{
write(STDOUT_FILENO, &format[i], 1);
written++;
}
i++;
}
va_end(args);
return (written);
}
/**
 * _strlen - Get the length of a string
 * @str: The input string
 *
 * Return: The number of characters in the string.
 */
size_t _strlen(const char *str)
{
size_t len = 0;
while (str[len] != '\0')
{
len++;
}
return (len);
}
/**
 * _strrchr - Locate the last occurrence of a character in a string
 * @str: The input string
 * @c: The character to search for
 *
 * Return: A pointer to the last occurrence of the character.
 */
char *_strrchr(const char *str, int c)
{
char *last = NULL;
while (*str != '\0')
{
if (*str == c)
{
last = (char *)str;
}
str++;
}
if (c == '\0')
{
return ((char *)str);
}
return (last);
}

