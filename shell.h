#ifndef SHELL_H
#define SHELL_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_ARGS 80

char *my_strcpy(char *dest, char *src);
void execute_command(char** arguments);
void prompt();
int my_strcmp(char *s1, char *s2);
ssize_t my_write(int fd, const void *buf, size_t count);
char *my_strcat(char *dest, char *src);
int my_strlen(const char *s);
size_t my_strcspn(const char *str, const char *delim);
char *my_strpbrk(const char *str, const char *delim);
char *my_strtok(char *str, const char *delim);
char *my_getenv(const char *name);
char *search_path(char *command);
void execute_command(char** arguments);
void exit_shell();
void print_environment();



#endif
