#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = NULL;
	char *token = NULL;
//	struct stat st;
	int filestatus;
	char *auxpath;

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
 *check if tokens[0] eixst in PATH
 */

//		filestatus = stat(tokens[0],&st);

		if(getenv("PATH") != NULL)
			auxpath = find_path(tokens[0]);
		/**
		 *if tokens[0] is found in PATH, update tokens[0] with full path
		 */
		if(auxpath != NULL && tokens[0][0]!='.'&& strcmp(tokens[0],"env") != 0)
		{
			tokens[0] = auxpath;
		}
		if (auxpath != NULL)
			free(auxpath);
		/**
		 *if file exists or command is exit or env.
		 */
//		if(filestatus == 0 || strcmp(tokens[0],"exit") == 0 || strcmp(tokens[0],"env") == 0)
			return (NULL);
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
/**
 *Mark the end of the array with a NULL pointer
 */
	tokens[position] = NULL;
	return (tokens);
}
