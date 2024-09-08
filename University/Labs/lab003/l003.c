//
// Created by Volodymyr Avvakumov on 07.09.2024.
//
#include <stdio.h>
#include <math.h>
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double perimeter(double a, double b, double c){
    return a + b + c;
}

double area(double a, double b, double c){
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));

}

int main(){
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf", &x1, &y1);
    printf("\n");
    scanf("%lf %lf", &x2, &y2);
    printf("\n");
    scanf("%lf %lf", &x3, &y3);
    printf("\n");
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double d3 = distance(x1, y1, x3, y3);
    printf("%lf", area(d1, d2, d3));
    return 0;
}