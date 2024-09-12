//
// Created by Volodymyr Avvakumov on 13.09.2024.
//
#include <math.h>
#include <stdio.h>

float a(int n, float x){
    float result = 0;
    for (int i = 0; i <= n; i++){
        result += pow(x, i);
    }
    return result;
}

float a_2(int n, float x){
    float result = 0;
    float an = 1;
    for(int i = 0; i <= n; i++){
        result += an;
        an *= x;
    }
    return result;
}


float b(int n, float x, float y){
    float result = 1;
    for (int i = 1; i <= n; i++){
        result += (pow(x, pow(2, i)) * pow(y, i));

    }
    return result;
}

float b_2(int n, float x, float y){
    float result = 1;
    float an = 1;
    float bn = 1;

    for (int i = 1; i <= n; i++){
        an *= x*x;
        bn *= y;
        result += (an + bn);

    }
    return result;
}

int main(){

    int n;
    float x, y;
    scanf("%d %f %f", &n, &x, &y);
    printf("%lf\n", a(n, x));
    printf("%lf\n", b(n, x, y));
    printf("%lf\n", b_2(n, x, y));
}