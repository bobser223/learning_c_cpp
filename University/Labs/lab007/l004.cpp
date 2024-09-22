//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a = ~(1 << k);
    int b = n & a;
    cout << b << endl;

    cout << hex << b << endl;

    printf("%Lx", b);

    return 0;
}