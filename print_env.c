#include "shell.h"

/**
 * exit_shell - Exits the shell program.
 */
void exit_shell(void)
{
	int exit_status = atoi(args[1]);

	exit(exit_status);
}

/**
 * print_environment - Prints the environment variables.
 */
void print_environment(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
