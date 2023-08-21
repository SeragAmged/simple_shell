#include "shell.h"
#include "string_helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/wait.h>

/**
 * penvironment - Print the current environment variables
 */
void penvironment(void)
{
    char **env = environ;
    while (*env)
    {
        _printf("%s\n", *env);
        env++;
    }
}

/**
 * tokenize_command - Tokenize a command into arguments
 * @command: The command to tokenize
 * @argv: An array to store the tokenized arguments
 *
 * Return: The number of arguments.
 */
int tokenize_command(char *command, char **argv)
{
    char *del;
    char *token;
    int argc;
    del = " ";
    token = strtok(command, del);

    argc = 0;
    while (token != NULL && argc < 10)
    {
        argv[argc++] = token;
        token = strtok(NULL, del);
    }
    argv[argc] = NULL;
    return (argc);
}

/**
 * read_command - Read a command from standard input
 *
 * Return: The read line.
 */

char *read_command(void)
{
    ssize_t i;
    char *temp;
    char buffer[BUFFER_SIZE];
    ssize_t n;
    char *line = NULL;
    size_t len = 0;

    while ((n = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        temp = realloc(line, len + n + 1);
        if (!temp)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        line = temp;

        i = 0;
        while (i < n)
        {
            line[len++] = buffer[i];
            if (buffer[i] == '\n')
            {
                line[len] = '\0';
                return (line);
            }
            i++;
        }
    }
    if (n == -1)
    {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    else if (n == 0 && len == 0)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    return (line);
}

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 */

char *_getenv(const char *name)
{
    size_t name_len;
    size_t i, j;
    if (name == NULL || environ == NULL)

        return (NULL);

    name_len = 0;
    while (name[name_len] != '\0')

        name_len++;

    i = 0;
    while (environ[i] != NULL)
    {
        j = 0;
        while (environ[i][j] != '\0' && environ[i][j] == name[j])
        {
            j++;
        }

        if (j == name_len && environ[i][j] == '=')
        {
            return (&environ[i][j + 1]);
        }

        i++;
    }

    return (NULL);
}
