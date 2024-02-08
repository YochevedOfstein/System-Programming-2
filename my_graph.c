#include <stdio.h>
#include "my_mat.h"

#define size 10

int main(){

    char func = 0;

    int num = 0;

    int i = 0;
    int j = 0;

    int graph[size][size];

    while((func != 'D') || (func != EOF)){
        scanf("%c", &func);

        if(func == 'A'){
            for(int i=0; i<size; i++){
                for(int j = 0; j<size; j++){
                 scanf("%d",&num);
                 graph[i][j] = num;
                }
            }
        }

        else if(func == 'B'){
            scanf("%d",&i); 
            scanf("%d",&j);

            if(hasPath(graph, i, j) == 0){
                printf("False");
            }
            else{
                printf("True");
            }
        }

        else if(func == 'C'){
            scanf("%d",&i); 
            scanf("%d",&j);
            int path = FloydWarshall(graph, i, j);
            if(path == 0){
               printf("%d", -1); 
            }
            printf("%d", path);
        }
    }
    return 0;
}


