//
// Created by Volodymyr Avvakumov on 18.08.2024.
//
#include <iostream>
using namespace std;

int main(){
    int size, counter = 0;
    float value, sum = 0;
    cin >> size;
    for (int i = 0; i < size; i++){
        cin >> value;
        if (value > 0){
            sum += value;
            counter += 1;
        }

    }
    if (counter == 0){
        cout << "Not Found";
    } else {
        cout << sum / counter;
    }
}