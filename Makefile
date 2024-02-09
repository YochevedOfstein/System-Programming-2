CC = gcc
AR = ar
FLAGS = -Wall -g -fPIC

all: my_graph my_knapsack

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_knapsack.o: my_knapsack.c
	$(CC) $(FLAGS) -c my_knapsack.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_graph: my_graph.o libmy_mat.a
	$(CC) $(FLAGS) -o my_graph my_graph.o libmy_mat.a

my_knapsack: my_knapsack.o
	$(CC) $(FLAGS) -o my_knapsack my_knapsack.o


.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_knapsack