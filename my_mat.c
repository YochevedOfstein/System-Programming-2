#include "my_mat.h"
#define size 10

int dist[size][size] = {0};

void createMatrix(int graph[size][size]){
    int num = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d",&num);
            graph[i][j] = num;
        }
    }
}

int FloydWarshall(int graph[size][size], int a, int b)
{

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

int hasPath(int graph[size][size], int i, int j){
    int dist = FloydWarshall(graph,i,j);
    if(dist == 0) {
        printf("False");
        return 0;
    }
    else{
    printf("True");
    return 1;
    }
}




