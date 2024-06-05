#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_string.h"
#include "generic_vector.h"
#include "associative_array.h"

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
	bool test; 
	char *temp, replay = ' ';

	struct node *root = NULL; 

	int word_length = 0, number_of_guesses = 0;
	char guess;

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
	game_vector = generic_vector_init_default(
			my_string_assignment,
			my_string_destroy
		);

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
		do{
			printf("What length word do you want to play with? ");
			scanf("%d", &word_length);
		}while(word_length < 1 || word_length > 30);

		printf("How many guesses would you like to have? ");
		scanf("%d", &number_of_guesses);
		clear_key_board_buffer();

		/*printf("Do you wish to have a running total of the number of words remaining in the world list? (y/n): " );
		scanf("%c", &running_total);
		clear_key_board_buffer();*/

		for(i = 0; i < word_length; i++){
			my_string_push_back(word, '-');
		}

		game_vector = My_vector[word_length+2];
		printf("\nYou have %d guesses left\n", number_of_guesses);
		printf("Used letters: %s\n", my_string_c_str(Used_letters));
		//printf("word: %s\n", my_string_c_str(word));

		do{
			if (root == NULL)
				printf("word: %s\n", my_string_c_str(word));
			else
				printf("word: %s\n", my_string_c_str(root->key));
			root = NULL;

			printf("Enter guess: ");
			scanf("%c",&guess);
			clear_key_board_buffer();

			for(i = generic_vector_get_size(game_vector)-1; i > 0; i--){
				hString = generic_vector_at(game_vector, i);
				get_word_key_value(word, new_key, *hString, guess);
				//printf("%s: %s", my_string_c_str(*hString), my_string_c_str(new_key));

				root = insert_node(root, new_key, *hString);
				//printf("%s\n", my_string_c_str(new_key));
			}
			print_preorder(root);
			printf("\n");

			//game_vector = get_common_word_family(root);
			root = get_common_word_family(root);
			game_vector = root->ar_vector; 

			my_string_push_back(Used_letters, guess);
			my_string_push_back(Used_letters, ' ');

			temp = my_string_c_str(root->key);
			for(i = 0; i < my_string_get_size(root->key); i++){
				if(guess == temp[i])
					test = true; 
			}
			if(!test)
				printf("\nI'm sorry, there were no %c's in the word\n", guess);
			printf("The computer has %d possibilities remaining\n", root->key_count);
			printf("Used Letters: %s\n", my_string_c_str(Used_letters));
			number_of_guesses--;

		}while(number_of_guesses > 0);

		/*if(!test)
			printf("\nI'm sorry, there were no %c's in the word\n", guess);
		printf("The computer has %d possibilities remaining\n", root->key_count);*/
		printf("The word I was thinking of was: %s\n", my_string_c_str(*generic_vector_at(game_vector,0)));

		for(i = 0; i < my_string_get_size(Used_letters); i++)
			my_string_pop_back(Used_letters);
		for(i = 0; i < my_string_get_size(word); i++)
			my_string_pop_back(word);

		printf("Would you like to play again? (y/n): ");
		scanf("%c", &replay);
		clear_key_board_buffer();

		printf("the answer: %c\n", replay);
	}while(replay == 'y');

	/****************************************************************************/

	/*for(int i = 0; i < 30; i++){
		printf("%d\n", generic_vector_get_size(My_vector[i]));
	}*/

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
	generic_vector_destroy(&game_vector);
	my_string_destroy(&word);
	my_string_destroy(&Used_letters);
	my_string_destroy(&hMy_string);
	//my_string_destroy(&(*hString));
	my_string_destroy(&new_key);

	return 0;
}

void clear_key_board_buffer()
{
	char c; 
	do{
		scanf("%c", &c);
	}while(c!='\n');
}