#include <stdio.h>
#include "my_mat.h"

#define size 10

int main(){

    char func = 0;

    int i = 0;
    int j = 0;

    int graph[size][size] = {0};

    while((func != 'D') || (func != EOF)){

        scanf("%c", &func);

        if(func == 'A'){

            createMatrix(graph);

        }


        else if(func == 'B'){
            scanf("%d",&i); 
            scanf("%d",&j);

            hasPath(graph, i, j);
     
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


