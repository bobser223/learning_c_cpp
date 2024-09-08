//
// Created by Volodymyr Avvakumov on 07.09.2024.
//
#include <stdio.h>
#include <math.h>
double perimeter(double a, double b, double c){
    return a + b + c;
}

double area(double a, double b, double c){
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));

}

int main(){
    double  a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%lf", area(a, b, c));
    return 0;
}
