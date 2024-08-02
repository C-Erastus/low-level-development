#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
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
			if (strncmp(command, "exit", 64) !=0 || strncmp(command, "cd", 64) !=0 || strncmp(command, "exec", 64) !=0)
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
 	char *cmd = (char *)malloc(sizeof(char)*64);

 	for(int i = 0; command[i] != EOF; i++){
 		if(!isspace(command[i]))
 			cmd[i] = command[i];
 		else
 			if (strncmp(cmd, "eixt", SIZE_T) == 0)
 				//do things for exit
 			else if (strncmp(cmd, "cd", SIZE_T) == 0)
 				// do things for cd 
 			else if (strncmp(cmd, "exec", SIZE_t) == 0)
 				// do things for exec
 			else
 				// do nothing
 	}

 	/* Add support for EXIT:
 	 * Add support for CD,
 	 * Add support  for exec
 	 */
 	return cmd; 
}