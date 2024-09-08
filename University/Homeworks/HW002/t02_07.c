//
// Created by Volodymyr Avvakumov on 08.09.2024.
//
#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("\n");
    scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);
    printf("\n");
    double r = distance(x1, y1, x2, y2);
    double R = distance(x3, y3, x4, y4);
    printf("ellipse area = %lf", M_PI * r * R);
    return 0;
}