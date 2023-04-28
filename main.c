#include "shell.h"

int main(int ac __attribute__((unused)), char** av)
{
	int status = 0;
	size_t bufsize = 500;
	char **args = NULL;
	ssize_t nread = 0;
	char *buffer;

	/**
	   int i;*/

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "($)", 3);

		buffer = malloc(500);
		nread = getline(&buffer,&bufsize, stdin);

		/*nread will return -1 when getline encounters and EOF condition or it encounters an error while reading input*/

		if (strcmp(buffer, "exit\n") == 0 || nread == -1)
			break;

		if (nread == 1)
		{
			free(buffer);
			continue;
		}
		args = parse_line(buffer, av[0]);

		if(args && args[0])
		{
			status = execute(args);
			if (access(buffer, F_OK) == -1)
				free(args[0]);
			free(args);
		}
		else if (!args)
			status = 32512;
		else
		{
			free(buffer);
			free(args);
			continue;
		}
		free(buffer);
	}

	free(buffer);
	buffer = NULL;
	exit(WEXITSTATUS(status));
}
