//
// Created by Volodymyr Avvakumov on 30.09.2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print(int* a,int n){
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);

    }
//    for (int i = 0; i < n; i++){
//        printf("%d\n", *(a + i));
//
//    }

}

int input(int** a){
    *a = (int*)malloc(0*sizeof(**a));
    int n = 0;
    while (n < 100){
        int x;
        scanf("%i", &x);
        if (x == 0){
            break;
        }
        *a = (int*)realloc(*a, (n+1)*sizeof(**a));
        if (a == NULL)
            exit(1);
        (*a)[n] = x;
        n++;
    }
    return n;
}

int is_sqr(int n){
    float sqrt_num = sqrt(n);
    int int_sqrt = (int)sqrt_num;
    if (int_sqrt == sqrt_num){
        return 1;
    }
}

int sqr_count(int* a, int n){
    int sum = 0;
    for (int i = 0; i < n; i ++){



    }
}


int main(){
    int* a;
    int n = input(&a);
//    print(a, n);

    free(a);

}