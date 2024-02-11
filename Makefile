CC = gcc
AR = ar
FLAGS = -Wall -g -fPIC

all: my_graph my_Knapsack

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_graph: my_graph.o libmy_mat.a
	$(CC) $(FLAGS) -o my_graph my_graph.o libmy_mat.a

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) -o my_Knapsack my_Knapsack.o


.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_Knapsack