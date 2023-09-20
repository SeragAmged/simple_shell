#include "string_helper.h"
#include <stdlib.h>

/**
 * converter - converts unsigned number to string
 * @num: unsigned number to be converted
* Return: string representation of the number
*/
char *converter(unsigned long num)
{
char *c;
unsigned int i, d;

d = number_counter(num);
c = malloc(sizeof(char) * (d + 1));
if (!c)
return (0);
if (num == 0)
c[0] = '0';
else
{
for (i = 0; i < d; i++)
{
c[d - i - 1] = (num % 10) + '0';
num /= 10;
}
}
c[d] = '\0';
return (c);
}
/**
 * number_counter - counts digits of a number
 * @num: number to look for
 * Return: n of digits
 */
unsigned int number_counter(unsigned long num)
{
unsigned int d = 0;
while (num > 0)
{
num /= 10;
d++;
}
return (d < 1 ? 1 : d);
}
