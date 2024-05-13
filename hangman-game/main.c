#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char** argv)
{

	//MY_STRING hMy_string[100] = {NULL};
	MY_STRING *hMy_string = NULL;
	hMy_string = (MY_STRING *)malloc(sizeof(MY_STRING)*100);

	for(int i = 0; i < 100; i++)
		hMy_string[i] = NULL;

	hMy_string[0] = my_string_init_c_string("COPY ME!");

	for(int i = 1; i < 100; i++)
		my_string_assignment(&hMy_string[i], hMy_string[0]);

	for(int i = 0; i < 100; i++)
		printf("%d\t%s\n", i+1, my_string_c_str(hMy_string[i]));

	for(int i = 0; i < 100; i++)
		my_string_destroy(&hMy_string[i]);

	return 0;
}
