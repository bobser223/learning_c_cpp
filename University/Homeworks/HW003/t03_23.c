//
// Created by Volodymyr Avvakumov on 12.09.2024.
//
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

double onestep(double x) {
    return (x >= 0) ? 1.0 : 0.0;
}

double onestep_derivative(double x) {
    if (x == 0) {
        return __DBL_MAX__;
    }
    return 0.0;
}

int main(){
    double x;
    scanf("%lf", &x);
    printf("%.2lf\n", onestep(x));
    printf("%.2lf\n", onestep_derivative(x));
    for (int i = 0; i < 2; ++i){
        printf("%d", i);
    }

    return 0;
}