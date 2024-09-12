//
// Created by Volodymyr Avvakumov on 13.09.2024.
//
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool isOdd(int num ){
    if (num % 2 == 0){
        return true;
    }
    return false;

}

float double_fact(int n){
    float result = 1;
    if (isOdd(n)){
        for (int i = 2; i < n; i += 2){
            result *= i;
        }
        return result;
    }
    for (int i = 1; i < n; i += 2){
        result *= i;
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%lf\n", double_fact(n));
}