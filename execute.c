#include "shell.h"

/**
 * execute - function that executes a given command
 * @args: array of arguments passed with the command
 * Return: void
 */

void execute(char *executable_path, char **args)
{
	pid_t pid;
	int status;
	if (args[0] == NULL)
	{
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(executable_path, args, NULL) == -1)
		{
			perror("execute");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
