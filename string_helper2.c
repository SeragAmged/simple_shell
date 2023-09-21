#include "shell.h"

/**
 * _putchar - Print character
 * @c: character
 */
void _putchar(char c)
{
write(STDOUT_FILENO, &c, 1);
}

/**
 * _print - prints a string
 * @s: string to print
 */
void _print(char *s)
{
int i;

if (s == NULL)
return;

for (i = 0; s[i] != '\0'; i++)
_putchar(s[i]);
}

/**
 * UnsignedLong_toString - converts long to string
 * @x: long number to be converted
 * Return: string = the number
 */
char *UnsignedLong_toString(unsigned long x)
{
char *c;
unsigned int i, d = 0;
unsigned long temp;

if (x == 0)
return ((char *) '0');

temp = x;
while (temp > 0)
{
temp /= 10;
d++;
}

c = malloc(sizeof(char) * (d + 1));
if (!c)
{
free(c);
return (0);
}

for (i = 0; i < d; i++)
{
c[d - i - 1] = (x % 10) + '0';
x /= 10;
}

c[d] = '\0';
return (c);
}

/**
 * _strcmp - finds if two strings are different
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if both are equal, 1 if s1 is greater, -1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
while ((*s1 != '\0') && (*s2 != '\0'))
{
if (*s1 < *s2)
return (-1);
else if (*s1 > *s2)
return (1);
s1++;
s2++;
}

if (*s1 == '\0' && *s2 == '\0')
return (0);
else if (*s1 == '\0')
return (-1);
else
return (1);
}

/**
 * _strtok - string tokenizer
 * @string: string to tokenize
 * @delim: separator to explode
 * Return: next token of a given string
 */
char *_strtok(char *string, char *delim)
{
static char *index;
int i;

if (string != NULL)
index = string;
else
string = index;
if (*index == '\0')
return (NULL);
while (*index != '\0')
{
for (i = 0; delim[i] != '\0'; i++)
{
if (*index == delim[i])
{
if (index == string)
{
index++;
string++;
}
else
{
*index = '\0';
break;
}
}
}
if (*index == '\0')
{
index++;
return (string);
}
index++;
}
return (string);
}
