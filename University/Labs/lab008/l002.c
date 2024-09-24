//
// Created by Volodymyr Avvakumov on 23.09.2024.
//

#include <stdio.h>
#define N 5

void print(int* arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d \n", arr[i]);
    }

}

int main(){
    int arree[N];
    int n = 5;
    int arre[n];
    int arr[] = {1, 2, 3, 4, 5};

    printf("%p\n", arr);
    for (int i = 0; i < n; i++){
        printf("%p %p\n", &arr[i], arr + 1);
    }
    print(arr, n);
}