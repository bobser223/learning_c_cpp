//
// Created by Volodymyr Avvakumov on 30.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
// cstdlib for cpp

void print(int* a,int n){
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);

    }
//    for (int i = 0; i < n; i++){
//        printf("%d\n", *(a + i));
//
//    }

}

void input(int* a,int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}





int main(){
    int n = 10;
//    scanf("%d", &n);
    int* a;
    // a = (int*)malloc(n * sizeof(int)); // posible (int*)malloc(m * sizeof(*a))
    a = (int*)calloc(n, sizeof(int));
    if (a == NUll)
        exit(1);
//    print(a, n);
//    input(a, n);
//    print(a, n);

    a = (int*)realloc(a, (n + 1)*sizeof(*a));
    a[n] = 1000;
    print(a, n+1);

    free(a);
    return 0;
}