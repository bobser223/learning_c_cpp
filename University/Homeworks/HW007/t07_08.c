//
// Created by Volodymyr Avvakumov on 23.09.2024.
// e

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int a){
    if (a == 1){
        return true;
    }
    int max_i = (int)sqrt(a) + 1;
    for (int i = 2; i < max_i; i++){
        if (a % i == 0){
            return false;
        }

    }
    return true;
}

void prime_count(int* arr, int size){
    int counter = 0;
    for (int i = 0; i < size; i++ ){
        if (is_prime(arr[i])){
            counter++;
        }

    }
    printf("there are %d prime numbers in this vector", counter);

}

int main(){
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    prime_count(arr, N);
}