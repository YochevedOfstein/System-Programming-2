#include "my_mat.h"
#define size 10


int FloydWarshall(int graph[][size], int a, int b) {
    int dist[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist[a][b];
}

int isPath(int i, int j, int graph[][size]){
if(graph[i][j] == 0) {
    return 0;
}
return 1;
}




