#ifndef STRING_H
#define STRING_H
#include <stddef.h>

int _printf(const char *format, ...);

int _strcmp(const char *s1, const char *s2);

int _strcmp_trim(const char *s1, const char *s2);

int _snprintf(char *str, size_t size, const char *format, ...);

char *_strdup(const char *s);

char *_strrchr(const char *str, int c);

size_t _strlen(const char *str);

void free_argv(char **argv);

#endif /* STRING_H */
