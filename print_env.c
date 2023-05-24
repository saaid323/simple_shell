#include "shell.h"

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
