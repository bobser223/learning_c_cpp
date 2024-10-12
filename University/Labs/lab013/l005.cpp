//
// Created by Volodymyr Avvakumov on 11.10.2024.
//
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int x, y;
    cin >> x;
    cin >> y;

    cout << pow(x, y) << endl;
    cout << scientific  << pow(x, y) << endl;
}
