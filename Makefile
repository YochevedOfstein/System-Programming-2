CC = gcc
AR = ar
FLAGS = -Wall -g 

all: my_graph

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_graph: my_graph.o libmy_mat.a
	$(CC) $(FLAGS) -o my_graph my_graph.o libmy_mat.a


.PHONY: clean all

clean:
	rm -f *.o *.a my_graph 