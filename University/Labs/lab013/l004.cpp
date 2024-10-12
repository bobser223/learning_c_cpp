//
// Created by Volodymyr Avvakumov on 11.10.2024.
//
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

void read_file(int* arr, int size, char* filename){
    ifstream finp("Labs/lab013/input.txt");
    if (!finp.is_open())
        exit(1);
    int i = 0;
    while (i < size){
        int n;
        finp >> n;
        if (!finp.good()){
            exit(2);
        }
        arr[i] = n;
        i ++;
    }
    finp.close();
}

void input_arr(int* arr, int size){
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void file_output()

int main(){
    int n;
    cout << "enter n: ";
    cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    input_arr(arr1, n);
    read_file(arr2, n, "Labs/lab013/input.txt");

    delete[] arr1;
    delete[] arr2;
}