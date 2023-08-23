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
 * _strdup - Duplicate a string
 * @s: The source string
 *
 * Return: A pointer to the new duplicate string, or NULL on failure.
 */
char *_strdup(const char *s)
{
size_t len = 0;
char *new_str;
while (s[len] != '\0')
{
len++;
}
new_str = malloc(len + 1);
if (new_str != NULL)
{
size_t i = 0;
while (s[i] != '\0')
{
new_str[i] = s[i];
i++;
}
new_str[i] = '\0';
}
return (new_str);
}
/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if strings are equal, <0 if s1<s2, >0 if s1>s2.
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2 || (*s2 == ' ' && *s1 == '\0'))
{
return (0);
}
else if (*s1 < *s2)
{
return (-1);
}
else
{
return (1);
}
}
/**
 * _snprintf - Write formatted output to a string with limited size
 * @str: The destination buffer
 * @size: The size of the buffer
 * @format: The format string
 * @...: The list of additional arguments based on the format string
 *
 * Return: The number of characters written (excluding the null byte).
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
size_t index, written;
va_list args;
index = 0;
written = 0;
va_start(args, format);
while (format[index] != '\0' && index < size - 1)
{
if (format[index] != '%')
str[written++] = format[index++];
else if (format[index + 1] == 's')
{
char *s = va_arg(args, char *);
size_t len = 0;
while (s[len] != '\0')
{
if (written + len < size - 1)
str[written++] = s[len];
else
break;
len++;
}
index += 2;
}
else
str[written++] = format[index++];
}
if (written < size)
str[written] = '\0';
else if (size > 0)
str[size - 1] = '\0';
va_end(args);
return (written);
}
/**
 * _strcmp_trim - Compare two strings trimed
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if strings are equal, <0 if s1<s2, >0 if s1>s2.
 */
int _strcmp_trim(const char *s1, const char *s2)
{
const char *end_s2 = s2 + _strlen(s2) - 1;
while (*s1 && (*s1 == ' ' || *s1 == '\t'))
{
s1++;
}
while (end_s2 >= s2 && (*end_s2 == ' ' || *end_s2 == '\t'))
{
end_s2--;
}
end_s2++;

if (*end_s2 == '\n')
{
end_s2--;
}
while (*s1 != '\0' && s2 != end_s2 && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2)
{
return (0);
}
else if (*s1 < *s2)
{
return (-1);
}
else
{
return (1);
}
}
