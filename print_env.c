#include "shell.h"

/**
 * exit_shell - Exits the shell program.
 */
void exit_shell(void)
{
	exit(0);
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
