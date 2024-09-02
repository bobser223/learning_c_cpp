//
// Created by Volodymyr Avvakumov on 18.08.2024.
//

#include <iostream>
using namespace std;
void findMin(int *lst, int size, int &min){
    min = lst[0];
    for (int i = 1; i < size; i++){
        int currNum = lst[i];
        if (currNum < min){
            min = currNum;
        }
    }

}

void findMax(int *lst, int size, int &max){
    max = lst[0];
    for (int i = 1; i < size; i++){
        int currNum = lst[i];
        if (currNum > max){
            max = currNum;
        }
    }

}

int main(){
    int size, value, min, max;
    cin >> size;
    int lst[size];
    for (int i = 0; i < size; i++){
        cin >> value;
        lst[i] = value;
    }

    findMin(lst, size, min);
    findMax(lst, size, max);

    for (int i = 0; i < size; i++){
        if (lst[i] == min){
            lst[i] = max;
        } else if (lst[i] == max){
            lst[i] = min;
        }
    }

    for (int i = 0; i < size; i++){
        cout << lst[i] << " ";
    }


}