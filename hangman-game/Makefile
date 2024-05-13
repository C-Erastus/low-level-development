CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o
UT_OBJ = unit_test.o test_def.o my_string.o

unit_test: $(UT_OBJ)
	$(CC) $(CFLAGS) -o unit_test $(UT_OBJ)

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o


unit_test.o: unit_test.c  
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o  
test_def.o: test_def.c  unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o  

clean:
	rm string_driver $(OBJECTS) unit_test $(UT_OBJ)
