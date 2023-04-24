#include "shell.h"

/**
 * create_argv - creates a new array of strings for the execve syscall
 * @path: path to the executable file
 * @args: command-line arguments
 *
 * Return: Pointer to the newly created array of strings
 */
char **create_argv(char *path, char **args)
{
	int arg_count = 0;
	char **argv = NULL;

	/* count the number of arguments */
	while (args[arg_count] != NULL)
		arg_count++;

	/* allocate memory for the argv array */
	argv = malloc(sizeof(char *) * (arg_count + 2));
	if (!argv)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	/* set the first element to the path */
	argv[0] = path;

	/* copy the arguments into the array */
	for (int i = 0; i < arg_count; i++)
	{
		argv[i + 1] = args[i];
	}

	/* set the last element to NULL */
	argv[arg_count + 1] = NULL;

	return argv;
}
