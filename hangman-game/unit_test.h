#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char *buffer, int length);
Status test_get_size_on_init_default_returns_0(char *buffer, int length);
Status test_get_capacity_on_init_default_returns_7(char *buffer, int length);

Status test_my_string_init_c_string_returns_nonNULL(char *buffer, int length);
Status test_my_string_init_c_string_capacity_one_greater_than_size(char *buffer, int length);
Status test_my_string_init_c_string_data_returns_nonNULL(char *buffer, int length);
Status test_my_string_init_c_string_is_NULL_terminated(char *buffer, int length);

Status test_my_string_get_capacity_returns_non_negative_integer(char* buffer, int length);
Status test_my_string_get_size_returns_non_negative_integer(char *buffer, int length);

Status test_my_string_compare_returns_integer_less_than_zero_when_left_string_is_smaller(char *buffer, int length);
Status test_my_string_compare_returns_interger_greater_than_zero_when_left_string_is_greater(char *buffer, int length);
Status test_my_string_compare_returns_0_when_the_strings_are_the_same(char *buffer, int length);

Status test_my_string_extraction_returns_success(char *buffer, int length);
Status test_my_string_extraction_returns_failure_reading_empty_file(char *buffer, int lenght);

Status test_my_string_insertion_returns_success(char *buffer, int length);
Status test_my_string_insertion_returns_failure_for_empty_string(char *buffer, int lenght);

Status test_my_string_push_back_returns_success(char *buffer, int length);

Status test_my_string_pop_back_returns_success(char *buffer, int length);

Status test_my_string_at_returns_NULL(char* buffer, int length);
Status test_my_string_at_returns_nonNULL(char *buffer, int length);

Status test_my_string_c_str_returns_null_terminated_string(char *buffer, int length);

Status test_my_string_concat_returns_nonNULL(char *buffer, int length);

Status test_my_string_empty_returns_true(char *buffer, int length);
Status test_my_string_empty_returns_false(char *buffer, int length);

#endif