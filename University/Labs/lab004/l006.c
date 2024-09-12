//
// Created by Volodymyr Avvakumov on 09.09.2024.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>

double D(double a, double b, double c){
    return pow(b, 2) - 4*a*c;
}

void solvePol(double a, double b, double c){
    double d = D(a, b, c);
    if (d == 0){
        printf("there is only one solution: %li", ((-b)/(2*a)));

    } else if (d > 0) {
        printf("there are two solutions: 1) %li 2) %li" , (((-b) + sqrt(d)))/(2*a), (((-b) - sqrt(d)))/(2*a));
    } else {
        printf("There are on solutions!!!");
    }
}

void solveBiquadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("Немає дійсних розв'язків.\n");
        return;
    }

    double y1 = (-b + sqrt(discriminant)) / (2 * a);
    double y2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("Корені рівняння для y: y1 = %.2f, y2 = %.2f\n", y1, y2);

    if (y1 >= 0) {
        double x1 = sqrt(y1);
        double x2 = -sqrt(y1);
        printf("Розв'язки для x при y1: x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else {
        printf("y1 < 0, тому немає дійсних коренів для x.\n");
    }

    if (y2 >= 0) {
        double x3 = sqrt(y2);
        double x4 = -sqrt(y2);
        printf("Розв'язки для x при y2: x3 = %.2f, x4 = %.2f\n", x3, x4);
    } else {
        printf("y2 < 0, тому немає дійсних коренів для x.\n");
    }
}

int main(){
    double a, b, c;
    scanf("%li %li %li", &a, &b, &c);
    solvePol(a, b, c);

}