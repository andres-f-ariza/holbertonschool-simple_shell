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
#include <sys/stat.h>
#include <errno.h>

/**
 *functions
 */
char *prompt(void);
char **parse_line(char *line, char *exec_name);
int execute(char **args);
char *find_path(char *file);
void builtin_env(void);

#endif

/**
 *macros
 */

#define ISATTYOUT \
	do {\
	if (isatty(0) == 0)\
		break;\
	} while (0)

#define ISATTYPROMPT(PROMPT, LEN) \
	do {\
	if (isatty(0) == 1)\
		write(STDOUT_FILENO, (PROMPT), (LEN));\
	} while (0)
