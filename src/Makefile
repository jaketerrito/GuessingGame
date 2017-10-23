CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = ../guess
OBJS = guess.c  treeFuncs.c helper.c 
all:$(MAIN)

$(MAIN): $(OBJS) guess.h treeFuncs.h helper.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean:
	rm *.o $(MAIN) core
