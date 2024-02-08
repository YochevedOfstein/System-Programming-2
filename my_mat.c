#include "my_mat.h"
#define size 10
#define INF 2147483647

int dist[size][size] = {0};

void createMatrix(int graph[][size]){
    int num = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d",&num);
            graph[i][j] = num;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(i == j){
                dist[i][j] = 0;
            }
            else if(graph[i][j] > 0){
                dist[i][j] = graph[i][j];
            }
            else{
                dist[i][j] = INF; 
            }
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(i!=j){
                    if (dist[i][k] != INF && dist[k][j] != INF){
                        if(dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
    }
}

void shortestPath(int i, int j){
    if((dist[i][j] == INF) || (i == j)){
        printf("-1\n"); 
    }
    else{
        printf("%d\n", dist[i][j]);
    }
}

void hasPath(int i, int j){
  
    if((dist[i][j] == INF) || (i == j)) {
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}




