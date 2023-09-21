# include "shell.h"

/**
 * am_I_delim - checks if a character is a delim
 * @c: character to be checked
 * @delim: delimiters
 * Return: 1 if character is a delimiter, 0 otherwise
 */
unsigned int am_I_delim(char c, char *delim)
{
while (*delim != '\0')
{
if (c == *delim)
return (1);
delim++;
}
return (0);
}

/**
* _str_To_UnsignedInt -converts string to unsigned integer
* @str: string to be converted
* Return: integer = the string
*/
unsigned int _str_To_UnsignedInt(const char *str)
{
unsigned int result = 0;

while (*str >= '0' && *str <= '9')
{
result = result * 10 + (*str - '0');
str++;
}

return (result);
}

/**
* _str_To_Int -converts string to signed integer
* @str: string to be converted
* Return: integer = the string
*/
unsigned int _str_To_Int(const char *str)
{
int sign = 1;

if (*str == '-')
{
sign = -1;
str++;
}

return ((int) _str_To_UnsignedInt(str) * sign);
}

/**
* _isPositive - checks if a string it self a positive number
* @str: string to be checked
* Return: 1 if str is a number, else 0
*/
int _isPositive(char *str)
{
while (*str)
{
if (*str < '0' || *str > '9')
return (0);
str++;
}
return (1);
}

/**
* _isNumber - checks if a string it self a number
* @str: string to be checked
* Return: 1 if str is a number, 0 if not
*/
int _isNumber(char *str)
{
while (*str)
{
if (*str == '-' || *str == '+')
{
str++;
continue;
}
break;
}

return (_isPositive(str));
}
