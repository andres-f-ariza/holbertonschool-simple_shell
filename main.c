#include "shell.h"
/**
 *main - entry point for the shell program
 *Return: 0 on success
*/

int main(int argc, char** argv) {
	char* executable_path = find_executable(argv[1]);

	if (executable_path == NULL) {
		printf("Executable '%s' not found in PATH\n", argv[1]);
		exit(1);
	}

	char** args = argv + 1;
	int status = execute(executable_path, args);

	free(executable_path);
	return status;
}
