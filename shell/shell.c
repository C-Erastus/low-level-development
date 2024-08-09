#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "shell.h"
#include <unistd.h>

char *parse_command(char *command, int *index)
{
	printf("parse command\n");
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
 	printf("cmd: %s\n", cmd);

 	return cmd;
}

void execute_exit(char *command, int *index)
{
	printf("Doing exit command\n");
	if(command[*index+1] != '\0')
		printf("exit has no argument\n");
}

char *execute_cd(char *command, int *index)
{
	printf("doing something with cd\n");
	char *cwd, path[PATH_MAX];

	cwd = (char*)malloc(sizeof(char)*PATH_MAX);
	if(cwd == NULL){
		printf("Failed to allocated space for cwd\n");
		exit(1);
	}

	for(int i = *index+1, j = 0; command[i] != '\0'; i++, j++){
 		path[j] = command[i]; 
 		printf("Path: %s\n", path);
 		if(chdir(path) == -1){
 			fprintf(stderr, "Error number: %d\n", errno);
 			perror("Error message from perror");
 		}else{
 			if(getcwd(cwd, sizeof(cwd)) != NULL)
 				printf("%s\n", cwd); 
 			else
 				perror("getcwd() error");
 		}
 	}

 	return cwd;
}

void execute_exec(char *command, int *index)
{
	printf("do something for exec\n");

	return;

}