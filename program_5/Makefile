CC=g++
CFLAGS=-g -std=c++11 -W -Werror -Wall -pedantic

all: mstapp

mstapp: graph.o minpriority.o mstapp.o
	$(CC) Graph.o MinPriority.o MSTapp.o -o mst

graph.o: Graph.cpp
	$(CC) $(CFLAGS) -c Graph.cpp

minpriority.o: MinPriority.cpp
	$(CC) $(CFLAGS) -c MinPriority.cpp

mstapp.o: MSTapp.cpp
	$(CC) $(CFLAGS) -c MSTapp.cpp

clean:
	rm -rf *.o mst
