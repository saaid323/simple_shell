#include "shell.h"

/**
 * _environ - Print the environment variables
 * @tokenized_command: Unused parameter (for compatibility with attribute)
 */

void _environ(char **tokenized_command __attribute__((unused)))
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		_write(environ[j], STDOUT_FILENO);
		_write("\n", STDOUT_FILENO);
	}
}

/**
 * exit_shell - Exit the shell
 * @command: Command arguments
 */

void exit_shell(char **command)
{
	int n = 0, arg;

	for (; command[n] != NULL; n++)
		;
	if (n == 1)
	{
		free(command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (n == 2)
	{
		arg = my_atoi(command[1]);
		if (arg == -1)
		{
			_write(shell_name, STDERR_FILENO);
			_write(": 1: exit: Illegal number: ", STDERR_FILENO);
			_write(command[1], STDERR_FILENO);
			_write("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(command);
			free(commands);
			exit(arg);
		}
	}
}

/**
 * my_atoi - Convert a string to an integer
 * @s: Input string
 *
 * Return: Converted integer value
 */
int my_atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}
