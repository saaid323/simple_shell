#include "shell.h"
/**
 * main - Entry point of the shell program.
 * Return: Always returns 0.
 */

int main(void)
{
	char *line = NULL, *args[MAX_ARGS], *token;
	size_t len = 0;
	int arg_count;

	while (1)
	{
		prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}

		line[my_strcspn(line, "\n")] = '\0';
		arg_count = 0;
		token = my_strtok(line, " ");

		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = token;
			token = my_strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		if (arg_count > 0 && my_strcmp(args[0], "exit") == 0)
		{
			int exit_status = atoi(args[1]);

			exit(exit_status);
		} else
			exit(0);
		if (arg_count > 0 && my_strcmp(args[0], "env") == 0)
			print_environment();
		else
			execute_command(args);
	}
	free(line);
	return (0);
}
