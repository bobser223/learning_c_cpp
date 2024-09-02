//
// Created by Volodymyr Avvakumov on 17.08.2024.
//
#include <iostream>

using namespace std;

int main(){
    int size, value;


    cin >> size;

    int lst[size];


    for (int i = 1; i <size; i++){
        cin >> value;
        lst[i] = value;
    }

    cin >> value;
    lst[0] = value;

    for (int i = 0; i < size; i++){
        cout << lst[i] << " ";
    }
    return 0;
}