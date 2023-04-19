#include "shell.h"
/**
 *main - entry point for the shell program
 *Return: 0 on success
*/

#define MAX_INPUT_LEN 1024

int main(void)
{
	char *input;
	char **args;
	char *executable_path;
	int status;

	while (1)
	{
		input = prompt();
		if (input == NULL)
		{
			break;
		}

		args = parse_line(input);
		if (args[0] == NULL)
		{
			free(args);
			free(input);
			continue;
		}

		executable_path = find_executable(args[0]);
		if (executable_path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			free(args);
			free(input);
			continue;
		}

		status = execute(executable_path, args);
		free(executable_path);
		free(args);
		free(input);

		if (status != 0)
		{
			fprintf(stderr, "An error occurred during command execution\n");
		}
	}

	return (0);
}
