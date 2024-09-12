//
// Created by Volodymyr Avvakumov on 09.09.2024.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

typedef unsigned long long int ulli;

int main(){
    int k = false ? 1 : 2;
    printf("%li\n", k);
    int n = 1;
    switch (n){
        case 1:
            printf("1");
            break;
        case 10:
            printf("10");
            break;
        case 20:
            printf("20");
            break;
        default:
            printf("defoult\n");
            break;
    }

    if (true ^ false){
        printf("wfuif");
    } else if (false || true){
        printf("2134234");
    } else {
        printf("]]]]]]]");
    }
}
