#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"

void clear_key_board_buffer();

int main(int argc, char** argv)
{
	FILE *fp;
	GENERIC_VECTOR My_vector[30]; 
	GENERIC_VECTOR game_vector;
	MY_STRING hMy_string = my_string_init_default();
	MY_STRING *hString; 
	MY_STRING Used_letters = my_string_init_default();
	MY_STRING word = my_string_init_default();
	MY_STRING new_key = my_string_init_default();
	int i;

	int word_length = 0, number_of_guesses = 0;
	char running_total, guess;

	fp = fopen("dictionary.txt", "r");
	if(fp == NULL){
		printf("Failed to open the dictionary\n");
	}

	for(i = 0; i < 30; i++){
		My_vector[i] = generic_vector_init_default(
				my_string_assignment,
				my_string_destroy
		);
	}
	/*game_vector = generic_vector_init_default(
			my_string_assignment,
			my_string_destroy
		);*/

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

	/********* THE GAME STARTS HERE **************/
	do{
		printf("What length word do you want to play with? ");
		scanf("%d", &word_length);
	}while(word_length < 1 || word_length > 30);

	printf("How many guesses would you like to have? ");
	scanf("%d", &number_of_guesses);
	clear_key_board_buffer();

	printf("Do you wish to have a running total of the number of words remaining in the world list? (y/n): " );
	scanf("%c", &running_total);
	clear_key_board_buffer();

	for(i = 0; i < word_length; i++){
		my_string_push_back(word, '-');
	}

	game_vector = My_vector[word_length];
	printf("\nYou have %d guesses left\n", number_of_guesses);
	printf("Used letters: %s\n", my_string_c_str(Used_letters));
	printf("word: %s\n", my_string_c_str(word));

	/*do{
		printf("Enter guess: ");
		scanf("%c",&guess);
		clear_key_board_buffer();

		for(i = generic_vector_get_size(game_vector); i > 0; i--){
			printf("gvector\n");
			hString = generic_vector_at(game_vector, i);
			get_word_key_value(word, new_key, *hString, guess);
			printf("get key\n");
			printf("%s: %s\n", my_string_c_str(generic_vector_at(game_vector, i)), my_string_c_str(new_key));

		}


	}while(number_of_guesses > 0);*/
	





	/****************************************************************************/

	for(int i = 0; i < 30; i++){
		printf("%d\n", generic_vector_get_size(My_vector[i]));
	}

	/*hString = generic_vector_at(My_vector[5], 1);
	printf("The vector string: %s\n", my_string_c_str(*hString));
	printf("after printing\n");*/

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

	my_string_destroy(&word);
	my_string_destroy(&Used_letters);
	my_string_destroy(&hMy_string);

	return 0;
}

void clear_key_board_buffer()
{
	char c; 
	do{
		scanf("%c", &c);
	}while(c!='\n');
}