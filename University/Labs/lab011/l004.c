//
// Created by Volodymyr Avvakumov on 05.10.2024.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct vertex{
    int x, y;

} vertex;

typedef struct rectangle{
    // v1------------+
    // |             |
    // |             |
    // |             |
    // |             |
    // +----------- v2
    vertex v1, v2;


} rectangle;


typedef struct pol{
    int power;
    int* coefficients;

} pol;

pol make_pol(){
    pol p;
    printf("enter power of polynomial: ");
    scanf("%d", &p.power);
    p.coefficients = (int*)calloc(p.power, sizeof(int));
    for (int i = 0; i < p.power; i++){
        printf("enter the coefficient to the power %d: ", i);
        scanf("%d", &(p.coefficients[i]));
    }
    return p;
}

void print_pol(pol p){
    for(int i = 0; i < p.power; i++){
        if (i == 0){
            printf("%d + ", p.coefficients[i]);
        } else if (i == p.power - 1){
            printf("%d*x^%d", p.coefficients[i], i);
        } else {
            printf("%d*x^%d + ", p.coefficients[i], i);
        }

    }
}
void kill_pol(pol p){
    free(p.coefficients);
}

int main(){
    pol p = make_pol();
    print_pol(p);
    kill_pol(p);
    return 0;
}