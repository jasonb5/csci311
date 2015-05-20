CC=g++
CFLAGS=-c -std=c++11 -Wall -W -Werror -pedantic -D HASH_TABLE_SIZE=10

all: hash

hash: main.o hash.o hash_function.o
	$(CC) main.o hash.o hash_function.o -o hash

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

hash.o: hash.cpp
	$(CC) $(CFLAGS) hash.cpp

hash_function.o: hash_function.cpp
	$(CC) $(CFLAGS) hash_function.cpp

clean:
	rm -rf *o hash
	
