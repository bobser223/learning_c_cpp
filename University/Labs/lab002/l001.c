//
// Created by Volodymyr Avvakumov on 06.09.2024.
//
#include <math.h>
#include <stdio.h>

int main(){
    double x = 1e-4;
    printf("%f \n", x);
    printf("%f \n", M_PI);
    printf("%f \n", M_E);
    long double y = 24.33e5;
    printf("%Lf \n", y);
    // sqrtf() and logf() analogue log() and sqrt() but for float type, not double
    printf("%f \n", sqrt(5));
    printf("%f \n", log(100));



}
