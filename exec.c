#include "shell.h"

/**
 * search_path - Searches for the full path of a command in
 * the PATH environment variable.
 * @command: Pointer to the command to search for.
 * Return: Pointer to the full path of the command, or NULL if not found.
 */
char *search_path(char *command)
{
	char *path = my_getenv("PATH");
	char *dir = my_strtok(path, ":");

	while (dir != NULL)
	{
		size_t dir_len = my_strlen(dir);
		size_t command_len = my_strlen(command);
		char *full_path = malloc(dir_len + 1 + command_len + 1);

		my_strcpy(full_path, dir);
		if (full_path[dir_len - 1] != '/')
		{
			my_strcat(full_path, "/");
		}
		my_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		dir = my_strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * execute_command - Executes a command with the given arguments.
 * @arguments: Null-terminated array of arguments, including the
 * command as the first argument.
 */
void execute_command(char **arguments)
{
	int status;
	char *error;
	pid_t pid;
	char *full_path;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return;
	}
	if (pid == 0)
	{
		if (arguments[0][0] != '/')
		{
			full_path = search_path(arguments[0]);
			if (full_path == NULL)
			{
				error = "./shell: No such file or directory\n";
				my_write(STDOUT_FILENO, error, my_strlen(error));
				exit(1);
			}
			arguments[0] = full_path;
		}
		execv(arguments[0], arguments);
		error = "./shell: No such file or directory\n";
		my_write(STDOUT_FILENO, error, my_strlen(error));
		exit(1);
	}
	waitpid(pid, &status, 0);
}

/**
 * my_strtok - Breaks a string into a sequence of tokens.
 * @str: Pointer to the input string to be tokenized.
 * @delim: Pointer to the string of delimiter characters.
 * Return: Pointer to the next token, or NULL if there are no more tokens.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start;
	char *token_end;

	if (str != NULL)
	{
		next_token = str;
	}
	if (next_token == NULL)
	{
		return (NULL);
	}

	token_start = next_token;
	token_end = my_strpbrk(next_token, delim);
	if (token_end != NULL)
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}
	return (token_start);
}

