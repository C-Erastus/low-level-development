CC = gcc
CFLAGS = -g -Wall

queue: circular_buffer.o
	$(CC) circular_buffer.o -o queue

circular_buffer.o: circular_buffer.c
	$(CC) -c circular_buffer.c -o circular_buffer.o

clean: 
	rm -f *.o queue
