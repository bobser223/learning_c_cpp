//
// Created by Volodymyr Avvakumov on 23.09.2024.
//
#include <stdio.h>

void foo_1(int* arr){
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i; i < size; i++){
        scanf("%d ", &arr[i]);
    }
}

void foo_2(int* arr) {
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i; i < size; i++){
        printf("%d /n", arr[i]);
    }

}

void foo_3(int* arr1, int* arr2, int* arr3){
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < size1; i++){
        arr3[i] = arr1[i] + arr2[i];

    }
}



int main(){
    int arr1, arr2, arr3;
    foo_1(arr1);
    foo_2(arr1);
    foo_1(arr2);
    foo_2(arr2);

    return 0;
}