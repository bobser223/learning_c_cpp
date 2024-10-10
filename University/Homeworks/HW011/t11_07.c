//
// Created by Volodymyr Avvakumov on 08.10.2024.
// z
#include <stdio.h>
#include <stdlib.h>
#define N 100

double count_mean(int* arr,int size){
    double sum;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum / size;
}


int file_components_less_then_ar_mean_count(const char* filename){
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Помилка відкриття файлу");
    }

    fseek(f,0, SEEK_END);
    int size = ftell(f);
    rewind(f);
    int n = size/sizeof(int);
    printf("%d\n", n);
    int arr[N];
    fread(arr, sizeof(int), n, f);

    int counter = 0;
    double mean = count_mean(arr, n);

    for (int i = 0; i < n; i++) {
        if (arr[i] < mean) counter++;
    }
    return counter;
}




int main(){


    return 0;
}
