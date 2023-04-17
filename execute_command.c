#include "shell.h"

/**
 *execute_command(): This function takes a command string as input and
 *uses execve() to execute the command.
 */

void execute_command(char *command) {
	char *args[] = {command, NULL};

	if (execve(command, args, environ) == -1) {
		perror("Error executing command");
	}
}
