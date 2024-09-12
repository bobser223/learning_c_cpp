//
// Created by Volodymyr Avvakumov on 13.09.2024.
// d
#include <stdio.h>
#include <math.h>

double const LAMBDA = 0.000000001;

double pi(){
    double an = 1;
    double sum = 1;
    int counter = 2;
    while(an > LAMBDA){
        an = 1/pow(counter, 4);
        sum += an;
        counter ++;
    }
    return sum;
}

int main(){

    printf("%lf \n", sqrt(sqrt(pi()*90)));
    printf("%lf \n", M_PI);

    return 0;
}