CC = gcc 
CFLAGS = -g -Wall -lreadline
OBJS = shell.o

shell: $(OBJS)
	$(CC) $(CFLAGS) -o shell $(OBJS)
shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c -o shell.o 
clean: 
	rm *.o shell