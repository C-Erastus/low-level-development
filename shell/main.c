#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>

#include "shell.h"
/* ADD THE: -lreadline compiler flag when compiling */

#define SIZE_T 64

int main(int argc, char** argv)
{
	char *buf, cmd[SIZE_T], *temp;
	long size;
	char *_path, *command;
	int index, pid, status;
	char *env;

	size = pathconf(".", _PC_PATH_MAX);
	command = (char*)malloc(sizeof(char)*sysconf(_SC_ARG_MAX));
	buf = (char*)malloc((size_t)size);
	_path = getcwd(buf, (size_t)size);

	printf("%s~$ ", _path);

	while ((command = readline(""))){
		//printf("%s~$ ", _path);
		if(strncmp(command, "", sysconf(_SC_ARG_MAX)) != 0){
			strncpy(cmd, parse_command(command, &index), SIZE_T);

			//printf("The returned command: %s\n", cmd);

			if(cmd[0] == '.' || cmd[0] == '/'){
				index = 0; 
				pid = fork();
				if(pid == 0){
					/* child world */
					execute_exec(command, &index); 
				}else{
					/* Parent world*/
					waitpid(pid, &status, 0);
				}
			}
			else if (strncmp(cmd, "exit", 64) == 0)
				execute_exit(command, &index);
			else if (strncmp(cmd, "cd", 64) == 0){
				temp = execute_cd(command, &index);
				strncpy(_path, temp, SIZE_T);
				free(temp);
				//printf("Done freeing up\n");
			}else if (strncmp(cmd, "exec", 64) == 0)
				execute_exec(command, &index);
			else{
				check_path(getenv("PATH"), cmd)

				printf("The env: %s\n", env);
				printf("%s: Unrecognized Command\n", cmd);
			}
			printf("%s~$ ", _path); 
		}
		else{
			printf("%s~$ ", _path);
			free(command);
		}
	}

	return 0;
}
/* https://kdlp.underground.software/course/spring2023/assignments/A1.html*/