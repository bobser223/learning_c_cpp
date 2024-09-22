//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int x = 1 << k;
    cout << (n | x);



    return 0;
}