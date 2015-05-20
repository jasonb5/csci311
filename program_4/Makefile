CC=g++
CFLAGS=-g -std=c++11 -Wall -W -Werror -pedantic

all: bst

bst: BSTapp.o BST.o Node.o
	$(CC) BSTapp.o BST.o Node.o -o bst

BSTapp.o: BSTapp.cpp
	$(CC) $(CFLAGS) -c BSTapp.cpp

BST.o: BST.cpp
	$(CC) $(CFLAGS) -c BST.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp

test: BSTTest.o BST.o Node.o
	$(CC) BSTTest.o BST.o Node.o -L${PWD}/ -lgtest -lpthread -o test

BSTTest.o: BSTTest.cpp
	$(CC) -I include/ -L${PWD}/ -c BSTTest.cpp -lgtest -lpthread

clean:
	rm -rf *o bst

