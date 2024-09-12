//
// Created by Volodymyr Avvakumov on 13.09.2024.
//
#include <math.h>
#include <stdio.h>

double foo(int n, float x){
    float result = 0;
    for (int i = 1; i <= n; i++)
        result += i * pow(x, i);

    return result;
}

int main(){
    int n;
    float x;
    scanf("%d %f", &n, &x);
    printf("%lf\n", foo(n, x));
}