#include "shell.h"

/**
 *find_executable - Find the executable file for a given command in the PATH
 *@command: the command to find the executable for
 *Return: a pointer to the full path of the executable if found, otherwise NULL
*/
#define MAX_PATH_LEN 1024

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_dir = strtok(path_copy, ":");

	while (path_dir != NULL) {
		char path_buffer[MAX_PATH_LEN];
		snprintf(path_buffer, MAX_PATH_LEN, "%s/%s", path_dir, command);
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
