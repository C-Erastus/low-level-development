#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char *buffer, int length)
{
	MY_STRING hString = NULL; 

	hString = my_string_init_default();

	if(hString == NULL){
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
			"my_string_init_default returns NULL", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString); 
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS; 
	}
}

Status test_get_size_on_init_default_returns_0(char *buffer, int length)
{
	MY_STRING hString = NULL; 
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString) != 0){
		status = FAILURE; 
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
			"Did not receive 0 from get_size after _init_default\n", length);
	}
	else{
		status = SUCCESS; 
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
	}

	my_string_destroy(&hString);
	return status; 
}

Status test_get_capacity_on_init_default_returns_7(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default(); 

	if(my_string_get_capacity(hString) != 7){
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString)); 
		strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
			"Did not receive 7 for get_capacity after _init_default\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_get_capacity_on_init_default_retruns_7\n", length);
		return SUCCESS;
	}
}

Status test_my_string_init_c_string_returns_nonNULL(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Anovai"); 

	if(hString== NULL){
		strncpy(buffer, "test_init_c_string_returns_nonNULL\n"
			"my_string_init_c_string returns NULL", length);
		return FAILURE; 
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_c_string_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_my_string_init_c_string_capacity_one_greater_than_size(char *buffer, int length)
{
	MY_STRING hString =  my_string_init_c_string("Anovai"); 

	if(!((my_string_get_size(hString)+1) == my_string_get_capacity(hString))){
		strncpy(buffer, "test_init_c_string_capacity_one_greater_than_size"
			"my_string_init_c_string capacity is not one greather than size", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_c_string_capcity_one_greater_than_size\n",length);
		return SUCCESS;
	}
}

Status test_my_string_init_c_string_data_returns_nonNULL(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Anovai"); 

	if(my_string_c_str(hString) == NULL){
		strncpy(buffer, "test_my_string_init_c_string_data_retrns_nonNULL"
			"my_string_init_c_string data returns NULL", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_c_string_data_returns_nonNULL\n", length);
		return SUCCESS; 
	}
}

Status test_my_string_init_c_string_is_NULL_terminated(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Anovai");
	char *data = my_string_c_str(hString);
	int index = my_string_get_capacity(hString);

	if(data[index-1] != '\0'){
		my_string_destroy(hString);
		strncpy(buffer, "test_my_string_init_c_string_is_NULL_terminated"
			"my_string_init_c_string is not NULL terminated\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString); 
		strncpy(buffer, "test_init_c_string_returns_is_NULL_terminated\n", length);
		return SUCCESS;
	}
} 

Status test_my_string_get_capacity_returns_non_negative_integer(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();

	if(my_string_get_capacity(hString) < 0 ){
		my_string_destroy(&hString);
		strncpy(buffer, "test_my_string_get_capacity_returns_non_negative_integer"
			"my_string_get_capacity returned a negative number\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_my_string_get_capacity_returns_non_negative_integer\n", length);
		return SUCCESS;
	}
}

Status test_my_string_get_size_returns_non_negative_integer(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();

	if(my_string_get_size(hString) < 0){
		my_string_destroy(&hString); 
		strncpy(buffer, "test_my_string_get_size_returns_non_negative_integer"
			"my_string_get_size returned a negative number\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_my_string_get_size_returns_non_negative_integer\n", length);
		return SUCCESS; 
	}
}

Status test_my_string_compare_returns_integer_less_than_zero_when_left_string_is_smaller(char *buffer, int length)
{
	MY_STRING hLeft_string = my_string_init_c_string("Erastus");
	MY_STRING hRight_string = my_string_init_c_string("erastus");

	if(my_string_compare(hLeft_string, hRight_string) >= 0){
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string); 
		strncpy(buffer, "test_my_string_compare_returns_integer_less_than_zero_when_left_string_is_smaller\n"
			"my_string_compare failed to returna a number less than zero", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string); 

		strncpy(buffer, "test_my_string_compare_returns_integer_less_than_zero_when_left_string_is_smaller\n", length);
		return SUCCESS;
	}
}

Status test_my_string_compare_returns_interger_greater_than_zero_when_left_string_is_greater(char *buffer, int length)
{
	MY_STRING hLeft_string = my_string_init_c_string("erastus");
	MY_STRING hRight_string = my_string_init_c_string("Erastus");

	if(my_string_compare(hLeft_string, hRight_string) <= 0){
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string);
		strncpy(buffer, "test_my_string_compare_returns_integer_greater_than_zero_when_left_string_is_greater\n"
			"my_string_compare failed to return number greater than zero when left string is greater\n", length);
		return FAILURE; 
	}
	else{
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string);

		strncpy(buffer, "test_my_string_compare_returns_integer_than_zero_when_left_string_is_greater\n", length);
		return SUCCESS;
	}
}

Status test_my_string_compare_returns_0_when_the_strings_are_the_same(char *buffer, int length)
{
	MY_STRING hLeft_string = my_string_init_c_string("erastus");
	MY_STRING hRight_string = my_string_init_c_string("erastus");

	if(my_string_compare(hLeft_string, hRight_string) != 0 ){
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string);

		strncpy(buffer, "test_my_string_comapre_returns_0_when_the_strings_are_the_same\n"
			"my_string_compare failed to return 0 when both strings are the same\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hLeft_string);
		my_string_destroy(&hRight_string);

		strncpy(buffer, "my_string_compare_returns_0_when_the_strings_are_the_same\n", length);
		return SUCCESS;
	}
}

Status test_my_string_extraction_returns_success(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	FILE *fp;

	fp = fopen("simple.txt", "r");
	if(fp == NULL)
		exit(1); 
	if(!my_string_extraction(hString, fp)){
		my_string_destroy(hString);

		strncpy(buffer, "my_string_extraction_return_success\n"
			"my_string_extraction failed to return success\n", length);
		fclose(fp);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		fclose(fp);

		strncpy(buffer, "my_string_extraction_return_success\n", length);
		return SUCCESS;
	}

}

Status test_my_string_extraction_returns_failure_reading_empty_file(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	FILE *fp;

	fp = fopen("empty.txt", "r");
	if(fp == NULL)
		exit(1);

	if(my_string_extraction(hString, fp)){
		my_string_destroy(&hString);
		fclose(fp);

		strncpy(buffer, "test_my_string_extraction_returns_failure_reading_empty_file\n"
			"my_string_extraction failed to return failure when reading empty file\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		fclose(fp); 

		strncpy(buffer, "test_my_string_returns_failure_reading_empty_file\n", length);
		return SUCCESS;
	}
}

Status test_my_string_insertion_returns_success(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Erastus"); 

	if(!my_string_insertion(hString, stdout)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_insertion_returns_success\n"
			"my_string_insertion failed to return success\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);
		strncpy(buffer, "test_my_string_insertion_returns_success\n", length);
		return SUCCESS;
	}
}

Status test_my_string_insertion_returns_failure_for_empty_string(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();

	if(my_string_insertion(hString, stdout)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_insertion_returns_failure_for_empty_string\n"
			"my_string_insertion failed to return failure for empty string\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "my_string_insertion_returns_failure_for_empty_string\n", length);
		return SUCCESS; 
	}
}

Status test_my_string_push_back_returns_success(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default(); 

	if(!my_string_push_back(hString, 'e')){
		my_string_destroy(&hString); 

		strncpy(buffer, "test_my_string_push_back_returns_success\n"
			"my_string_push_back failed to return success\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_push_back_returns_success\n", length);
		return SUCCESS;
	}
}

Status test_my_string_pop_back_returns_success(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Erastus");

	if(!my_string_pop_back(hString)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_pop_back_returns_success\n"
			"my_string_pop_back failed to return success\n", length);
		return FAILURE;
	}
	else {
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_pop_back_return_success\n", length);
		return SUCCESS;
	}
}

Status test_my_string_at_returns_NULL(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();

	if(my_string_at(hString, 0) != NULL){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_at_returns_NULL\n"
			"my_string_at failed to return NULL\n", length);
		return FAILURE; 
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_at_returns_NULL\n", length);
		return SUCCESS;
	}
}

Status test_my_string_at_returns_nonNULL(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Erastus");

	if(!my_string_at(hString, 0)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_at_returns_nonNULL\n"
			"my_string_at returned NULL\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_at_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_my_string_c_str_returns_null_terminated_string(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Erastus");

	if((my_string_c_str(hString)[7]) != '\0'){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_c_str_returns_null_terminated_string\n"
			"my_string_c_strfailed to null terminat the string\n", length);
		return FAILURE; 
	}
	else{
		my_string_destroy(&hString); 

		strncpy(buffer, "test_my_string_c_str_returns_null_terminated_string", length);

		return SUCCESS;
	}
}

