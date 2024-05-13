#include <stdio.h>
#include "unit_test.h"

int main(int argc, char** argv)
{

	Status (*test[])(char*, int) = 
	{
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_get_capacity_on_init_default_returns_7,

		test_my_string_init_c_string_returns_nonNULL, 
		test_my_string_init_c_string_capacity_one_greater_than_size,
		test_my_string_init_c_string_data_returns_nonNULL,
		test_my_string_init_c_string_is_NULL_terminated,

		test_my_string_get_capacity_returns_non_negative_integer,
		test_my_string_get_size_returns_non_negative_integer,

		test_my_string_compare_returns_integer_less_than_zero_when_left_string_is_smaller,
		test_my_string_compare_returns_interger_greater_than_zero_when_left_string_is_greater,
		test_my_string_compare_returns_0_when_the_strings_are_the_same,

		test_my_string_extraction_returns_success, 
		test_my_string_extraction_returns_failure_reading_empty_file,

		test_my_string_insertion_returns_success,
		test_my_string_insertion_returns_failure_for_empty_string,

		test_my_string_push_back_returns_success,

		test_my_string_pop_back_returns_success, 

		test_my_string_at_returns_NULL,
		test_my_string_at_returns_nonNULL,

		test_my_string_c_str_returns_null_terminated_string, 

		test_my_string_concat_returns_nonNULL,

		test_my_string_empty_returns_true,
		test_my_string_empty_returns_false,

	};

	int number_of_functions = sizeof(test)/sizeof(test[0]);
	int i;
	char buffer[500];
	int success_count = 0; 
	int failure_count = 0; 

	for(i = 0; i < number_of_functions; i++){
		if(test[i](buffer, 500) == FAILURE){
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++; 
		}
		else{
			printf("PASS: Test %d passed\n", i);
			printf("\t%s\n", buffer);
			success_count++;
		}
	}
	printf("Total number of test: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count,
		number_of_functions, failure_count, number_of_functions);

	return 0;
}
