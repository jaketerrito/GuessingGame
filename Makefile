CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = guess
OBJS = src/guess.c  src/treeFuncs.c src/helper.c 
all:$(MAIN)

$(MAIN): $(OBJS) src/guess.h src/treeFuncs.h src/helper.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean:
	rm  $(MAIN)
