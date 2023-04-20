#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
*/

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	if (path == NULL) {
		return NULL;
	}
	char *path_copy = strdup(path);
	if (path_copy == NULL) {
		perror("strdup");
		return NULL;
	}
	char *path_dir = strtok(path_copy, ":");
	while (path_dir != NULL) {
		char path_buffer[MAX_PATH_LEN];
		if (snprintf(path_buffer, MAX_PATH_LEN, "%s/%s", path_dir, command) >= MAX_PATH_LEN) {
			perror("snprintf");
			free(path_copy);
			return NULL;
		}
		if (access(path_buffer, X_OK) == 0) {
			char *result = strdup(path_buffer);
			free(path_copy);
			return result;
		}
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
