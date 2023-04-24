#include "shell.h"

void print_args(char **args) {
	int i = 0;
	while (args[i] != NULL) {
		printf("args[%d]: %s\n", i, args[i]);
		i++;
	}
}
