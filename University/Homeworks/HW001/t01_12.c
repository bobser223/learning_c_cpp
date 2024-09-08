//
// Created by Volodymyr Avvakumov on 06.09.2024.
//
#include<stdio.h>

int main(){
    // setlocale()
    double period = 365 + 1.0 / (4 + (1.0 / (7 + (1.0 / 1 + 1 / 3))));
    printf("period = %lf", period);
    return 0;

}