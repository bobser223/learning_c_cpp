//
// Created by Volodymyr Avvakumov on 08.09.2024.
//
// a - Avvakumov

#include <stdio.h>
#include <math.h>

double th( double x){
    return ((exp(x) - (1.0 / (exp(x)))) / (exp(x) + (1.0 / (exp(x)))));
}

double th_derivative(double x){
    return ( (4*exp(2*x)) / (pow( (exp(2*x) + 1) ,2)) );
}

int main(){
    double x;
    scanf("%lf", &x);
    printf("%lf \n", th(x));
    printf("%lf \n", th_derivative(x));
    return 0;
}