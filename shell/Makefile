CC = gcc 
CFLAGS = -Wall -g
OBJS = main.o shell.o

shell: $(OBJS)
	$(CC) $(CFLAGS) -o shell $(OBJS)
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c -o main.o
shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c -o shell.o 
clean: 
	rm *.o shell