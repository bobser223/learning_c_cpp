//
// Created by Volodymyr Avvakumov on 06.09.2024.
//
#include <math.h>
#include <stdio.h>

int main() {
    double a, b;
    printf("please enter two nums ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    double mid = (a + b) / 2;
    long double midGam = 2 / ((1.0 /a) + (1.0 /b));
    printf("%lf, %Lf \n", mid, midGam);
    printf("%e, %e \n", mid, midGam);

//   printf("%i", n);

}