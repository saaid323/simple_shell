#include "shell.h"

/**
 * search_path - Search for a command in the PATH environment variable
 * @command: The command to search for
 *
 * Return: The type of the command
 */

int search_path(char *command)
{
	int i;
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_command[i] != NULL; i++)
	{
		if (_strcmp(command, internal_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}
	return (INVALID_COMMAND);
}

/**
 * execute_command - Execute a command
 * @tokenized_path: The tokenized command
 * @command: The type of the command
 */
void execute_command(char **tokenized_path, int command)
{
	void (*func)(char **command);

	if (command == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_path[0], tokenized_path, NULL) == -1)
		{
			perror(my_getenv("PWD"));
			exit(2);
		}
	}
	if (command == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_path[0]), tokenized_path, NULL) == -1)
		{
			perror(my_getenv("PWD"));
			exit(2);
		}
	}
	if (command == INTERNAL_COMMAND)
	{
		func = _func(tokenized_path[0]);
		func(tokenized_path);
	}
	if (command == INVALID_COMMAND)
	{
		_write(shell_name, STDERR_FILENO);
		_write(": 1: ", STDERR_FILENO);
		_write(tokenized_path[0], STDERR_FILENO);
		_write(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - Check if a command exists in the directories listed in the PATH
 * @command: The command to check
 *
 * Return: The path of the command if found, NULL otherwise
 */
char *check_path(char *command)
{
	char **array = NULL;
	char *temp, *temp2, *path_1;
	char *path = my_getenv("PATH");
	int j;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_1 = malloc(sizeof(*path_1) * (_strlen(path) + 1));
	_strcpy(path, path_1);
	array = my_strtok(path_1, ":");
	for (j = 0; array[j] != NULL; j++)
	{
		temp2 = _strcat(array[j], "/");
		temp = _strcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(array);
			free(path_1);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_1);
	free(array);
	return (NULL);
}

/**
 * _func - Return a function pointer corresponding to a command
 * @command: The command name
 *
 * Return: A function pointer corresponding to the command
 */
void (*_func(char *command))(char **)
{
	int i;

	func_command co[] = {{"env", _environ}, {"exit", exit_shell}};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, co[i].command_name) == 0)
			return (co[i].func);
	}
	return (NULL);
}

/**
 * my_getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable if found, NULL otherwise
 */
char *my_getenv(char *name)
{
	char **env;
	char *pair;
	char *name_2;

	for (env = environ; *env != NULL; env++)
	{
		for (pair = *env, name_2 = name; *pair == *name_2; pair++, name_2++)
		{
			if (*pair == '=')
				break;
		}
		if ((*pair == '=') && (*name_2 == '\0'))
			return (pair + 1);
	}
	return (NULL);
}
