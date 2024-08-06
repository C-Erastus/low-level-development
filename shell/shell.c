#include <stdio.h>
#include "shell.h"

char *parse_command(char *command)
{
	int j;
	printf("parse command\n");
	char cwd[PATH_MAX], path[PATH_MAX];
 	char *cmd = (char *)malloc(sizeof(char)*64);
 	int i;

 	for(i = 0; command[i] !='0'; i++){
 		if(!isspace(command[i]))
 			cmd[i] = command[i];
 		else if (isspace(command[i]))
 			break;
 	}

 	printf("cmd: %s\n", cmd);

 	return cmd;
}

char *execute_cd(char *command)
{
	char cwd[PATH_MAX], path[PATH_MAX];
	
	for(i = i+1, j = 0; command[i] != '\0'; i++, j++)
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