Status test_my_string_concat_returns_nonNULL(char *buffer, int length)
{
	MY_STRING hResult = my_string_init_c_string("Eras");
	MY_STRING hAppend = my_string_init_c_string("tus");

	if(!my_string_concat(hResult, hAppend)){
		my_string_destroy(hResult);
		my_string_destroy(hAppend);

		strncpy(buffer, "test_my_string_concat_returns_nonNULL\n"
			"my_string_concat returned NULL\n", length);
		return FAILURE;
	}
	else{
		my_string_destroy(&hResult);
		my_string_destroy(&hAppend);

		strncpy(buffer, "test_my_string_concat_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_my_string_empty_returns_true(char *buffer, int length)
{
	MY_STRING hString = my_string_init_default();

	if(!my_string_empty(hString)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_empty_returns_true\n"
			"my_string_empty returned False\n", length);
		return FAILURE; 
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_empty_reuns_tue\n", length);
		return SUCCESS;
	}
}

Status test_my_string_empty_returns_false(char *buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Erastus");

	if(my_string_empty(hString)){
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_empty_returns_false\n"
			"my_string_empty returned True\n", length); 
		return FAILURE;
	}
	else{
		my_string_destroy(&hString);

		strncpy(buffer, "test_my_string_returns_false\n", length);
		return SUCCESS;
	}
}