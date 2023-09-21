#include "shell.h"

/**
 * _printEnv - prints environment variables
 */
void _printEnv(void)
{
int i;

for (i = 0; environ[i] != NULL; i++)
{
_print(environ[i]);
_print("\n");
}
}

/**
* _getenv - fetch environment variables
* @key: object name
* @len: len of name
* Return: value of key if exist, or null
*/
char *_getenv(const char *key, size_t len)
{
size_t i, j;

if ((key == NULL) || (environ == NULL))
return (NULL);

for (i = 0; environ[i] != NULL; i++)
{
for (j = 0; (j < len) && (environ[i][j] != '\0')
&& (environ[i][j] == key[j]); j++)
;

if ((environ[i][j] == '=') && (j == len))
return (&environ[i][j + 1]);
}

return (NULL);
}
