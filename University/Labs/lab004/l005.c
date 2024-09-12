//
// Created by Volodymyr Avvakumov on 09.09.2024.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>

void findmax(double a, double b){
    if (a > b){
        printf("a = %ld > b = %ld", a, b);
    } else if (b > a) {
        printf("a = %ld < b = %ld", a, b);
    } else {
        printf("a = %ld == b = %ld", a, b);
    }

}

int main(){
    double x, y;
    scanf("%lf %lf", &x, &y);
    findmax(x, y);
    return 0;
}