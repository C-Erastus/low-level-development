#ifdef SHELL_H
#define SHELL_H

// Parse a given command 
char *parse_command(char *command);

// Executes the exit shell command
void execute_exit(char *command);

// Executes the change directory (cd) shell command
char *execute_cd(char * command);

// Executes the exce shell command
void execute_exec(char *command); 

#endif 