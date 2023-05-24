#include "shell.h"

/**
 * my_getenv - Gets the value of an environment variable.
 * @name: Pointer to the name of the environment variable.
 * Return: Pointer to environment variable, or NULL if not found.
 */

char *my_getenv(const char *name)
{
	extern char **environ;
	size_t name_len = my_strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}
