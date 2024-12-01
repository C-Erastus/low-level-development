#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "shell.h"
#include <unistd.h>
#include <string.h>

/*Function "parse_command": parse the input command */
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

/* Function "execute_exit": exits the shell  */
void execute_exit(char *command, int *index)
{
	printf("Doing exit command\n");
	if(command[*index+1] != '\0')
		printf("exit has no argument\n");
	exit(1);
}

/* Function "execute_exit": executs the 'cd' command */
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
	char **args, *path, *token, *new_command;
	int i = 0;

	printf("do something for exec\n");

	path = (char*)malloc(sizeof(char)*PATH_MAX);
	if(path == NULL){
		printf("Failed to allocat space for path\n"); 
		exit(1);
	}
	args = (char**)malloc(sizeof(char**)*PATH_MAX);
	if(args == NULL){
		printf("Failed to allocate space for path\n");
		exit(1);
	}

	new_command = &command[*index];
	token = strtok(new_command, " ");
	strncpy(path, token, PATH_MAX); 
	//printf("%s\n", path);
	while((token = strtok(NULL, " ")) != NULL){
		//token = strtok(NULL, " "); 
		args[i] = (char*)malloc(sizeof(char)*PATH_MAX);
		if(args[i] == NULL){
			printf("Failed to allocate sapce for arg[%d]\n", i);
			exit(1);
		}
		strncpy(args[i], token, PATH_MAX);
		i++; 
	}
	printf("end of while loop\n");
	if(execv(path, args) == -1){
		perror("execv failed");
		printf("The path in exec: %s\n", path);
		fprintf(stderr, "Error number: %d\n", errno);
	}

}

/* what is this function doing? *?
bool check_path(char *path, char *cmd)
{
	char dir[1000000],;
	for(int i = 0, j = 0; path[i] != '\0'; i++, j++){
		if(path[i] != ':')
			dir[j] = path[i];
		else{ 
			file = fopen(dir, "r");
			if(fgets(buf, sizeof(buf), file) != NULL){
				if(strncmp(buf, command, PATH_MAX) == 0)
					return true; 
			}
		}
		j = 0;
		set dir = {\0};
	}
	return false; 
}*/