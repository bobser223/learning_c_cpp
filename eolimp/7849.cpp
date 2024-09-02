//
// Created by Volodymyr Avvakumov on 18.08.2024.
//
#include <iostream>
using namespace std;
void findMin(int *lst, int size, int &min, int &minIndex){
    min = lst[0];
    minIndex = 0;
    for (int i = 1; i < size; i++){
        int currNum = lst[i];
        if (currNum < min){
            min = currNum;
            minIndex = i;
        }
    }

}

void findMax(int *lst, int size, int &max, int &maxIndex){
    max = lst[0];
    maxIndex = 0;
    for (int i = 1; i < size; i++){
        int currNum = lst[i];
        if (currNum > max){
            max = currNum;
            maxIndex = i;
        }
    }

}

int main(){
    int size, value, min, minIndex, max, maxIndex;
    cin >> size;
    int lst[size];
    for (int i = 0; i < size; i++){
        cin >> value;
        lst[i] = value;
    }

    findMin(lst, size, min, minIndex);
    findMax(lst, size, max, maxIndex);

    lst[maxIndex] = min;
    lst[minIndex] = max;
    for (int i = 0; i < size; i++){
        cout << lst[i] << " ";
    }


}