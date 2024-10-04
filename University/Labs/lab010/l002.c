//
// Created by Volodymyr Avvakumov on 30.09.2024.
//

#include <stdlib.h>
#include <stdio.h>

void fill_arr(int* a,int n){
    for (int i = 1; i <= n; i++)
        a[i-1] = i;
}

int sqr_arr_sum(int* a, int n){
    int sum = 0;
    for (int i = 0; i < n; i ++){
        sum += a[i]*a[i];
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    int* a;
    a = calloc(n, sizeof(*a));
    fill_arr(a, n);

    printf("%d", sqr_arr_sum(a, n));


    free(a);


    return 0;
}