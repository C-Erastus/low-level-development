#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
/* ADD THE: -lreadline compiler flag when compiling */
int main(int argc, char** argv)
{
	char *buf;
	long size;
	char *_path;
	size = pathconf(".", _PC_PATH_MAX);

	buf = (char*)malloc((size_t)size);
	_path = getcwd(buf, (size_t)size);

	printf("%s~$ ", _path);

	while (readline("")){
		printf("%s~$ ", _path);
	}

	return 0;
}