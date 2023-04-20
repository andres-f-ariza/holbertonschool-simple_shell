#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
*/
int MAX_PATH_LEN = 1024;

char *find_executable(char* executable_name, char* path) {
	char* path_copy;
	char* path_dir;
	char path_buffer[MAX_PATH_LEN];
	// copy path string to avoid modifying original
	path_copy = strdup(path);
	// iterate over path directories
	path_dir = strtok(path_copy, ":");
	while (path_dir != NULL) {
		// construct full path to executable
		snprintf(path_buffer, sizeof(path_buffer), "%s/%s", path_dir, executable_name);
		// check if file exists and is executable
		if (access(path_buffer, X_OK) == 0) {
			return strdup(path_buffer);
		}
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
