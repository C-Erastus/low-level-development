#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"

struct my_string{	
	int size; /*representing the numbe rof characters the string currently holds */
	int capacity; /* an integer, capacity, representing the number of characters the string CAN hold*/
	char *data; /* Holds the dynamic array of characters representing a given string; */ 
};

MY_STRING my_string_init_default(void)
{
	struct my_string *My_string = (struct my_string *)malloc(sizeof(struct my_string));
	if(My_string != NULL){
		My_string->size = 0;
		My_string->capacity = 7;

		My_string->data = (char *)malloc(sizeof(char) * My_string->capacity);
		if(My_string->data == NULL){
			printf("failed to allocate space for the My_string data");
			exit(1);
		}
		return My_string;
	}
	else
		return NULL; 
} 

MY_STRING my_string_init_c_string(const char *c_string)
{
	int size = 0;	
	struct my_string *My_string;

	for(; c_string[size] != '\0'; size++);
	My_string = (struct my_string *)malloc(sizeof(struct my_string));
	if(My_string != NULL){
		My_string->size = size;
		My_string->capacity = size+1;

		My_string->data = (char *)malloc(sizeof(char)*My_string->capacity);
		if(My_string->data != NULL){
			for(int i = 0; i < My_string->size; i++){
				My_string->data[i] = c_string[i];
			}
				/* NULL terminate the string */
				My_string->data[size] = '\0';
		} /*end inner if */
		else
			return NULL;
		/* SUCCESS */
		return My_string;
	} /* end outter if */
	else
		return NULL;
}
int my_string_get_capacity(MY_STRING hMy_string)
{
	struct my_string *My_string = (struct my_string *)hMy_string;
	return My_string->capacity;	
}

int my_string_get_size(MY_STRING hMy_string)
{
	struct my_string *My_string = (struct my_string *)hMy_string;
	return My_string->size; 
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	struct my_string *Left_My_string = (struct my_string *)hLeft_string; 
	struct my_string *Right_My_string = (struct my_string *)hRight_string; 
	int big_string_size = 0;
	int Left_string_size = Left_My_string->size;
	int Right_string_size = Right_My_string->size;

	if (Left_string_size > Right_string_size)
		big_string_size = Left_string_size;
	else if (Left_string_size < Right_string_size)
		big_string_size = Right_string_size;
	else 
		big_string_size = Left_string_size; 

	for(int i = 0; i < big_string_size; i++){
		if (Left_My_string->data[i] < Right_My_string->data[i])
			return -1;
		else if (Left_My_string->data[i] > Right_My_string->data[i])
			return 1;
		/*else if (Left_My_string->data[i] == '\0')
			return -1;
		else if (Right_My_string->data[i] == '\0')
			return 1;*/
	}
	return 0; /* the strings are the same */ 
}

Status my_string_extraction(MY_STRING hMy_string, FILE *fp)
{
	char c = 0; int i = 0;
	struct my_string *My_string = (struct my_string *)hMy_string; 
	My_string->size = 0;

	for(i = 0; i < My_string->size; i++)
		My_string->data[i] = '\0';

	i = 0;
	while ((c = fgetc(fp)) == ' ');
	if (c == EOF)
		return FAILURE; 
	else
		{My_string->data[i] = c; i++; My_string->size++;}

	while ((c = fgetc(fp)) != EOF){
		if( c != ' ' && c != '\n'){
			if(My_string->size == My_string->capacity-1){
				My_string->data = (char *)realloc(My_string->data, sizeof(char) * (My_string->size*2));
				if(My_string->data == NULL ) {return FAILURE;}
				My_string->capacity = (My_string->size*2)+1;
			}
			My_string->data[i] = c; i++;
			My_string->size++;
		}
		else
			{
				My_string->data[My_string->size] = '\0';
				ungetc(c, fp);
				 return SUCCESS;
			}

	}


	My_string->data[My_string->size] = '\0';
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE *fp)
{
	struct my_string *My_string = (struct my_string *)hMy_string;

	if(My_string == NULL){
		return FAILURE; 
	}

	if(My_string->size == 0)
		return FAILURE;

	for(int i = 0; i < My_string->size; i++){
		fputc(My_string->data[i], fp);
	}

	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	struct my_string *My_string = (struct my_string *)hMy_string; 

	if(My_string->size == My_string->capacity-1){
		My_string->data = (char *)realloc(My_string->data, sizeof(char) * (My_string->capacity * 2));
		if(My_string->data == NULL)
			return FAILURE;
		for(int i = My_string->size; i < My_string->capacity; i++)
			My_string->data[i] = '\0';
		My_string->capacity*=2;
	}

	for (int i = 0; i < (My_string->capacity - 1); i++){
		if(My_string->data[i] == '\0'){
			My_string->data[i] = item;
			My_string->size++;
			break;
		} 
	}
	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	struct my_string *My_string = (struct my_string *)hMy_string; 
	if (My_string == NULL)
		return FAILURE;
	My_string->data[My_string->size-1] = '\0';
	My_string->size--; 

	return SUCCESS; 
}

