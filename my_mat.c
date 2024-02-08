#include "my_mat.h"
#define size 10


int FloydWarshall(int graph[size][size], int a, int b) {
    int dist[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(i!=j){
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    return dist[a][b];
}

int hasPath(int graph[][size], int i, int j){
    int dist = FloydWarshall(graph,i,j);
    if(dist == 0) {
        return 0;
    }
    return 1;
}




