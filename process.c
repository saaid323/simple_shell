#include "shell.h"

/**
 * process - Process function for the shell
 */

void process(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
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
		exit(status);
	}
}

/**
 * init - Initialize and execute a command
 * @command: The command to be executed
 * @command_type: The type of the command
 */

void init(char **command, int command_type)
{
	pid_t PID;

	if (command_type == EXTERNAL_COMMAND || command_type == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(command, command_type);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(command, command_type);
}

/**
 * ctrl_c - Handle the SIGINT signal (Ctrl+C)
 * @sig: Signal number
 */
void ctrl_c(int sig)
{
	if (sig == SIGINT)
		_write("\n#cisfun$ ", STDIN_FILENO);
}

/**
 * comment - Remove comments from the input string
 * @input: Input string
 */
void comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}

/**
 * _write - Write string to a file descriptor
 * @s: Input string
 * @stream: File descriptor
 */

void _write(char *s, int stream)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		write(stream, &s[i], 1);
}
