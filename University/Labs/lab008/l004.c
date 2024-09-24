//
// Created by Volodymyr Avvakumov on 23.09.2024.
//
#include <stdio.h>

int main(){
    int arr[] = {5, 112, 4, 3};
    for (int i = 0; i < 4; i ++){
        printf("%d \n", arr[3 - i]);
    }
    return 0;
}