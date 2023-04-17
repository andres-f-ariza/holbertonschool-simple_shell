#include "shell.h"

/**
 * main - entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	pid_t pid;
	int status;
	char *argv[] = {NULL};
	char *envp[] = {NULL};

	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);

		/* remove the trailing newline character */
		buffer[strcspn(buffer, "\n")] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Error: forking child process failed");
			exit(1);
		}

		if (pid == 0)
		{
			/* child process */
			if (execve(buffer, argv, envp) == -1)
			{
				perror("Error: execve failed");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			/* parent process */
			wait(&status);
		}
	}

	free(buffer);
	buffer = NULL;

	return (0);
}