char *my_string_at(MY_STRING hMy_string, int index)
{
	struct my_string *My_string = (struct my_string *)hMy_string; 

	if (index >= My_string->size || My_string->size == 0)
		return NULL; 
	return &(My_string->data[index]); 
}

char *my_string_c_str(MY_STRING hMy_string)
{
	struct my_string *My_string = (struct my_string *)hMy_string; 

	if(My_string->size == My_string->capacity)
		My_string->data = (char *)realloc(My_string->data, sizeof(char) * (My_string->capacity + 1));
	My_string->data[My_string->size] = '\0';
	return &(My_string->data[0]); 
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	struct my_string *result = (struct my_string *)hResult;
	struct my_string *append = (struct my_string *)hAppend;
	int i = result->size;

	result->size+= append->size;
	result->capacity+= append->capacity;

	result->data = (char *)realloc(result->data, sizeof(char) * (result->size + append->size));
	if(result->data == NULL){
		return FAILURE;
	}
	for(int j = 0; i < result->size; i++, j++){
		result->data[i] = append->data[j];
	}

	return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string){
	struct my_string *My_string = (struct my_string *)hMy_string; 

	if (My_string->size == 0)
		return TRUE;
	return FALSE;
}

void my_string_assignment(Item *pLeft, Item Right)
{
	struct my_string *pMy_left = (struct my_string *)*pLeft;
	struct my_string *My_right = (struct my_string *)Right;

	if(pMy_left == NULL)
		pMy_left = my_string_init_default(); 

	if(pMy_left->capacity <= My_right->capacity){
		pMy_left->data = (char *)realloc(pMy_left->data, My_right->capacity * sizeof(char));

		pMy_left->capacity = My_right->capacity;
		pMy_left->size = My_right->size;
		for(int i = 0; i < pMy_left->size; i++)
			pMy_left->data[i] = My_right->data[i];
		//pMy_left->data[pMy_left->size] = '\0';

		*pLeft = (Item)pMy_left;
	} else if (pMy_left->capacity > My_right->capacity){
		pMy_left->size = My_right->size; 
		for(int i = 0; i < pMy_left->size; i++)
			pMy_left[i] = My_right[i];

		*pLeft = (Item)pMy_left;
		//pMy_left->data[pMy_left->capacity-1] = '\0';
	}
	/*else{
		if(pMy_left->size < My_right->size){
			pMy_left->data = (char *)realloc(pMy_left->data, sizeof(char)*(My_right->capacity - pMy_left->capacity));
			pMy_left->size = My_right->size;
			pMy_left->capacity = My_right->capacity;
			for(int i = 0; i < pMy_left->size; i++)
				pMy_left->data[i] = My_right->data[i];
			pMy_left->data[pMy_left->size] = '\0';
		}
		else if (pMy_left->size >= My_right->size){
			free(pMy_left->data);
			pMy_left->data = (char *)malloc(sizeof(char) * My_right->capacity);

			for(int i = 0; i < My_right->size; i++)
				pMy_left->data[i] = My_right->data[i];
			pMy_left->data[My_right->size] = '\0'; 
			pMy_left->size = My_right->size; 
			pMy_left->capacity = My_right->capacity;
		}

	}*/

}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
	struct my_string *_current_word_family = (struct my_string *)current_word_family; 
	struct my_string *_new_key = (struct my_string *)new_key;
	struct my_string *_word = (struct my_string *)word; 

	my_string_assignment((MY_STRING)&_new_key, (MY_STRING)_current_word_family);

	for(int i = 0; i < _word->size; i++){
		if(_word->data[i] == guess)
			_new_key->data[i] = guess; 
	}
	new_key = (MY_STRING)_new_key;
	return SUCCESS;
}

void my_string_destroy(Item* pItem)
{
	struct my_string *My_string = (struct my_string *)*pItem;
	free(My_string->data);
	My_string->data = NULL;
	free(My_string);
	My_string = NULL;
}

