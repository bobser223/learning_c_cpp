//
// Created by Volodymyr Avvakumov on 15.10.2024.
//
//
// Created by Volodymyr Avvakumov on 13.10.2024.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;



void push_back(double** arr, int* size, double var) {
    double* arr2 = new double[*size + 1];
    for (int i = 0; i < *size; i++) {
        arr2[i] = (*arr)[i];
    }
    arr2[*size] = var;
    delete[] *arr;
    *arr = arr2;
    (*size)++;
}

void print_arcsin(double num){
    if (num < -1 || num > 1) {
    } else {
        cout << asin(num) << endl;
    }
}

void print_arcsins_from_arr(double* arr, int size){
    for (int i = 0; i < size; i++){
        print_arcsin(arr[i]);
    }
}


int read_txt_to_arr(double** arr, int* size, char* filename){
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    while (!file.eof()) {

        double a;
        file >> a;
        push_back(arr, size, a);
        file.ignore(256, ';');
    }
    file.close();
    return 0;
}


int main(){
    int size = 0;
    double* arr = new double[0];

    read_txt_to_arr(&arr, &size, "Homeworks/HW012/doubles.txt");
//    for (int i = 0; i < size; i++){
//        cout << arr[i] << endl;
//    }
    print_arcsins_from_arr(arr, size);
    delete[] arr;
    return 0;
}