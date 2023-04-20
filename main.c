#include "shell.h"
/**
 *main - entry point for the shell program
 *Return: 0 on success
*/


int main(int argc __attribute__((unused)), char** argv) {
	char* executable_path = argv[1];
	char** args;
	int status;

	args = argv + 2;
	status = execute(executable_path, args);

	return status;
}
