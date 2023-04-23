#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	/**
	 *conditional checking whether the tokens pointer is null or not.
	 */

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
/**
 *conditional checking if the array of tokens is bigger than the predetermined
 *size
 */
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
return (tokens);
}
