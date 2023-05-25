#include "shell.h"

char **commands = NULL;
char *line = NULL;
char *shell_name = NULL;
int status = 0;

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Return: Always 0 on success
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c);
	shell_name = argv[0];
	while (1)
	{
		process();
		_write("#cisfun$ ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		newline(line);
		comment(line);
		commands = my_strtok(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = my_strtok(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = search_path(current_command[0]);
			init(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
}

/**
 * my_strtok - Tokenize a string into an array
 * @input_string: Input string to be tokenized
 * @deli: Delimiter string
 * Return: Double pointer to an array of tokens
 */

char **my_strtok(char *input_string, char *deli)
{
	int n = 0;
	char **a = NULL;
	char *token = NULL;
	char *b = NULL;

	token = _strtok(input_string, deli, &b);
	while (token != NULL)
	{
		a = my_realloc(a, sizeof(*a) * n, sizeof(*a) * (n + 1));
		a[n] = token;
		token = _strtok(NULL, deli, &b);
		n++;
	}
	a = my_realloc(a, sizeof(*a) * n, sizeof(*a) * (n + 1));
	a[n] = NULL;
	return (a);
}
