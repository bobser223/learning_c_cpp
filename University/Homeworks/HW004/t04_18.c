//
// Created by Volodymyr Avvakumov on 13.09.2024.
// zh
#include <stdio.h>

// -x^2 / 4i^2 + 2x
double sequence(double x, int n){
    double an = x;
    for (int i = 1; i <= n; i++){
        an *= ((-x*(float)x)/((float)4*i*i + 2*i));
    }
    return an;
}


int main(){
    int n;
    double x;
    scanf("%lf %d", &x, &n);
    printf("%lf", sequence(x, n));

    return 0;
}