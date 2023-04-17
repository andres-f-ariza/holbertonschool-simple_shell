#include "shell.h"
/**
 *read_input(): This function reads input from the user and returns a
 *string representing the command to be executed.
 */
#define BUFFER_SIZE 1024
char *read_input(void) {
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	int c, position = 0;

	if (!buffer) {
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();

		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}

		position++;

		if (position >= BUFFER_SIZE) {
			fprintf(stderr, "Command too long\n");
			exit(EXIT_FAILURE);
		}
	}
}
