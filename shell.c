#include "shell.h"
#include "string_helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
/**
 * shell_loop - Main shell loop to read and execute commands
 */
void shell_loop(void)
{
    char *line;
    ssize_t my_len;
    size_t ref = 0;

    while (1)
    {
        _printf(PROMPT);
        fflush(stdout);
        my_len = getline(&line, &ref, stdin);
        if (my_len <= 0)
        {
        /*EOF encountered (Ctrl+D pressed)*/
        break;
        }
        /*line = read_command();*/
        /*Remove newline character if present*/
        if (line[my_len - 1] == '\n')
        {
        line[my_len - 1] = '\0';
        my_len--;
        }
        if (my_len > 0)
        /*Skip empty lines*/
        {
        if (_strcmp(line, "exit") == 0)
        {
        break;
        }
        if (_strcmp(line, "^C") == 0)
        {
        break;
        }
        else if (_strcmp(line, "env") == 0)
        {
        penvironment();
        }
        else
        {
        execute_command(line, my_len);
        }
        }

        free(line);
        line = NULL;
    }
    free(line);
}

/**
 * execute_command - Execute a command and its arguments
 * @command: The command to execute.
 */
void execute_command(char *command, size_t len)
{
    char *copy;
    size_t i;
    char *argv[ARGSIZE];
    int argc;
    char *command_name;

    copy = malloc(len);
    if (copy == NULL)
    {
        /*perror("malloc error");*/
        exit(EXIT_FAILURE);
        return;
    }
    i = 0;
    while (command[i] != '\0' && command[i] != '\n')
    {
        copy[i] = command[i];
        i++;
    }
    copy[i] = '\0';

    argc = tokenize_command(copy, argv);

    if (argc > 0)
    {
        command_name = get_command_name(argv[0]);
        if (command_name != NULL && command_exists(command_name))
        {
            execute_with_fork(argv);
        }
        else
        {
            _printf("Command not found: ");
            _printf(argv[0]);
            _printf("\n");
        }
        free(command_name);
    }

    free(copy);    
}

/**
 * execute_with_fork - Execute a command with fork and wait
 * @argv: An array of arguments for the command
 */
void execute_with_fork(char **argv)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork error:");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(argv[0], argv, NULL);
        perror("execve Error");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}

/**
 * command_exists - Check if a command exists in the PATH
 * @command: The name of the command to check
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int command_exists(const char *command)
{
    char *path_copy, *del, *token, *path;
    path = _getenv("PATH");
    if (path == NULL)
    {
        return (0);
    }

    path_copy = _strdup(path);
    del = ":";
    token = strtok(path_copy, del);

    while (token != NULL)
    {
        char full_path[1024];
        _snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (1);
        }
        token = strtok(NULL, del);
    }

    free(path_copy);
    return (0);
}

/**
 * get_command_name - Get the name of the command from its full path
 * @command_with_path: The full path of the command
 *
 * Return: The name of the command.
 */
char *get_command_name(const char *command_with_path)
{
    char *last_slash = _strrchr(command_with_path, '/');
    if (last_slash != NULL)
    {
        return (_strdup(last_slash + 1)); /*Skip the slash to get the command name*/
    }
    return (_strdup(command_with_path)); /*No path, return as is*/
}
