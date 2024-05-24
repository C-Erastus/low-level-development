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

	fp = fopen("dictionary.txt", "r");
	/*fp = fopen("simple.txt", "r");*/
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
		/*my_string_insertion(hMy_string, stdout);
		printf("\n");*/
		if(my_string_get_size(hMy_string) < 30)
			if(!generic_vector_push_back(My_vector[my_string_get_size(hMy_string)], (Item)hMy_string)){
				printf("Failed to push string back\n"); 
				my_string_insertion(hMy_string, fp);
				exit(1);
			}
	
	}

	for(int i = 0; i < 30; i++){
		printf("%d\n", generic_vector_get_size(My_vector[i]));
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
	
	my_string_destroy(&hMy_string);

	return 0;
}
