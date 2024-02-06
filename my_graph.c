#include <stdio.h>
#include "my_mat.h"

#define size 10

int main(){

    char func;

    int num;

    int i;
    int j;

    int graph[size][size];


    scanf("%c", &func);

    if(func == 'A'){
         for(int i=0; i<size; i++){
            for(int j = 0; j<size; j++){
             scanf("%d",&num);
             graph[i][j] = num;
            }
        }
       scanf("%c", &func); 
    }

    else if(func == 'B'){
       scanf("%d",&i); 
       scanf("%d",&j);

       if(isPath(i, j, graph) == 0){
        printf("False");
       }
       else{
        printf("True");
       }
       scanf("%c", &func);
    }

    else if(func == 'C'){
       scanf("%d",&i); 
       scanf("%d",&j);
       printf("%d", FloydWarshall(graph, i, j));
       scanf("%c", &func);
    }
    
    else if(func == 'D' || func == EOF){
        return 0;
    }
    else{
        return 1;
    }

    return 0;
}


