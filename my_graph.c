#include <stdio.h>
#include "my_mat.h"

#define size 10

int main(){

    char func = 0;

    char A = 'A';
    char B = 'B';
    char C = 'C';
    char D = 'D';

    int num;

    int i = 0;
    int j = 0;

    int graph[size][size];

    while(func != D){
        scanf("%c", &func);

        if(func == A){
            for(int i=0; i<size; i++){
                for(int j = 0; j<size; j++){
                 scanf("%d",&num);
                 graph[i][j] = num;
                }
            }
        }

        else if(func == B){
            scanf("%d",&i); 
            scanf("%d",&j);

            if(isPath(i, j, graph) == 0){
                printf("False");
            }
            else{
                printf("True");
            }
        }

        else if(func == C){
            scanf("%d",&i); 
            scanf("%d",&j);
            printf("%d", FloydWarshall(graph, i, j));
        }
    }
    return 0;
}


