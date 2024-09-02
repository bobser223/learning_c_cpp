#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



int main() {
    int size, value;
    cin >> size;
    int lst[size];
    for (int i = 0; i < size; i++){
        cin >> value;
        lst[i] = value;
    }


    for (int i = 0; i < size; i ++){
        int currNum = lst[i];
        if (currNum == 101){
            continue;
        }
        for (int j = i + 1; j < size; j++){
            int nextNum = lst[j];
            if (lst[j] == currNum){
                lst[j] = 101;
            }
        }
    }
    for (int i = 0; i < size; i++){
        if (lst[i] == 101){
            continue;
        } else {
            cout << lst[i] << " ";
        }
    }
}