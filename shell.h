#ifndef SHELL_H
#define SHELL_H

#define PROMPT "$ "
#define LINE_DELIMITER " \n\r\t"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

char *getPWD(void);
void signal_helper(int sig_id);
void _end_of_file(ssize_t line_size, char **argv, char *buffer, int status);
int _env(char *arg, char *buffer, char **argv);

int _Command_right(char *cmd);
char *_find_Path(char *path_par, char *cmd);
int _execute_command(char *arg0, char **argv);

void _printEnv(void);
char *_getenv(const char *key, size_t len);

char **_args_builder(char *str, unsigned long *argc, char *delim);
char *_strdup(const char *str);
size_t _strlen(const char *str);
char *_strcat(char *destination, char *source);
char *_startsWith(char *str, const char *needle);

void _putchar(char c);
void _print(char *s);
char *UnsignedLong_toString(unsigned long x);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);

unsigned int am_I_delim(char c, char *delim);
unsigned int _str_To_UnsignedInt(const char *str);
unsigned int _str_To_Int(const char *str);
int _isPositive(char *str);
int _isNumber(char *str);



char **_realloc(char **ptr, size_t old_size, size_t new_size);
void _free_pointer(void *ptr);
void _mass_free(char **ptr);
void freeBuffs(char *buffer, char **argv);

void _alloc_check(void *ptr);

int _command_exist(void *ptr, char *command,
							   size_t iter_num, int *status);

int _my_exit(char *cmd, char *arg1, int *status, size_t iter_num);

#endif
