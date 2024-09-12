//
// Created by Volodymyr Avvakumov on 13.09.2024.
//
#include <math.h>
#include <stdio.h>

void fact_rev(int n){
    printf("%d! = ", n);
    for (int i = n; i >= 1; i--){
        if(i == 1){
            printf("%d\n", i);
            break;
        }
        printf("%d*", i);

    }
}

void fact(int n){
    printf("%d! = ", n);
    for (int i = 1; i <= n; i++){
        if(i == n){
            printf("%d\n", i);
            break;
        }
        printf("%d*", i);

    }
}
int main(){

    int num;
    scanf("%d", &num);
    fact(num);
    fact_rev(num);
}