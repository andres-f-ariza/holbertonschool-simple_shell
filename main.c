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
		/**
		   i = 0;*/
		buffer = malloc(500);
		nread=getline(&buffer,&bufsize, stdin);

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "($)", 3);
/*nread will return -1 when getline encounters and EOF condition or it encounters an error while reading input*/

		if (strcmp(buffer, "exit\n") == 0 || nread == -1)
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
