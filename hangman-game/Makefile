CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o associative_array.o
UT_OBJ = unit_test.o test_def.o my_string.o 


string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

unit_test: $(UT_OBJ)
	$(CC) $(CFLAGS) -o unit_test $(UT_OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.c generic_vector.h
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
associative_array.o: associative_array.c associative_array.h
	$(CC) $(CFLAGS) -c associative_array.c -o associative_array.o 

unit_test.o: unit_test.c  
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o  
test_def.o: test_def.c  unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o  

clean:
	rm string_driver $(OBJECTS) unit_test $(UT_OBJ)
