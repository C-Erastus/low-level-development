#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "shell.h"
#include <unistd.h>

char *parse_command(char *command, int *index)
{
	//printf("parse command\n");
 	char *cmd = (char *)malloc(sizeof(char)*64);
 	int i;

 	for(i = 0; command[i] !='\0'; i++){
 		if(!isspace(command[i]))
 			cmd[i] = command[i];
 		else if (isspace(command[i])){
 			*index = i;
 			break;
 		}
 	}
 	*index = i;
 	//printf("cmd: %s\n", cmd);

 	return cmd;
}

void execute_exit(char *command, int *index)
{
	//printf("Doing exit command\n");
	if(command[*index+1] != '\0')
		printf("exit has no argument\n");
}

char *execute_cd(char *command, int *index)
{
	//printf("doing something with cd\n");
	char *cwd, *path;

	path = (char*)malloc(sizeof(char)*PATH_MAX);
	if(path == NULL){
		printf("Failed to allocated space for path\n");
		exit(1);
	}
	cwd = (char*)malloc(sizeof(char)*PATH_MAX);
	if(cwd == NULL){
		printf("Failed to allocated space for cwd\n");
		exit(1);
	}

	for(int i = *index+1, j = 0; command[i] != '\0'; i++, j++)
 		path[j] = command[i]; 

 	//printf("Path: %s\n", path);
 	if(chdir(path) == -1){
 		fprintf(stderr, "Error number: %d\n", errno);
 		perror("Error message from perror");
 	}
 	if(getcwd(cwd, PATH_MAX) == NULL)
 			perror("getcwd() error");
 	//printf("cwd: %s\n", cwd);
 	free(path);
 	return cwd;
}

void execute_exec(char *command, int *index)
{
	char **_argv;
	printf("do something for exec\n");
	_argv = (char**)malloc(sizeof(char**)*PATH_MAX);
	int space_count = 0; 

	for (int i = (*index)+1; command[i] != '\0'; i++){
		if(command[i] == ' ')
			space_count++;
	}
	printf("space count: %d\n", space_count);
	*index++;
	new_command = command[index];
	fgets(path, new_command); // test by printing the path

	for(int i = 0; i < PATH_MAX; i++){
		_argv[i] = (char*)malloc(sizeof(char*)PATH_MAX);
		fgets(_argv[i], new_command);
	}
	/* Use this version */
	while(fgets(_argv[i]), new_command){
		;
	}

	if(execv(path, _argv) == -1){
		perror("execv failed");
	}

	return;

}