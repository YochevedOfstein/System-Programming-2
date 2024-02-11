#include <stdio.h>
#define weight 20
#define size 5


int MAX(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int KnapSack(int weights[], int values[], int selected_bool[]){

    int WS[size + 1][weight + 1];

    for(int i = 0; i <= size; i++ ){
        for(int j = 0; j <= weight; j++){
            if((i == 0) || (j == 0)){
                WS[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                WS[i][j] = MAX(values[i-1] + WS[i-1][j-weights[i-1]], WS[i-1][j]);
            }
            else{
                WS[i][j] = WS[i-1][j];
            }
        }
    }

    int tempWeight = weight;
    for(int i = size; i > 0 && tempWeight > 0; i--){
        if(WS[i][tempWeight] != WS[i-1][tempWeight]){
            selected_bool[i-1] = 1;
            tempWeight = tempWeight - weights[i-1];
        }
    }  
    return WS[size][weight];
}

int main(){
 
    int selected_bool[size];
    char items[size];
    int weights[size];
    int values[size];

    for(int i = 0; i < size; i++){
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
        selected_bool[i] = 0;
    }

    int profit = KnapSack(weights, values, selected_bool);


    printf("Maximum profit: %d\n", profit);
    printf("Selected items:");

    for(int i = 0; i < size; i++){
        if(selected_bool[i] == 1){
            printf(" %c", items[i]);
        }
    }
   printf("\n"); 
}

