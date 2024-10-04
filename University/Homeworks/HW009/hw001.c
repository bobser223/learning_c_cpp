//
// Created by Volodymyr Avvakumov on 03.10.2024.
//


#include <stdlib.h>
#include <stdio.h>


int arithmetic_mean(int* vec, int n){
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += vec[i];
    }
    return (sum / n);
}

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);

    int* vec = (int*) calloc(n, sizeof(*vec));

    for(int i = 0; i < n; i++){
        printf("eneter %d number from %d : ", i+1, n);
        scanf("%d", &vec[i]);
    }
    int mean = arithmetic_mean(vec, n);
    for (int i = 0; i < n; i++){
        vec[i] = abs(vec[i] - mean);
    }
    // 2 3 4 1 3 5
    for (int i = 0; i < n; i++){
        printf("%d ", vec[i]);
    }

    free(vec);
    return 0;
}