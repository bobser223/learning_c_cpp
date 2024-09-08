//
// Created by Volodymyr Avvakumov on 07.09.2024.
//
#include <stdio.h>
#include <math.h>
double Rosenbrock2d(double x, double y) {

    return 100 * pow((pow(x, 2) - y ), 2) + pow((x - 1), 2);
}
int main(){
    double x, y;
    scanf("%lf  %lf", &x, &y);
    printf("%lf", Rosenbrock2d(x, y));
    return 0;
}