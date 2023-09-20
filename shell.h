#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
extern char **environ;

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024
#define ARGSIZE 513

char *_getenv(const char *name);

void penvironment(void);

int command_exists(const char *command);

char *get_command_name(const char *command_with_path);

void execute_command(char *command, size_t len, unsigned long iterman);

char **tokenize_command(char *command);

int get_argc(char **argv);

void execute_child(char **argv, const char *path);

void execute_with_fork(char **argv, int *exit_code, int *status);

void shell_loop(void);

#endif /* SHELL_H */
