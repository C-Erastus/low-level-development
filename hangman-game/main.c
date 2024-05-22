#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"

int main(int argc, char** argv)
{
	FILE *fp;
	GENERIC_VECTOR My_vector[30]; 
	MY_STRING hMy_string = my_string_init_default();
	MY_STRING *hString; 
	int i;
	fp = fopen("simple.txt", "r");
	if(fp == NULL){
		printf("Failed to open the dictionary\n");
	}

	for(i = 0; i < 30; i++){
		My_vector[i] = generic_vector_init_default(
				my_string_assignment,
				my_string_destroy
		);
	}

	while(my_string_extraction(hMy_string, fp)){
		printf("%s\n", my_string_c_str(hMy_string));
		i = my_string_get_size(hMy_string);
		generic_vector_push_back(My_vector[i], hMy_string);
		printf("one down\n");
	}

	hString = generic_vector_at(My_vector[5], 1);
	printf("The vector string: %s\n", my_string_c_str(*hString));
	printf("after printing\n");

	/*MY_STRING hMy_string[100] = {NULL};

	for(int i = 0; i < 100; i++)
		hMy_string[i] = NULL;

	hMy_string[0] = my_string_init_c_string("COPY ME!");
	printf("The NULL terminator: %d\n", my_string_c_str(hMy_string[0])[8]);

	for(int i = 1; i < 100; i++)
		my_string_assignment(&hMy_string[i], hMy_string[0]);

	for(int i = 0; i < 100; i++)
		printf("%d\t%s\n", i+1, my_string_c_str(hMy_string[i]));

	for(int i = 0; i < 100; i++)
		my_string_destroy(&hMy_string[i]);*/

	fclose(fp);
	for(i = 0; i < 30; i++)
		generic_vector_destroy(&My_vector[i]);

	return 0;
}
