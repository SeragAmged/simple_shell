#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
extern char **environ;

#define PROMPT "$ "
#define BUFFER_SIZE 1024
#define ARGSIZE 513

int custom_exec(char *command, char **args);

char *_getenv(const char *name);

void penvironment(void);

int command_exists(const char *command);

char *get_command_name(const char *command_with_path);

void execute_command(char *command, size_t len);

int tokenize_command(char *command, char **argv);

void execute_child(char **argv, const char* path);

void execute_with_fork(char **argv);

void shell_loop(void);

#endif /* SHELL_H */
