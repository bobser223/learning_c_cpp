//
// Created by Volodymyr Avvakumov on 23.09.2024.
// h

#include <stdio.h>

void min_among_odd_i(double* arr, int size){
    double min = arr[0];
    for (int i = 2; i < size; i += 2 ){
        if (arr[i] < min){
            min = arr[i];
        }

    }
    printf("min = %lf", min);
}

int main(){
    int size;

    scanf("%d", &size);

    double arr[size], a;

    for (int i = 0; i < size; i++){
        scanf("%lf", &a);
        arr[i] = a;
    }
    min_among_odd_i(arr, size);
    return 0;
}


