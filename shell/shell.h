#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>

// Parse a given command 
char *parse_command(char *command, int *index);

// Executes the exit shell command
void execute_exit(char *command, int *index);

// Executes the change directory (cd) shell command
char *execute_cd(char *command, int *index);

// Executes the exce shell command
void execute_exec(char *command, int *index); 

bool check_path(char *path, char *cmd); 

#endif 