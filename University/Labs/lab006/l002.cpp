//
// Created by Volodymyr Avvakumov on 16.09.2024.
// 3
#include <iostream>

using namespace std;

bool isOdd(int n){
    if (n % 2 == 0) return true;
    return false;
}

int sec(int n){
    int a0 = n;
    int a1;
    for (int i = 0;; i++){
        if (isOdd(a0)){
            a1 = a0 / 2;
        } else {
            a1 = 3*a0 + 1;
        }
        if (a1 == 1){
            return true;
        }
        a0 = a1;
    }

}

int sec_max(int n){
    int a0 = n;
    int a1;
    for (int i = 0;; i++){
        if (isOdd(a0)){
            a1 = a0 / 2;
        } else {
            a1 = 3*a0 + 1;
        }
        if (a1 == 1){
            return i;
        }
        a0 = a1;
    }

}

int main(){
    int sum = 0;
    for (int i = 1; i <= 1000; i++){
        if (sec(i)){
            sum += 1;
        }
    }
//    cout << sum << endl;
    if (sum == 1000){
        cout << "win" << endl;
    } else {
        cout << "pipiska" << endl;
    }
    int max = 0;
    for (int i = 1; i <= 1000; i++){
        if (sec_max(i) > max){
            max = sec_max(i);
        }
    }
    cout << max << endl;
    return 0;
}