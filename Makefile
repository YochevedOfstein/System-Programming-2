CC = gcc
FLAGS = -Wall -g 

all: my_graph

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_graph: my_mat.o my_graph.o
	$(CC) $(FLAGS) -o my_graph my_mat.o my_graph.o


.PHONY: clean all

clean:
	rm -f *.o my_graph