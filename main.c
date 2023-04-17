#include "shell.h"

/**
 * main - Main function for shell
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: Always 0
 */

int main(void) {
	char *command;
	int status;

	while (1) {
		printf("$ ");
		command = read_input();

		pid_t pid = fork();

		if (pid == -1) {
			perror("Error forking");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
				execute_command(command);
			exit(EXIT_SUCCESS);
		} else {
		      			wait(&status);
		}

		free(command);
	}

	return 0;
}
