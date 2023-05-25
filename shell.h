#ifndef SHELL_H
#define SHELL_H

#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 *struct commands - a struct that hold command name and corresponding function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct commands {
  char *command_name;
  void (*func)(char **command);
} func_command;

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1
#define min(x, y) (((x) < (y)) ? (x) : (y))

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;
extern void process(void);
extern void init(char **current_command, int type_command);

void _write(char *s, int stream);
char **my_strtok(char *input_string, char *deli);
void newline(char *str);
int _strlen(char *s);
void _strcpy(char *src, char *dest);

int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strspn(char *str1, char *str2);
int _strcspn(char *str1, char *str2);
char *_strchr(char *s, char c);

char *_strtok(char *str, char *deli, char **t);
int my_atoi(char *s);
void (*_func(char *command))(char **);
char *my_getenv(char *name);
int search_path(char *command);

void execute_command(char **tokenized_path, int command);
char *check_path(char *command);
void *my_realloc(void *ptr, unsigned int old, unsigned int new_);
void ctrl_c(int sig);
void comment(char *input);

void _environ(char **tokenized_command __attribute__((unused)));
void exit_shell(char **command);

#endif
