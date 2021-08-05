CC = gcc
CFLAGS = -Iinclude

all:
	rm -rf ./build
	mkdir ./build
	$(CC) $(CFLAGS) ./src/*.c -obuild/graph.o