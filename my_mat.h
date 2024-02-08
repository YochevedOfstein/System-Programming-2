#include <stdio.h>
#define size 10

void createMatrix(int graph[size][size]);

int FloydWarshall(int graph[size][size], int i, int j);

int hasPath(int graph[size][size], int i, int j) ;