//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    uint32_t n = 0x0103070F;
//    cin >> n;
    cout << bitset<32>(n) << endl;
    uint32_t left8 = n >> 24; // 0x00000000001
    uint32_t right8 = n << 24;
    n = (n >> 8) << 8;
    n = (n << 8) >> 8;
    cout << ((n | right8) | left8) << endl;

    cout << bitset<32>((n | right8) | left8) << endl;

    cout << hex << ((n | right8) | left8) << endl;



    return 0;
}