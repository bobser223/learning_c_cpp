//
// Created by Volodymyr Avvakumov on 08.09.2024.
//
#include <stdio.h>
#include <math.h>

int main(){
    double x;
    long double y;
    scanf("%lf", &x);
    y = pow(x, 8);
    printf("%20.4Lf", y);

    return 0;
}