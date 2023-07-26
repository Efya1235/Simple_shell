#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

extern char **environ;

#define BUFFER_SIZE 1024
#define Max_Arguments 1000


char *read_ptr();
void print_tokens(char **args);
void free_args(char **args, int arg_count);
void swap_int(int *a, int *b);
void bubble_sort(int *array, size_t size);
void remove_trailing_newline(char *inputptr);
void handle_command_path(char **args);
void handle_command_execution(char **args);
void handle_shell(void);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void handle_shell_exit(char *arg);
int _isdigit(int j);
int _strcmp(char *m1, char *m2);
char *_strcat(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
int tokenize_arguments(char *inputptr, char **args);

/**customs functions*/
char *_strdup(char *str);
int _atoi(char *s);

#endif
