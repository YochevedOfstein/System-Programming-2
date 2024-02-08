CC = gcc
AR = ar
FLAGS = -Wall -g 

all: connections

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

connections: my_graph.o libmy_mat.a
	$(CC) $(FLAGS) -o connections my_graph.o libmy_mat.a


.PHONY: clean all

clean:
	rm -f *.o *.a connections