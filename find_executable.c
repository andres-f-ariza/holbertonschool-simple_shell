#include "shell.h"

/**
 *find_executable - Find the executable file for a given command in the PATH
 *@command: the command to find the executable for
 *Return: a pointer to the full path of the executable if found, otherwise NULL
*/

#define MAX_PATH_LEN 1024

char* find_executable(char* executable) {
	char* path = getenv("PATH");
	char* path_copy = strdup(path);
	char* path_dir;
	char* executable_path = NULL;

	while ((path_dir = strtok(path_copy, ":")) != NULL) {
		strcpy(path_copy, path_dir);

		char path_buffer[MAX_PATH_LEN];
		snprintf(path_buffer, MAX_PATH_LEN, "%s/%s", path_dir, executable);

		if (access(path_buffer, X_OK) == 0) {
			executable_path = strdup(path_buffer);
			break;
		}
	}

	free(path_copy);
	return executable_path;
}
