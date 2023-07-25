#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>

#define MAX_INPUT_LENGTH 4096
#define BUFFER_SIZE 1024
#define AND 1
#define DELIMITER " \t\r\n\a"
#define OR 2
extern char **environ;

int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
void _prompt(void);
void print_env(void);
int status(char **buffer);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _chdir(char **arguments);
int print_args(char **args);
int execute_env(char **args);
int run_builtins(char **args);
int pipe_builtin(char **cmd1, char **cmd2);
char **split_input(char *input);
char *read_input(void);
int process(char **args);
int main(int argc, char **argv);
int get_input(char *filename);

#endif
