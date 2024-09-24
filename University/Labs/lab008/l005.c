//
// Created by Volodymyr Avvakumov on 23.09.2024.
// 5
#include <stdio.h>

void odd_even_count(int* arr, int br){
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < br; i++){
        if (arr[i] % 2 == 0){
            even_count += 1;
        } else {
            odd_count += 1;
        }
    }
    printf("there are %d evens and %d odds \n", even_count, odd_count);


}

int main(){
    int arr[50];
    int a, br;
    for (int i = 0; i < 50; i++){
        scanf("%d", &a);
        if (a == 0){
            br = i;
            break;
        }
        arr[i] = a;

    }
    odd_even_count(arr, br);
    return 0;
}