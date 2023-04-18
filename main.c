#include "shell.h"
/**
 *main - entry point for the shell program
 *Return: 0 on success
*/
int main(void)
{
	char *buffer = NULL;
	char **args = NULL;

	while (1) {
		buffer = prompt();
		if (!buffer)
			break;
		args = parse_line(buffer);
		execute(args);
		free(buffer);
		free(args);
	}

	return (0);
}
