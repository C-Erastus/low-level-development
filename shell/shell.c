#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
/* ADD THE: -lreadline compiler flag when compiling */

#define SIZE_T 64

char *parse_command(char *command);
int main(int argc, char** argv)
{
	char *buf;
	long size;
	char *_path, *command;

	size = pathconf(".", _PC_PATH_MAX);
	command = (char*)malloc(sizeof(char)*sysconf(_SC_ARG_MAX));
	buf = (char*)malloc((size_t)size);
	_path = getcwd(buf, (size_t)size);

	printf("%s~$ ", _path);

	while ((command = readline(""))){
		//printf("%s~$ ", _path);
		if(strncmp(command, "", sysconf(_SC_ARG_MAX)) != 0){
			command = parse_command(command);
			printf("The returned command: %s\n", command);
			if (strncmp(command, "exit", 64) !=0 && strncmp(command, "cd", 64) !=0 && strncmp(command, "exec", 64) !=0)
				printf("%s: Unrecognized Command\n", command);
			printf("%s~$ ", _path); 
		}
		else
			printf("%s~$ ", _path);
	}

	return 0;
}
char *parse_command(char *command)
{
	printf("parse command\n");
	char cwd[PATH_MAX], path[PATH_MAX];
 	char *cmd = (char *)malloc(sizeof(char)*64);
 	int i;
 	for(i = 0; command[i] != EOF; i++){
 		if(!isspace(command[i]))
 			cmd[i] = command[i];
 		else if (isspace(command[i]))
 			break;
 	}

 	printf("cmd: %s\n", cmd);

 	if (strncmp(cmd, "exit", 64) == 0){
 		printf("exit part\n");
 		if(command[i+1] != EOF)
 			printf("exit has no argument\n"); 
 	}else if (strncmp(cmd, "cd", SIZE_T) == 0){
 		printf("doing cd things\n");
 		for(i = i+1; command[i] != EOF; i++)
 			path[i] = command[i]; 
 		if(chdir(path) == -1){
 			fprintf(stderr, "Error number: %d\n", errno);
 			perror("Error message from perror");
 		}else{
 			if(getcwd(cwd, sizeof(cwd)) != NULL)
 				printf("%s", cwd); 
 			else
 				perror("getcwd() error");
 		}

 	}else if (strncmp(cmd, "exec", SIZE_T) == 0)
 		printf("do something for exec\n");

 	/* Add support for EXIT:
 	 * Add support for CD,
 	 * Add support  for exec
 	 */
 	return cmd; 
}