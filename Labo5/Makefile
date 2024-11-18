CC = gcc 
CFLAGS = -Wall -Wextra

all: main

main: main.o double_list.o
	$(CC) $(CFLAGS) -o main main.o double_list.o

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

clean:
	rm -f *.o main
