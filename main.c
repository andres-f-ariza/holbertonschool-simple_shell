#include "shell.h"

/**
 *main - entry point for the shell program
 *Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char **args = NULL;

	while (1)
	{
		printf("$ ");

		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				putchar('\n');
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("readline");
				exit(EXIT_FAILURE);
			}
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (*buffer == '\0')
			continue;

		args = parse_line(buffer);

		execute(args);

		free(args);
	}

	free(buffer);
	return (0);

}
