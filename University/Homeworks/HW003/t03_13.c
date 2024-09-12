//
// Created by Volodymyr Avvakumov on 11.09.2024.
//
#include <stdint.h>
#include <stdio.h>
void solve(double a1, double b1, double c1, double a2, double b2, double c2) {
    double det = a1 * b2 - a2 * b1;

    if (det == 0) {
        if ((a1 / a2 == b1 / b2) && (a1 / a2 == c1 / c2)) {
            printf("The system has infinitely many solutions.\n");
        } else {
            printf("The system has no solutions.\n");
        }
    } else {
        double x = (c1 * b2 - c2 * b1) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        printf("The system has a unique solution:\n");
        printf("x = %.2f, y = %.2f\n", x, y);
    }
}



int main(){
    float a1, b1, c1, a2, b2, c2;
    printf("please enter a1, b1, c1\t");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("\n");
    printf("please enter a2, b2, c2\t");
    scanf("%lf %lf %lf", &a2, &b2, &c2);
    solve(a1, b1, c1, a2, b2, c2);

    return 0;
}