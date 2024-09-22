//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int8_t a = 0b00001101;
    int8_t b = 0b00011010;

    cout << bitset<8>(a) << ' ' << (int16_t) a << endl;
    cout << bitset<8>(b) << ' ' << (int16_t) b << endl;


    cout << "a & b = "<< bitset<8>(a&b) << endl;
    cout << "a | b = "<< bitset<8>(a|b) << endl;
    cout << "a ^ b = "<< bitset<8>(a^b) << endl << endl;


    cout << "~a = "<< bitset<8>(~a) << endl;
    cout << "~b = "<< bitset<8>(~b) << endl << endl;


    cout << "a << 1 = "<< bitset<8>(a << 1) << endl;
    cout << "b << 1 = "<< bitset<8>(b << 1) << endl << endl;

    cout << "a >> 1 = "<< bitset<8>(a >> 1) << endl;
    cout << "b >> 1 = "<< bitset<8>(b >> 1) << endl << endl;

    cout << "~0 = "<< bitset<8>(~0) << ' ' << ~0 << endl << endl;
    return 0;
}