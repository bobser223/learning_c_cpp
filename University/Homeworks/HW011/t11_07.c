//
// Created by Volodymyr Avvakumov on 08.10.2024.
// z
#include <stdio.h>
#include <stdlib.h>
#define N 100

void write_nums_to_b_file(int* nums, int size, char* filename){
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        perror("Помилка відкриття файлу");
    }
    for (int i = 0; i < size; i++){
        fwrite(nums + i, sizeof(int), 1, f);
    }
    fclose(f);
}

void write_nums_to_b_file_1(int* nums, int size, char* filename){
    FILE* f = fopen(filename, "wb");
    for (int i = 0; i < size; i++){
        fwrite(&nums[i], sizeof(int), 1, f);
    }


}

double count_mean(int* arr,int size){
    double sum = 0;
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
//    printf("%d\n", size);
    rewind(f);
//    fseek(f,0, SEEK_SET);
    int n = size/sizeof(int);
//    printf("%d\n", n);
    int arr[N];
    fread(arr, sizeof(int), n, f);
    fclose(f);
    int counter = 0;
    double mean = count_mean(arr, n);
//    printf("%lf", mean);
    for (int i = 0; i < n; i++) {
//        printf("%d\n", arr[i]);
        if (arr[i] < mean) counter++;
    }
    return counter;
}



int main(){
    int nums[] = {1, 2, 3, 4, 5, 6};
    int nums_size = sizeof(nums) /sizeof(nums[0]);
    write_nums_to_b_file(nums, nums_size, "Homeworks/HW011/nums.pipka");
    printf("%d",file_components_less_then_ar_mean_count("Homeworks/HW011/nums.pipka"));

    return 0;
}
