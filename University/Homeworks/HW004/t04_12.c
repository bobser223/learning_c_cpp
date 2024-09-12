//
// Created by Volodymyr Avvakumov on 13.09.2024.
// a
#include <stdio.h>

double polynomial(double x, int n){
    double sum = 1;
    double an = 1;
    for (int i = 0; i < n - 1; i++){
        an *= x*x;
        sum += an;
    }
    return sum;
}


int main(){
    int n;
    double x;
    scanf("%lf %d", &x, &n);
    printf("%f", polynomial(x, n));

    return 0;
}