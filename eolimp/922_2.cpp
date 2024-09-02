//
// Created by Volodymyr Avvakumov on 17.08.2024.
//

#include <iostream>

using namespace std;

int main(){
    int size, value;

    cin >> size;

    int lst[size], lst2[size];


    for (int i = 0; i <size; i++){
        cin >> value;
        lst[i] = value;
    }

    lst2[0] = lst[size - 1];
    for (int i = 0; i < size - 1 ; i++)
        lst2[i + 1] = lst[i];

    for (int i = 0; i < size; i++){
        cout << lst2[i] << " ";
    }

    return 0;
}