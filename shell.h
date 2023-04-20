#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

/**
 *libraries
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *functions
*/

char **parse_line(char *line);
void execute(char *executable_path, char **args);
char *find_executable(char* executable_name, char* path);
char *prompt(void);
char *find_path(char *command);



#endif
