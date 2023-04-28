#include "shell.h"
int main(int ac __attribute__((unused)), char** av)
{
	int status = 0;
	char *buffer = NULL;
	size_t bufsize = 500;
	ssize_t nread = 0;
	char **args = NULL;

	/**
	   int i;*/

	while (1)
	{
		/**
		   i = 0;*/

		if (isatty(STDIN_FILENO))

			buffer = malloc(500);
		write(STDOUT_FILENO, "($)", 3);

		if (strcmp(buffer, "exit\n") == 0)
			break;

	   
		args = parse_line(buffer, av[0]);

		if(args)
			status = execute(args);
		else
			status = 32512;
	}

	free(buffer);
	buffer = NULL;
	exit(WEXITSTATUS(status));
}
