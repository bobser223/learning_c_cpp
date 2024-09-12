//
// Created by Volodymyr Avvakumov on 13.09.2024.
//
#include <math.h>
#include <stdio.h>


double my_sin(double x, int n){
    if (n <= 0){
        return x;
    }
    return my_sin(sin(x), n -1);
}

double cycle_sin(double x, int n){
    for (int i = 0; i < n; i++){
        x = sin(x);
    }
    return x;
}

int main(){
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%lf\n", cycle_sin(x, n));
    printf("%lf", my_sin(x, n));

}