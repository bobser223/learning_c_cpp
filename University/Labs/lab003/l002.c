//
// Created by Volodymyr Avvakumov on 07.09.2024.
//
#include <stdio.h>
#include <math.h>
double polA(double x){
    x = x * x + 1;
    x *= x;
    return x;

}

double polB(double x){
    double sum;
    for(int i = 0; i <= 4; i ++){
        sum += pow(x, i);
    }
    return sum;
}

double polV(double x){
    return pow((x + 1), 5);

}

double polH(double x){
    double y = pow(x, 3);
    double z = y * pow(x, 6);
    return z + y + 1;

}

double polD(double x){
    double sum = 1;
    for(int i = 1; i <= 5; i ++){
        sum += pow(x, i) * pow(2, i);
    }
    return sum;

}

double polE(double x){
    double y = pow(x, 3);
    double z = y * pow(x, 2);
    return z + y + x;

}

int main(){
    double x;
    scanf("%lf", &x);
    printf("%lf\n", polA(x));
    printf("%lf\n", polB(x));
    printf("%lf\n", polV(x));
    printf("%lf\n", polH(x));
    printf("%lf\n", polD(x));
    printf("%lf\n", polE(x));
    return 0;
}